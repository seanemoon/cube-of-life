This is an implementation of Conway's game of life on the faces of a spinnable  
cube. This is primarily a project to have fun learning SDL and OpenGL and is  
currently a work in progress.  

If you want to try it out at its current stage please feel free! It is a work  
in progress with commits being pushed up often, so no guarantees that it will  
ever work at any point in time.  

To run it:  
navigate to the top level directory of the project  
build for your platform  
  $ bin/build.sh -p <platform>  
    - currently supported platforms are: linux, android  
run the tester!  
  for linux:  
    $ out/linux/tester  
  for android:  
    $ adb install -r out/android/CubeSpinner-debug.apk  
