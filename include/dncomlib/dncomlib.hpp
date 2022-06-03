#pragma once

#include <dncomlib/app_domain.hpp>
#include <dncomlib/meta_host.hpp>
#include <dncomlib/unique_releasable.hpp>
#include <dncomlib/unknown_enumerator.hpp>
#include <dncomlib/runtime_info.hpp>
#include <dncomlib/runtime_host.hpp>
#include <dncomlib/clr_debugging.hpp>

#include <dncomlib/mslib/IUnknown.hpp>

namespace dncomlib
{
    auto clr_create_instance(const GUID & clsid, const GUID & riid) -> dncomlib::unique_releasable<dncomlib::mslib::IUnknown>;

    auto clr_create_meta_host_instance() -> dncomlib::meta_host;
    auto clr_create_debugging() -> dncomlib::clr_debugging;
}