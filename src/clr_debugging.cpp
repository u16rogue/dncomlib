#include <dncomlib/clr_debugging.hpp>

dncomlib::clr_debugging::clr_debugging(mslib::ICLRDebugging * i)
	: dncomlib::unique_releasable<mslib::ICLRDebugging>(i)
{
}