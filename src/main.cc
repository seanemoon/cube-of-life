#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <memory>

#include "SDL_handle.h"
#include "graphics.h"
#include "event_handler.h"

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
  graphics_handler->AddObject(std::unique_ptr<Triangle>(Triangle::Create()));
  EventHandler event_handler{graphics_handler.get()};

  event_handler.Run();
 
  return 0;
}
