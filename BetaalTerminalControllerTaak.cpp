#include "BetaalTerminalControllerTaak.hpp"

bool BetaalTerminalControllerTaak::isValidKenteken(std::string kenteken)
{
    return true;
}

float BetaalTerminalControllerTaak::calculatePrice(float time)
{
    return 0.0f;
}

BetaalTerminalControllerTaak::BetaalTerminalControllerTaak(): keypad(this)
{
}

void BetaalTerminalControllerTaak::MessageEntered(std::string msg)
{
    MsgEnteredChannel.write(msg);
}

void BetaalTerminalControllerTaak::main_taak()
{
    for (;;)
    {
        // Wachten
        display.showMessage("Type kenteken in!");
        auto msg = MsgEnteredChannel.read();
        if (!isValidKenteken(msg))
        {
            //Foutief kenteken
            display.showMessage("Verkeerd kenteken, probeer op nieuw!");
            wait(5000);
            continue;
        }
        // Kenteken ophalen
        auto time_elapsed = network.GetKentekenplaat(msg);
        if (time_elapsed == -1)
        {
            //Foutief kenteken
            display.showMessage("Verkeerd kenteken, probeer op nieuw!");
            wait(5000);
            continue;
        }
        // Betalen
        display.showMessage("Voltooi openstaand bedrag!");
        auto exitStatus = pinAutomaat.RequestPayment(calculatePrice(time_elapsed));
        if (exitStatus == -1){
            //Foutief kenteken
            display.showMessage("Verkeerd kenteken, probeer op nieuw!");
            wait(5000);
            continue;
        }
        // Betaling voltooid
        display.showMessage("Betaling voltooid!");
        network.NoteTime(msg);
        printer.PrintUitrijkaart(msg, time_elapsed);
        wait(3000);
    }
}
