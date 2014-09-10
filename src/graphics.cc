#include "graphics.h"

#include <cstdlib>
#include <iostream>

#include <cmath>

#include "GLES2/gl2.h"
#include "GLES2/gl2ext.h"
#include "SDL/SDL.h"
#define GLM_FORCE_RADIANS
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "graphics/objects/triangle.h"
#include "graphics/camera.h"

namespace chaos {

Graphics::Graphics(SDLHandle &SDL_handle)
  : window_{SDL_handle.window()}, 
    camera_ {},
    triangle_(Triangle::Create()) {}

void Graphics::Move()
{
  camera_.Translate(glm::vec3(0, 0, 0.01f));
}

void Graphics::Rotate(bool left)
{
  if (left)
    camera_.Rotate(glm::vec3(-0.02f, 0.0f, 0.0f));
  else
    camera_.Rotate(glm::vec3(0.02f, 0.0f, 0.0f));
}

void Graphics::Update()
{
  triangle_->Draw(camera_);
} 

}  // namespace chaos
