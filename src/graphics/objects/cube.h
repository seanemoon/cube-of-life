#ifndef CHAOS_GRAPHICS_OBJECTS_CUBE_H
#define CHAOS_GRAPHICS_OBJECTS_CUBE_H

#include "graphics/camera.h"
#include "graphics/objects/drawable.h"
#include "util/graphics.h"
#include "util/math.h"

namespace chaos {

/*******************************************************************************
 * Cube:
 *
 * Holds the vertices for the triangle object and the ability to draw it.
 *
 ******************************************************************************/
class Cube : public Drawable {
 public:
  // The cube class does not provide acces to its constructors, instead it
  // should be accessed through the create method to enable error handling.
  // Returns nullptr on error.
  static Cube *Create();

  // Renders the cube as if viewed by the camera.
  virtual void Draw(Camera &camera) override;

 private:
  Cube(GLuint program);
  GLuint program_;
  GLfloat vertices_[36 * 3];
};

}  // namespace chaos

#endif  // CHAOS_GRAPHICS_OBJECTS_CUBE_H
