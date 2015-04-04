#pragma once

#define HRESULT int
#define UINT unsigned int

typedef struct _GUID {
	unsigned long  Data1;
	unsigned short Data2;
	unsigned short Data3;
	unsigned char  Data4[8];
} GUID;

#define REFIID const GUID&

#define interface struct

#define IN
#define OUT
