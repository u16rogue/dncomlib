cmake_minimum_required(VERSION 3.18)

project(
	dncomlib
	VERSION 1.0
	LANGUAGES CXX
	DESCRIPTION "dotNet COM Library for C++"	
)

add_library(
	${PROJECT_NAME}

	STATIC	

	"${CMAKE_CURRENT_SOURCE_DIR}/include/dncomlib/unique_releasable.hpp"

	"${CMAKE_CURRENT_SOURCE_DIR}/include/dncomlib/meta_host.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/src/meta_host.cpp"

	"${CMAKE_CURRENT_SOURCE_DIR}/include/dncomlib/unknown_enumerator.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/src/unknown_enumerator.cpp"
	
	"${CMAKE_CURRENT_SOURCE_DIR}/include/dncomlib/dncomlib.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/src/dncomlib.cpp"
	
	"${CMAKE_CURRENT_SOURCE_DIR}/include/dncomlib/runtime_info.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/src/runtime_info.cpp"

	"${CMAKE_CURRENT_SOURCE_DIR}/include/dncomlib/runtime_host.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/src/runtime_host.cpp"

	"${CMAKE_CURRENT_SOURCE_DIR}/include/dncomlib/app_domain.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/src/app_domain.cpp"

	"${CMAKE_CURRENT_SOURCE_DIR}/include/dncomlib/clr_debugging.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/src/clr_debugging.cpp"

	"${CMAKE_CURRENT_SOURCE_DIR}/include/dncomlib/mslib/IUnknown.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/include/dncomlib/mslib/ICorRuntimeHost.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/include/dncomlib/mslib/ICLRuntimeInfo.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/include/dncomlib/mslib/IEnumUnknown.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/include/dncomlib/mslib/ICLRMetaHost.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/include/dncomlib/mslib/ICLRDebugging.hpp"
)

set_target_properties(
	${PROJECT_NAME}
	PROPERTIES
	CXX_STANDARD 20
	CXX_STANDARD_REQUIRED True
)

target_include_directories(
	${PROJECT_NAME}
	PUBLIC
	"${CMAKE_CURRENT_SOURCE_DIR}/include/"
)