#ifndef CHAOS_GRAPHICS_CAMERA_H
#define CHAOS_GRAPHICS_CAMERA_H

#include "graphics/perspective.h"
#include "util/math.h"

namespace chaos {

/******************************************************************************* 
 * Camera:
 *
 * Encapsulates the viewer of the scene. Its main purpose is
 * to provide an easy way to move and orient the camera and to yield a matrix
 * that is the product of the perspective and view matrices.
 *
 ******************************************************************************/
class Camera {
 public:
  Camera();
  // This updates the way the camera is oriented with change in mouse
  // coordinates. This is similar to how the source engine operates.
  void UpdateOrientation(int delta_x, int delta_y);

  // This matrix is the product of the perspective and view matrices.
  // The perspective matrix comes from the stored Perspective object.
  math::Matrix4f Matrix();

  // Moves the camera in the given direction scaled by delta_t.
  // This ensures that players speed does not depend on hardware
  // speed.
  // This currently expects a normalized vector.
  // TODO: Move normalization into this method instead.
  void Move(math::Vector3f direction, time_t delta_t);

  // Returns a normalized vector in the floor-direction that the camera is facing.
  // This means that pitch is not taken into account, and that the y component
  // is always zero.
  math::Vector3f Forward();

  // Returns a normalized vector orthogonal to Forward() that is in the x-z plane.
  math::Vector3f Right();

 private:
  // Coordinates of the camera.
  math::Vector3f location_;

  // Orientation of the camera stored as a quaternion.
  math::Quaternion orientation_;

  // Perspective class holding perspective settings that is used to generate
  // a perspective matrix.
  Perspective perspective_;
};

}  // namespace chaos

#endif  // CHAOS_GRAPHICS_CAMERA_H
