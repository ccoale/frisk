#we require c++11 to build.
if(UNIX)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif(UNIX)

add_executable(test test_main.cpp)
target_link_libraries (test LINK_PUBLIC frisk)
include_directories(../inc)
