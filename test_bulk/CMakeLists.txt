cmake_minimum_required(VERSION 3.12)

project(bulk VERSION ${PROJECT_VESRION})
add_executable(test_bulk test.cpp)

target_link_libraries(test_bulk bulk_lib)

set_target_properties(test_bulk test_bulk PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(test_bulk
    PRIVATE "${CMAKE_BINARY_DIR}"
)

if (MSVC)
    target_compile_options(test_bulk PRIVATE
        /W4
    )
    target_compile_options(test_bulk PRIVATE
        /W4
    )
else ()
    target_compile_options(test_bulk PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(test_bulk PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

install(TARGETS test_bulk RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT hippiman1221@gmail.com)
include(CPack)