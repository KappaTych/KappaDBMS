cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

project(KappaDBMS VERSION 0.0.1)

set(EXECUTABLE kappa)

set(CMAKE_CURRENT_SOURCE_DIR ${CMAKE_BINARY_DIR}/../src/backend)
set(src ${CMAKE_CURRENT_SOURCE_DIR})
set(dir ${CMAKE_BINARY_DIR}/bin)

set(EXECUTABLE_OUTPUT_PATH ${dir} CACHE PATH "Build directory" FORCE)
set(LIBRARY_OUTPUT_PATH ${dir} CACHE PATH "Build directory" FORCE)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${dir})
set(CMAKE_BUILD_FILES_DIRECTORY ${dir})
set(CMAKE_BUILD_DIRECTORY ${dir})
set(CMAKE_BINARY_DIR ${dir})
set(EXECUTABLE_OUTPUT_PATH ${dir})
set(LIBRARY_OUTPUT_PATH ${dir}lib)
set(CMAKE_CACHEFILE_DIR ${dir})

set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -flto -mthreads -std=c++14 -I C:/git/KappaDBMS/src/backend/lib/asio/asio/include") # -Wall -Wextra -Werror


# set(CMAKE_PREFIX_PATH src/backend/lib/asio/asio/include)
# add_subdirectory(src/backend/lib/asio/asio/include)

# set(LINK_LIBS asio)
# if (WIN32)
# 	# set(LINK_LIBS "${LINK_LIBS} ws2_32")
# endif()


file(GLOB_RECURSE SRC_PARSER . src/backend/parser/*.cpp)
file(GLOB_RECURSE SRC_SERVER . src/backend/server/*.cpp)
# set(SRC_SERVER "${SRC_SERVER} ...")
# include_directories(${dir}/lib/asio/asio/include)

add_executable(${EXECUTABLE} ${src}/main.cpp ${SRC_PARSER} ${SRC_SERVER})
# target_include_directories(${EXECUTABLE} PUBLIC ${dir}/include
#     ${dir}/lib/asio/asio/include
# )
target_link_libraries(${EXECUTABLE} ws2_32 wsock32)
