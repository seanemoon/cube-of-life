#ifndef CHAOS_GRAPHICS_PERSPECTIVE_H
#define CHAOS_GRAPHICS_PERSPECTIVE_H

#define GLM_FORCE_RADIANS
#include "glm/glm.hpp"

namespace chaos {

class Perspective {
 public:
  Perspective();
  Perspective(
      float field_of_view,
      float perspective,
      float near,
      float far);

  glm::mat4 Matrix() const;
 private:
  float field_of_view_;
  float perspective_;
  float near_;
  float far_;
};

}  // namespace chaos

#endif  // CHAOS_GRAPHICS_PERSPECTIVE_H
