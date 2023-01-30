#pragma once

#include "string"

#include "rtos.hpp"

class NPTServerTaak : public rtos::taak {
private:
    void main_taak() override;
public:
    std::string GetTime();
};