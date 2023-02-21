cmake_minimum_required(VERSION 3.25)
project(defaultProject VERSION 0.0.1 LANGUAGES CXX DESCRIPTION "Default setup for cmake c++ project")



add_subdirectory(src)

#if(${CMAKE_BUILD_TYPE} STREQUAL "bench")
#   add_subdirectory(bench)
#elseif(${CMAKE_BUILD_TYPE} STREQUAL "test")
#    add_subdirectory(test)
#endif()
