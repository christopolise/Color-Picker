// AUTHORED BY christopolise 2019-07-20

#include <LiquidCrystal.h>

// Arduino pin numbers
const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = A0; // analog pin connected to X output
const int Y_pin = A1; // analog pin connected to Y output
const int red_light_pin = 11;
const int green_light_pin = 10;
const int blue_light_pin = 9;

LiquidCrystal lcd(12, 13, 4, 5, 6, 7);

unsigned int red = 0;
unsigned int green = 0;
unsigned int blue = 0;

void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);

  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);

  lcd.begin(16, 2);
}

void loop() {

  lcd.setCursor(0, 0);
  lcd.print("Color: ");
  lcd.print("#");
  if (red == 0){
    lcd.print("00");
  }
  else
  {
    lcd.print(red, HEX);  
  }
  if (green == 0){
    lcd.print("00");
  }
  else
  {
    lcd.print(green, HEX);  
  }
  if (blue == 0){
    lcd.print("00");
  }
  else
  {
    lcd.print(blue, HEX);  
  }

  lcd.setCursor(0,1);
  lcd.print("Light: ");
  
  if (!digitalRead(SW_pin))
  {
    red = 0;
    green = 0;
    blue = 0;
    lcd.print("OFF");
    
  }
  else
  {
    red = map(analogRead(X_pin), 0, 1023, 0, 255);
    green = map(analogRead(Y_pin), 0, 1023, 0, 255);
    blue = map(analogRead(X_pin)+analogRead(Y_pin), 0, 2047, 127, 0);
    lcd.print("ON ");
  }
  RGB_color(red, green, blue);
//  delayMicroseconds(250);
  
}

void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}
