#include <dncomlib/dncomlib.hpp>
#include <Windows.h>

static auto dn_generic_create_instance(const dncomlib::GUID & clsid, const dncomlib::GUID & riid) -> void *
{
	void * res = nullptr;

    HMODULE hmscoree = LoadLibraryW(L"MSCorEE.dll");
    if (hmscoree)
    { 
        long(__stdcall * _CLRCreateInstance)(const dncomlib::GUID &, const dncomlib::GUID &, void **) = reinterpret_cast<decltype(_CLRCreateInstance)>(GetProcAddress(hmscoree, "CLRCreateInstance"));
        if (_CLRCreateInstance)
            _CLRCreateInstance(clsid, riid, &res);
    }

    return res;
}

auto dncomlib::clr_create_instance(const GUID & clsid, const GUID & riid) -> dncomlib::unique_releasable<dncomlib::mslib::IUnknown>
{
    return dncomlib::unique_releasable<mslib::IUnknown>(reinterpret_cast<mslib::IUnknown *>(dn_generic_create_instance(clsid, riid)));
}

auto dncomlib::clr_create_meta_host_instance() -> dncomlib::meta_host
{
	constexpr dncomlib::GUID CLSID_CLRMetaHost = {
		.Data1 = 0x9280188d,
		.Data2 = 0x0E8E,
		.Data3 = 0x4867,
		.Data4 = { 0xB3, 0x0C, 0x7F, 0xA8, 0x38, 0x84, 0xE8, 0xDE }
	};

	constexpr dncomlib::GUID IID_ICLRMetaHost = {
		.Data1 = 0xD332DB9E,
		.Data2 = 0xB9B3,
		.Data3 = 0x4125,
		.Data4 = { 0x82, 0x07, 0xA1, 0x48, 0x84, 0xF5, 0x32, 0x16 }
	};

	return dncomlib::meta_host(reinterpret_cast<mslib::ICLRMetaHost *>(dn_generic_create_instance(CLSID_CLRMetaHost, IID_ICLRMetaHost)));
}

auto dncomlib::clr_create_debugging() -> clr_debugging
{
	constexpr dncomlib::GUID CLSID_CLRDebugging = {
		.Data1 = 0xbacc578d,
		.Data2 = 0xfbdd,
		.Data3 = 0x48a4,
		.Data4 = { 0x96, 0x9f, 0x2, 0xd9, 0x32, 0xb7, 0x46, 0x34 }
	};

	constexpr dncomlib::GUID IID_ICLRDebugging = {
		.Data1 = 0xd28f3c5a,
		.Data2 = 0x9634,
		.Data3 = 0x4206,
		.Data4 = { 0xa5, 0x9, 0x47, 0x75, 0x52, 0xee, 0xfb, 0x10 }
	};

	return dncomlib::clr_debugging(reinterpret_cast<mslib::ICLRDebugging *>(dn_generic_create_instance(CLSID_CLRDebugging, IID_ICLRDebugging)));
}