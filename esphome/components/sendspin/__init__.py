import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.const import CONF_ID

# Dependency declarations
AUTO_LOAD = ["media_source", "media_player"]
CODEOWNERS = ["@KuriGohan-Kamehameha"]

DOMAIN = "sendspin"

# Configuration keys
CONF_TASK_STACK_IN_PSRAM = "task_stack_in_psram"
CONF_KALMAN_PROCESS_ERROR = "kalman_process_error"

# Create a namespace for the component
sendspin_ns = cg.esphome_ns.namespace('sendspin')
SendSpinComponent = sendspin_ns.class_('SendSpinComponent', cg.Component)

# Define the configuration schema for the component
CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(SendSpinComponent),
    cv.Optional(CONF_TASK_STACK_IN_PSRAM, default=False): cv.boolean,
    cv.Optional(CONF_KALMAN_PROCESS_ERROR, default=0.01): cv.float_range(min=0.0, max=1.0),
}).extend(cv.COMPONENT_SCHEMA)

async def to_code(config):
    # Create the main component
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    
    # Set configuration options
    cg.add(var.set_task_stack_in_psram(config[CONF_TASK_STACK_IN_PSRAM]))
    cg.add(var.set_kalman_process_error(config[CONF_KALMAN_PROCESS_ERROR]))
