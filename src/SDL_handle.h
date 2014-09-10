#ifndef CHAOS_SDLHANDLE_H
#define CHAOS_SDLHANDLE_H

#include <memory>

#include "SDL/SDL.h"

namespace chaos {

class SDLHandle {
public:
  SDLHandle();
  ~SDLHandle();

  SDL_Window *window() { return window_; }
  SDL_GLContext &context() { return context_; }
private:
  SDL_Window *window_;
  SDL_GLContext context_;
};

}  // namespace chaos

#endif  // CHAOS_SDLHANDLE_H
