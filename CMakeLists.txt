cmake_minimum_required(VERSION 2.8.1) 
project(gtest_mem) 
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

add_library(gtest_mem_main gtest_mem_main.cpp) 

add_executable(gtest_mem_test test/fixture.cpp) 
target_link_libraries(gtest_mem_test gtest.lib gtest_mem_main)
add_test(gtest_mem_test gtest_mem_test)
