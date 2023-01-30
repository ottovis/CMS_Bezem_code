#pragma once

#include "string"

#include "rtos.hpp"

class PrinterTaak : public rtos::taak
{
private:
    void main_taak() override;

public:
    void PrintUitrijkaart(std::string kenteken, float tijd);
};