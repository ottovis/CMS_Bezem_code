#pragma once    

#include "rtos.hpp"
#include "string"

#include "rtos.hpp"
#include "DisplayTaak.hpp"
#include "KeypadControllerTaak.hpp"
#include "NetworkControllerTaak.hpp"
#include "SlagboomControllerTaak.hpp"
#include "AutoSensorController.hpp"
#include "BuzzerTaak.hpp"

class KentekenInvoerControllerTaak : public rtos::taak
{
private:
    DisplayTaak display;
    KeypadControllerTaak keypad;
    NetworkControllerTaak network;
    SlagboomControllerTaak slagboom;
    Buzzer buzzer;
    AutoSensorController autosensor;

    void main_taak() override;
    bool isValidKenteken(std::string kenteken);
    rtos::channel_t MsgEnteredChannel;
    rtos::pool_t auto_event_pool;
    rtos::flag_t auto_event_changed_flag;
    rtos::channel_t UitrijkaartEnteredChannel;

public:
    KentekenInvoerControllerTaak();
    void MessageEntered(std::string msg);
    void CarStatus(std::string status);
    void UitrijkaartIngevoerd(std::string kenteken);
};