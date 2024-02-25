cmake_minimum_required(VERSION 3.12)
project(main_project)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")

add_subdirectory(bulk)

#add_subdirectory(test)

install(TARGETS bulk RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT hippiman1221@gmail.com)
include(CPack)