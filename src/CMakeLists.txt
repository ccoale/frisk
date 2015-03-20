#we require c++11 to build.
if(UNIX)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif(UNIX)

set(FRISK_SRC
ConsoleReporter.cpp
TestCollection.cpp
Test.cpp  
)
add_library(frisk ${FRISK_SRC})
