cmake_minimum_required(VERSION 3.10)
project(Area51 VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include(GNUInstallDirs)

# ── Main application ────────────────────────────────────────────────────────
add_executable(area51 main.cpp src/Human.cpp)

install(TARGETS area51
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# ── Tests ───────────────────────────────────────────────────────────────────
option(BUILD_TESTING "Build and install test binaries" ON)

if(BUILD_TESTING)
    find_package(Boost REQUIRED COMPONENTS unit_test_framework)
    enable_testing()

    # Catch2 single-header test
    add_executable(area51_tests test.cpp src/Human.cpp)
    add_test(NAME CatchTests COMMAND area51_tests)

    # Boost.Test suites
    add_executable(test1 test1.cpp src/Human.cpp)
    target_link_libraries(test1 PRIVATE Boost::unit_test_framework)
    add_test(NAME BoostTest_Factorial COMMAND test1)

    add_executable(test2 test2.cpp src/Human.cpp)
    target_link_libraries(test2 PRIVATE Boost::unit_test_framework)
    add_test(NAME BoostTest_HumanFactorial COMMAND test2)

    add_executable(test3 test3.cpp src/Human.cpp)
    target_link_libraries(test3 PRIVATE Boost::unit_test_framework)
    add_test(NAME BoostTest_HumanName COMMAND test3)

    # Install test binaries into a Yocto ptest-compatible path
    set(PTEST_INSTALL_DIR ${CMAKE_INSTALL_LIBDIR}/${PROJECT_NAME}/ptest)

    install(TARGETS area51_tests test1 test2 test3
        RUNTIME DESTINATION ${PTEST_INSTALL_DIR}
    )

    install(FILES ${CMAKE_SOURCE_DIR}/run-ptest
        DESTINATION ${PTEST_INSTALL_DIR}
        PERMISSIONS
            OWNER_READ OWNER_WRITE OWNER_EXECUTE
            GROUP_READ GROUP_EXECUTE
            WORLD_READ WORLD_EXECUTE
    )
endif()
