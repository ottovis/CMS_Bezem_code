#include "rtos.hpp"

void rtos::taak::wait(int ms)
{
    return;
}


void rtos::channel_t::write(const std::string &msg)
{
}


void rtos::channel_t::write(const std::string &msg)
{
}

std::string rtos::channel_t::read()
{
    return std::string();
}

void rtos::flag_t::set()
{
}

void rtos::flag_t::clear()
{
}

bool rtos::flag_t::read()
{
    return false;
}

void rtos::pool_t::write(const std::string &msg)
{

}

std::string rtos::pool_t::read()
{
    return std::string();
}
