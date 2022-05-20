#pragma once

#include <dncomlib/mslib/IUnknown.hpp>

namespace dncomlib::mslib
{
    class ICorRuntimeHost: public IUnknown
    {
    public:
        virtual long __stdcall CreateLogicalThreadState(void) = 0;

        virtual long __stdcall DeleteLogicalThreadState(void) = 0;

        virtual long __stdcall SwitchInLogicalThreadState(
            /* [in] */ unsigned long * pFiberCookie) = 0;

        virtual long __stdcall SwitchOutLogicalThreadState(
            /* [out] */ unsigned long ** pFiberCookie) = 0;

        virtual long __stdcall LocksHeldByLogicalThread(
            /* [out] */ unsigned long * pCount) = 0;

        virtual long __stdcall MapFile(
            /* [in] */ void * hFile,
            /* [out] */ void ** hMapAddress) = 0;

        virtual long __stdcall GetConfiguration(
            /* [out] */ void ** pConfiguration) = 0;

        virtual long __stdcall Start(void) = 0;

        virtual long __stdcall Stop(void) = 0;

        virtual long __stdcall CreateDomain(
            /* [in] */ const wchar_t * pwzFriendlyName,
            /* [in] */ IUnknown * pIdentityArray,
            /* [out] */ IUnknown ** pAppDomain) = 0;

        virtual long __stdcall GetDefaultDomain(
            /* [out] */ IUnknown ** pAppDomain) = 0;

        virtual long __stdcall EnumDomains(
            /* [out] */ void ** hEnum) = 0;

        virtual long __stdcall NextDomain(
            /* [in] */ void * hEnum,
            /* [out] */ IUnknown ** pAppDomain) = 0;

        virtual long __stdcall CloseEnum(
            /* [in] */ void * hEnum) = 0;

        virtual long __stdcall CreateDomainEx(
            /* [in] */ const wchar_t * pwzFriendlyName,
            /* [in] */ IUnknown * pSetup,
            /* [in] */ IUnknown * pEvidence,
            /* [out] */ IUnknown ** pAppDomain) = 0;

        virtual long __stdcall CreateDomainSetup(
            /* [out] */ IUnknown ** pAppDomainSetup) = 0;

        virtual long __stdcall CreateEvidence(
            /* [out] */ IUnknown ** pEvidence) = 0;

        virtual long __stdcall UnloadDomain(
            /* [in] */ IUnknown * pAppDomain) = 0;

        virtual long __stdcall CurrentDomain(
            /* [out] */ IUnknown ** pAppDomain) = 0;
    };
}