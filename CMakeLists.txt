cmake_minimum_required(VERSION 3.18)

project(dncomlib)

add_library(${PROJECT_NAME} STATIC
	"includes/dncomlib/unique_clr_releasable.hpp"
	"includes/dncomlib/dncomlib.hpp"
	"src/dncomlib.cpp"
)

target_include_directories(${PROJECT_NAME} PUBLIC "includes/")