#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main()
{
  string r, g, b;
  int lines, chars;
  string file, color;
  fstream reader; 
  char choice;
  string input;

  do{ 

    cout << "Open file to view the color:\n";
    getline(cin,file);
    reader.open(file);
    vector <string> text;
  
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
    
      for (int i=0; i < (int)text.size(); i++ ){
        if(text[i].find(input) != -1){
          cout << text[i] << endl;
          i=(int)text.size();
          
        }
        
      }
       
    }
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
 