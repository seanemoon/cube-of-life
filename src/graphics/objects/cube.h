#ifndef CHAOS_GRAPHICS_OBJECTS_CUBE_H
#define CHAOS_GRAPHICS_OBJECTS_CUBE_H

#include "GLES2/gl2.h"

#define GLM_FORCE_RADIANS
#include "glm/glm.hpp"

#include "graphics/camera.h"
#include "graphics/objects/drawable.h"

namespace chaos {

class Cube : public Drawable {
 public:
  static Cube *Create();

  virtual void Rotate(glm::mat4 const &rotation);
  virtual void Translate(glm::mat4 const &translation);
  virtual glm::mat4 const &Model() const;
  virtual void Draw(Camera const &camera) const override;
 private:
  Cube(GLuint program);

  GLuint program_;
  glm::mat4 model_;
  glm::mat4 rotation_;
  glm::mat4 translation_;
  GLfloat vertices_[36 * 3];
};

}  // namespace chaos

#endif  // CHAOS_GRAPHICS_OBJECTS_CUBE_H
