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

