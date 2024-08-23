#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define OLED_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(115200);
  Serial.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS)) {
    Serial.println(F("Fail to init display SSD1306"));
    for (;;);
  }

  display.clearDisplay();
}

void loop() {
  const float BETA = 3950;
  int analogValue = analogRead(4);
  int celcius = 1 / (log(1 / (4095. / analogValue -1)) / BETA + 1.0 / 298.15) - 273.15;

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(15, 1);
  display.println("Temperatura atual");

  display.setTextSize(2);
  display.setCursor(40, 35);
  display.print(celcius);

  display.setCursor(65, 30);
  display.write(248);

  display.setCursor(77, 35);
  display.println("C");

  display.display();
  delay(2000);
}
