#include <stdio.h>
#include <memory.h>
#include "TesterObj.h"


TesterObj::TesterObj()
			: m_uiRefCount(0)
{
	printf("TesterObj::TesterObj(), ref count = %d\n", (UINT)m_uiRefCount);
}


TesterObj::~TesterObj()
{
	printf("TesterObj::~TesterObj(), ref count = %d\n", (UINT)m_uiRefCount);
}

HRESULT TesterObj::QueryInterface(IN REFIID riid, OUT void** ppvObject) {
	if (0 == memcmp(&riid, &IID_IUnknown, sizeof(GUID)))
		*ppvObject = (IUnknown*)((ITester*)this);
	else if (0 == memcmp(&riid, &IID_ITester, sizeof(GUID)))
		*ppvObject = (ITester*)this;
	else if (0 == memcmp(&riid, &IID_IRefCountPrinter, sizeof(GUID)))
		*ppvObject = (IRefCountPrinter*)this;
	else
		return E_NOINTERFACE;
	AddRef();// A reference to the object is returned via '*ppvObject', add a ref
	return S_OK;
}

UINT TesterObj::AddRef(void) {
	return m_uiRefCount.fetch_add(1) + 1;
}

UINT TesterObj::Release(void) {
	const UINT uiRef = m_uiRefCount.fetch_sub(1) - 1;
	if (0 == uiRef)
		delete this;
	return uiRef;
}

void TesterObj::TestMe() {
	printf("TesterObj::TestMe(), This is a test!\n");
}

void TesterObj::PrintRefCount() {
	printf("TesterObj::PrintRefCount(), Ref count is %d\n", (UINT)m_uiRefCount);
}

HRESULT TesterObj::CreateInstance(OUT IUnknown** ppUnk) {
	TesterObj* pObj = new TesterObj();
	if (0 == pObj)
		return E_OUTOFMEMORY;
	pObj->AddRef();
	HRESULT hr = pObj->QueryInterface(IID_IUnknown, (void**)ppUnk);
	pObj->Release();// if 'pObj->QueryInterface' has failed, it doesn't increase the ref count, and this 'Release()' will destruct the object
	return hr;
}