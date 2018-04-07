cmake_minimum_required (VERSION 3.8)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Wextra -Weverything \
                     -Wno-padded -Wno-c++98-compat")

project (DesignPatterns)
add_executable(DesignPatterns Visitor.cpp Expression.cpp Composite.cpp main.cpp)