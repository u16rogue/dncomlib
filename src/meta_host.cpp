#include <dncomlib/meta_host.hpp>
#include <utility>
#include <Windows.h>

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

auto dcl::meta_host::enumerate_loaded_runtimes(void * process_handle) -> dcl::unknown_enumerator
{
    IEnumUnknown * res {};
    if (instance->EnumerateLoadedRuntimes(reinterpret_cast<HANDLE>(process_handle), &res) != S_OK)
        return dcl::unknown_enumerator(nullptr);

    return dcl::unknown_enumerator(res);
}