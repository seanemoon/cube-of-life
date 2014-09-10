#ifndef CHAOS_GRAPHICS_OBJECTS_TRIANGLE_H
#define CHAOS_GRAPHICS_OBJECTS_TRIANGLE_H

#include "GLES2/gl2.h"

#define GLM_FORCE_RADIANS
#include "glm/glm.hpp"

#include "graphics/camera.h"
#include "graphics/objects/drawable.h"

namespace chaos {

class Triangle : public Drawable {
 public:
  static Triangle *Create();

  glm::mat4 Model() const;
  virtual void Draw(Camera const &camera) const override;
 private:
  Triangle(GLuint program);

  GLuint program_;
  GLfloat vertices_[9];
};

}  // namespace chaos

#endif  // CHAOS_GRAPHICS_OBJECTS_TRIANGLE_H
