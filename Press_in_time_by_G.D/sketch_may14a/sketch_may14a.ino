#include <LiquidCrystal.h>
#define RIGHT 10
#define CENTER 9
#define LEFT 8
int buttons[] = {RIGHT,CENTER,LEFT};
int randomPosition;
int positionX = 0;
int theresOrNot = -1;
bool smilingFace;
bool skull;
bool hearth;
int nHealth = 3;
int nPoint;
int y = 15;
int x = 1000;
float startGame;
float endGame;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

byte halfheartleft[8] = {
  B00110,
  B01111,
  B11111,
  B11111,
  B01111,
  B00111,
  B00011,
  B00001,
};

byte halfheartright[8] = {
  B01100,
  B11110,
  B11111,
  B11111,
  B11110,
  B11100,
  B11000,
  B10000,
};

byte halfsmilefaceright[8] = {
  B00000,
  B01100,
  B01100,
  B00000,
  B00001,
  B00010,
  B11100,
  B00000,
};

byte halfsmilefaceleft[8] = {
  B00000,
  B00110,
  B00110,
  B00000,
  B10000,
  B01000,
  B00111,
  B00000,
};

byte halfskullleft[8] = {
  B01111,
  B01111,
  B01001,
  B01001,
  B01110,
  B01110,
  B00111,
  B00101,
};

byte halfskullright[8] = {
  B11110,
  B11110,
  B10010,
  B10010,
  B01110,
  B01110,
  B11100,
  B10100
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
  lcd.createChar(4, halfskullleft);
  lcd.createChar(5, halfskullright);
  randomSeed(analogRead(0)); 
}

void loop() 
{
  introduction();
  set_level();
  give_health(nHealth);
  while(nHealth != 0)
  {
    press_in_time();
  }
  game_over();
}

void introduction()
{
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Press in time!");
  lcd.setCursor(5,1);
  lcd.print("by G.D.");
  delay(2000);
}

void give_health(int nHearth)
{
  lcd.clear();
  lcd.setCursor(7,0);
  lcd.print("HP:");
  int x = 15;
  int type = 1;
  for (int i = 0; i < (nHearth*2); i++)
  {
    lcd.setCursor(x,0);
    lcd.write(byte(type));
    x--;
    if(type == 1)
    {
      type = 0;
    }
    else
    {
      type = 1;
    }
  }
}

void set_level()
{
  bool choose = false;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("EASY NORMAL HARD");
  while(!choose)
  {
  if(digitalRead(LEFT) == LOW)
  {
    choose = true;
    x = 1000;
    lcd.clear();
    lcd.setCursor(3,0);
    lcd.print("EASY MODE!");
    delay(1000);
    lcd.clear();
    lcd.setCursor(6,0);
    lcd.print("3...");
    delay(1000);
    lcd.setCursor(6,0);
    lcd.print("2...");
    delay(1000);
    lcd.setCursor(6,0);
    lcd.print("1...");
    delay(1000);
  }
  if(digitalRead(CENTER) == LOW)
  {
    choose = true;
    x = 750;
    lcd.clear();
    lcd.setCursor(2,1);
    lcd.print("NORMAL MODE!");
    delay(1000);
    lcd.clear();
    lcd.setCursor(6,0);
    lcd.print("3...");
    delay(1000);
    lcd.setCursor(6,0);
    lcd.print("2...");
    delay(1000);
    lcd.setCursor(6,0);
    lcd.print("1...");
    delay(1000);
  }
  if(digitalRead(RIGHT) == LOW)
  {
    choose = true;
    x = 500;
    lcd.clear();
    lcd.setCursor(3,1);
    lcd.print("HARD MODE!");
    delay(1000);
    lcd.clear();
    lcd.setCursor(6,0);
    lcd.print("3...");
    delay(1000);
    lcd.setCursor(6,0);
    lcd.print("2...");
    delay(1000);
    lcd.setCursor(6,0);
    lcd.print("1...");
    delay(1000);
  }
  }
}
void  press_in_time()
{
  random_position();
  if(digitalRead(RIGHT) == LOW || digitalRead(CENTER) == LOW || digitalRead(LEFT) == LOW)
  {
    if (nHealth > 0 && theresOrNot == 0)
    {
      nHealth--;
      give_health(nHealth);
      nPoint -= 10;
      give_points();
    }
  }
  else if((digitalRead(LEFT) == LOW) && (theresOrNot == 1) && (positionX == 1))
  {
    if(smilingFace = true)
    {
    if (nHealth > 0)
    {
      nHealth--;
      give_health(nHealth);
      nPoint -= 10;
      give_points();
    }
    }
    else if(hearth = true)
    {
      if (nHealth < 3)
      {
        nHealth++;
        give_health(nHealth);
      }
    }
    else if(skull = true)
    {
      nPoint += 10;
      give_points();
    }
  }
    else if((digitalRead(CENTER) == LOW) && (theresOrNot = 1) && (positionX = 4))
  {
    if(smilingFace = true)
    {   
    if (nHealth > 0)
    {
      nHealth--;
      give_health(nHealth);
      nPoint -= 10;
      give_points();
    }
    }
    else if(hearth = true)
    {
      if (nHealth < 3)
      {
        nHealth++;
        give_health(nHealth);
      }
    }
    else if(skull = true)
    {
       nPoint += 10;
       give_points();
    }
  }
      else if((digitalRead(RIGHT) == LOW) && (theresOrNot = 1) && (positionX = 7))
  {
    if(smilingFace = true)
    {
    if (nHealth > 0)
    {
      nHealth--;
      give_health(nHealth);
      nPoint -= 10;
      give_points();
    }
    }
    else if(hearth = true)
    {
      if (nHealth < 3)
      {
        nHealth++;
        give_health(nHealth);
      }
    }
    else if(skull = true)
    {
      nPoint += 10;
      give_points();
    }
  }
}

