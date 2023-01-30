#include "KeypadControllerTaak.hpp"


void KeypadControllerTaak::main_taak()
{
    std::string msg;
    for (;;)
    {
        char key = KeyPressedChannel.read()[0];
        if (key != '\0'){
            msg.push_back(key);
            continue;
        }
        BetaalTerminalController->MessageEntered(msg);
    }
}

KeypadControllerTaak::KeypadControllerTaak(BetaalTerminalControllerTaak *BetaalTerminalController) : BetaalTerminalController(BetaalTerminalController)
{
}

void KeypadControllerTaak::KeyPressed(std::string key)
{
    KeyPressedChannel.write("1");
}