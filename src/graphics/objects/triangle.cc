#include "graphics/objects/triangle.h"

#include "graphics/camera.h"
#include "util/graphics.h"

namespace chaos {

Triangle::Triangle(GLuint program)
  : program_{program},
    vertices_{
      -1.0f, -1.0f, 0.0f,
       1.0f, -1.0f, 0.0f,
       0.0f,  1.0f, 0.0f
    } {}

Triangle *Triangle::Create()
{
  GLchar v_shader_str[] =
  "attribute vec4 vPosition;         \n"
  "uniform mat4 MVP;                 \n"
  "void main()                       \n"
  "{                                 \n"
  "  gl_Position = MVP * vPosition;  \n"
  "}                                 \n";

  GLchar f_shader_str[] =
  "void main()                                \n"
  "{                                          \n"
  "  gl_FragColor = vec4(0.0, 7.0, 3.0, 1.0); \n"
  "}                                          \n";

  GLuint program = GraphicsUtil::LoadShaders(v_shader_str, f_shader_str);
  if (!program) return nullptr;

  return new Triangle(program);
}

void Triangle::Draw(Camera &camera)
{
  glUseProgram(program_);
  GLuint matrix_id = glGetUniformLocation(program_, "MVP");
  math::Matrix4f mvp = camera.Matrix() * Model();
  glUniformMatrix4fv(matrix_id, 1, GL_FALSE, mvp.data());
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, vertices_);
  glEnableVertexAttribArray(0);
  glDrawArrays(GL_TRIANGLES, 0, 3);
}



}  // namespace chaos
