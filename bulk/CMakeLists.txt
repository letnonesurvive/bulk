cmake_minimum_required(VERSION 3.12)


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
