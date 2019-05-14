#include <LiquidCrystal.h>
#define RIGHT 10
#define CENTER 9
#define LEFT 8

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

byte halfheartleft[8] = {
  B00110,
  B01111,
  B11111,
  B11111,
  B01111,
  B00111,
  B00011,
  B00001
};

byte halfheartright[8] = {
  B01100,
  B11110,
  B11111,
  B11111,
  B11110,
  B11100,
  B11000,
  B10000
};

byte halfsmilefaceright[8] = {
  B00000,
  B01100,
  B01100,
  B00000,
  B00001,
  B00010,
  B11100,
  B00000
};

byte halfsmilefaceleft[8] = {
  B00000,
  B00110,
  B00110,
  B00000,
  B10000,
  B01000,
  B00111,
  B00000
};

byte halfangryfaceleft[8] = {
  B10000,
  B01110,
  B00110,
  B00110,
  B00000,
  B00111,
  B01000,
  B00000
};

byte halfangryfaceright[8] = {
  B00001,
  B01110,
  B01100,
  B01100,
  B00000,
  B11100,
  B00010,
  B00000
};

byte halfskullleft[8] = {
  B01111,
  B01111,
  B01001,
  B01001,
  B01110,
  B01110,
  B00111,
  B00111
};

byte halfskullright[8] = {
  B11110,
  B11110,
  B10010,
  B10010,
  B01110,
  B01110,
  B11100,
  B11100
};

void setup() 
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(RIGHT, INPUT_PULLUP);
  pinMode(CENTER, INPUT_PULLUP);
  pinMode(LEFT, INPUT_PULLUP);
  lcd.createChar(0, halfheartleft);
  lcd.createChar(1, halfheartright);
  lcd.createChar(2, halfsmilefaceright);
  lcd.createChar(3, halfsmilefaceleft);
  lcd.createChar(4, halfangryfaceleft);
  lcd.createChar(5, halfangryfaceright);
  lcd.createChar(6, halfskullleft);
  lcd.createChar(7, halfskullright);
  lcd.write(byte(0));
  lcd.write(byte(1));  
}

void full_hearth(int x)
{
  lcd.setCursor(x,0);
  lcd.write(byte(1));
  lcd.setCursor(x-1,0);
  lcd.write(byte(0));
}

void full_health()
{
  for(int i = 16; i<10; i-2)
  {
    full_hearth(i);
  }
}

void loop() 
{
 full_health();
}
