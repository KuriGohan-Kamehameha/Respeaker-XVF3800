import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import media_source
from esphome.const import CONF_ID
from . import sendspin_ns, SendSpinComponent

DEPENDENCIES = ["sendspin"]

SendSpinMediaSource = sendspin_ns.class_("SendSpinMediaSource", media_source.MediaSource)

CONFIG_SCHEMA = media_source.MEDIA_SOURCE_SCHEMA.extend(
    {
        cv.GenerateID(): cv.declare_id(SendSpinMediaSource),
    }
)

async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await media_source.register_media_source(var, config)
