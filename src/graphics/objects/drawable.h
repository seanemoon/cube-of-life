#ifndef GRAPHICS_OBJECTS_DRAWABLE_H
#define GRAPHICS_OBJECTS_DRAWABLE_H

#include "graphics/camera.h"

namespace chaos {

class Drawable {
 public:
  virtual void Draw(Camera const &camera) const = 0;

  virtual void Rotate(glm::mat4 const &rotation) = 0;
  virtual void Translate(glm::mat4 const &translation) = 0;
  virtual glm::mat4 const &Model() const = 0;
};

}  // namespace chaos

#endif  // GRAPHICS_OBJECTS_DRAWABLE_H
