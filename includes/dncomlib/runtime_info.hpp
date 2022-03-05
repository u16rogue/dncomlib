#pragma once

#include "unique_releasable.hpp"
#include <metahost.h>
#include <mscoree.h>

namespace dncomlib
{
    class runtime_info : public dncomlib::unique_releasable<ICLRRuntimeInfo>
    {
    public:
        runtime_info(runtime_info &) = delete;
        runtime_info(const runtime_info &) = delete;

        runtime_info() = default;
        runtime_info(ICLRRuntimeInfo *i_);
    };
}