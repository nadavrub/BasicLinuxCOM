#define E_NOINTERFACE 0x80004002L
#define S_OK 0
#define E_OUTOFMEMORY 0x8007000EL

// Generic test for success on any status value (non-negative numbers indicate success).
#define SUCCEEDED(hr) (((HRESULT)(hr)) >= 0)

// and the inverse
#define FAILED(hr) (((HRESULT)(hr)) < 0)