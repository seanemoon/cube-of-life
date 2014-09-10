#ifndef CHAOS_GRAPHICS_CAMERA_H
#define CHAOS_GRAPHICS_CAMERA_H

#define GLM_FORCE_RADIANS
#include "glm/glm.hpp"

#include "perspective.h"

namespace chaos {

class Camera {
 public:
  Camera();
  void Rotate(glm::vec3 radians);
  void Translate(glm::vec3 direction);
  glm::mat4 Matrix() const;
 private:
  glm::vec3 location_;
  glm::vec3 direction_;
  glm::vec3 focus_;
  bool focused_;
  Perspective perspective_;
};

}  // namespace chaos

#endif  // CHAOS_GRAPHICS_CAMERA_H
