#include <dncomlib/meta_host.hpp>
#include <utility>

dcl::meta_host::meta_host(ICLRMetaHost * i_)
    : instance (i_)
{
}

dcl::meta_host::operator bool() const noexcept
{
    return static_cast<bool>(instance);
}

auto dcl::meta_host::operator = (meta_host && rhs) -> void
{
    instance = std::move(rhs.instance);
}

auto dcl::meta_host::operator -> () -> ICLRMetaHost *
{
    return *instance.ppinstance();
}