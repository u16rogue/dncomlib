#include <dncomlib/dncomlib.hpp>

#include <Windows.h>

auto dcl::clr_create_instance(const IID & clsid, const IID & riid) -> dcl::meta_host
{
    ICLRMetaHost * res {};

    HMODULE hmscoree = LoadLibraryW(L"MSCorEE.dll");
    if (hmscoree)
    {
        decltype(CLRCreateInstance) * _CLRCreateInstance;
        _CLRCreateInstance = reinterpret_cast<decltype(_CLRCreateInstance)>(GetProcAddress(hmscoree, "CLRCreateInstance"));
        if (_CLRCreateInstance)
            _CLRCreateInstance(clsid, riid, reinterpret_cast<LPVOID *>(&res));
    }

    return dcl::meta_host(res);
}