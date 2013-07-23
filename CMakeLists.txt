cmake_minimum_required(VERSION 2.8.1) 
project(gtest_memory_leak_detector) 
enable_testing()

add_definitions(-DUNICODE -D_UNICODE)
include_directories(../../3p/googletest_r655/include/)
link_directories(../../3p/googletest_r655/bin/$(Configuration)/)

add_definitions(/W4)
add_definitions(/WX)
add_definitions(-D_VARIADIC_MAX=10)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} /MT")
set(CMAKE_CXX_FLAGS_MINSIZEREL "${CMAKE_CXX_FLAGS_MINSIZEREL} /MT")

add_library(gtest_mld_main gtest_mld_main.cpp) 

add_executable(gtest_mld_test test/fixture.cpp) 
target_link_libraries(gtest_mld_test gtest.lib gtest_mld_main)
add_test(gtest_mld_test gtest_mld_test)
