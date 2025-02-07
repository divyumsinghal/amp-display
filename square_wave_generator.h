#pragma once
#include <Arduino.h>

class square_wave_generator {
 private:
  int pin;
  int duty_cycle;

 public:
  square_wave_generator(int pin, int duty_cycle = 80);
  void set_duty_cycle(int new_duty_cycle);
};
