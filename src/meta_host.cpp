#include <dncomlib/meta_host.hpp>
#include <utility>
#include <Windows.h>

dncomlib::meta_host::meta_host(mslib::ICLRMetaHost * i_)
    : dncomlib::unique_releasable<mslib::ICLRMetaHost>(i_)
{
}

auto dncomlib::meta_host::enumerate_loaded_runtimes(void * process_handle) -> dncomlib::unknown_enumerator
{
    mslib::IEnumUnknown * res {};
    instance->EnumerateLoadedRuntimes(reinterpret_cast<HANDLE>(process_handle), &res) ;
    return dncomlib::unknown_enumerator(res);
}