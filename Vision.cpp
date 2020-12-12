#include "vision.h"
#include <string>
#include <iostream>
#define RESET "\x1b[0m"
#include <fstream> 

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::hex;
using std::fstream;
vision::vision(){
  
}

////////////////////////////////////////////////// Functions ///////////////////////////////////////////////////////////////////////////////

// hexValue is used to convert a value from the list of color value into hex
string vision:: hexValue(int color_value, string hex_value){
  
  cout << "Enter a value that ranges from 0 to 255." << endl;
  cout << "It will convert it into a hex value." << endl;
  cin >> color_value;
  
  if (color_value >= 0 && color_value <=255) {
    cout << color_value << endl;
    cout << hex << color_value << endl; // the 'hex' is what creates the value  
    cout << "Enter the hex value given.\n";
    cin >> hex_value;
    
  }else{
    cout << "The value is not within the range of 0 to 255.\n";
  }
  return hex_value;
} 

// it dispays both the colors and gives the user feedback on what type of color blindness they have ////////
// the function check_eyes is used for the conditions to reduce the clutterness/repetition of the same statements
char vision::color_Shown(string typeOfBlindness){
  char choice;
  //this portion is where the if else statements are found 
 
 do{
   // create a do while loop function that will repeat this set of questions 
   string color_msg;
   string disease;
    cout << "Continue with (Y)es or any other character for no.\n";
    
    color_msg ="\u001b[0;34m This sentence has both colors:\u001b[0;32m blue and green.\n"; 
    disease = "trianopia.\n";
    check_eyes(color_msg,disease);
    
    color_msg= "\u001b[0;33m This setence has both colors:\u001b[0;31m yellow and red.\n";
    disease = "tritanomaly.\n ";
    check_eyes(color_msg, disease);

    color_msg = "\u001b[0;31m This sentence has both colors:\u001b[0;32m red and green.\n";
    disease = "deuteranomaly.\n";
    check_eyes (color_msg,disease);
  
    color_msg ="\u001b[0;31m This sentence has\u001b[0;32m both colors:\u001b[0;31m red and green.\n";
    disease = "protanomaly.\n";
    check_eyes(color_msg, disease);
   
    color_msg= "\u001b[0;32m This sentence has both colors:\u001b[0;31m green and red.\n";
    disease = "protanomaly.\n";
    check_eyes(color_msg, disease);
    
    color_msg = "\u001b[0;36m This sentence has both colors:\u001b[0;35m cyan and magenta.\n";  
    disease = "monochromacy.\n";
    check_eyes( color_msg, disease);
   
  }while(choice == 'Q');
  return choice;
 
}

// it is used inside the function color_Shown repetitely /////////////////////////////////////////
void vision::check_eyes(string color_msg, string disease){
  char choice;
  printf ( "%s" ,color_msg.c_str()); // just set the " " with color to print
  printf (RESET); // this then resets the color back to white 
  
  cin >> choice; //decisions for the user
  if(choice == 'y' && 'Y'){
    cout << "You have regular vision.\n";
  }
  else{
    cout << "You might have " << disease;
  } 
}

//a straight forward menu used for the main.cpp /////////////////////////////////////////////
//this creates an interfaced with the functions tied to certain char variables
char vision::chooseMenu(){
  char input;
  do{
     // Menu input/output
    cout << "Menu\n----\n";
    cout << "(C)olor input test\n";
    cout << "(O)pen file\n";
    cout << "(H)ex converter\n";
    cout << "(L)ist of diseases\n";
    cout << "(Q)uit\n";
    
    cin >> input;
   
   cin.ignore();
   
  }while (input != 'O' && input != 'o' && input != 'L' && input != 'l' && input != 'C' && input !='c' && input != 'Q' && input != 'q' && input !='H' && input !='h');
  return input; //ends the loop 
}

// an array that displays my list of color blindness using a loop/////////////////////////
void vision::ListOfBlindness(){
   cout << "This is the list of the different types of color blindness:\n";
  string types [6]={ "tritanopia", "tritanomaly", "deuteranomaly", "protanomaly", "protanopia", "monochromacy"};
  for (int i=0; i<=5; i++){
    cout << types[i]  << endl;
  }
}

//opens the .txt file /////////////////////////////////////////////////////////////////////
void vision::fileReader(){
  string r, g, b;
  int lines, chars;
  string file, color;
  fstream reader; 
  char choices;
  string input;
 do{ 
    //this opens the file and prints out its contents
    cout << "Open file to view the color:\n";
    getline(cin,file);
    reader.open(file);
    vector <string> text;
    //opens the file color.txt
    if(reader.is_open()){
      chars=0;
      lines=0;
      while (getline(reader, color)){
        char a[color.size()];
        chars+=color.size();
        lines++;
        cout << "Color: " << color << endl;
        text.push_back (color);
      }
      
      //  this portion sets up the part to find the value in the file 
      cout << "Put in the value of the color that you want to see." <<endl;
      cin >> r;
      cin >> g;
      cin >> b;
      cout << "(" << r << ", " << g << ", " << b << ")" << endl;
      input = "("; 
      input += r;
      input += ", ";
      input += g;
      input += ", ";
      input += b;
      input += ")";
      // decisions/iterations 
      // locates the value in the function
      bool found_color=false;
      for (int i=0; i < (int)text.size(); i++ ){
        if(text[i].find(input) != -1){
          cout << text[i] << endl;
          i=(int)text.size();
          found_color=true;
        }
      } // if the user input a value that is not in the file
        // it will display that it is invalid
      if (found_color==false){
        cout << "Value is invalid" << endl;
      } 
    }
    
    // this creates a loop for opening the file and restarting the program
    if (!reader.is_open()){
      cout << "Could not open file." << endl;
    }
    cout << "Analyze another color (y/n)?" << endl;
    cin >> choices;
    cin.ignore();
    reader.close();
    
    //gives the user the choice to whether or not to repeat the loop or end it
  }while( choices=='y');
}