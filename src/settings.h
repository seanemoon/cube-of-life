#ifndef CHAOS_SETTINGS_H
#define CHAOS_SETTINGS_H

// TODO: This currently won't scale as an actuall settings class.
// Constants are fine for now for quick development, but we will
// need a way to tweak these settings later, hopefully at runtime.
namespace chaos {
namespace settings {

// TODO: these could really be named better.
// Mouse sensitivity.
static const float kSensitivity = 0.001f;

// Movement speed.
static const float kSpeed = 0.01f;

}  // namespace settings
}  // namespace chaos

#endif
