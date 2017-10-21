#include "Battery.h"

Battery::Battery()
{
  Name = " ";
  Cell_1 = 0;
  Cell_2 = 0;
  Cell_3 = 0;
  Cell_4 = 0;
}

Battery::Battery(char newName, double newCell_1, double newCell_2 , double newCell_3, double newCell_4)
{
  Name = newName;
  Cell_1 = newCell_1;
  Cell_2 = newCell_2;
  Cell_3 = newCell_3;
  Cell_4 = newCell_4;
}

double Battery::getTotal(){
  return Cell_1 + Cell_2 + Cell_3 + Cell_4;
  
}
String Battery::getName(){
  return String(Name);
}

