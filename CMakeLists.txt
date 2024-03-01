# установка версии CMake
cmake_minimum_required(VERSION 3.16)

# название проекта (обязательно)
project(oopprog2applicat)

# установка стандарта языка - C++20
set(CMAKE_CXX_STANDARD 20)

# установка флагов компилятора: CMAKE_CXX_FLAGS += -Wall -Wextra
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_subdirectory(Source)

add_executable(main main.cpp)

target_link_libraries(main source)
