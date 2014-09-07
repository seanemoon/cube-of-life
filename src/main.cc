#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <memory>

#include "GLES2/gl2.h"
#include "GLES2/gl2ext.h"
#include "SDL/SDL.h"

class Graphics {
 public:
  Graphics(SDL_Window *window) : window_{window} {}
  void Update()
  {
    glClearColor(rand() % 255 / 255.0f, rand() % 255 / 255.0f,
        rand() % 255 / 255.0f, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    SDL_GL_SwapWindow(window_);
  }

 private:
  SDL_Window *window_;
};

void UpdateFrame(void *param)
{
  Graphics *graphics = (Graphics *)param;
  graphics->Update();
}

void checkSDLError(int line = -1)
{
#ifndef NDEBUG
  const char *error = SDL_GetError();
  if (*error != '\0')
  {
    printf("SDL Error: %s\n", error);
    if (line != -1) printf(" + line: %i\n", line);
    SDL_ClearError();
  }
#endif
}

int main(int argc, char *argv[])
{
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    std::cerr << "Could not initialize SDL" << std::endl;
    return 1;
  }

  SDL_DisplayMode display_mode;
  SDL_GetDesktopDisplayMode(0, &display_mode);

  // Create window and renderer
  SDL_Window *window = SDL_CreateWindow(nullptr, 0, 0, display_mode.w,
      display_mode.h, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

  if (!window)
  {
    std::cerr << "Could not initialize window." << std::endl;
    return 1;
  }

  auto gl = SDL_GL_CreateContext(window);

  auto version = glGetString(GL_VERSION);
  std::cout << "OpenGL version: " << version << std::endl;

  std::unique_ptr<Graphics> graphics =
      std::unique_ptr<Graphics>(new Graphics(window));

  SDL_Event event;
  auto done = false;
  while (!done)
  {
    SDL_PumpEvents();
    while (SDL_PollEvent(&event))
    {
      switch(event.type)
      {
        case SDL_QUIT:
          done = true;
          break;
        case SDL_KEYDOWN:
          done = true;
          break;
        case SDL_WINDOWEVENT:
        {
          switch (event.window.event)
          {
            case SDL_WINDOWEVENT_RESIZED:
            {
              break;
            }
          }
        }
      }
    }
    graphics->Update();
  }

  SDL_GL_DeleteContext(gl);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
