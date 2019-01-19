cmake_minimum_required(VERSION 2.8.0 FATAL_ERROR)
project(KappaDBMS)

set(BUILD_MAJOR "0")
set(BUILD_MINOR "0")
set(BUILD_VERSION "1")
set(BUILD_VERSION ${BUILD_MAJOR}.${BUILD_MINOR}.${BUILD_VERSION})

set(EXECUTABLE kappa)

set(CMAKE_CURRENT_SOURCE_DIR ${CMAKE_BINARY_DIR}/../src)
set(src ${CMAKE_CURRENT_SOURCE_DIR})
set(lib ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(dir ${CMAKE_BINARY_DIR}/bin)

set(EXECUTABLE_OUTPUT_PATH ${dir} CACHE PATH "Build directory" FORCE)
set(LIBRARY_OUTPUT_PATH ${dir} CACHE PATH "Build directory" FORCE)
set(LIBRARY_OUTPUT_DIRECTORY ${dir})

set(CMAKE_LIBRARY_OUTPUT_PATH ${dir})
set(CMAKE_ARCHIVE_OUTPUT_PATH ${dir})
set(CMAKE_RUNTIME_OUTPUT_PATH ${dir})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${dir})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${dir})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${dir})
set(CMAKE_BUILD_FILES_DIRECTORY ${dir})
set(CMAKE_BUILD_DIRECTORY ${dir})
set(CMAKE_CACHEFILE_DIR ${dir})
set(CMAKE_BINARY_DIR ${dir})
set(CMAKE_CURRENT_BINARY_DIR ${dir})

set(PROJECT_BINARY_DIR ${dir})

# set(CMAKE_C_COMPILER gcc)
# set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -ggdb3 -std=c++14") # -Wall -Wextra -Werror
set(OPTION_BUILD_TESTS OFF)

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


option(BUILD_PARSER "Build PARSER" ON)
option(BUILD_STORAGE "Build STORAGE" ON)
option(BUILD_DRIVER "Build DRIVER" ON)
option(BUILD_SERVER "Build SERVER" ON)
option(BUILD_TESTS "Build TESTS" OFF)

# set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH}:${dir})
# set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH}:${lib}/clsocket)
# set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH}:${lib}/cppfs)

include_directories(
    ${lib}/ctpl
    ${lib}/clsocket/src
    ${lib}/cppfs/source/cppfs/include
)

set(CLSOCKET_DEP_ONLY ON)
add_subdirectory(${lib}/cppfs)
add_subdirectory(${lib}/clsocket)

set(LINK_LIBS clsocket cppfs pthread)

if (BUILD_PARSER)
    add_subdirectory(${src}/parser)
    list(APPEND LINK_LIBS parser)
endif()

if (BUILD_STORAGE)
    add_subdirectory(${src}/storage)
    list(APPEND LINK_LIBS storage)
endif()

if (BUILD_DRIVER)
    add_subdirectory(${src}/driver)
    list(APPEND LINK_LIBS driver)
endif()

if (BUILD_SERVER)
    file(GLOB_RECURSE SRC_SERVER . ${src}/server/*.cpp)

    add_executable(${EXECUTABLE} ${src}/main.cpp ${SRC_SERVER})
    set_target_properties(${EXECUTABLE} PROPERTIES VERSION ${BUILD_VERSION} SOVERSION ${BUILD_MAJOR})
    target_link_libraries(${EXECUTABLE} ${LINK_LIBS})
    target_include_directories(${EXECUTABLE} PUBLIC
        ${src}/
        ${src}/include
    )
endif()

