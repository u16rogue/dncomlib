#pragma once

#include <dncomlib/unique_releasable.hpp>
#include <dncomlib/mslib/IUnknown.hpp>
#include <string>

namespace dncomlib
{
    class app_domain : public dncomlib::unique_releasable<mslib::IUnknown>
    {
    public:
        app_domain(app_domain &) = delete;
        app_domain(const app_domain &) = delete;

        app_domain() = default;
        app_domain(mslib::IUnknown * i_);

        auto get_friendly_name() -> std::wstring;

        static auto from_unknown(const dncomlib::unique_releasable<mslib::IUnknown> & unk) -> app_domain;
    };
}