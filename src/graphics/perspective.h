#ifndef CHAOS_GRAPHICS_PERSPECTIVE_H
#define CHAOS_GRAPHICS_PERSPECTIVE_H

#include "util/math.h"

namespace chaos {

/*******************************************************************************
 * Perspective:
 *
 * A wrapper class around a perspective matrix that provides the ability to
 * easily tweak settings.
 *
 ******************************************************************************/
class Perspective {
 public:
  Perspective();
  Perspective(float field_of_view, float aspect_ratio, float z_near,
      float z_far);

  // Constructs and returns a perspective matrix determined by the current
  // settings.
  // TODO: We should store a matrix either statically or as a class variable
  // to avoid recalculating it every frame (it shouldn't change).
  math::Matrix4f Matrix() const;

 private:
  // The angle that the camera opens out.
  float field_of_view_;

  // The ratio width/height of the screen.
  float aspect_ratio_;

  // How close something needs to be to the camera before it's clipped.
  float z_near_;

  // How far something needs to be away from the camera before it's clipped.
  float z_far_;
};

}  // namespace chaos

#endif  // CHAOS_GRAPHICS_PERSPECTIVE_H
