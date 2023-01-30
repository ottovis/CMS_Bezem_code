#pragma once

#include "rtos.hpp"
#include "string"
#include "KentekenInvoerControllerTaak.hpp"


class AutoSensorController : public rtos::taak {
private:
    void main_taak() override;
    KentekenInvoerControllerTaak *kentekenInvoerControllerTaak;
public:
    AutoSensorController(KentekenInvoerControllerTaak *kentekenInvoerControllerTaak);
    void SlagboomDoorreden(bool status);
    void AutoAanwezig(bool status);

};