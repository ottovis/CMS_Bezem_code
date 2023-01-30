#pragma once

#include "rtos.hpp"
#include "string"

class Buzzer: public rtos::taak
{
private:
    void main_taak() override;
public:
    Buzzer();
    void buzz(int ms);
};