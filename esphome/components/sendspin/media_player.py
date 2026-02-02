import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import media_player
from esphome.const import CONF_ID
from . import sendspin_ns, SendSpinComponent

DEPENDENCIES = ["sendspin"]

SendSpinMediaPlayer = sendspin_ns.class_("SendSpinMediaPlayer", media_player.MediaPlayer)

CONFIG_SCHEMA = media_player.MEDIA_PLAYER_SCHEMA.extend(
    {
        cv.GenerateID(): cv.declare_id(SendSpinMediaPlayer),
    }
).extend(cv.COMPONENT_SCHEMA)

async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    await media_player.register_media_player(var, config)
