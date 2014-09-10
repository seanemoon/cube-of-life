#include "event_handler.h"

#include "graphics/graphics_handler.h"
#include "SDL/SDL.h"

#define GLM_FORCE_RADIANS
#include "glm/glm.hpp"

namespace chaos {

EventHandler::EventHandler(GraphicsHandler *graphics_handler)
  : graphics_handler_{graphics_handler} {}

void EventHandler::Run()
{
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
        case SDL_FINGERDOWN: // fallthrough
        case SDL_FINGERUP: // fallthrough
        case SDL_FINGERMOTION: // fallthrough
        case SDL_KEYDOWN:
          switch(event.key.keysym.sym)
          {
            case SDLK_LEFT:
              break;
            case SDLK_RIGHT:
              break;
          }
          break;
      }
    }
    graphics_handler_->Update();
  }
}

}  // namespace chaos
