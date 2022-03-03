#pragma once

#include "unique_releasable.hpp"
#include "unknown_enumerator.hpp"
#include <metahost.h>

namespace dncomlib
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

        auto enumerate_loaded_runtimes(void * process_handle) -> dncomlib::unknown_enumerator;

    private:
        dncomlib::unique_releasable<ICLRMetaHost> instance;
    };
}