cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 17)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(bulk_project VERSION ${PROJECT_VESRION})

add_subdirectory(bulk)

add_subdirectory(test_bulk)
