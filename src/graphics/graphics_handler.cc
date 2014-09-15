#include "graphics/graphics_handler.h"

#include <memory>
#include <vector>

#include "graphics/camera.h"
#include "graphics/objects/drawable.h"
#include "util/graphics.h"
#include "util/math.h"
#include "util/window.h"

static bool transform = false;

namespace chaos {

GraphicsHandler::GraphicsHandler()
  : camera_ {},
    objects_ {},
    window_(SDL_GL_GetCurrentWindow()) {glClearColor(0.3f, 0.3f, 0.3f, 1.0f);}

GraphicsHandler::GraphicsHandler(Camera camera)
  : camera_{camera},
    objects_ {},
    window_(SDL_GL_GetCurrentWindow()) {}

Camera &GraphicsHandler::GetCamera()
{
  return camera_;
}

void GraphicsHandler::AddObject(std::unique_ptr<Drawable> object)
{
  objects_.push_back(std::move(object));
}

void GraphicsHandler::Draw() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  for (auto &object : objects_) {
    if (transform) {
     // object->Rotate(rotation);
    }
    object->Draw(camera_);
  }
  SDL_GL_SwapWindow(window_);
}

void GraphicsHandler::WindowSize(int *x, int *y)
{
  SDL_GetWindowSize(window_, x, y);
}

void GraphicsHandler::Update() {
  Draw();
}

}  // namespace chaos
