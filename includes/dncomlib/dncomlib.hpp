#pragma once

#include <metahost.h>
#include <mscoree.h>

#include "meta_host.hpp"
#include "unique_releasable.hpp"
#include "unknown_enumerator.hpp"

namespace dcl
{
    auto clr_create_instance(const IID & clsid, const IID & riid) -> dcl::meta_host;
}