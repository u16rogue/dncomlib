#include <dncomlib/runtime_info.hpp>

dncomlib::runtime_info::runtime_info(mslib::ICLRRuntimeInfo *i_)
    : dncomlib::unique_releasable<mslib::ICLRRuntimeInfo>(i_)
{
}

auto dncomlib::runtime_info::is_started(DWORD * out_startup_flags) -> bool
{
    BOOL  flag {};
    DWORD dummy_flags {};
    if (instance->IsStarted(&flag, out_startup_flags ?: /* hello msvc compiler users :) */ &dummy_flags) != S_OK)
        return false;

    return flag;
}

auto dncomlib::runtime_info::get_host() -> runtime_host
{
    constexpr GUID CLSID_CorRuntimeHost = {
		.Data1 = 0xcb2f6723,
        .Data2 = 0xab3a,
        .Data3 = 0x11d2,
        .Data4 = { 0x9c, 0x40, 0x00, 0xc0, 0x4f, 0xa3, 0x0a, 0x3e }
    };

    constexpr GUID IID_ICorRuntimeHost = {
        .Data1 = 0xcb2f6722,
        .Data2 = 0xab3a,
        .Data3 = 0x11d2,
        .Data4 = { 0x9c, 0x40, 0x00, 0xc0, 0x4f, 0xa3, 0x0a, 0x3e }
    };

    mslib::ICorRuntimeHost * res {};
    instance->GetInterface(CLSID_CorRuntimeHost, IID_ICorRuntimeHost, reinterpret_cast<LPVOID *>(&res));
    return runtime_host(res);
}

auto dncomlib::runtime_info::from_unknown(const dncomlib::unique_releasable<mslib::IUnknown> & unk) -> runtime_info
{
    constexpr GUID IID_ICLRRuntimeInfo = {
		.Data1 = 0xBD39D1D2,
        .Data2 = 0xBA2F, 
        .Data3 = 0x486a,
        .Data4 = { 0x89, 0xB0, 0xB4, 0xB0, 0xCB, 0x46, 0x68, 0x91 }
    };

    mslib::ICLRRuntimeInfo * res {};
    unk->QueryInterface(IID_ICLRRuntimeInfo, reinterpret_cast<void **>(&res));
    return runtime_info(res);
}

auto dncomlib::runtime_info::get_version_string() -> std::wstring
{
    wchar_t ver[256] {};
    unsigned long nv = 256;
    instance->GetVersionString(ver, &nv); 
    return std::wstring(ver);
}