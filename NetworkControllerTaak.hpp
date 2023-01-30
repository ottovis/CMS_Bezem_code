#pragma once

#include "string"

#include "rtos.hpp"
#include "NPTServerTaak.hpp"
#include "ServerSQLTaak.hpp"

class NetworkControllerTaak : public rtos::taak
{
private:
    ServerSQLTaak ServerSQL;
    NPTServerTaak NPTServer;
    void main_taak() override;
public:
    NetworkControllerTaak();
    float GetKentekenplaat(std::string kentekenplaat);
    void AddKentekenplaat(std::string kentekenplaat);
    void NoteTime(std::string kentekenplaat);
    bool CheckIfValid(std::string kenteken);
};
