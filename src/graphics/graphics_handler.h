#ifndef CHAOS_GRAPHICS_GRAPHICS_HANDLER_H
#define CHAOS_GRAPHICS_GRAPHICS_HANDLER_H

#include <memory>

#include "graphics/objects/drawable.h"
#include "util/window.h"

namespace chaos {

/*******************************************************************************
 * GraphicsHandler:
 *
 * Handles all the graphic updating and drawing logic. The class should be used
 * by adding all Drawable objects that you wish it to control and then calling
 * Update once per frame in the main game loop.
 *
 ******************************************************************************/
class GraphicsHandler {
 public:
  GraphicsHandler();
  GraphicsHandler(Camera camera);

  // Returns a mutable reference to the stored camera.
  Camera &GetCamera();

  // Handles all book-keeping that must be done for each frame and then calls
  // Draw.
  void Update();

  // Adds an object to be rendered when Update() is called.
  void AddObject(std::unique_ptr<Drawable> object);

  // Populates the value pointed to by width and height with the dimensions
  // of the window.
  void WindowSize(int *width, int *height);

 private:
  // Iterates through the collection of Drawable objects and renders them by
  // calling Draw on each one.
  void Draw();

  // The camera that determines the POV of the scene.
  Camera camera_;

  // Collection of all the Drawable objects that will be rendered when Update()
  // is called.
  // TODO: Make these shared_ptr's so they can be updated by the physics
  // handler.
  std::vector<std::unique_ptr<Drawable>> objects_;

  SDL_Window *window_;
};

}  // namespace chaos

#endif  // CHAOS_GRAPHICS_GRAPHICS_HANDLER_H
