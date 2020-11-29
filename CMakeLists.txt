cmake_minimum_required(VERSION 3.15)
project(kudryWM VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_FLAGS_DEBUG_INIT "-Wall -DDEBUG -Wformat=2 -Wfloat-equal -fsanitize=address -fsanitize=undefined -fstack-protector")
set(CMAKE_CXX_FLAGS_RELEASE_INIT "-Wall")

#add_executable(app user-side/main.cpp)
add_executable(app user-side/raven-scrollbar.cpp)

add_subdirectory(kudry)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -O3")

target_link_libraries(
    app 
    PUBLIC kudry
)