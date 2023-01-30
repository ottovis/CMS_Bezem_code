#pragma once

#include "string"

#include "rtos.hpp"
#include "DisplayTaak.hpp"
#include "KeypadControllerTaak.hpp"
#include "NetworkControllerTaak.hpp"
#include "PinAutomaatTaak.hpp"
#include "PrinterTaak.hpp"


class BetaalTerminalControllerTaak : public rtos::taak
{
private:
    DisplayTaak display;
    KeypadControllerTaak keypad;
    NetworkControllerTaak network;
    PinAutomaatTaak pinAutomaat;
    PrinterTaak printer;
    
    bool isValidKenteken(std::string kenteken);
    float calculatePrice(float time);
    rtos::channel_t MsgEnteredChannel;
    void main_taak() override;

public:
    BetaalTerminalControllerTaak();
    void MessageEntered(std::string msg);
};