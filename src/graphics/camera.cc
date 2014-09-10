#include "graphics/camera.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "graphics/perspective.h"

namespace chaos {
    
Camera::Camera()
  : location_(0,0,-20),
    direction_(0,0,1),
    focus_(0,0,0),
    focused_(true),
    perspective_() {}

void Camera::Translate(glm::vec3 direction)
{
  location_ += direction;
}

void Camera::Rotate(glm::vec3 radians)
{
  focused_ = false;
  glm::mat4 rot(1.0f);
  rot = glm::rotate(rot, radians[0], glm::vec3(0,1,0));
  rot = glm::rotate(rot, radians[1], glm::vec3(1,0,0));
  glm::vec4 rotated = rot * glm::vec4(direction_, 0.0f);
  direction_ = glm::vec3(rotated);
}

glm::mat4 Camera::Matrix() const
{
  glm::vec3 center = (focused_) ? focus_ : location_ + direction_;
  glm::mat4 view = glm::lookAt(
      location_,
      center,
      glm::vec3(0, 1, 0));
  return perspective_.Matrix() * view;
}

}  // namespace chaos
