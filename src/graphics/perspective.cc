#include "graphics/perspective.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace chaos {

Perspective::Perspective()
  : field_of_view_(45.0f),
    perspective_(1366.0f / 768.0f),
    near_(0.1f),
    far_(100.0f) {}

Perspective::Perspective(
    float field_of_view,
    float perspective,
    float near,
    float far)
  : field_of_view_(field_of_view),
    perspective_(perspective),
    near_(near),
    far_(far) {}

glm::mat4 Perspective::Matrix() const
{
  return glm::perspective(field_of_view_, perspective_, near_, far_);
}

}  // namespace chaos
