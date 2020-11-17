#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#define RESET "\x1b[0m"
using namespace std;
//prototypes
string hexValue ( int, string );
char color_Shown(string);
int main()
{
  string r, g, b;
  int lines, chars;
  string file, color;
  fstream reader; 
  char choice;
  string input;
  int color_value;
  string hex_value;
  string typeOfBlindness;

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
      // function dispays various colors and their type of color blindness
      color_Shown(typeOfBlindness);
      //  this portion sets up the part to find the value in the file 
      cout << "Put in the value of the color that you see." <<endl;
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
      }
      if (found_color==false){
        cout << "Value is invalid" << endl;
      } 
    }
    // after finding th value, the user can play around with the hex converter
    hexValue (color_value, hex_value);
    // this creates a loop for opening the file and restarting the program
    if (!reader.is_open()){
      cout << "Could not open file." << endl;
    }
    cout << "Analyze another color (y/n)?" << endl;
    cin >> choice;
    cin.ignore();
    reader.close();
    
  }while( choice=='y');
  
return 0;
}
 //converts a value into a hex
string hexValue ( int color_value, string hex_value){
  cout << "Enter a value that ranges from 0 to 255." << endl;
  cout << "It will convert it into a hex value." << endl;
  cin >> color_value;
  
  if (color_value >= 0 && color_value <=255) {
    cout << color_value << endl;
    cout << hex << color_value << endl;
    cout << "Enter the hex value.\n";
    cin >> hex_value;
    
  }else{
    cout << "The value is not within the range of 0 to 255.\n";
  }
  return hex_value;
  }
  // prints color and asks for the user's input
  // it then ties a false statement with type of blindness
char color_Shown(string typeOfBlindness){
  cout << "This is the list of the different types of color blindness.\n";
  string types [6]={ "tritanopia", "tritanomaly", "deuteranomaly", "protanomaly", "protanopia", "normal"};
  for (int i=0; i<=5; i++){
    cout << types[i]  << endl;
    
  }
  cout << "Press 'y' to continue.\n";
  char color_Shown;
  char choice;
  
 do{
    cin >> choice;
    if (choice == 'y'){
     printf("\u001b[0;34m" "This sentence has both colors:" "\u001b[0;32m" "blue and green." RESET  "\n");
   }else if (choice == 'n'){
     cout << "You might have tritanopia.\n";}
    cin >> choice;
    if (choice == 'y'){
      printf("\u001b[0;33m" "This setence has both colors:" "\u001b[0;31m" "yellow and red." RESET  "\n");
   }else if(choice == 'n'){
     cout << "You might have tritanomaly.\n";}
    cin >> choice;
    if (choice == 'y'){
      printf ("\u001b[0;31m" "This sentence has both colors:" "\u001b[0;32m" "red and green." RESET "\n");
   }else if (choice == 'n') {
      cout << "You might have deuteranomaly.\n";}
    cin >> choice;  
   if (choice == 'y'){
     printf ("\u001b[0;31m" "This sentence has both colors:" "\u001b[0;32m" "red and green." RESET "\n");
    }else if (choice == 'n'){
      cout << "You might have protanomaly.\n";}
    cin >> choice;  
    if (choice == 'y'){
      printf ("\u001b[0;32m" "This sentence has both colors:" "\u001b[0;31m" "green and red." RESET "\n");
   }else if (choice == 'n'){
      cout << "You might have protanopia.\n";}
    cin >> choice;
   if (choice == 'y'){
      printf ("\u001b[0;36m" "This sentence has both colors:" "\u001b[0;35m" "cyan and magenta." RESET "\n");
   }else if (choice == 'n'){
      cout << "You have regular vision.";}
    cin >> choice;
    return choice;
 }while(choice != 'y' || choice!='n');
}



