#pragma once

#include "unique_clr_releasable.hpp"
#include <optional>
#include <metahost.h>
#include <mscoree.h>

namespace dcl
{
    auto clr_create_instance(const IID & clsid, const IID & riid) -> dcl::unique_clr_releasable<ICLRMetaHost>;
}