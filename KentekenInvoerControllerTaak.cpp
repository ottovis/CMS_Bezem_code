#include "KentekenInvoerControllerTaak.hpp"

void KentekenInvoerControllerTaak::main_taak()
{
    for(;;){
        // Wachten op auto
        display.showMessage("");

        // Invoer uitrijkaart of kenteken
        // mijn mock implementatie ondersteund bij nader inzien niet wachten op meerdere waitables
        auto waitable = wait(auto_event_changed_flag + UitrijkaartEnteredChannel);
        if (waitable == auto_event_changed_flag){
            display.showMessage("Voer kenteken of uitrijkaart in!");
            auto_event_changed_flag.clear();
            auto msg = MsgEnteredChannel.read();
            if(!isValidKenteken(msg)){
                //Foutief kenteken
                display.showMessage("Verkeerd kenteken, probeer op nieuw!");
                wait(3000);
                auto_event_changed_flag.set();
                continue;
            }
            // Open slagboom
            slagboom.SetSlagboom(true);
            display.showMessage("Succes! Rijdt u door!!");
            auto_event_changed_flag.read();
            auto_event_changed_flag.clear();
            slagboom.SetSlagboom(false);
            if(auto_event_pool.read() == "CAR_LEFT"){
                // Reset
                continue;
            }
            network.AddKentekenplaat(msg);
        }   
        else{
            auto kenteken = UitrijkaartEnteredChannel.read();
            if (!network.CheckIfValid(kenteken)){
                //Buzz
                buzzer.buzz(3000);
                display.showMessage("Verlopen uitrijkaart! Koop een nieuwe!");
                auto_event_changed_flag.clear();
                continue;
            }
            // Open slagboom
            slagboom.SetSlagboom(true);
            display.showMessage("Tot ziens!");
            auto_event_changed_flag.read();
            auto_event_changed_flag.clear();
            slagboom.SetSlagboom(false);
        }
    }
}

bool KentekenInvoerControllerTaak::isValidKenteken(std::string kenteken)
{
    return true;
}

KentekenInvoerControllerTaak::KentekenInvoerControllerTaak(): keypad(this), autosensor(this)
{
}

void KentekenInvoerControllerTaak::MessageEntered(std::string msg)
{
    MsgEnteredChannel.write(msg);
}

void KentekenInvoerControllerTaak::CarStatus(std::string status)
{
    auto_event_changed_flag.set();
    auto_event_pool.write(status);
}

void KentekenInvoerControllerTaak::UitrijkaartIngevoerd(std::string kenteken)
{
    UitrijkaartEnteredChannel.write(kenteken);
}

