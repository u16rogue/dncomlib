#pragma once

#include <dncomlib/unique_releasable.hpp>
#include <dncomlib/mslib/IUnknown.hpp>
#include <dncomlib/mslib/ICLRDebugging.hpp>

namespace dncomlib
{
	class clr_debugging : public dncomlib::unique_releasable<mslib::ICLRDebugging>
	{
	public:
		clr_debugging() = default;
		clr_debugging(mslib::ICLRDebugging * i);
	};
}