void random_char(int positionChar)
{
  int randomChar = random(0,101);
  lcd.setCursor(0,1);
  lcd.print("|");
  lcd.setCursor(3,1);
  lcd.print("|");
  lcd.setCursor(6,1);
  lcd.print("|");
  lcd.setCursor(9,1);
  lcd.print("|");
  if((randomChar >= 0) && (randomChar <= 20))
  {
    bool smilingFace = false;
    bool skull = false;
    bool hearth = true;
    lcd.setCursor(positionChar,1);
    lcd.write(byte(0));
    lcd.setCursor(positionChar+1,1);
    lcd.write(byte(1));
    delay(x);
    lcd.setCursor(positionChar,1);
    lcd.print(" ");
    lcd.setCursor(positionChar+1,1);
    lcd.print(" ");
  }
  else if((randomChar > 20) && (randomChar <= 50))
  {
    bool smilingFace = true;
    bool skull = false;
    bool hearth = false;
    lcd.setCursor(positionChar,1);
    lcd.write(byte(3));
    lcd.setCursor(positionChar+1,1);
    lcd.write(byte(2));
    delay(x);
     lcd.setCursor(positionChar,1);
    lcd.print(" ");
    lcd.setCursor(positionChar+1,1);
    lcd.print(" ");
  }
  else if((randomChar > 50) && (randomChar <= 100))
  {
    bool smilingFace = false;
    bool skull = true;
    bool hearth = false;
    lcd.setCursor(positionChar,1);
    lcd.write(byte(4));
    lcd.setCursor(positionChar+1,1);
    lcd.write(byte(5));
    delay(x);
    lcd.setCursor(positionChar,1);
    lcd.print(" ");
    lcd.setCursor(positionChar+1,1);
    lcd.print(" ");
  }
}

void random_position()
{
  randomPosition = random(0,3);
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

void give_points()
{
  lcd.setCursor(11,1);
  lcd.print("NP:");
  lcd.setCursor(14,1);
  lcd.print(String(nPoint));
}

void game_over()
{
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("GAME");
  lcd.setCursor(1,1);
  lcd.print("OVER");
  delay(2000);
  lcd.clear();
  endGame = millis();
  double gameTime = (endGame - startGame) / 1000;
  lcd.setCursor(1,0);
  lcd.print("Time:" + String(gameTime) + " sec");
  lcd.setCursor(1,1);
  lcd.print("Points:" + String(nPoint));
}


