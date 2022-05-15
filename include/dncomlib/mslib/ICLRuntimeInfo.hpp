#pragma once
#include <dncomlib/mslib/IUnknown.hpp>

namespace dncomlib
{
    class ICLRRuntimeInfo : public IUnknown
    {
    public:
        virtual long __stdcall GetVersionString(
            /* [annotation][size_is][out] */
            const wchar_t *pwzBuffer,
            /* [out][in] */ unsigned long *pcchBuffer) = 0;

        virtual long __stdcall GetRuntimeDirectory(
            /* [annotation][size_is][out] */
            const wchar_t *pwzBuffer,
            /* [out][in] */ unsigned long * pcchBuffer) = 0;

        virtual long __stdcall IsLoaded(
            /* [in] */ void *  hndProcess,
            /* [retval][out] */ int * pbLoaded) = 0;

        virtual long __stdcall LoadErrorString(
            /* [in] */ int iResourceID,
            /* [annotation][size_is][out] */
            const wchar_t *pwzBuffer,
            /* [out][in] */ unsigned long * pcchBuffer,
            /* [lcid][in] */ long iLocaleID) = 0;

        virtual long __stdcall LoadLibrary(
            /* [in] */ const wchar_t * pwzDllName,
            /* [retval][out] */ void *  * phndModule) = 0;

        virtual long __stdcall GetProcAddress(
            /* [in] */ const char * pszProcName,
            /* [retval][out] */ void * * ppProc) = 0;

        virtual long __stdcall GetInterface(
            /* [in] */ const GUID & rclsid,
            /* [in] */ const GUID & riid,
            /* [retval][iid_is][out] */ void * * ppUnk) = 0;

        virtual long __stdcall IsLoadable(
            /* [retval][out] */ int * pbLoadable) = 0;

        virtual long __stdcall SetDefaultStartupFlags(
            /* [in] */ unsigned long dwStartupFlags,
            /* [in] */ const wchar_t *  pwzHostConfigFile) = 0;

        virtual long __stdcall GetDefaultStartupFlags(
            /* [out] */ unsigned long * pdwStartupFlags,
            /* [annotation][size_is][out] */
            const wchar_t *pwzHostConfigFile,
            /* [out][in] */ unsigned long * pcchHostConfigFile) = 0;

        virtual long __stdcall BindAsLegacyV2Runtime(void) = 0;

        virtual long __stdcall IsStarted(
            /* [out] */ int * pbStarted,
            /* [out] */ unsigned long * pdwStartupFlags) = 0;

    };
}