#ifndef GRAPHICS_OBJECTS_DRAWABLE_H
#define GRAPHICS_OBJECTS_DRAWABLE_H

#include "graphics/camera.h"
#include "util/math.h"

namespace chaos {

/*******************************************************************************
 * Drawable:
 *
 * Pure virtual class that provides all common functionality needed to move,
 * transform, scale, and draw models. Subclasses should provide their own
 * vertices and implementation of draw.
 * TODO: look into a way encoding the fact that vertices are required and
 * providing a standard implementation of draw.
 *
 ******************************************************************************/
class Drawable {
 public:
  Drawable();
  virtual void Draw(Camera &camera) = 0;
  // Rotates the object by the given rotation.
  // TODO: Use quaternions instead of matrices for rotate.
  virtual void Rotate(math::Matrix4f const &rotate);

  // Translates the object by the given matrix.
  // TODO: take in a vector instead.
  virtual void Translate(math::Matrix4f const &translate);

  // Scales the object by the given matrix.
  // TODO: update a scaling factor instead.
  virtual void Scale(math::Matrix4f const &scale);

  // Updates the matrix if it is dirty and then returns a constant reference
  // to it.
  virtual math::Matrix4f const &Model();

 private:
  bool dirty_model_;
  math::Matrix4f model_;
  math::Matrix4f rotate_;
  math::Matrix4f translate_;
  math::Matrix4f scale_;
};

}  // namespace chaos

#endif  // GRAPHICS_OBJECTS_DRAWABLE_H
