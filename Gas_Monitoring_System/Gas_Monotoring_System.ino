#define BLYNK_TEMPLATE_ID "TMPL3Ty576t6B"
#define BLYNK_TEMPLATE_NAME "Gas Detector"
#define BLYNK_AUTH_TOKEN "RHgjKgBzsLRDfnmmMZSb4hwKvcbbd5bG"
// From your device in Blink App

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Enter your Auth token from Blink App
char auth[] = "RHgjKgBzsLRDfnmmMZSb4hwKvcbbd5bG"; 
char ssid[] = "-------"; // Enter your WIFI SSID
char pass[] = "********"; // Enter your WIFI password

BlynkTimer timer;
int pinValue = 0;
int count = 0;

#define Buzzer D6 
#define Green D8
#define Sensor A0

// V1 - Button
// V6 - Gauge Meter
// V7 - Terminal

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Wifi Connected Success!");
  pinMode(Green, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(Sensor, INPUT);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(100L, readSensor);
}
// Receive Data from Button
BLYNK_WRITE(V1) {
  pinValue = param.asInt();
}

void readSensor() {
  int sensor = analogRead(Sensor);
  int sensor2 = map(sensor, 0, 4096, 0, 255);
  Serial.println(sensor2);
 if (pinValue == 1) {
    if (sensor2 < 50) {
      digitalWrite(Green, HIGH);
      digitalWrite(Red, LOW);
      digitalWrite(Buzzer, LOW);
      // Print to the Terminal
      Blynk.virtualWrite(V7, "Gas value: Normal\n");
    } 
    else if (sensor2 >=50) {
      digitalWrite(Green, LOW);
      digitalWrite(Red, HIGH);
      digitalWrite(Buzzer, HIGH);
      // Print to the Terminal
      Blynk.virtualWrite(V7, "Gas value: High\n"); 
    }
    // Send sensor value to the Gauge widget (V6)
    Blynk.virtualWrite(V6, sensor2);
  } 
  else {
    digitalWrite(Red, LOW);
    digitalWrite(Buzzer, LOW);
    digitalWrite(Green, LOW);
    // Print to the Terminal
    Blynk.virtualWrite(V7, "Gas Detector turned off\n"); 
  }
}
void loop() {
  Blynk.run();
  timer.run();
  delay(1000);
}
