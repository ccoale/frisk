#we require c++11 to build.
if(UNIX)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif(UNIX)

add_executable(demo Main.cpp)
target_link_libraries (demo LINK_PUBLIC frisk)