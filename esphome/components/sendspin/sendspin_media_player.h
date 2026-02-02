#pragma once

#ifdef USE_ESP_IDF

#include "esphome/components/media_player/media_player.h"
#include "esphome/core/component.h"

namespace esphome {
namespace sendspin {

class SendSpinMediaPlayer : public media_player::MediaPlayer, public Component {
 public:
  void setup() override;
  void dump_config() override;
  
  media_player::MediaPlayerTraits get_traits() override;
  
 protected:
  void control(const media_player::MediaPlayerCall &call) override;
};

}  // namespace sendspin
}  // namespace esphome

#endif  // USE_ESP_IDF
