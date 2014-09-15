#include "graphics/camera.h"

#include "graphics/perspective.h"
#include "settings.h"
#include "util/math.h"

namespace chaos {

Camera::Camera()
  : location_{0, 0, 0},
    orientation_{math::Quaternion::Identity()},
    perspective_{}
{
}

void Camera::Move(math::Vector3f direction, time_t delta_t)
{
  location_ += settings::kSpeed * delta_t * direction;
}

math::Vector3f Camera::Forward()
{
  math::Vector3f direction = orientation_ * math::Vector3f(0, 0, 1);
  return math::Vector3f(direction.x(), 0, direction.z()).normalized();
}

math::Vector3f Camera::Right()
{
  math::Vector3f direction = orientation_ * math::Vector3f(-1, 0, 0);
  return math::Vector3f(direction.x(), 0, direction.z()).normalized();
}

void Camera::UpdateOrientation(int delta_x, int delta_y)
{
  static float pitch = 0;
  static float yaw = 0;
  if (delta_x == 0 && delta_y == 0) return;

  pitch += delta_y * settings::kSensitivity;
  yaw   -= delta_x * settings::kSensitivity;
  if (pitch > math::PI / 2.0f) pitch = math::PI / 2.0f;
  if (pitch < -math::PI / 2.0f) pitch = -math::PI / 2.0f;

  auto yaw_quat = math::CreateQuaternion(yaw, {0,1,0});
  auto pitch_quat = math::CreateQuaternion(pitch, {1,0,0});
  orientation_ = (yaw_quat * pitch_quat).normalized();
}

math::Matrix4f Camera::Matrix()
{
  auto view = math::LookAt(
      location_,
      (location_ + orientation_ * math::Vector3f(0,0,1)).eval(),
      orientation_ * math::Vector3f(0,1,0)
  );
  return perspective_.Matrix() * view;
}

}  // namespace chaos
