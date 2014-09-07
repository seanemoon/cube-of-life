usage()
{
cat << EOF

  usage bin/arguments.sh options

  This script parses the arguments for the build.

  OPTIONS:
   -h   Show this message.
   -v   Do a verbose build.
   -f   Do a fast build (only one platform).
   -j   Do a multithreaded build.
   -p   Set the platform to build for (android, linux).

EOF
}

while getopts "hvfjp:" OPTION
do
  case $OPTION in
    h)
      usage
      exit 1
      ;;
    v)
      export VERBOSE=1
      ;;
    f)
      export FAST_BUILD=1
      ;;
    j)
      export MULTITHREAD=1
      ;;
    p)
      for platform in $SUPPORTED_PLATFORMS
      do
        if [[ $OPTARG = $platform ]]; then
          export TARGET_PLATFORM=$platform
          break
        fi
      done
      if [[ -z $TARGET_PLATFORM ]]; then
        echo "ERROR: invalid target platform specified."
        exit 1
      fi
      ;;
  esac
done

if [[ -z $TARGET_PLATFORM ]]; then
  echo "ERROR: no target platform specified."
  usage
  exit 1
fi
echo "Building for platform: $TARGET_PLATFORM"
if [[ $VERBOSE ]]; then
  echo "VERBOSE is on."
fi
if [[ $FAST_BUILD ]]; then
  echo "FAST_BUILD is on."
fi
if [[ $MULTITHREAD ]]; then
  echo "MULTITHREAD is on."
fi
