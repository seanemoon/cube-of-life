#include "graphics/perspective.h"

#include "util/math.h"

namespace chaos {

// TODO: Remove default magical constants and instead either move to settings
// or something similar
Perspective::Perspective()
  : field_of_view_(45.0f),
    aspect_ratio_(1366.0f / 768.0f),
    z_near_(0.1f),
    z_far_(100.0f) {}

Perspective::Perspective(
    float field_of_view,
    float aspect_ratio,
    float z_near,
    float z_far)
  : field_of_view_(field_of_view),
    aspect_ratio_(aspect_ratio),
    z_near_(z_near),
    z_far_(z_far) {}

math::Matrix4f Perspective::Matrix() const
{
  return math::Perspective<float>(field_of_view_, aspect_ratio_, z_near_,
      z_far_);
}

}  // namespace chaos
