#include "graphics/objects/triangle.h"

#include "GLES2/gl2.h"
#include "GLES2/gl2ext.h"

#include "graphics/camera.h"
#include "graphics/graphics_util.h"

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

glm::mat4 Triangle::Model() const
{
  return glm::mat4(1.0f);
}

void Triangle::Draw(Camera const &camera) const
{
  glUseProgram(program_);
  GLuint matrix_id = glGetUniformLocation(program_, "MVP");
  glm::mat4 mvp = camera.Matrix() * Model();  
  glUniformMatrix4fv(matrix_id, 1, GL_FALSE, &mvp[0][0]);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, vertices_);
  glEnableVertexAttribArray(0);
  glDrawArrays(GL_TRIANGLES, 0, 3);
}



}  // namespace chaos
