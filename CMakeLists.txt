cmake_minimum_required(VERSION 4.1.1)
project(cap1)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_executable(cap1 
    main.cpp
    bmi.cpp
    dirsearch.cpp
    editorshell.cpp
    tokenizer.cpp
)

include(CTest)
find_package(GTest REQUIRED)
add_executable(unit_tests 
    tests/BmiTest.cpp
    bmi.cpp
)

target_link_libraries(unit_tests
    GTest::gtest_main    
)
include(GoogleTest)
gtest_discover_tests(unit_tests)
