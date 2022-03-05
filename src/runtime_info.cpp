#include <dncomlib/runtime_info.hpp>

dncomlib::runtime_info::runtime_info(ICLRRuntimeInfo *i_)
    : dncomlib::unique_releasable<ICLRRuntimeInfo>(i_)
{
}

auto dncomlib::runtime_info::is_started(DWORD * out_startup_flags) -> bool
{
    BOOL  flag {};
    DWORD dummy_flags {};
    if (instance->IsStarted(&flag, out_startup_flags ?: /* hello msvc compiler users :) */ &dummy_flags) != S_OK)
    {
        return false;
    }

    return flag;
}

auto dncomlib::runtime_info::from_thunk(const dncomlib::unique_releasable<IUnknown> & thunk) -> runtime_info
{
    ICLRRuntimeInfo * res {};
    thunk->QueryInterface(IID_ICLRRuntimeInfo, reinterpret_cast<void **>(&res));
    return runtime_info(res);
}