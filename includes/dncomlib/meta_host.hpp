#pragma once

#include "unique_clr_releasable.hpp"
#include <metahost.h>

namespace dcl
{
    class meta_host
    {
    public:
        meta_host(meta_host &) = delete;
        meta_host(const meta_host &) = delete;

        meta_host() = default;
        meta_host(ICLRMetaHost * i_);

        auto operator -> () -> ICLRMetaHost *;
        auto operator = (meta_host && rhs) -> void;
        operator bool() const noexcept;
    private:
        dcl::unique_clr_releasable<ICLRMetaHost> instance;
    };
}