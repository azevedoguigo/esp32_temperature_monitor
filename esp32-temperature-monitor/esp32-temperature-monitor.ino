void setup() {
  Serial.begin(115200);
  Serial.begin(9600);
}

void loop() {
  const float BETA = 3950;
  int analogValue = analogRead(4);
  float celcius = 1 / (log(1 / (4095. / analogValue -1)) / BETA + 1.0 / 298.15) - 273.15;

  Serial.println(celcius);
  delay(2000);
}
