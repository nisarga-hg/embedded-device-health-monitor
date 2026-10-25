
#include <DHT.h>

// Pin configuration
#define DHTPIN 15
#define DHTTYPE DHT22
#define LED_PIN 4

// Create DHT sensor object
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);

  dht.begin();

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  Serial.println("================================");
  Serial.println(" Embedded Device Health Monitor");
  Serial.println("================================");
  Serial.println("System started successfully!");
}

void loop() {
  // Read sensor data
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  Serial.println("-------------------------------");

  // Check whether sensor readings are valid
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("ERROR: Sensor reading failed!");

    digitalWrite(LED_PIN, LOW);
  } else {
    // Display temperature
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" C");

    // Display humidity
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");

    // Check device health
    if (temperature >= 30.0) {
      digitalWrite(LED_PIN, HIGH);

      Serial.println("WARNING: High temperature!");
      Serial.println("Status: ALERT");
    } else {
      digitalWrite(LED_PIN, LOW);

      Serial.println("Status: NORMAL");
    }

    // Humidity warning
    if (humidity >= 70.0) {
      Serial.println("WARNING: High humidity!");
    } else if (humidity < 20.0) {
      Serial.println("WARNING: Low humidity!");
    }
  }

  // Wait 2 seconds before the next reading
  delay(2000);
}
