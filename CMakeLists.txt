cmake_minimum_required(VERSION 3.12)
project(main_project)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")

add_subdirectory(bulk)

#add_subdirectory(test)