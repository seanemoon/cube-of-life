# CMAKE_BINARY_DIR is where you call make from
# CMAKE_SOURCE_DIR is where your CMakeLists.txt is

cmake_minimum_required(VERSION 2.8)
set(TARGET_PLATFORM $ENV{TARGET_PLATFORM})
set(EXECUTABLE $ENV{EXECUTABLE})

if (${TARGET_PLATFORM} STREQUAL "")
  message(FATAL_ERROR "ERROR: Please specify a target platform.")
endif()
if (${EXECUTABLE} STREQUAL "")
  message(FATAL_ERROR "ERROR: Please specify an executable name.")
endif()

if (${TARGET_PLATFORM} STREQUAL "android")

  # TOOLCHAIN_PREFIX is an ugly string thats part directory and part prefix
  # For some reason, the arm-linux-androideabi folder doesn't get g++ and gcc
  # generated within them.
  set(TOOLCHAIN_PREFIX ${CMAKE_TOOLCHAIN_DIR}/bin/${CMAKE_TOOLCHAIN_NAME})
  set(CMAKE_CXX_COMPILER ${TOOLCHAIN_PREFIX}-g++)
  set(CMAKE_C_COMPILER ${TOOLCHAIN_PREFIX}-gcc)

elseif (${TARGET_PLATFORM} STREQUAL "linux")
else ()
  message(FATAL_ERROR "ERROR: The specified target platform is not supported.")
endif ()

project(SDLTEST)

link_directories(${CMAKE_SOURCE_DIR}/lib)
include_directories(
  ${CMAKE_SOURCE_DIR}/include
  ${CMAKE_SOURCE_DIR}/src
)

set (CMAKE_CXX_FLAGS -std=c++11)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out)

set (sources
  src/main.cc
  src/SDL_handle.cc
  src/graphics.cc
  src/event_handler.cc
  src/graphics/graphics_util.cc
  src/graphics/camera.cc
  src/graphics/perspective.cc
  src/graphics/graphics_handler.cc
  src/graphics/objects/triangle.cc
)


add_executable(${EXECUTABLE} ${sources})
target_link_libraries(tester SDL2 dl GL pthread)
