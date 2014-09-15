#ifndef CHAOS_UTIL_MATH_EIGEN_H
#define CHAOS_UTIL_MATH_EIGEN_H

#include "Eigen/Core"
#include "Eigen/Geometry"

namespace chaos {
namespace math {

/*******************************************************************************
 * MathEigen:
 *
 * The Eigen implementation of the math utilities.
 *
 ******************************************************************************/

// Typedefs used throughout the codebase.
typedef Eigen::Vector3f Vector3f;
typedef Eigen::Matrix4f Matrix4f;
typedef Eigen::Quaternion<float> Quaternion;

static const float PI = 3.14159f;

template<class T>
T DegreesToRadians(T degrees)
{
  return degrees * PI/180;
}

// Creates the quaternion that is equivalent to a rotation of the given angle
// around the given axis.
// Expects the angle to be in radian.
template<class T>
Eigen::Quaternion<T> CreateQuaternion(T angle, Eigen::Matrix<T,3,1> axis)
{
  return Eigen::Quaternion<T>(Eigen::AngleAxis<T>(angle, axis));
}

// This is the Eigen version of glPerspective and glm::perspective.
// Creates the perspective matrix that has a field of view of fovy,
// an aspect ratio of aspect, and only displays objects between z_nrear and
// z_far.
template<class T>
Eigen::Matrix<T,4,4> Perspective(double fovy, double aspect, double z_near,
    double z_far)
{
  typedef Eigen::Matrix<T,4,4> Matrix4;

  double fovy_radians = DegreesToRadians(fovy);
  double tan_half_fovy = tan(fovy_radians/2.0);

  Matrix4 result = Matrix4::Zero();
  result(0,0) = 1.0 / (aspect * tan_half_fovy);
  result(1,1) = 1.0 / (tan_half_fovy);
  result(2,2) = -(z_far + z_near)/(z_far - z_near);
  result(3,2) = -1.0;
  result(2,3) = -(2.0 * z_far * z_near)/(z_far - z_near);

  return result;
}

// This is the Eigen version of glLookAt and glm::LookAt.
// Creates the view matrix from the given settings. Eye is the coordinates
// of the camera. Center is the coordinates that the camera is looking at.
// Up is the vector pointing upwards from the camera.
template<class T>
Eigen::Matrix<T,4,4> LookAt(
  Eigen::Matrix<T,3,1> const &eye,
  Eigen::Matrix<T,3,1> const &center,
  Eigen::Matrix<T,3,1> const &up)
{
  typedef Eigen::Matrix<T,4,4> Matrix4;
  typedef Eigen::Matrix<T,3,1> Vector3;

  Vector3 f = (center - eye).normalized();
  Vector3 u = up.normalized();
  Vector3 s = f.cross(u).normalized();
  u = s.cross(f);

  Matrix4 result;
  result <<
     s.x(),  s.y(),  s.z(), -s.dot(eye),
     u.x(),  u.y(),  u.z(), -u.dot(eye),
    -f.x(), -f.y(), -f.z(),  f.dot(eye),
         0,      0,      0,           1;

  return result;
}

}  // namepsace math
}  // namespace chaos

#endif  // CHAOS_UTIL_MATH_EIGEN_H
