LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := main

SDL_PATH := ../SDL
SOURCE_PATH := ../../../src

LOCAL_C_INCLUDES := ${INCLUDE_DIR}/SDL/include ${INCLUDE_DIR}/SDL ${INCLUDE_DIR} ${SRC_DIR}

# Add your application source files here...
LOCAL_SRC_FILES := $(SDL_PATH)/src/main/android/SDL_android_main.c \
  $(SOURCE_PATH)/main.cc \
  $(SOURCE_PATH)/graphics.cc \
  $(SOURCE_PATH)/SDL_handle.cc \
  $(SOURCE_PATH)/event_handler.cc \
	${SOURCE_PATH}/graphics/camera.cc \
	${SOURCE_PATH}/graphics/perspective.cc \
	${SOURCE_PATH}/graphics/objects/triangle.cc 

LOCAL_SHARED_LIBRARIES := SDL2

LOCAL_LDLIBS := -lGLESv1_CM -lGLESv2 -llog

include $(BUILD_SHARED_LIBRARY)
