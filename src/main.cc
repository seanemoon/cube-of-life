#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <memory>

#define GLM_FORCE_RADIANS
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "SDL_handle.h"
#include "event_handler.h"

#include "graphics/graphics_handler.h"
#include "graphics/objects/cube.h"
#include "graphics/objects/triangle.h"

using namespace chaos;

int main(int argc, char *argv[])
{
  // RAII handle
  SDLHandle sdl_handle;

  /*
  std::unique_ptr<Graphics> graphics(new Graphics(sdl_handle));
  EventHandler event_handler(graphics.get());
  event_handler.Run();
  */


  std::unique_ptr<GraphicsHandler> graphics_handler(new GraphicsHandler());
  //graphics_handler->AddObject(std::unique_ptr<Cube>(Cube::Create()));
  int counter = 0;
  float distance = 3.0f;
  for (int x = -1; x < 2; x++) {
    for (int y = -1; y < 2; y++) { 
      for (int z = -1; z < 2; z++) {
        Cube *cube = Cube::Create();
        cube->Translate(glm::translate(glm::mat4(1.0), glm::vec3(x*distance, y*distance, z*distance)));
        graphics_handler->AddObject(std::unique_ptr<Cube>(cube));

        counter++;
      }
    }
  }
  printf("Counter: %i\n", counter);
  EventHandler event_handler{graphics_handler.get()};

  event_handler.Run();
 
  return 0;
}
