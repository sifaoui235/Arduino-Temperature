#include <DHT.h>;
#include<LiquidCrystal_I2C.h>

#define DHT11_PIN 2
#define DHTTYPE DHT11
DHT dht(DHT11_PIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

float temp, hum;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
  lcd.init();
  lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
  temp = dht.readTemperature();
  hum = dht.readHumidity();
  Serial.print("temp = ");
  Serial.print(temp);
  Serial.println(" °C");
  Serial.print(" hum = ");
  Serial.print(hum);
  Serial.println(" %");
  
  delay(1000);

  lcd.setCursor(0, 0);
  lcd.print("Temp = ");
  lcd.setCursor(7, 0);
  lcd.print(temp);
  lcd.setCursor(11, 0);
  lcd.print(" C");
  
  delay(1000);
  
  lcd.setCursor(0, 1);
  lcd.print("Hum  = ");
  lcd.setCursor(7, 1);
  lcd.print(hum);
  lcd.setCursor(11, 1);
  lcd.print(" %");

  delay(1000);
}
