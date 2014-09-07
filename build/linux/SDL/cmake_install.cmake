# Install script for directory: /home/sean/development/projects/cube_spinner/deps/SDL

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/usr/local")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "1")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/sean/development/projects/cube_spinner/build/linux/SDL/libSDL2.a")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/sean/development/projects/cube_spinner/build/linux/SDL/libSDL2-2.0.so.0.2.1"
    "/home/sean/development/projects/cube_spinner/build/linux/SDL/libSDL2-2.0.so.1"
    "/home/sean/development/projects/cube_spinner/build/linux/SDL/libSDL2-2.0.so"
    )
  FOREACH(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDL2-2.0.so.0.2.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDL2-2.0.so.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDL2-2.0.so"
      )
    IF(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      IF(CMAKE_INSTALL_DO_STRIP)
        EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "${file}")
      ENDIF(CMAKE_INSTALL_DO_STRIP)
    ENDIF()
  ENDFOREACH()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/sean/development/projects/cube_spinner/build/linux/SDL/libSDL2main.a")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/SDL2" TYPE FILE FILES
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_version.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_rect.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_test_crc32.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_filesystem.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_test_compare.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_video.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_error.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_syswm.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_quit.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_bits.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_test_random.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_config_wiz.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_config_iphoneos.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_test_log.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_opengl.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_test_common.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_joystick.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_assert.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_test_font.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_config_windows.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_egl.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_messagebox.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_config_pandora.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_keycode.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_test_md5.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_system.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_render.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_config_android.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_config_macosx.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_thread.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_copying.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_events.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_gesture.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_atomic.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_audio.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_config_minimal.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_shape.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_opengles.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_revision.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_main.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_touch.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_name.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_rwops.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/close_code.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_config_psp.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_cpuinfo.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_keyboard.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_endian.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_clipboard.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_mouse.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_surface.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_opengles2.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_power.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_pixels.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_stdinc.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_test_harness.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_gamecontroller.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_test_images.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_log.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_test_assert.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_hints.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_test.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_loadso.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_config_winrt.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_blendmode.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_test_fuzzer.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_platform.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_mutex.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_timer.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_types.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_scancode.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/begin_code.h"
    "/home/sean/development/projects/cube_spinner/deps/SDL/include/SDL_haptic.h"
    "/home/sean/development/projects/cube_spinner/build/linux/SDL/include/SDL_config.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  
      execute_process(COMMAND /usr/bin/cmake -E create_symlink
      "libSDL2-2.0.so" "libSDL2.so")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "/home/sean/development/projects/cube_spinner/build/linux/SDL/libSDL2.so")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/sean/development/projects/cube_spinner/build/linux/SDL/sdl2.pc")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE PROGRAM FILES "/home/sean/development/projects/cube_spinner/build/linux/SDL/sdl2-config")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/aclocal" TYPE FILE FILES "/home/sean/development/projects/cube_spinner/deps/SDL/sdl2.m4")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
ELSE(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
ENDIF(CMAKE_INSTALL_COMPONENT)

FILE(WRITE "/home/sean/development/projects/cube_spinner/build/linux/SDL/${CMAKE_INSTALL_MANIFEST}" "")
FOREACH(file ${CMAKE_INSTALL_MANIFEST_FILES})
  FILE(APPEND "/home/sean/development/projects/cube_spinner/build/linux/SDL/${CMAKE_INSTALL_MANIFEST}" "${file}\n")
ENDFOREACH(file)
