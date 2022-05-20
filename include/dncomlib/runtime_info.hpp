#pragma once

#include <dncomlib/unique_releasable.hpp>
#include <dncomlib/runtime_host.hpp>
#include <Windows.h>
#include <dncomlib/mslib/ICLRuntimeInfo.hpp>

namespace dncomlib
{
    class runtime_info : public dncomlib::unique_releasable<mslib::ICLRRuntimeInfo>
    {
    public:
        runtime_info(runtime_info &) = delete;
        runtime_info(const runtime_info &) = delete;

        runtime_info() = default;
        runtime_info(mslib::ICLRRuntimeInfo *i_);

        auto is_started(DWORD * out_startup_flags = nullptr) -> bool;
        auto get_host() -> runtime_host;
        auto get_version_string() -> std::wstring;

        static auto from_unknown(const dncomlib::unique_releasable<mslib::IUnknown> & unk) -> runtime_info;
    };
}