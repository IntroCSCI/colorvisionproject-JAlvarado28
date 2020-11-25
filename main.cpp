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
  //inputs
  string r, g, b;
  int lines, chars;
  string file, color;
  fstream reader; 
  char choices;
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
      }
      if (found_color==false){
        cout << "Value is invalid" << endl;
      } 
    }
    // after finding the value, the user can play around with the hex converter
    hexValue (color_value, hex_value);
    // this creates a loop for opening the file and restarting the program
    if (!reader.is_open()){
      cout << "Could not open file." << endl;
    }
    cout << "Analyze another color (y/n)?" << endl;
    cin >> choices;
    cin.ignore();
    reader.close();
    
  }while( choices=='y');
  
return 0;
}
 //converts a value into a hex
 //int color_value will be set up for next delivereable inclucing a vector
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
  string types [6]={ "tritanopia", "tritanomaly", "deuteranomaly", "protanomaly", "protanopia", "monochromacy"};
  for (int i=0; i<=5; i++){
    cout << types[i]  << endl;
    
  }
  char choice;
  //this portion is where the if else statements are found 
  // it dispays both the colors and gives the user feedback on what type of color blindness they have
 do{
    printf("\u001b[0;34m" "This sentence has both colors: " "\u001b[0;32m" "blue and green." RESET  "\n");
    cout << "(Y)es or (N)o\n";
    cin >> choice;
    if (choice == 'y' || choice == 'Y'){
     cout << "You have regular visoin.\n";
   }else if (choice == 'n' || choice == 'N'){
     cout << "You might have tritanopia.\n";}
  
    printf("\u001b[0;33m" "This setence has both colors: " "\u001b[0;31m" "yellow and red." RESET  "\n");
    cin >> choice;
    if (choice == 'y' || choice == 'Y'){
      cout << "You have regular vision.\n";
   }else if(choice == 'n' || choice == 'N'){
     cout << "You might have tritanomaly.\n";}

    printf ("\u001b[0;31m" "This sentence has both colors: " "\u001b[0;32m" "red and green." RESET "\n");
    cin >> choice;
    if (choice == 'y' || choice == 'Y'){
      cout << "You have regular vision.\n";
   }else if (choice == 'n' || choice == 'N') {
      cout << "You might have deuteranomaly.\n";}

    printf ("\u001b[0;31m" "This sentence has" "\u001b[0;32m" " both colors: " "\u001b[0;31m" "red and green." RESET "\n");
    cin >> choice;  
   if (choice == 'y' || choice == 'Y'){
     cout << "You have regular vision.\n";
    }else if (choice == 'n' || choice == 'N'){
      cout << "You might have protanomaly.\n";}

    printf ("\u001b[0;32m" "This sentence has both colors: " "\u001b[0;31m" "green and red." RESET "\n");
    cin >> choice;  
    if (choice == 'y' || choice == 'Y'){
      cout << "You have regular vision.\n";
   }else if (choice == 'n' || choice == 'N'){
      cout << "You might have protanopia.\n";}

    printf ("\u001b[0;36m" "This sentence has both colors: " "\u001b[0;35m" "cyan and magenta." RESET "\n");  
    cin >> choice;
   if (choice == 'y' || choice == 'Y'){
      cout << "You have regular vision.\n";
   }else if (choice == 'n' || choice == 'N'){
      cout << "You might have  monochromacy.\n";}
  }while(choice != 'y' && choice != 'Y' && choice != 'N' && choice != 'n');
  return choice;
 
}



