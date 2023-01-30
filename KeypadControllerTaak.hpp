#pragma once

#include "string"

#include "rtos.hpp"
#include "BetaalTerminalControllerTaak.hpp"

class KeypadControllerTaak : public rtos::taak{
private:
    BetaalTerminalControllerTaak* BetaalTerminalController;
    rtos::channel_t KeyPressedChannel;
    void main_taak() override;
public:
    KeypadControllerTaak(BetaalTerminalControllerTaak* BetaalTerminalController);
    void KeyPressed(std::string key);
};
