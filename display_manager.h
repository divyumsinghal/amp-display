#pragma once

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define MARGIN 3

class display_manager {
 private:
  Adafruit_SSD1306 display;

 public:
  display_manager(uint8_t width, uint8_t height, uint8_t mosi, uint8_t clk,
                  uint8_t dc, uint8_t reset, uint8_t cs);
  void begin();
  void clear();
  void draw_graph(int *graph_data);
  void print_info(unsigned long time, int value);
  void update();
};
