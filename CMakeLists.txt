cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

project(KappaDBMS)

# set up versioning.
set(BUILD_MAJOR "0")
set(BUILD_MINOR "0")
set(BUILD_VERSION "1")
set(BUILD_VERSION ${BUILD_MAJOR}.${BUILD_MINOR}.${BUILD_VERSION})

set(EXECUTABLE kappa)

set(CMAKE_CURRENT_SOURCE_DIR ${CMAKE_BINARY_DIR}/../src/backend)
set(src ${CMAKE_CURRENT_SOURCE_DIR})
set(lib ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(dir ${CMAKE_BINARY_DIR}/bin)

set(EXECUTABLE_OUTPUT_PATH ${dir} CACHE PATH "Build directory" FORCE)
set(LIBRARY_OUTPUT_PATH ${dir} CACHE PATH "Build directory" FORCE)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${dir})
set(CMAKE_BUILD_FILES_DIRECTORY ${dir})
set(CMAKE_BUILD_DIRECTORY ${dir})
set(CMAKE_BINARY_DIR ${dir})
set(EXECUTABLE_OUTPUT_PATH ${dir})
set(LIBRARY_OUTPUT_PATH ${dir}/lib)
set(CMAKE_CACHEFILE_DIR ${dir})

# set(CMAKE_C_COMPILER gcc)
# set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -flto -s") # -Wall -Wextra -Werror

# set(CMAKE_PREFIX_PATH src/backend/include)
add_subdirectory(${lib}/clsocket)

set(LINK_LIBS clsocket)
# if (WIN32)
# 	# set(LINK_LIBS "${LINK_LIBS} ws2_32")
# endif()


option(BUILD_PARSER "Build PARSER" ON)
option(BUILD_SERVER "Build SERVER" ON)

if (BUILD_PARSER)
	file(GLOB_RECURSE SRC_PARSER . src/backend/parser/*.cpp)
endif()

if (BUILD_SERVER)
	file(GLOB_RECURSE SRC_SERVER . src/backend/server/*.cpp)
endif()

add_executable(${EXECUTABLE} ${src}/main.cpp ${SRC_PARSER} ${SRC_SERVER})
target_link_libraries(${EXECUTABLE} ${LINK_LIBS})
target_include_directories(${EXECUTABLE} PUBLIC
	${src}/include
	${lib}/clsocket/src
	${lib}/ctpl
)
# target_link_libraries(${EXECUTABLE} ws2_32 wsock32)
