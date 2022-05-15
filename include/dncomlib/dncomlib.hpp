#pragma once

#include <dncomlib/app_domain.hpp>
#include <dncomlib/meta_host.hpp>
#include <dncomlib/unique_releasable.hpp>
#include <dncomlib/unknown_enumerator.hpp>
#include <dncomlib/runtime_info.hpp>
#include <dncomlib/runtime_host.hpp>

#include <dncomlib/mslib/IUnknown.hpp>

namespace dncomlib
{
    auto clr_create_instance(const GUID & clsid, const GUID & riid) -> dncomlib::meta_host;
}