cmake_minimum_required(VERSION 3.18)

project(dncomlib)

add_library(${PROJECT_NAME} STATIC
	"includes/dncomlib/meta_host.hpp"
	"src/meta_host.cpp"

	"includes/dncomlib/unknown_enumerator.hpp"
	"src/unknown_enumerator.cpp"

	"includes/dncomlib/unique_releasable.hpp"
	
	"includes/dncomlib/dncomlib.hpp"
	"src/dncomlib.cpp"
)

target_include_directories(${PROJECT_NAME} PUBLIC "includes/")