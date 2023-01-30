#pragma once
#include "rtos.hpp"
#include "string"

class SlagboomControllerTaak : public rtos::taak
{
private:
    void main_taak() override;

public:
    SlagboomControllerTaak();
    void SetSlagboom(bool status);
};