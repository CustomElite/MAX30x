#pragma once

#include <Arduino.h>

class MAX30x
{
public:
    enum class Channel
    {
        NONE = 0,
        NO_1,
        NO_2,
        NO_3,
        NO_4,
        NO_5,
        NO_6,
        NO_7,
        NO_8
    };

public:
    MAX30x(uint8_t pin_EN, uint8_t pin_A0, uint8_t pin_A1, uint8_t pin_A2);
    void init();
    void switchTo(Channel channel);
    inline Channel getChannel() const
    { 
        return m_selectedChannel; 
    }

private:
    const uint8_t m_pinEN, m_pinA0, m_pinA1, m_pinA2;
    Channel m_selectedChannel;
    bool m_initialized;

private:
    void set_pins(uint8_t a2, uint8_t a1, uint8_t a0, uint8_t en);
};