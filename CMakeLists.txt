cmake_minimum_required(VERSION 3.25)
project(Giftwrap)

find_package(SDL2 REQUIRED)

set(CMAKE_CXX_STANDARD 23)

add_executable(
        ${PROJECT_NAME}
        src/main.cpp

        src/Application.cpp
        src/Complex.cpp
        src/Hull.cpp
        src/Set.cpp
)

target_link_libraries(${PROJECT_NAME} PUBLIC ${SDL2_LIBRARIES})

# Sets executable folder to bin
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)