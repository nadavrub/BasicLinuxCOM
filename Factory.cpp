#include "TesterObj.h"

HRESULT CreateTester(OUT ITester** ppObj) {
	IUnknown* pUnk = 0;
	HRESULT hr = S_OK;
	if (FAILED(hr = TesterObj::CreateInstance(&pUnk)))
		return hr;
	hr = pUnk->QueryInterface(IID_ITester, (void**)ppObj);
	pUnk->Release();
	return hr;
}