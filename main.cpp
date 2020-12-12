#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "vision.h"
#define RESET "\x1b[0m"
using namespace std;


int main()
{
  
  vision Type; // object for vision
  char choices;
  int color_value;
  string hex_value;
  string typeOfBlindness;
  

  cout << "Welcome to the Color Analyzer\n";
  cout << "=============================\n";
  do{
    choices = Type.chooseMenu();
  
     if (choices == 'C' || choices == 'c'){
      Type.color_Shown(typeOfBlindness);
    }
    if (choices == 'O' || choices == 'o'){
      Type.fileReader();
    }
    if(choices == 'H' || choices == 'h'){
      Type.hexValue( color_value,  hex_value);
    }
    if (choices == 'L' || choices == 'l'){
      Type.ListOfBlindness();
    }
  }while(choices != 'q' && choices !='Q');

return 0;
}