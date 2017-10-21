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
    char Name;
    double Cell_1;
    double Cell_2;
    double Cell_3;
    double Cell_4;
};

#endif
