#pragma once

#include <dncomlib/unique_releasable.hpp>
#include <dncomlib/unknown_enumerator.hpp>
#include <dncomlib/mslib/ICLRMetaHost.hpp>

namespace dncomlib
{
    class meta_host : public dncomlib::unique_releasable<ICLRMetaHost>
    {
    public:
        meta_host() = default;
        meta_host(ICLRMetaHost * i_);

        auto enumerate_loaded_runtimes(void * process_handle) -> dncomlib::unknown_enumerator;
    };
}