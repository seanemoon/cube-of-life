#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <unordered_map>

#include "SDL_handle.h"
#include "event_handler.h"
#include "graphics/graphics_handler.h"
#include "graphics/objects/cube.h"
#include "graphics/objects/triangle.h"
#include "util/math.h"
#include "util/window.h"

using namespace chaos;

int main(int argc, char *argv[])
{
  // RAII handle
  SDLHandle sdl_handle;

  std::unique_ptr<GraphicsHandler> graphics_handler(new GraphicsHandler());
  int counter = 0;
  float distance = 3.0f;
  for (int x = -1; x < 2; x++) {
    for (int y = -1; y < 2; y++) { 
      for (int z = -1; z < 2; z++) {
        if (x == 0 && y == 0 && z == 0) continue;
        Cube *cube = Cube::Create();
        // cube->Translate(glm::translate(glm::mat4(1.0), glm::vec3(x*distance, y*distance, z*distance)));
        cube->Translate(Eigen::Affine3f(Eigen::Translation3f(x*distance,y*distance,z*distance)).matrix());
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
