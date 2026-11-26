#define BLYNK_TEMPLATE_ID "TMPL31mM9W1Id"
#define BLYNK_TEMPLATE_NAME "Fish feeding"
#define BLYNK_AUTH_TOKEN "U7ibNuiIxeIwInc6qcZJFRPLuxMY1o_o"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>
#include <DHT.h>

char ssid[] = "poco m4 pro 5g";
char pass[] = "xxxxxxxxxx";

#define SERVO_PIN D4
#define DHTPIN D1
#define DHTTYPE DHT11
#define waterLevelPin D6
#define pumpPin D7

Servo feeder;
DHT dht(DHTPIN, DHTTYPE);

int phPin = A0;

BlynkTimer timer;

void sendSensor()
{
  if(Blynk.connected())
  {
    Serial.println("Blynk Connected");
  }
  else
  {
    Serial.println("Blynk Not Connected");
  }

  int phValue = analogRead(phPin);
  int waterLevel = digitalRead(waterLevelPin);
  float temp = dht.readTemperature();

  Serial.println("------ Sensor Data ------");

  if (!isnan(temp))
  {
    if(temp > 50 || temp < 0)
    {
      return;
    }

    temp = round(temp * 10) / 10.0;

    Serial.print("Temperature: ");
    Serial.println(temp);

    Blynk.virtualWrite(V0, temp);

    if(temp > 30)
    {
      Serial.println("High Temperature");
    }
    else if(temp < 24)
    {
      Serial.println("Low Temperature");
    }
    else
    {
      Serial.println("Normal Temperature");
    }
  }

  float ph = 14.0 - (phValue * 14.0 / 1023.0);

  if (ph < 0) ph = 0;
  if (ph > 14) ph = 14;

  Serial.print("pH Value: ");
  Serial.println(ph, 2);

  if (ph < 7.0)
  {
    Serial.println("Water is Acidic");
  }
  else if (ph >= 7.0 && ph <= 7.5)
  {
    Serial.println("Water is Neutral");
  }
  else
  {
    Serial.println("Water is Basic");
  }

  if (waterLevel == 1)
  {
    Serial.println("Water Level: Wet");
  }
  else
  {
    Serial.println("Water Level: Dry");
  }

  if (waterLevel == 0)
  {
    digitalWrite(pumpPin, HIGH);
  }
  else
  {
    digitalWrite(pumpPin, LOW);
  }
}

BLYNK_WRITE(V1)
{
  int value = param.asInt();

  if(value == 1)
  {
    feeder.write(180);
    Serial.println("Fish Feeder ON");
  }
  else
  {
    feeder.write(0);
    Serial.println("Fish Feeder OFF");
  }
}

void setup()
{
  Serial.begin(9600);

  feeder.attach(SERVO_PIN);
  feeder.write(0);

  dht.begin();
  pinMode(waterLevelPin, INPUT);
  pinMode(pumpPin, OUTPUT);

  Serial.println("Connecting Blynk...");
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  timer.setInterval(5000L, sendSensor);

  Serial.println("System Started");
}

void loop()
{
  Blynk.run();
  timer.run();
}
