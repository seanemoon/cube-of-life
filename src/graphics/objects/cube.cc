#include "graphics/objects/cube.h"

#include "graphics/camera.h"
#include "util/graphics.h"
#include "util/math.h"

static GLfloat g_color_buffer_data[] = {
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
  "#version 130                      \n"
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
  "#version 130                               \n"
  "in vec3 fragColor;                         \n"
  "out vec3 color;                            \n"
  "void main()                                \n"
  "{                                          \n"
  "   color = fragColor;                      \n"
  "}                                          \n";

  GLuint program = GraphicsUtil::LoadShaders(v_shader_str, f_shader_str);
  if (!program) return nullptr;

  /*
  for (int i =0; i < 12*3; i+=1) {
    g_color_buffer_data[i*3 + 0] = 0 * 18  / (3*12.0f);
    g_color_buffer_data[i*3 + 1] = 18 / (3*12.0f);
    g_color_buffer_data[i*3 + 2] = 18 / (3*12.0f);
  }
  */

  return new Cube(program);
}

void Cube::Draw(Camera &camera)
{
  glUseProgram(program_);


  GLuint matrix_id = glGetUniformLocation(program_, "MVP");
  math::Matrix4f mvp = camera.Matrix() * Model();
  glUniformMatrix4fv(matrix_id, 1, GL_FALSE, mvp.data());
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, vertices_);
  glEnableVertexAttribArray(0);

  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, g_color_buffer_data);
  glBindAttribLocation(program_, 1, "vColor");
  glEnableVertexAttribArray(1);

  glDrawArrays(GL_TRIANGLES, 0, 36);
}

}  // namespace chaos
