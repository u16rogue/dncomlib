#include <dncomlib/dncomlib.hpp>

#include <Windows.h>

auto dncomlib::clr_create_instance(const GUID & clsid, const GUID & riid) -> dncomlib::meta_host
{
    ICLRMetaHost * res {};

    HMODULE hmscoree = LoadLibraryW(L"MSCorEE.dll");
    if (hmscoree)
    { 
        long(__stdcall*_CLRCreateInstance)(const GUID &, const GUID &, void **) = reinterpret_cast<decltype(_CLRCreateInstance)>(GetProcAddress(hmscoree, "CLRCreateInstance"));
        if (_CLRCreateInstance)
            _CLRCreateInstance(clsid, riid, reinterpret_cast<LPVOID *>(&res));
    }

    return dncomlib::meta_host(res);
}