#ifndef Battery_h
#define Battery_h

#include "Arduino.h"

class Battery
{
  public:
    Battery();
    Battery(char newName, double newCell_1, double newCell_2 , double newCell_3, double newCell_4);
    double getTotal();
    String getName();
  private:
    char thisName;
    double cell_1;
    double cell_2;
    double cell_3;
    double cell_4;
    double total;
};

#endif
