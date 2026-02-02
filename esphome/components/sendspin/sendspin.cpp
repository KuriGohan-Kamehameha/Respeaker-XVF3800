#include "sendspin.h"
#include "esphome/core/log.h"

namespace esphome {
namespace sendspin {

static const char *const TAG = "sendspin";

void SendSpinComponent::setup() {
  ESP_LOGCONFIG(TAG, "Setting up SendSpin component...");
}

void SendSpinComponent::dump_config() {
  ESP_LOGCONFIG(TAG, "SendSpin:");
  ESP_LOGCONFIG(TAG, "  Task stack in PSRAM: %s", YESNO(this->task_stack_in_psram_));
  ESP_LOGCONFIG(TAG, "  Kalman process error: %.4f", this->kalman_process_error_);
}

float SendSpinComponent::get_setup_priority() const {
  return setup_priority::AFTER_CONNECTION;
}

}  // namespace sendspin
}  // namespace esphome
