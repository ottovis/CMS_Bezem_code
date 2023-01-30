#pragma once

#include "string"

#include "rtos.hpp"

class DisplayTaak : public rtos::taak
{
private:
    rtos::channel_t showMessageChannel;
    std::string msg;
    void main_taak() override;
public:
    void showMessage(std::string msg);
};
