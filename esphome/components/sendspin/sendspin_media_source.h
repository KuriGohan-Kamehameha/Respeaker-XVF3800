#pragma once

#ifdef USE_ESP_IDF

#include "esphome/components/media_source/media_source.h"
#include "esphome/core/component.h"

namespace esphome {
namespace sendspin {

class SendSpinMediaSource : public media_source::MediaSource {
 public:
  void setup() override;
};

}  // namespace sendspin
}  // namespace esphome

#endif  // USE_ESP_IDF
