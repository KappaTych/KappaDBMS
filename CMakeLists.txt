cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

project(KappaDBMS VERSION 0.0.1)

set(EXECUTABLE kappa)

set(CMAKE_CURRENT_SOURCE_DIR ${CMAKE_BINARY_DIR}/src/backend)
set(dir ${CMAKE_BINARY_DIR}/bin)

set(EXECUTABLE_OUTPUT_PATH ${dir} CACHE PATH "Build directory" FORCE)
set(LIBRARY_OUTPUT_PATH ${dir} CACHE PATH "Build directory" FORCE)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${dir})
set(CMAKE_BUILD_FILES_DIRECTORY ${dir})
set(CMAKE_BUILD_DIRECTORY ${dir})
set(CMAKE_BINARY_DIR  ${dir})
set(EXECUTABLE_OUTPUT_PATH ${dir})
set(LIBRARY_OUTPUT_PATH ${dir}lib)
set(CMAKE_CACHEFILE_DIR ${dir})

set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -flto -mthreads -Wall -Wextra -Werror")

file(GLOB_RECURSE SOURCES . src/backend/*.cpp)

add_executable(${EXECUTABLE} ${SOURCES})
target_include_directories(${EXECUTABLE} PRIVATE ${dir}/include
    ${dir}/lib/asio/asio/include
)
# target_link_libraries(${EXECUTABLE} ${PTHREAD_LIBRARY})
