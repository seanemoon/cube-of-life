#include "SDL_handle.h"

#include <memory>
#include <iostream>

#include "GLES2/gl2.h"
#include "GLES2/gl2ext.h"
#include "SDL/SDL.h"

namespace chaos {

SDLHandle::SDLHandle()
{
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    std::cerr << "Could not initialize SDL" << std::endl;
    exit(1);
  }

  SDL_DisplayMode display_mode;
  SDL_GetDesktopDisplayMode(0, &display_mode);

  window_ = SDL_CreateWindow("Cube of Life", 0, 0,
      display_mode.w, display_mode.h,
      SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

  if (!window_)
  {
    std::cerr << "Could not initialize window." << std::endl;
    exit(1);
  }

  context_ = SDL_GL_CreateContext(window_);

  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_GL_SetSwapInterval(1);

  auto version = glGetString(GL_VERSION);
  std::cout << "OpenGL version: " << version << std::endl;
}

SDLHandle::~SDLHandle()
{
  SDL_GL_DeleteContext(context_);
  SDL_DestroyWindow(window_);
  SDL_Quit();
}

}  // namespace chaos
