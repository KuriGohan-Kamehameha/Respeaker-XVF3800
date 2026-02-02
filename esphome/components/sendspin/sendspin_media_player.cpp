#include "sendspin_media_player.h"

#ifdef USE_ESP_IDF

#include "esphome/core/log.h"

namespace esphome {
namespace sendspin {

static const char *const TAG = "sendspin.media_player";

void SendSpinMediaPlayer::setup() {
  ESP_LOGCONFIG(TAG, "Setting up SendSpin Media Player...");
}

void SendSpinMediaPlayer::dump_config() {
  ESP_LOGCONFIG(TAG, "SendSpin Media Player");
}

media_player::MediaPlayerTraits SendSpinMediaPlayer::get_traits() {
  auto traits = media_player::MediaPlayerTraits();
  traits.set_supports_pause(true);
  return traits;
}

void SendSpinMediaPlayer::control(const media_player::MediaPlayerCall &call) {
  if (call.get_command().has_value()) {
    switch (call.get_command().value()) {
      case media_player::MEDIA_PLAYER_COMMAND_PLAY:
        ESP_LOGD(TAG, "Play command received");
        this->state = media_player::MEDIA_PLAYER_STATE_PLAYING;
        break;
      case media_player::MEDIA_PLAYER_COMMAND_PAUSE:
        ESP_LOGD(TAG, "Pause command received");
        this->state = media_player::MEDIA_PLAYER_STATE_PAUSED;
        break;
      case media_player::MEDIA_PLAYER_COMMAND_STOP:
        ESP_LOGD(TAG, "Stop command received");
        this->state = media_player::MEDIA_PLAYER_STATE_IDLE;
        break;
      default:
        break;
    }
    this->publish_state();
  }
}

}  // namespace sendspin
}  // namespace esphome

#endif  // USE_ESP_IDF
