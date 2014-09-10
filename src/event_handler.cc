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
        case SDL_FINGERUP: // fallthrough
        case SDL_KEYUP:
          graphics_handler_->Stop();
          break;
        case SDL_FINGERDOWN:
          graphics_handler_->Begin(false, glm::vec3(1.0f, 1.0f, 1.0f));
          break;
        case SDL_KEYDOWN:
          bool negative = false;
          glm::vec3 axis(0.0f, 1.0f, 0.0f);
          switch(event.key.keysym.sym)
          {
            case SDLK_LEFT:
              negative = true;
              break;
            case SDLK_RIGHT:
              break;
            case SDLK_DOWN:
              axis = glm::vec3(1.0f, 0.0f, 0.0f);
              negative = true;
              break;
            case SDLK_UP:
              axis = glm::vec3(1.0f, 0.0f, 0.0f);
              break;
          }
          graphics_handler_->Begin(negative, axis);
          break;
      }

    }
    graphics_handler_->Update();
  }
}

}  // namespace chaos
