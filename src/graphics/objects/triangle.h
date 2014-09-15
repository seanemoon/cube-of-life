#ifndef CHAOS_GRAPHICS_OBJECTS_TRIANGLE_H
#define CHAOS_GRAPHICS_OBJECTS_TRIANGLE_H

#include "graphics/camera.h"
#include "graphics/objects/drawable.h"
#include "util/graphics.h"
#include "util/math.h"

namespace chaos {

/*******************************************************************************
 * Triangle:
 *
 * Holds the vertices for the triangle object and the ability to draw it.
 *
 ******************************************************************************/
class Triangle : public Drawable {
 public:
  // The triangle class does not provide acces to its constructors, instead it
  // should be accessed through the create method to enable error handling.
  // Returns nullptr on error.
  static Triangle *Create();

  // Renders the cube as if viewed by the camera.
  virtual void Draw(Camera &camera) override;

 private:
  Triangle(GLuint program);
  GLuint program_;
  GLfloat vertices_[9];
};

}  // namespace chaos

#endif  // CHAOS_GRAPHICS_OBJECTS_TRIANGLE_H
