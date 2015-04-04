#include "combase.inl"
#include "winerror.h"

static const GUID IID_ITester = { 0x12345678, 0x1234, 0x1234, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 } };

interface ITester : public IUnknown
{
	virtual void TestMe() = 0;
};

static const GUID IID_IRefCountPrinter = { 0x12345678, 0x1234, 0x1234, { 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01 } };

interface IRefCountPrinter : public IUnknown
{
	virtual void PrintRefCount() = 0;
};

HRESULT CreateTester(OUT ITester** ppObj);