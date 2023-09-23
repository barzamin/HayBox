#include "modes/extra/SCON4.hpp"

SCON4::SCON4(socd::SocdType horizontal_socd, socd::SocdType vertical_socd) {
    _socd_pair_count = 2;
    // note mod_x is used as jump
    _socd_pairs = new socd::SocdPair[_socd_pair_count]{
        socd::SocdPair{&InputState::left,  &InputState::right, horizontal_socd},
        socd::SocdPair{ &InputState::down, &InputState::mod_x, vertical_socd  },
    };
}

void SCON4::UpdateDigitalOutputs(InputState &inputs, OutputState &outputs) {
    // right fingers:
    //   b  grab  super R
    // a   x     x     x
    //
    // left fingers:
    // L on normal button

    outputs.a = inputs.b;
    outputs.b = inputs.r;
    outputs.y = inputs.y;
    outputs.x = inputs.lightshield;
    outputs.triggerRDigital = inputs.midshield;
    outputs.triggerLDigital = inputs.l;

    outputs.start = inputs.start;
}

// via Melee20Button
constexpr uint8_t ANALOG_STICK_MIN = 48;
constexpr uint8_t ANALOG_STICK_NEUTRAL = 128;
constexpr uint8_t ANALOG_STICK_MAX = 208;

void SCON4::UpdateAnalogOutputs(InputState &inputs, OutputState &outputs) {
    UpdateDirections(
        inputs.left,
        inputs.right,
        inputs.down,
        inputs.mod_x, // NOTE: jump on Mod X
        // TODO: do sth other than the normal cstick here
        inputs.c_left,
        inputs.c_right,
        inputs.c_down,
        inputs.c_up,
        ANALOG_STICK_MIN,
        ANALOG_STICK_NEUTRAL,
        ANALOG_STICK_MAX,
        outputs
    );

    if (outputs.triggerLDigital) {
        outputs.triggerLAnalog = 140;
    }
    if (outputs.triggerRDigital) {
        outputs.triggerRAnalog = 140;
    }
}
