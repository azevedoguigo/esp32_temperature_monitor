const int sensorPin = 23;

const float resistor = 10000;
const float beta = 3950;

void setup() {
  Serial.begin(115200);
}

void loop() {
  int analogValue = analogRead(sensorPin);

  float resistence = resistor * (4095.0 / (float)analogValue - 1.0);
  float temperatureKelvin = 1.0 / (1.0 / 298.15 + log(resistence / resistor) / beta);
  float temperatureCelcius = temperatureKelvin - 273.15;

  Serial.print("Temperatura: ");
  Serial.print(temperatureCelcius);
  Serial.println(" C");
  
  delay(1000);
}
