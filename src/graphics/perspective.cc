#include "graphics/perspective.h"

#include "util/math.h"

namespace chaos {

// TODO: Remove default magical constants and instead either move to settings
// or something similar
Perspective::Perspective()
  : field_of_view_(45.0f),
    aspect_ratio_(1366.0f / 768.0f),
    near_z(0.1f),
    far_z(100.0f) {}

Perspective::Perspective(
    float field_of_view,
    float aspect_ratio,
    float near_z,
    float far_Z)
  : field_of_view_(field_of_view),
    aspect_ratio_(aspect_ratio),
    near_z(near_z),
    far_z(far_z) {}

Math::Matrix4f Perspective::Matrix() const
{
  return math::Perspective<float>(field_of_view_, aspect_ratio, near_z_,
      far_z_);
}

}  // namespace chaos
