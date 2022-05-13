cmake_minimum_required(VERSION 3.22)
project(OpenCLAttempt)

set(CMAKE_CXX_STANDARD 14)

add_executable(OpenCLAttempt main.cpp SequencialEQ.cpp SequencialEQ.h)

# You can alter these according to your needs, e.g if you don't need to display images - set(YOU_NEED_X11 0)
set(YOU_NEED_X11 1)
set(YOU_NEED_PNG 1)
set(YOU_NEED_JPG 1)

if(${YOU_NEED_X11} EQUAL 1)
    message(STATUS "Looking for X11...")
    find_package(X11 REQUIRED)
    include_directories(${X11_INCLUDE_DIR})
    target_link_libraries(OpenCLAttempt ${X11_LIBRARIES})
else()
    target_compile_definitions(OpenCLAttempt PRIVATE cimg_display=0)
endif()

