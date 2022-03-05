#pragma once

#include "unique_releasable.hpp"

#include <Windows.h>
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

        auto is_started(DWORD * out_startup_flags = nullptr) -> bool;

        static auto from_thunk(const dncomlib::unique_releasable<IUnknown> & thunk) -> runtime_info;
    };
}