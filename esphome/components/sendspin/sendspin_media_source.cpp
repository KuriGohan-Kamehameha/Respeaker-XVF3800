#include "sendspin_media_source.h"

#ifdef USE_ESP_IDF

#include "esphome/core/log.h"

namespace esphome {
namespace sendspin {

static const char *const TAG = "sendspin.media_source";

void SendSpinMediaSource::setup() {
  ESP_LOGCONFIG(TAG, "Setting up SendSpin Media Source...");
}

}  // namespace sendspin
}  // namespace esphome

#endif  // USE_ESP_IDF
