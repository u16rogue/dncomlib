#include <dncomlib/runtime_host.hpp>

dncomlib::runtime_host::runtime_host(mslib::ICorRuntimeHost * i_)
    : dncomlib::unique_releasable<mslib::ICorRuntimeHost>(i_)
{
}

auto dncomlib::runtime_host::get_default_domain_thunk() -> dncomlib::unique_releasable<mslib::IUnknown>
{
    mslib::IUnknown * res {};
    instance->GetDefaultDomain(&res);
    return dncomlib::unique_releasable<mslib::IUnknown>(res);
}