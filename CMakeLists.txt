cmake_minimum_required(VERSION 3.12)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(bulk VERSION ${PROJECT_VESRION})
add_library(bulk_lib bulk.cpp ComandHandler.hxx ComandHandler.cxx Logger.hxx Logger.cxx OutputHandler.hxx OutputHandler.cxx)
add_executable(bulk bulk.cpp ComandHandler.hxx ComandHandler.cxx Logger.hxx Logger.cxx OutputHandler.hxx OutputHandler.cxx)

set_target_properties(bulk bulk PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(bulk
    PRIVATE "${CMAKE_BINARY_DIR}"
)

if (MSVC)
    target_compile_options(bulk PRIVATE
        /W4
    )
    target_compile_options(bulk PRIVATE
        /W4
    )
else ()
    target_compile_options(bulk PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(bulk PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

install(TARGETS bulk RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT hippiman1221@gmail.com)
include(CPack)

project(test)
add_executable(test test.cpp) 
target_include_directories(test PUBLIC ${Boost_INCLUDE_DIRS}) 
install(TARGETS test RUNTIME DESTINATION bin)
target_link_libraries(test bulk_lib)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
include(CPack)