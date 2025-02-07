#include "square_wave_generator.h"

square_wave_generator::square_wave_generator(int pin, int duty_cycle)
    : pin(pin), duty_cycle(duty_cycle) {
  pinMode(pin, OUTPUT);
  analogWrite(pin, duty_cycle);
}

void square_wave_generator::set_duty_cycle(int new_duty_cycle) {
  duty_cycle = new_duty_cycle;
  analogWrite(pin, duty_cycle);
}