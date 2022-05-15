#pragma once
#include <dncomlib/mslib/IUnknown.hpp>

namespace dncomlib
{
    class IEnumUnknown: public IUnknown
    {
    public:
        virtual /* [local] */ long __stdcall Next(
            /* [annotation][in] */
		    unsigned long celt,
            /* [annotation][out] */
            IUnknown **rgelt,
            /* [annotation][out] */
            unsigned long *pceltFetched) = 0;

        virtual long __stdcall Skip(
            /* [in] */ unsigned long celt) = 0;

        virtual long __stdcall Reset(void) = 0;

        virtual long __stdcall Clone(
            /* [out] */ IEnumUnknown ** ppenum) = 0;

    };
}