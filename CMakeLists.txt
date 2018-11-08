cmake_minimum_required(VERSION 2.8.0 FATAL_ERROR)

project(KappaDBMS)

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
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -flto -s -std=c++11") # -Wall -Wextra -Werror

# OS and compiler checks.
if(UNIX)
	# linux / normal unix
	add_definitions(-D_LINUX)
	if(CYGWIN)
		# Special Cygwin stuff here
	elseif(APPLE)
		# Special Apple stuff here
		remove_definitions(-D_LINUX)
		add_definitions(-D_DARWIN)
	endif()
elseif(WIN32)
	add_definitions(-DWIN32)
	if(MINGW)
		# Special MINGW stuff here
	elseif(MSVC)
		# Special MSVC stuff here
		add_definitions(-D_WINSOCK_DEPRECATED_NO_WARNINGS)
	else()
		# No idea what it is, but there's a good chance it's too weird.
		MESSAGE( FATAL_ERROR "Using unknown WIN32 compiler... NOT. Please add to build system." )
	endif()
endif()

# set(CMAKE_PREFIX_PATH src/backend/include)
set(CLSOCKET_DEP_ONLY ON)
add_subdirectory(${lib}/clsocket)

option(BUILD_PARSER "Build PARSER" ON)
option(BUILD_SERVER "Build SERVER" ON)
option(PARSER_SHARED "Make parser as shared library" OFF)

if (BUILD_PARSER)
	file(GLOB_RECURSE SRC_PARSER . src/backend/parser/*.cpp)
endif()

if (BUILD_SERVER)
	file(GLOB_RECURSE SRC_SERVER . src/backend/server/*.cpp)
endif()

if(PARSER_SHARED)
    add_library(parser SHARED EXCLUDE_FROM_ALL ${SRC_PARSER})
else()
    add_library(parser STATIC EXCLUDE_FROM_ALL ${SRC_PARSER})
endif()

set(LINK_LIBS clsocket pthread parser)
# if (WIN32)
# 	# set(LINK_LIBS "${LINK_LIBS} ws2_32")
# endif()

add_executable(${EXECUTABLE} ${src}/main.cpp ${SRC_SERVER})
target_link_libraries(${EXECUTABLE} ${LINK_LIBS})
target_include_directories(${EXECUTABLE} PUBLIC
	${src}/include
	${lib}/clsocket/src
	${lib}/ctpl
)
