#ifndef CHAOS_EVENT_HANDLER_H
#define CHAOS_EVENT_HANDLER_H

#include "graphics/graphics_handler.h"

namespace chaos {

class EventHandler {
public:
  EventHandler(GraphicsHandler *graphics_handler_);

  void Run();
private:
  GraphicsHandler *graphics_handler_;
};

}  // namespace chaos

#endif  // CHAOS_EVENT_HANDLER_H
