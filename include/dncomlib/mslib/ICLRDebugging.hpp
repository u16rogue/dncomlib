#pragma once

#include <dncomlib/mslib/IUnknown.hpp>

namespace dncomlib::mslib
{
	class ICLRDebugging : public IUnknown
    {
    public:
        virtual long __stdcall OpenVirtualProcess( 
            /* [in] */ unsigned long long moduleBaseAddress,
            /* [in] */ IUnknown *pDataTarget,
            /* [in] */ /* ICLRDebuggingLibraryProvider */ void *pLibraryProvider,
            /* [in] */ /* CLR_DEBUGGING_VERSION */ void *pMaxDebuggerSupportedVersion,
            /* [in] */ const GUID & riidProcess,
            /* [iid_is][out] */ IUnknown **ppProcess,
            /* [out][in] */ /* CLR_DEBUGGING_VERSION */ void *pVersion,
            /* [out] */ /* CLR_DEBUGGING_PROCESS_FLAGS */ void *pdwFlags) = 0;
        
        virtual long __stdcall CanUnloadNow( 
            void * hModule) = 0;
    };
}