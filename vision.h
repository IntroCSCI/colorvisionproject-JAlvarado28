#ifndef VISION_H
#define VISION_H
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class vision{
 private:
   int color_value;
   string hex_value;
   string typeOfBlindness;
   
 public:
    vision();
    string hexValue ( int, string ); // a little gimmick in where the user can play around with the hex converter
    char color_Shown(string); // this is for (C), printing out the color/ requesting user input
    void check_eyes(string color_msg, string disease); // used for function color_shown to reduce the lines in program
    char chooseMenu(); // my menu 
    void ListOfBlindness(); // this is for (L), printing the array of diseases
    void fileReader(); // this is for (O), opening/printing the file 
};


#endif