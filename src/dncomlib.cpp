#include <dncomlib/dncomlib.hpp>

#include <Windows.h>

auto dcl::clr_create_instance(const IID & clsid, const IID & riid) -> dcl::unique_clr_releasable<ICLRMetaHost>
{
    dcl::unique_clr_releasable<ICLRMetaHost> meta_host;

    HMODULE hmscoree = LoadLibraryW(L"MSCorEE.dll");
    if (!hmscoree)
    {
        decltype(CLRCreateInstance) * _CLRCreateInstance;
        _CLRCreateInstance = reinterpret_cast<decltype(_CLRCreateInstance)>(GetProcAddress(hmscoree, "CLRCreateInstance"));
        if (_CLRCreateInstance)
            _CLRCreateInstance(clsid, riid, reinterpret_cast<LPVOID *>(meta_host.ppinstance()));
    }

    return meta_host;
}