#pragma once

#include "rtos.hpp"
#include "string"

class PinAutomaatTaak : public rtos::taak
{
private:
    void main_taak() override;

public:
    PinAutomaatTaak();
    int RequestPayment(float Amount);
};