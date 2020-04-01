#include "DHT.h"

#define LED_PIN 13
#define DHT_PIN 2
#define DHT_TYPE DHT22

DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  pinMode(LED_PIN, OUTPUT);

  Serial.begin(115200);
  delay(100);
  Serial.println(F("U,9600,N"));
  Serial.begin(9600);
  delay(100);
  Serial.println(F("AT+NAMESENSOR001"));

  dht.begin();
}

void loop() {
  delay(10000);

  digitalWrite(LED_PIN, HIGH);

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println(F("{\"error\":\"Invalid sensor reading\"}"));
    return;
  }

  Serial.print(F("{\"humidity\":"));
  Serial.print(humidity);
  Serial.print(F(",\"temperature\":"));
  Serial.print(temperature);
  Serial.println(F("}"));

  digitalWrite(LED_PIN, LOW);
}
