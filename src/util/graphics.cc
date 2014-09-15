#include "util/graphics.h"

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

namespace chaos {

GLuint GraphicsUtil::LoadShaders(GLchar const * const vshader_str,
    GLchar const * const fshader_str)
{
  GLuint program;
  GLuint vertex_shader;
  GLuint fragment_shader;
  GLint linked;

  // Load the vertex/fragment shaders
  std::vector<GLuint> shaders;
  shaders.push_back(CompileShader(GL_VERTEX_SHADER, vshader_str));
  shaders.push_back(CompileShader(GL_FRAGMENT_SHADER, fshader_str));

  // Create the program object
  program = glCreateProgram();
  if(program == 0) {
    return 0;
  }

  for (GLuint shader : shaders) {
    glAttachShader(program, shader);
  }

  // Bind vPosition to attribute 0
  glBindAttribLocation(program, 0, "vPosition");

  // Link the program
  glLinkProgram(program);

  // Check the link status
  glGetProgramiv(program, GL_LINK_STATUS, &linked);

  if(!linked)
  {
     GLint info_len = 0;

     glGetProgramiv(program, GL_INFO_LOG_LENGTH, &info_len);

     if(info_len > 1)
     {
        char* info_log = (char *)malloc(sizeof(char) * info_len);

        glGetProgramInfoLog(program, info_len, NULL, info_log);
        printf("Error linking program:\n%s\n", info_log);

        free(info_log);
     }

     glDeleteProgram(program);
     return 0;
  }

  return program;
}

GLuint GraphicsUtil::CompileShader(GLenum type, char const *shader_str) {
   GLuint shader;
   GLint compiled;

   // Create the shader object
   shader = glCreateShader(type);

   if(shader == 0)
      return 0;

   // Load the shader source
   GLchar const * const casted = (GLchar const * const) shader_str;
   glShaderSource(shader, 1, &casted, NULL);

   // Compile the shader
   glCompileShader(shader);

   // Check the compile status
   glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);

   if(!compiled)
   {
      GLint infoLen = 0;

      glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLen);

      if(infoLen > 1)
      {
         char* infoLog = (char *)malloc(sizeof(char) * infoLen);

         glGetShaderInfoLog(shader, infoLen, NULL, infoLog);
         printf("Error compiling shader:\n%s\n", infoLog);
         free(infoLog);
      }

      glDeleteShader(shader);
      return 0;
   }

   return shader;
}

}  // namespace chaos
