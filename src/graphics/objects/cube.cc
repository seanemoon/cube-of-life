#include "graphics/objects/cube.h"

#define GLM_FORCE_RADIANS
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "GLES2/gl2.h"
#include "GLES2/gl2ext.h"

#include "graphics/camera.h"
#include "graphics/graphics_util.h"

static const GLfloat g_color_buffer_data[] = {
    0.583f,  0.771f,  0.014f,
    0.609f,  0.115f,  0.436f,
    0.327f,  0.483f,  0.844f,
    0.822f,  0.569f,  0.201f,
    0.435f,  0.602f,  0.223f,
    0.310f,  0.747f,  0.185f,
    0.597f,  0.770f,  0.761f,
    0.559f,  0.436f,  0.730f,
    0.359f,  0.583f,  0.152f,
    0.483f,  0.596f,  0.789f,
    0.559f,  0.861f,  0.639f,
    0.195f,  0.548f,  0.859f,
    0.014f,  0.184f,  0.576f,
    0.771f,  0.328f,  0.970f,
    0.406f,  0.615f,  0.116f,
    0.676f,  0.977f,  0.133f,
    0.971f,  0.572f,  0.833f,
    0.140f,  0.616f,  0.489f,
    0.997f,  0.513f,  0.064f,
    0.945f,  0.719f,  0.592f,
    0.543f,  0.021f,  0.978f,
    0.279f,  0.317f,  0.505f,
    0.167f,  0.620f,  0.077f,
    0.347f,  0.857f,  0.137f,
    0.055f,  0.953f,  0.042f,
    0.714f,  0.505f,  0.345f,
    0.783f,  0.290f,  0.734f,
    0.722f,  0.645f,  0.174f,
    0.302f,  0.455f,  0.848f,
    0.225f,  0.587f,  0.040f,
    0.517f,  0.713f,  0.338f,
    0.053f,  0.959f,  0.120f,
    0.393f,  0.621f,  0.362f,
    0.673f,  0.211f,  0.457f,
    0.820f,  0.883f,  0.371f,
    0.982f,  0.099f,  0.879f
};

namespace chaos {

Cube::Cube(GLuint program)
  : program_{program},
    model_{glm::mat4(1.0f)},
    rotation_{glm::mat4(1.0f)},
    translation_{glm::mat4(1.0f)},
    vertices_{
      -1.0f,-1.0f,-1.0f, // triangle 1 : begin
      -1.0f,-1.0f, 1.0f,
      -1.0f, 1.0f, 1.0f, // triangle 1 : end
       1.0f, 1.0f,-1.0f, // triangle 2 : begin
      -1.0f,-1.0f,-1.0f,
      -1.0f, 1.0f,-1.0f, // triangle 2 : end
       1.0f,-1.0f, 1.0f,
      -1.0f,-1.0f,-1.0f,
       1.0f,-1.0f,-1.0f,
       1.0f, 1.0f,-1.0f,
       1.0f,-1.0f,-1.0f,
      -1.0f,-1.0f,-1.0f,
      -1.0f,-1.0f,-1.0f,
      -1.0f, 1.0f, 1.0f,
      -1.0f, 1.0f,-1.0f,
       1.0f,-1.0f, 1.0f,
      -1.0f,-1.0f, 1.0f,
      -1.0f,-1.0f,-1.0f,
      -1.0f, 1.0f, 1.0f,
      -1.0f,-1.0f, 1.0f,
       1.0f,-1.0f, 1.0f,
       1.0f, 1.0f, 1.0f,
       1.0f,-1.0f,-1.0f,
       1.0f, 1.0f,-1.0f,
       1.0f,-1.0f,-1.0f,
       1.0f, 1.0f, 1.0f,
       1.0f,-1.0f, 1.0f,
       1.0f, 1.0f, 1.0f,
       1.0f, 1.0f,-1.0f,
      -1.0f, 1.0f,-1.0f,
       1.0f, 1.0f, 1.0f,
      -1.0f, 1.0f,-1.0f,
      -1.0f, 1.0f, 1.0f,
       1.0f, 1.0f, 1.0f,
      -1.0f, 1.0f, 1.0f,
       1.0f,-1.0f, 1.0f
    } {}

Cube *Cube::Create()
{
  GLchar v_shader_str[] =
  "#version 130                     \n"
  "attribute vec4 vPosition;         \n"
  "in vec3 vColor;                   \n"
  "out vec3 fragColor;               \n"
  "uniform mat4 MVP;                 \n"
  "void main()                       \n"
  "{                                 \n"
  "  gl_Position = MVP * vPosition;  \n"
  "  fragColor = vColor;             \n"
  "}                                 \n";

  GLchar f_shader_str[] =
  "#version 130                     \n"
  "in vec3 fragColor;                     \n"
  "out vec3 color;                            \n"
  "void main()                                \n"
  "{                                          \n"
  "   color = fragColor;                      \n"
  "}                                          \n";

  //"  //gl_FragColor = vec4(0.0, 7.0, 3.0, 1.0); \n"

  GLuint program = GraphicsUtil::LoadShaders(v_shader_str, f_shader_str);
  if (!program) return nullptr;

  return new Cube(program);
}

void Cube::Rotate(glm::mat4 const &rotation)
{
  rotation_ = rotation * rotation_;
  model_ = translation_ * rotation_;
}

void Cube::Translate(glm::mat4 const &translation)
{
  translation_ = translation * translation_;
  model_ = translation_ * rotation_;
}

glm::mat4 const &Cube::Model() const
{
  return model_;
}

void Cube::Draw(Camera const &camera) const
{
  glUseProgram(program_);


  GLuint matrix_id = glGetUniformLocation(program_, "MVP");
  glm::mat4 mvp = camera.Matrix() * Model();
  glUniformMatrix4fv(matrix_id, 1, GL_FALSE, &mvp[0][0]);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, vertices_);
  glEnableVertexAttribArray(0);

  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, g_color_buffer_data);
  glBindAttribLocation(program_, 1, "vColor");
  glEnableVertexAttribArray(1);

  glDrawArrays(GL_TRIANGLES, 0, 36);
}

}  // namespace chaos
