#pragma once
#include <dncomlib/mslib/IUnknown.hpp>
#include <dncomlib/mslib/IEnumUnknown.hpp>

namespace dncomlib
{
    class ICLRMetaHost: public IUnknown
    {
    public:
        virtual long __stdcall GetRuntime(
            /* [in] */ const wchar_t * pwzVersion,
            /* [in] */ const GUID & riid,
            /* [retval][iid_is][out] */ void ** ppRuntime) = 0;

        virtual long __stdcall GetVersionFromFile(
            /* [in] */ const wchar_t * pwzFilePath,
            /* [annotation][size_is][out] */
						const wchar_t * pwzBuffer,
            /* [out][in] */ unsigned long * pcchBuffer) = 0;

        virtual long __stdcall EnumerateInstalledRuntimes(
            /* [retval][out] */ IEnumUnknown ** ppEnumerator) = 0;

        virtual long __stdcall EnumerateLoadedRuntimes(
            /* [in] */ void * hndProcess,
            /* [retval][out] */ IEnumUnknown ** ppEnumerator) = 0;

        virtual long __stdcall RequestRuntimeLoadedNotification(
            /* [in] */ void * pCallbackFunction) = 0;

        virtual long __stdcall QueryLegacyV2RuntimeBinding(
            /* [in] */ const GUID & riid,
            /* [retval][iid_is][out] */ void ** ppUnk) = 0;

        virtual long __stdcall ExitProcess(
            /* [in] */ int ExitCode) = 0;

    };
}