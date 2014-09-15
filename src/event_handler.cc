#include "event_handler.h"

#include <chrono>
#include <iostream>
#include <unordered_map>
#include <iostream>

#include "graphics/graphics_handler.h"
#include "util/math.h"

namespace chaos {

EventHandler::EventHandler(GraphicsHandler *graphics_handler)
  : graphics_handler_{graphics_handler}
{
  // Enable this for first-person style camera
  SDL_SetRelativeMouseMode(SDL_TRUE);
}

void EventHandler::HandleMouse()
{
  int delta_x, delta_y;
  SDL_GetRelativeMouseState(&delta_x, &delta_y);
  graphics_handler_->GetCamera().UpdateOrientation(delta_x, delta_y);
}

void EventHandler::KeyDown(SDL_Keycode code)
{
  key_states_[code] = true;
}

void EventHandler::KeyUp(SDL_Keycode code)
{
  key_states_[code] = false;
}

bool EventHandler::IsKeyPressed(SDL_Keycode code)
{
  return key_states_[code];
}

void EventHandler::HandleKeyState()
{
  math::Vector3f direction = math::Vector3f::Zero();
  for (auto const &key_state : key_states_)
  {
    if (!key_state.second) continue;
    switch(key_state.first)
    {
      case SDLK_w:
        direction += graphics_handler_->GetCamera().Forward();
        break;
      case SDLK_a:
        direction -= graphics_handler_->GetCamera().Right();
        break;
      case SDLK_s:
        direction -= graphics_handler_->GetCamera().Forward();
        break;
      case SDLK_d:
        direction += graphics_handler_->GetCamera().Right();
        break;
    }
  }

  // We do don't want to normalize if we have the zero vector as that has
  // undefined behavior, and we only need to normalize if we have accumulated
  // more than one direction. Forward() and Right() give us normalized vectors
  // to start with.
  if (direction.norm() > 1) direction.normalize();

  graphics_handler_->GetCamera().Move(direction, delta_t_);
}


void EventHandler::Run()
{
  SDL_Event event;
  auto done = false;

  auto time_previous = std::chrono::system_clock::now();
  auto time_now = std::chrono::system_clock::now();
  while (!done)
  {
    time_now = std::chrono::system_clock::now();
    delta_t_ = std::chrono::duration_cast<std::chrono::milliseconds>(
        (time_now - time_previous)).count();

    SDL_PumpEvents();
    while (SDL_PollEvent(&event))
    {
      switch(event.type)
      {
        case SDL_MOUSEMOTION:
          HandleMouse();
          break;
        case SDL_QUIT:
          done = true;
          break;
        case SDL_FINGERUP: // fallthrough
        case SDL_KEYDOWN:
          KeyDown(event.key.keysym.sym);
          break;
        case SDL_KEYUP:
          KeyUp(event.key.keysym.sym);
          break;
      }
    }

    HandleKeyState();
    graphics_handler_->Update();

    time_previous = time_now;
  }
}

}  // namespace chaos
