#include "graphics/graphics_handler.h"

#include <vector>
#include <memory>

#include "GLES2/gl2.h"
#include "GLES2/gl2ext.h"
#include "SDL/SDL.h"

#include "graphics/camera.h"
#include "graphics/objects/drawable.h"

namespace chaos {

GraphicsHandler::GraphicsHandler()
  : camera_ {} ,
    objects_ {},
    window_(SDL_GL_GetCurrentWindow()) {}

GraphicsHandler::GraphicsHandler(Camera camera)
  : camera_{camera},
    objects_ {},
    window_(SDL_GL_GetCurrentWindow()) {}

void GraphicsHandler::AddObject(std::unique_ptr<Drawable> object)
{
  objects_.push_back(std::move(object));
}

void GraphicsHandler::Draw() {
  glClear(GL_COLOR_BUFFER_BIT);
  for (auto &object : objects_) {
    object->Draw(camera_);
  }
  SDL_GL_SwapWindow(window_);
}

void GraphicsHandler::Update() {
  Draw();
}

}  // namespace chaos
