#pragma once

#include "string"

namespace rtos
{
    struct channel_t
    {
        void write(const std::string &msg);
        std::string read();
    };

    struct flag_t
    {
        void set();
        void clear();
        bool read();
    };

    struct pool_t
    {
        void write(const std::string &msg);
        std::string read();
    };

    class taak
    {
    public:
        taak() = default;
        ~taak() = default;
        virtual void main_taak() = 0;
        void wait(int ms);
    };
};