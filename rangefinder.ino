#include <LiquidCrystal.h>

int trig = A1;
int echo = A0;

double duration;
double cm_dist;

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

void setup()
{
  Serial.begin(9600);
  
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);

  lcd.begin(16, 2);
  lcd.setCursor(0,0);          
  lcd.print("| RANGE FINDER |");
  lcd.setCursor(0,1);
  lcd.print("|==============|");
  
  delay(1500);
}

double getDistance()
{
  digitalWrite(trig, HIGH);
  delayMicroseconds(2);
  digitalWrite(trig, LOW);
  delayMicroseconds(10);
  duration = pulseIn(echo, HIGH);  
  
  double distance = (duration*0.0343)/2;
  
  return distance;
}

void printDistance(double distance)
{
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print(distance);
  lcd.print(" cm"); 
}

void loop()
{
  cm_dist = getDistance();
  //Serial.println(cm_dist);
  printDistance(cm_dist);
  delay(500);
}
