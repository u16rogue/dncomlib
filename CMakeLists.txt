cmake_minimum_required(VERSION 3.18)

project(dncomlib)

add_library(
	${PROJECT_NAME}
	
	"include/dncomlib/unique_releasable.hpp"

	"include/dncomlib/meta_host.hpp"
	"src/meta_host.cpp"

	"include/dncomlib/unknown_enumerator.hpp"
	"src/unknown_enumerator.cpp"
	
	"include/dncomlib/dncomlib.hpp"
	"src/dncomlib.cpp"
	
	"include/dncomlib/runtime_info.hpp"
	"src/runtime_info.cpp"

	"include/dncomlib/runtime_host.hpp"
	"src/runtime_host.cpp"

	"include/dncomlib/app_domain.hpp"
	"src/app_domain.cpp"
)

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")