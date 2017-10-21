// include the library code:
#include <LiquidCrystal.h>
#include "Battery.h"
#include "function.h"

// initialize the LCD library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
int buttonApin = 2;
int buttonBpin = 3;
bool buttonAValue;
bool buttonBValue;
int analogPin0 = 0;

const int ARRAYMAX = 10;
int lastIndex;
int displayIndex;
double cells[4];
Battery Batteries[ARRAYMAX];

void setup() {
  Serial.begin(9600); 
  
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  pinMode(buttonApin, INPUT_PULLUP);  
  pinMode(buttonBpin, INPUT_PULLUP);  
  lastIndex = 0;
  displayIndex = 0;

  addBattery('A', 5, 5, 5, 5);
  addBattery('B', 2, 2, 2, 2);
  addBattery('C', 4, 2, 2, 5);
}

void loop() {
  
  // Buttons
  buttonHandler();

  // Display
  displayBattery();
  int val = analogRead(analogPin0);    // read the input pin
  lcd.setCursor(0,1);
  lcd.print(String(val));
}

void addBattery(char Name, double Cell_1, double Cell_2 , double Cell_3, double Cell_4)
{
  Batteries[lastIndex] = Battery(Name, Cell_1, Cell_2, Cell_3, Cell_4);
  lastIndex++;
}

void displayBattery(){
  
  test(cells);
  Batteries[0] = Battery('A', cells[0], cells[1], cells[2], cells[3]);
  
  Battery thisBattery = Batteries[displayIndex];
  lcd.setCursor(0, 0);
  lcd.print(thisBattery.getName() );
  lcd.setCursor(1,0);
  lcd.print(" = " + String(thisBattery.getTotal()));
}


void buttonHandler(){
 // Button A
  if ( digitalRead(buttonApin) == LOW && digitalRead(buttonApin) != buttonAValue )
  {
    buttonAValue = digitalRead(buttonApin);
    lcd.clear();
    if(displayIndex + 1 < lastIndex){displayIndex++;}
  }
  else if (digitalRead(buttonApin) == HIGH && digitalRead(buttonApin) != buttonAValue)
  {
    buttonAValue = digitalRead(buttonApin);
    lcd.clear();
  }

  // Button B
  if ( digitalRead(buttonBpin) == LOW && digitalRead(buttonBpin) != buttonBValue )
  {
    buttonBValue = digitalRead(buttonBpin);
    lcd.clear();
    if(displayIndex - 1 >= 0){displayIndex--;}
  }
  else if (digitalRead(buttonBpin) == HIGH && digitalRead(buttonBpin) != buttonBValue)
  {
    buttonBValue = digitalRead(buttonBpin);
    lcd.clear();
  }
}

