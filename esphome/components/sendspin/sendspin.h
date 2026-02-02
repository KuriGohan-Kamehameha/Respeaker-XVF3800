#pragma once

#include "esphome/core/component.h"
#include "esphome/core/defines.h"

namespace esphome {
namespace sendspin {

class SendSpinComponent : public Component {
 public:
  void setup() override;
  void dump_config() override;
  float get_setup_priority() const override;

  void set_task_stack_in_psram(bool value) { this->task_stack_in_psram_ = value; }
  void set_kalman_process_error(float value) { this->kalman_process_error_ = value; }

 protected:
  bool task_stack_in_psram_{false};
  float kalman_process_error_{0.01f};
};

}  // namespace sendspin
}  // namespace esphome
