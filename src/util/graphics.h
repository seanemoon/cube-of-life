#ifndef CHAOS_UTIL_GRAPHICS_H
#define CHAOS_UTIL_GRAPHICS_H

#include "GLES2/gl2.h"
#include "GLES2/gl2ext.h"

namespace chaos {


/*******************************************************************************
 * GraphicsUtil:
 *
 * Utility methods for graphics related routines.
 *
 ******************************************************************************/
class GraphicsUtil {
 public:
  // Loads a vertex shader and a fragment shader and returns a handle
  // to a new program that they are linked to.
  // TODO: Investigate if creating a program for every object is
  // the correct thing to do.
  static GLuint LoadShaders(char const * vshader_str, char const *fshader_str);

  // Compiles the shader string into a shader and returns its handle
  static GLuint CompileShader(GLenum type, char const *shader_str);
};

}  // namespace chaos

#endif  // CHAOS_UTIL_GRAPHICS_H
