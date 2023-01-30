#include "DisplayTaak.hpp"

void DisplayTaak::showMessage(std::string msg)
{
    showMessageChannel.write(msg);
}

void DisplayTaak::main_taak()
{
    for (;;)
    {
        auto msg = showMessageChannel.read();
    }
}