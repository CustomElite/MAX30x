#include "MAX30x.hpp"

MAX30x::MAX30x(uint8_t pin_EN, uint8_t pin_A0, uint8_t pin_A1, uint8_t pin_A2)
  : m_pinEN(pin_EN),
  m_pinA0(pin_A0),
  m_pinA1(pin_A1),
  m_pinA2(pin_A2),
  m_selectedChannel(Channel::NONE)
{
  pinMode(m_pinEN, OUTPUT);
  pinMode(m_pinA0, OUTPUT);
  pinMode(m_pinA1, OUTPUT);

  if (m_pinA2) pinMode(m_pinA2, OUTPUT);

  set_pins(0, 0, 0, 0);
}

void MAX30x::switchTo(Channel channel)
{
  switch (channel) {
    case Channel::NONE:
      set_pins(0, 0, 0, 0);
      m_selectedChannel = Channel::NONE;
      break;
    case Channel::NO_1:
      set_pins(0, 0, 0, 1);
      m_selectedChannel = Channel::NO_1;
      break;
    case Channel::NO_2:
      set_pins(0, 0, 1, 1);
      m_selectedChannel = Channel::NO_2;
      break;
    case Channel::NO_3:
      set_pins(0, 1, 0, 1);
      m_selectedChannel = Channel::NO_3;
      break;
    case Channel::NO_4:
      set_pins(0, 1, 1, 1);
      m_selectedChannel = Channel::NO_4;
      break;
    case Channel::NO_5: 
      set_pins(1, 0, 0, 1);
      m_selectedChannel = (m_pinA2) ? Channel::NO_5 : Channel::NO_1;
      break;
    case Channel::NO_6:
      set_pins(1, 0, 1, 1);
      m_selectedChannel = (m_pinA2) ? Channel::NO_6 : Channel::NO_2;
      break;
    case Channel::NO_7:
      set_pins(1, 1, 0, 1);
      m_selectedChannel = (m_pinA2) ? Channel::NO_7 : Channel::NO_3;
      break;
    case Channel::NO_8:
      set_pins(1, 1, 1, 1);
      m_selectedChannel = (m_pinA2) ? Channel::NO_8 : Channel::NO_4;
      break;
    default:
      set_pins(0, 0, 0, 0);
      m_selectedChannel = Channel::NONE;
      break;
  }
}

void MAX30x::set_pins(uint8_t a2, uint8_t a1, uint8_t a0, uint8_t en)
{
  digitalWrite(m_pinEN, en);
  digitalWrite(m_pinA0, a0);
  digitalWrite(m_pinA1, a1);
  if (m_pinA2)
    digitalWrite(m_pinA2, a2);
}