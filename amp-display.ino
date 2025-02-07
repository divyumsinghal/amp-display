#include "display_manager.h"
#include "graph_plotter.h"
#include "square_wave_generator.h"

#define TEST_WAVE 3  // 976.5625 Hz
#define FINAL_SIGNAL A0

#define OLED_MOSI 9
#define OLED_CLK 10
#define OLED_DC 11
#define OLED_CS 12
#define OLED_RESET 13

display_manager oled_display(SCREEN_WIDTH, SCREEN_HEIGHT, OLED_MOSI, OLED_CLK,
                             OLED_DC, OLED_RESET, OLED_CS);
square_wave_generator square_wave(TEST_WAVE);
graph_plotter graph;

unsigned long current_millis = 0;
unsigned long previous_clock = 0;
int input = 0;

void setup() {

  Serial.begin(9600);
  Serial.println("Hello World!");
  oled_display.begin();
  pinMode(FINAL_SIGNAL, INPUT);
  pinMode(TEST_WAVE, OUTPUT);
}

void loop() {

  while (current_millis - previous_clock < 200) ;

  previous_clock = current_millis;
  current_millis = millis();
  input = analogRead(FINAL_SIGNAL);
  graph.preprocess_data(input);
  graph.update_display(oled_display, current_millis);
}