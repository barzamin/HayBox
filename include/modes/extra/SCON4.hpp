#ifndef _MODES_SCON4_HPP
#define _MODES_SCON4_HPP

#include "core/ControllerMode.hpp"
#include "core/socd.hpp"
#include "core/state.hpp"

// Super Clash of Ninja 4
class SCON4 : public ControllerMode {
  public:
    SCON4(socd::SocdType horizontal_socd, socd::SocdType vertical_socd);

  private:
    void UpdateDigitalOutputs(InputState &inputs, OutputState &outputs);
    void UpdateAnalogOutputs(InputState &inputs, OutputState &outputs);
};

#endif