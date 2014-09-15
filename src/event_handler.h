#ifndef CHAOS_EVENT_HANDLER_H
#define CHAOS_EVENT_HANDLER_H

#include <unordered_map>

#include "graphics/graphics_handler.h"

namespace chaos {


/******************************************************************************* 
 * EventHandler:
 *
 * Handles the main loop and event dispatching for the entire game.
 * TODO: Separate the main loop into its own class.
 *
 ******************************************************************************/
class EventHandler {
public:
  EventHandler(GraphicsHandler *graphics_handler_);

  // The main loop for the game. This is in charge of handling events and
  // updating the GraphicsHandler as well.
  void Run();

private:
  // Handles mouse actions. This currently only handles mouse movement to
  // update the camera.
  void HandleMouse();

  // Updates internal state to reflect that the key is currently pressed.
  void KeyDown(SDL_Keycode code);

  // Updates internal state to reflect that the key is no longer pressed.
  void KeyUp(SDL_Keycode code);

  // A helper function to determine if a key is pressed.
  bool IsKeyPressed(SDL_Keycode code);

  // Iterates through currently pressed keys and invokes whatever actions those
  // keys correspond to. This may not be a good way of handling one-off events
  // but works well for motion.
  // TODO: look into a better way to handle key state.
  void HandleKeyState();

  // A handle to the one and only GraphicsHandler for the game.
  // TODO: we may want this to be a unique pointer; look into how the current
  // life-time is handled.
  GraphicsHandler *graphics_handler_;

  // Represents the currently pressed keys. This gives us O(1) (on average)
  // insertions and updates, which is the only operations we will be needing.
  // We could switch this to a tree based structure if we notice that we get
  // some random freezing, but I don't believe this will be an issue.
  std::unordered_map<SDL_Keycode, bool> key_states_;

  // Holds the change in time between the current iteration of the main loop
  // and the previous iteration of the main loop. This gives us the ability
  // to standardize speeds instead of having them dependent on client hardware.
  // I haven't looked into how secure this is for people hacking their delta_t
  // to get superspeed but this is out of scope for now.
  time_t delta_t_;
};

}  // namespace chaos

#endif  // CHAOS_EVENT_HANDLER_H
