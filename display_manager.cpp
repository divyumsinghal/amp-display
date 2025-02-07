#include "display_manager.h"

display_manager::display_manager(uint8_t width, uint8_t height, uint8_t mosi,
                                 uint8_t clk, uint8_t dc, uint8_t reset,
                                 uint8_t cs)
    : display(width, height, mosi, clk, dc, reset, cs) {}

void display_manager::begin() {
  if (!display.begin(SSD1306_SWITCHCAPVCC)) {
    while (true) Serial.println(F("SSD1306 allocation failed"));
  }

  display.display();
  delay(2000);
  display.clearDisplay();
}

void display_manager::clear() { display.clearDisplay(); }

void display_manager::draw_graph(int *graph_data) {
  for (int i = 0; i < SCREEN_WIDTH - 1; i++) {
    int y1 =
        map(graph_data[i], 0, 1023, SCREEN_HEIGHT - 1 - MARGIN, 0 + MARGIN);
    int y2 =
        map(graph_data[i + 1], 0, 1023, SCREEN_HEIGHT - 1 - MARGIN, 0 + MARGIN);

    // consider replacing i + 1 with i for somoother line
    display.drawLine(i, y1, i + 1, y2, WHITE);
  }
}

void display_manager::print_info(unsigned long time, int value) {
  display.setCursor(0, SCREEN_HEIGHT - 10);
  display.setTextColor(WHITE);
  display.print("Time: ");
  display.print(time / 1000);
  display.print("s ");
  display.print("Value: ");
  display.print(value);
}

void display_manager::update() { display.display(); }