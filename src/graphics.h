#ifndef CHAOS_GRAPHICS_H
#define CHAOS_GRAPHICS_H

#include "SDL_handle.h"
#include "GLES2/gl2.h"
#include "GLES2/gl2ext.h"
#include "SDL/SDL.h"

#include "graphics/camera.h"
#include "graphics/objects/triangle.h"

namespace chaos {

class Graphics {
public:
  Graphics(SDLHandle &SDL_handle);
  
  void Move();
  void Update();
  void Rotate(bool left);
  static GLuint LoadShader(GLenum type, GLchar const * const src);

private:
  SDL_Window *window_;
  Camera camera_;
  Triangle *triangle_;
};

}  // namespace chaos

#endif  // CHAOS_GRAPHICS_H
