#include <LiquidCrystal.h>

const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int s1 = 11;
int s2 = 12;
unsigned long t1 = 0;
unsigned long t2 = 0;
float d = 10 ; //give the distance between two IR sensor 
float velocity;

void setup() {
  lcd.begin(16, 2);
  pinMode(s1, INPUT);
  pinMode(s2, INPUT);
  Serial.begin(9600);
  lcd.setCursor(0, 0);
  lcd.print(" Speed Detector ");
}

void loop() {
  // Wait for the first sensor to be blocked
  while (digitalRead(s1));
  while (digitalRead(s1) == 0);
  t1 = millis();

  // Wait for the second sensor to be blocked
  while (digitalRead(sen2));
  t2 = millis();

  // Calculate velocity
  velocity = t2 - t1;
  velocity = velocity / 1000; // Convert milliseconds to seconds
  velocity = (d / velocity); // Calculate speed using v = d / t and measure the valur d;
  velocity = velocity * 3600; // Convert to kilometers per hour
  velocity = velocity / 1000; // Convert to meters per kilometer

  // Display the speed on the LCD with a flashing effect
  for (int i = 5; i > 0; i--) {
    lcd.setCursor(3, 1);
    lcd.print(velocity);
    lcd.print(" Km/hr   ");
    delay(500);
    lcd.setCursor(3, 1);
    lcd.print("            ");
    delay(500);
  }
}
