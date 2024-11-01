cmake_minimum_required(VERSION 3.10)

set(PATCH_VERSION "2" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.1.${PATCH_VERSION})

project(bulk_prg VERSION ${PROJECT_VESRION})

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

#configure_file(version.h.in version.h)

add_executable(bulk main.cpp)
add_executable(test_bulk test_bulk.cpp)

set_target_properties(bulk test_bulk PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)
#target_include_directories(bulk_prg
#    PRIVATE "${CMAKE_BINARY_DIR}"
#)
set_target_properties(test_bulk PROPERTIES
    COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

#target_link_libraries(bulk PRIVATE
#    bulk_prg
#)
target_link_libraries(test_bulk
    ${Boost_LIBRARIES}
    #bulk_prg
)

if (MSVC)
    target_compile_options(bulk PRIVATE
        /W4
    )
    target_compile_options(bulk_prg PRIVATE
        /W4
    )
    target_compile_options(test_bulk PRIVATE
        /W4
    )
else ()
    target_compile_options(bulk PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
#    target_compile_options(bulk_prg PRIVATE
#        -Wall -Wextra -pedantic -Werror
#    )
    target_compile_options(test_bulk PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()



install(TARGETS bulk RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)

enable_testing()

add_test(test_bulk test_bulk)
