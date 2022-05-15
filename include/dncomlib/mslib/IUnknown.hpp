#pragma once

namespace dncomlib
{
	struct GUID
	{
		unsigned long  Data1;
		unsigned short Data2;
		unsigned short Data3;
		unsigned char  Data4[8];
	};

	class IUnknown
	{
	public:	
		virtual long __stdcall QueryInterface(const GUID & riid, void * ppvObject) = 0;
		virtual unsigned long __stdcall AddRef( void) = 0;
		virtual unsigned long __stdcall Release( void) = 0;
	};
}