usermods/LDR_Dusk_Dawn_v2/library.json#ifndef WLED_ENABLE_MQTT
#error "This user mod requires MQTT to be enabled."
#endif

#pragma once

#include "wled.h"

class UserMod_ChildrenTimer : public Usermod
{
private:
  // Private class members. You can declare variables and functions only accessible to your usermod here
  bool enabled = false;

public:
  // non WLED related methods, may be used for data exchange between usermods (non-inline methods should be defined out of class)

  /**
   * Enable/Disable the usermod
   */
  inline void enable(bool enable) { enabled = enable; }

  /**
   * Get usermod enabled/disabled state
   */
  inline bool isEnabled() { return enabled; }

  /*
   * getId() allows you to optionally give your V2 usermod an unique ID (please define it in const.h!).
   * This could be used in the future for the system to determine whether your usermod is installed.
   */
  uint16_t getId() override
  {
    return USERMOD_ID_TIMER;
  }

  void setup()
  {
    Serial.println("Starting!");
  }

  // gets called every time WiFi is (re-)connected.
  void connected()
  {
  }

  void loop()
  {
    strip.setPixelColor(0, 100);
    strip.setPixelColor(1, 200);
  }
};
