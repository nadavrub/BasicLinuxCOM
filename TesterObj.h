#pragma once
#include <atomic>
#include "Interface.h"

class TesterObj : public ITester
				, public IRefCountPrinter
{
protected:
	std::atomic_uint m_uiRefCount;

	TesterObj();
	~TesterObj();

public:
	// IUnknown implementation
	HRESULT QueryInterface(IN REFIID riid, OUT void** ppvObject);
	UINT AddRef(void);
	UINT Release(void);

	// ITester implementation
	void TestMe();

	// IRefCountPrinter implementatin
	void PrintRefCount();

	static HRESULT CreateInstance(OUT IUnknown** ppUnk);
};
