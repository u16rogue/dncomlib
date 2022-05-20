#pragma once

#include <dncomlib/mslib/IEnumUnknown.hpp>
#include <dncomlib/unique_releasable.hpp>

namespace dncomlib
{
    class unknown_enumerator
    {
        class enumerable
        {
        public:
            enumerable(mslib::IEnumUnknown * i_);

            auto operator * () -> dncomlib::unique_releasable<mslib::IUnknown>;
            auto operator ++ () -> void;
            auto operator != (const enumerable & rhs) -> bool;
        private:
            mslib::IUnknown * current;
            mslib::IEnumUnknown * instance;
        };

    public:
        unknown_enumerator(unknown_enumerator &) = delete;
        unknown_enumerator(const unknown_enumerator &) = delete;

        unknown_enumerator() = default;
        unknown_enumerator(mslib::IEnumUnknown * i_);

        operator bool () const noexcept;
        auto operator -> () -> mslib::IEnumUnknown *;
        auto operator = (unknown_enumerator && rhs) -> void;

        auto begin() -> unknown_enumerator::enumerable;
        auto end() -> unknown_enumerator::enumerable;

    private:
        dncomlib::unique_releasable<mslib::IEnumUnknown> instance;
    };
}