#include <assert.h>
#include <stdio.h>
#include "Interface.h"

int main(int argc, char *argv[])
{
	IRefCountPrinter*	pRefCntPrinter	= 0;
	ITester*			pTester			= 0;
	HRESULT				hr				= S_OK;

	if (FAILED(hr = CreateTester(&pTester))) {
		printf("failed creating object with hr = 0x%.8x\n", hr);
		return hr;
	}

	if (FAILED(hr = pTester->QueryInterface(IID_IRefCountPrinter, (void**)&pRefCntPrinter))) {
		assert(false);
	}
	pRefCntPrinter->PrintRefCount();
	pTester->TestMe();
	pTester->Release();// Kills the object

	printf("Object is still alive\n");
	pRefCntPrinter->PrintRefCount();
	pRefCntPrinter->Release();
	return 0;
}