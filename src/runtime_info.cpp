#include <dncomlib/runtime_info.hpp>

dncomlib::runtime_info::runtime_info(ICLRRuntimeInfo *i_)
    : dncomlib::unique_releasable<ICLRRuntimeInfo>(i_)
{
}