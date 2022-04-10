cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Theatre VERSION 1.0.0)

set(SRC_FILES src/actor.cpp src/employee.cpp src/hall.cpp src/musical.cpp src/musician.cpp src/performance.cpp src/performer.cpp src/play.cpp src/singer.cpp src/sysManager.cpp)
add_executable(${PROJECT_NAME} src/main.cpp ${SRC_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC include)