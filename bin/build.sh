source bin/exports.sh # set some environment variables
source bin/arguments.sh # parse the arguments into env variables

if [[ $TARGET_PLATFORM = android ]]; then
  #export NDK_MODULE_PATH=$DEPS_DIR
  #export NDK_PROJECT_PATH=$ANDROID_DIR
  #export INCLUDE_DIRECTORY=$INCLUDE_DIR
  pushd $ANDROID_DIR
    NDK_BUILD_OPTIONS=""
    if [[ $MULTITHREAD ]]; then
      NDK_BUILD_OPTIONS="-j $NDK_BUILD_OPTIONS"
    fi
    if [[ $VERBOSE ]]; then
      NDK_BUILD_OPTIONS="-d $NDK_BUILD_OPTIONS"
    fi

    ndk-build $NDK_BUILD_OPTIONS && \
    ant debug

    # Copy the final product into our main output folder
    mkdir -p $OUT_DIR/$TARGET_PLATFORM/
    # CubeSpinner is set by android-project/build.xml
    cp bin/CubeSpinner-debug.apk $OUT_DIR/$TARGET_PLATFORM/
  popd
elif [[ $TARGET_PLATFORM = linux ]]; then
  if [[ $VERBOSE ]]; then
    CMAKE_OPTIONS="-DCMAKE_VERBOSE_MAKEFILE=ON"
  fi
  if [[ $MULTITHREAD ]]; then
    MAKE_OPTIONS="-j"
  fi

  mkdir -p $BUILD_DIR/$TARGET_PLATFORM/SDL
  pushd $BUILD_DIR/$TARGET_PLATFORM/SDL
    cmake $CMAKE_OPTIONS $DEPS_DIR/SDL && \
    make $MAKE_OPTIONS

    # Copy the SDL lib into our lib directory
    cp libSDL2.a $LIB_DIR/
  popd
  mkdir -p $BUILD_DIR/$TARGET_PLATFORM/main
  pushd $BUILD_DIR/$TARGET_PLATFORM/main
    cmake $CMAKE_OPTIONS $MAIN_DIR && \
    make $MAKE_OPTIONS

    # Copy the final product into our main output folder
    mkdir -p $OUT_DIR/$TARGET_PLATFORM/
    cp out/$EXECUTABLE $OUT_DIR/$TARGET_PLATFORM/
  popd
fi
