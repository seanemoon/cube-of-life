#ifndef CHAOS_SDLHANDLE_H
#define CHAOS_SDLHANDLE_H

#include <memory>

#include "util/window.h"

namespace chaos {

/*******************************************************************************
 * SDLHandle:
 *
 * Initializes all of SDL and GL's settings and provides a RAII management of
 * the resources associated with them.
 *
 ******************************************************************************/
class SDLHandle {
public:
  // Initializes SDL and tweaks some of its settings. This also creates the
  // OpenGL context and sets some settings there as well.
  SDLHandle();

  // Calls all the functions needed to clean up the memory grabbed at
  // initialization time.
  ~SDLHandle();

  // TODO: See why we needed access to these two; may be vestigial at this point.
  SDL_Window *window() { return window_; }
  SDL_GLContext &context() { return context_; }

private:
  SDL_Window *window_;
  SDL_GLContext context_;
};

}  // namespace chaos

#endif  // CHAOS_SDLHANDLE_H
