// include the library code:
#include <LiquidCrystal.h>
#include "Battery.h"
#include "getVoltages.h"

// initialize the LCD library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
int donePin = 2;
int nextPin = 3;
bool done;
bool next;

const int ARRAYMAX = 10;
int lastIndex;
int displayIndex;
Battery Batteries[ARRAYMAX];
// Use one char and letter++?
char letters[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W','X', 'Y', 'Z'};
int state;

void setup() {
  Serial.begin(9600); 
  
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  pinMode(donePin, INPUT_PULLUP);  
  pinMode(nextPin, INPUT_PULLUP);  
  lastIndex = 0;
  displayIndex = 0;
  state = 0;
}

void loop() {
  
  // Buttons
  buttonHandler();

  // Display
  view();
}

void view(){
  
  if(state == 0){
    lcd.setCursor(1, 0);
    lcd.print("Welcome!" );
    lcd.setCursor(1, 1);
    lcd.print("Click Done..." );
  }
  else if(state == 1){
    lcd.setCursor(0, 0);
    lcd.print("Name = " + String(letters[lastIndex]) );
    double arr[4];
    double voltage = getVoltages(arr);
    lcd.setCursor(0,1);
    lcd.print(String(voltage) + " V");
    lcd.setCursor(11,1);
    lcd.print("Save?");
  }
  else if(state == 2){
    // Display current battery
    Battery thisBattery = Batteries[displayIndex];
    lcd.setCursor(0, 0);
    lcd.print("Name: " + thisBattery.getName() );
    lcd.setCursor(0,1);
    lcd.print(String(thisBattery.getTotal()) + "V");
    lcd.setCursor(9,1);
    lcd.print("Next ->");
  }
  else if(state == 3){
    lcd.setCursor(1, 0);
    lcd.print("Charging!" );
    lcd.setCursor(1, 1);
    lcd.print("Stuff" );
  }
  else if(state == 4){
    lcd.setCursor(1, 0);
    lcd.print("Finished!" );
    lcd.setCursor(1, 1);
    lcd.print("Restart?" );
  }
}

void buttonHandler(){
  // Done Button
  if ( digitalRead(donePin) == LOW && digitalRead(donePin) != done )
  {
    done = digitalRead(donePin);
    lcd.clear();
    doneHandler();
    delay(10);
  }
  else if (digitalRead(donePin) == HIGH && digitalRead(donePin) != done)
  {
    done = digitalRead(donePin);
    lcd.clear();
  }

  // Next Button
  if ( digitalRead(nextPin) == LOW && digitalRead(nextPin) != next )
  {
    next = digitalRead(nextPin);
    lcd.clear();
    nextHandler();
    delay(10);
  }
  else if (digitalRead(nextPin) == HIGH && digitalRead(nextPin) != next)
  {
    next = digitalRead(nextPin);
    lcd.clear();
  }
}

void doneHandler(){
  displayIndex = 0;
  if(state + 1 <= 4){ state++; }
  else{
    state = 0; 
    lastIndex = 0;
    displayIndex = 0;
  }
}

void nextHandler(){
  if (state == 1){
    if(lastIndex < ARRAYMAX){
      double cells[4];
      getVoltages(cells);
      addBattery(lastIndex, cells[0], cells[1], cells[2], cells[3]);
      popupMessage("Saved!", 1000);
    }
    else{
      popupMessage("Not Saved, Full!", 1000);
    }
  }
  else if(state == 2){
    if(displayIndex < lastIndex-1){displayIndex++;}
    else { displayIndex = 0; }
  }
}

void addBattery(int letterIndex, double Cell_1, double Cell_2 , double Cell_3, double Cell_4)
{
  Batteries[lastIndex] = Battery(letters[letterIndex], Cell_1, Cell_2, Cell_3, Cell_4);
  lastIndex++;
}

void popupMessage(String message, int delayMs){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(message);
  delay(delayMs);
  lcd.clear();
}




