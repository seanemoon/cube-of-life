#include "graphics/graphics_handler.h"

#include <vector>
#include <memory>

#define GLM_FORCE_RADIANS
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "GLES2/gl2.h"
#include "GLES2/gl2ext.h"
#include "SDL/SDL.h"

#include "graphics/camera.h"
#include "graphics/objects/drawable.h"

static bool transform = false;
static glm::mat4 rotation;

namespace chaos {

GraphicsHandler::GraphicsHandler()
  : camera_ {} ,
    objects_ {},
    window_(SDL_GL_GetCurrentWindow()) {glClearColor(0.3f, 0.3f, 0.3f, 1.0f);}

GraphicsHandler::GraphicsHandler(Camera camera)
  : camera_{camera},
    objects_ {},
    window_(SDL_GL_GetCurrentWindow()) {}

void GraphicsHandler::AddObject(std::unique_ptr<Drawable> object)
{
  objects_.push_back(std::move(object));
}

void GraphicsHandler::Begin(bool negative, glm::vec3 axis)
{
  transform = true;
  float radians = 0.03f;
  if (negative) radians *= -1;
  rotation = glm::rotate(glm::mat4(1.0f), radians, axis);
}

void GraphicsHandler::Stop()
{
  transform = false;
}

void GraphicsHandler::Draw() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  for (auto &object : objects_) {
    if (transform) {
      object->Rotate(rotation);
      object->Translate(rotation);
    }
//      object->Transform(glm::rotate(glm::mat4(1.0f), 0.01f, glm::normalize(glm::vec3(1,1,1))));
    object->Draw(camera_);
  }
  SDL_GL_SwapWindow(window_);
}

void GraphicsHandler::Update() {
  // camera_.Rotate(glm::vec3(0.001f, 0.001f, 0.1f));
  Draw();
}

}  // namespace chaos
