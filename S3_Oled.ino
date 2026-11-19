#include <Wire.h>
#include <Adafruit_SH110X.h>

#define PIN_SDA 1
#define PIN_SCL 2
Adafruit_SH1106G display(128, 64, &Wire, -1);

void setup() {
  Wire.setPins(PIN_SDA, PIN_SCL);
  Wire.begin(PIN_SDA, PIN_SCL);
  display.begin(0x3C, true);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SH110X_WHITE);
  display.setCursor(0, 10);
  display.print("Hola S3");
  display.display();
}
void loop() {}