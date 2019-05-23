#include <LiquidCrystal.h>
#define RIGHT 10
#define CENTER 9
#define LEFT 8
bool correct = false;
int heartsToTakeAway = 0;
int heartsToAdd = 0;
int i = 10;
int positionX = 0;
int theresOrNot = -1;
bool smilingFace;
bool angryFace;
bool hearth;
int nHealth;
int nPoint;

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
  randomSeed(analogRead(0)); 
}

void loop() 
{
 full_health();
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
    nHealth = 3; 
    full_hearth(i);
    delay(500);
  }
}

void remove_health(int hearts)
{
  int nHearth = 0;
  while(nHearth = hearts)
  {
    lcd.setCursor(i,0);
    lcd.clear();
    lcd.setCursor(i-1,0);
    lcd.clear();
    delay(500);
    nHearth++;
    i+2;
  }
}

void add_health(int hearts)
{
  int nHearth = 0;
  while(nHearth = hearts)
  {
    lcd.setCursor(i-1,0);
    lcd.write(byte(1));
    lcd.setCursor(i-2,0);
    lcd.write(byte(0));
    delay(500);
    nHearth++;
    i-2;
  }
}

void add_or_remove_health(bool correct)
{
  if(correct = false)
  {
    nHealth --;
    heartsToTakeAway++;
    remove_health(heartsToTakeAway);
  }
  else if (correct = true)
  {
    nHealth ++;
    heartsToAdd++;
    add_health(heartsToAdd);
  }
}

void random_char(int positionChar)
{
  int randomChar = random(0,101);
  if((randomChar >= 0) && (randomChar <= 20))
  {
    bool smilingFace = false;
    bool angryFace = false;
    bool hearth = true;
    lcd.setCursor(positionChar,1);
    lcd.write(byte(0));
    lcd.setCursor(positionChar+1,1);
    lcd.write(byte(1));
  }
  else if((randomChar > 20) && (randomChar <= 50))
  {
    bool smilingFace = true;
    bool angryFace = false;
    bool hearth = false;
    lcd.setCursor(positionChar,1);
    lcd.write(byte(3));
    lcd.setCursor(positionChar+1,1);
    lcd.write(byte(2));
  }
  else if((randomChar > 50) && (randomChar <= 100))
  {
    bool smilingFace = false;
    bool angryFace = true;
    bool hearth = false;
    lcd.setCursor(positionChar,1);
    lcd.write(byte(4));
    lcd.setCursor(positionChar+1,1);
    lcd.write(byte(5));
  }
}

void random_position()
{
  int randomPosition = random(0,3);
  theresOrNot = 0;
   if(randomPosition == 0)
  {
    positionX = 1;
    random_char(positionX);
    theresOrNot = 1;
  }
  else if(randomPosition == 1)
  {
    positionX = 4;
    random_char(positionX);
    theresOrNot = 1;
  }
  else if(randomPosition == 2)
  {
    positionX = 7;
    random_char(positionX);
    theresOrNot = 1;
  }
}

void  press_in_time()
{
  if(digitalRead(RIGHT) == LOW || digitalRead(CENTER) == LOW || digitalRead(LEFT) == LOW && theresOrNot = 0)
  {
    if (nHealth > 0)
    {
      add_or_remove_health(false);
    }
    else{}
    nPoint -= 10;
  }
  else if((theresOrNot = 1) && (positionX = 1) && (digitalRead(LEFT) == LOW))
  {
    if(smilingFace = true)
    {
    if (nHealth > 0)
    {
      add_or_remove_health(false);
    }
    else{}
    nPoint -= 10;
    }
    else if(hearth = true)
    {
      if (nHealth < 3)
      {
        add_or_remove_health(true);
      }
      else{}
    }
    else if(angryFace = true)
    {
      nPoint += 10;
    }
  }
    else if((theresOrNot = 1) && (positionX = 4) && (digitalRead(CENTER) == LOW))
  {
    if(smilingFace = true)
    {   
    if (nHealth > 0)
    {
      add_or_remove_health(false);
    }
    else{}
    nPoint -= 10;
    }
    else if(hearth = true)
    {
      if (nHealth < 3)
      {
        add_or_remove_health(true);
      }
      else
      {}
    }
    else if(angryFace = true)
    {
       nPoint += 10;
    }
  }
      else if((theresOrNot = 1) && (positionX = 7) && (digitalRead(RIGHT) == LOW))
  {
    if(smilingFace = true)
    {
    if (nHealth > 0)
    {
      add_or_remove_health(false);
    }
    else{}
    nPoint -= 10;
    }
    else if(hearth = true)
    {
      if (nHealth < 3)
      {
        add_or_remove_health(true);
      }
      else
      {}
    }
    else if(angryFace = true)
    {
      nPoint += 10;
    }
  }
}

