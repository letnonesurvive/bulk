cmake_minimum_required(VERSION 3.12)

add_library(bulk_lib bulk.cpp ComandHandler.hxx ComandHandler.cxx Observer.hxx FileLogger.hxx FileLogger.cxx ConsoleLogger.hxx ConsoleLogger.cxx )
add_executable(bulk bulk.cpp ComandHandler.hxx ComandHandler.cxx Observer.hxx FileLogger.hxx FileLogger.cxx ConsoleLogger.hxx ConsoleLogger.cxx )

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
