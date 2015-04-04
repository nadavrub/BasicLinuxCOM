#include "windowsdef.h"

// {00000000-0000-0000-C000-000000000046}
static const GUID IID_IUnknown = { 0x00000000, 0x0000, 0x0000, { 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46 } };

interface IUnknown
{
	virtual HRESULT QueryInterface(IN REFIID riid, OUT void** ppvObject) = 0;
	virtual UINT AddRef(void) = 0;
	virtual UINT Release(void) = 0;
};
