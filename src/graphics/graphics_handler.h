#ifndef CHAOS_GRAPHICS_GRAPHICS_HANDLER_H
#define CHAOS_GRAPHICS_GRAPHICS_HANDLER_H

#include <vector>
#include <memory>

#include "SDL/SDL.h"

#include "graphics/objects/drawable.h"
#include "graphics/camera.h"

namespace chaos {

class GraphicsHandler {
 public:
  GraphicsHandler();
  GraphicsHandler(Camera camera);
  void Draw();
  void Update();
  void AddObject(std::unique_ptr<Drawable> object);
 private:
  Camera camera_;
  std::vector<std::unique_ptr<Drawable>> objects_;
  SDL_Window *window_;
};

}  // namespace chaos

#endif  // CHAOS_GRAPHICS_GRAPHICS_HANDLER_H
