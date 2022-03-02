#pragma once

#include "unique_clr_releasable.hpp"
#include <metahost.h>

namespace dcl
{
    class unknown_enumerator
    {
    public:
        
    private:
        dcl::unique_clr_releasable<IEnumUnknown> instance;
    };
}