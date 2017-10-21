#include "Battery.h"

Battery::Battery()
{
  thisName = " ";
  cell_1 = 0;
  cell_2 = 0;
  cell_3 = 0;
  cell_4 = 0;
}

Battery::Battery(char newName, double newCell_1, double newCell_2 , double newCell_3, double newCell_4)
{
  thisName = newName;
  cell_1 = newCell_1;
  cell_2 = newCell_2;
  cell_3 = newCell_3;
  cell_4 = newCell_4;
  total = Cell_1 + Cell_2 + Cell_3 + Cell_4;
}

double Battery::getTotal(){
  return total;
  
}
String Battery::getName(){
  return String(thisName);
}

