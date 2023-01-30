#pragma once

#include "string"

#include "rtos.hpp"
#include "KeypadControllerTaak.hpp"

class KeypadTaak : public rtos::taak{
private:
    KeypadControllerTaak *keypadcontroller;
    void main_taak() override;
public:
    KeypadTaak(KeypadControllerTaak *keypadcontroller);
};