#include <dncomlib/app_domain.hpp>

#include <oleauto.h>

dncomlib::app_domain::app_domain(IUnknown * i_)
    : dncomlib::unique_releasable<IUnknown>(i_)
{
}

auto dncomlib::app_domain::get_friendly_name() -> std::wstring
{
    HRESULT(__fastcall * _gfn)(void *, void *, BSTR *) = nullptr;
    _gfn = reinterpret_cast<decltype(_gfn)>(reinterpret_cast<void ***>(instance)[0][53]);
    BSTR name {};
    _gfn(instance, nullptr, &name);
    auto out = std::wstring(name);
    if (name)
        SysFreeString(name);
    return out;
}

auto dncomlib::app_domain::from_unknown(const dncomlib::unique_releasable<IUnknown> & unk) -> app_domain
{
    GUID _appdomain_uuid {
        .Data1 = 0x5F696DC,
        .Data2 = 0x2B29,
        .Data3 = 0x3663,
        .Data4 = { 0xAD, 0x8B, 0xC4, 0x38, 0x9C, 0xF2, 0xA7, 0x13 }
    };

    IUnknown * res {};
    unk->QueryInterface(_appdomain_uuid, reinterpret_cast<void **>(&res));
    return app_domain(res);
}