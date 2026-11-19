#include <Wire.h>
#include <U8g2lib.h>

// ===== AQUÍ defines tus pines =====
static const int PIN_SDA = 1;   // SDA / D1 del OLED
static const int PIN_SCL = 2;   // SCK / SCL / D0 del OLED

// SH1106 128x64, I2C por hardware, buffer completo CONSTRUCTOR_1
//U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /*reset=*/U8X8_PIN_NONE);

// CONSTRUCTOR_2 (para usar este borrar o comentar las líneas Wire.*)
U8G2_SH1106_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /*clock=*/PIN_SCL, /*data=*/PIN_SDA, /*reset=*/U8X8_PIN_NONE);

void setup() {

  // para el bloque que sigue ver comentarios de los CONSTRUCTORES
  //Wire.setPins(PIN_SDA, PIN_SCL);          // fija pines antes de begin() p/CONSTRUCTOR_1
  //Wire.begin(PIN_SDA, PIN_SCL, 400000);    // 400 kHz p/CONSTRUCTOR_1
  
  u8g2.setI2CAddress(0x3C << 1);           // U8g2 usa dirección de 8 bits
  u8g2.begin();

  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB10_tr);
  u8g2.drawStr(0, 20, "ESP32-S3");
  u8g2.setFont(u8g2_font_6x10_tf);
  u8g2.drawStr(0, 40, "OLED 1.3 SH1106");
  u8g2.sendBuffer();
}

void loop() {}
