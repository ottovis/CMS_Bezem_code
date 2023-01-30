#pragma once

#include "string"

#include "rtos.hpp"

class ServerSQLTaak : public rtos::taak
{
private:
    void main_taak() override;

public:
    ServerSQLTaak();
    void remove(std::string kenteken);
    void insert(std::string kenteken, std::string time);
};