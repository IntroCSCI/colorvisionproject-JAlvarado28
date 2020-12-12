Color Accuracy Project
## Description

V2.0 Updates
Pull the color values from the imported file .text provided by the programmer. These values should be within 0 and 255 (dec). Then it tells the user what colors are present, based off of what RGB value each color is mostly made up of, or blended with. Then tell the user what colors there are. Then the user is given the choice for a color input test in which it prints out two separate colors. Depending on the choice the user inputs, it will tell what type of vision they might have. The other option that is given to the user is to play around with the hex converter given the ranges that was provided as well as a list referenced to the types of color blindness. 

## Developer

Jesus Alvarado

## Example

To run the program, give the following commands:
There are 5 different options that the user is given from the interface. 
(C) takes the user to a color test where they are shown two sets of colors and is given feedback on the type of blindness they might have.
(O) gives the user the options to open a file that prints out a variables of the colors given 
(H) is a simple tool to convert the value from a limit in the ranges to a hex value
(L) prints out the array of types of blindness that the user is given for their color input test
(Q) this serves to end the loop 
```
g++ -std=c++11 *.cpp -o cvp; ./cvp
```

Here is an example of the program running:

```
 g++ -std=c++11 *.cpp -o cvp; ./cvp
Welcome to the Color Analyzer
=============================
Menu
----
(C)olor input test
(O)pen file
(H)ex converter
(L)ist of diseases
(Q)uit
l
This is the list of the different types of color blindness:
tritanopia
tritanomaly
deuteranomaly
protanomaly
protanopia
monochromacy
Menu
----
(C)olor input test
(O)pen file
(H)ex converter
(L)ist of diseases
(Q)uit
q
 
```

## C++ Guide

### Variables and Data Types

There are several variables that are being used in which are seperated by 4 categories. The int (lines, chars) are used to write out the file that is being open. This gives it a more clean appearance as well as being the source of the file being printed out. The string (file, color, input) are used to open the file, label the text=color, and input is the result of one of the user's action. These work to open the file as well as initialize our functions in the program. Fstream (reader) is where the files will be opened and printed out. The string (r, g, b) is where the user would input their actions which will give us an output back on the color that is related to it. This is achieved by using the vector (text) to find and print out the result the user is looking for. 
The new variables complement the ones from the previous deliverable as it does not stray off from the first. I gave it a sense of continuity with the addition of new arrays and vectors. The new variables are categorized depending on its function and location of the variable within the program. 

New Updates: Added more functions as well as more variables. This is set up inside the functions to reduce the clutterness in the main.cpp. One of the greatest improvements to my project yet was reducing the main to the minimum by using functions inside a menu type of function. This was idea the was brought up from our previous grocery list lab as well. 

```
char vision::chooseMenu(){
  char input;
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
  return input;
}  
```
The use of class (vision.cpp) made the program more organized and easier to read. 
### Input and Output

The input and output have been used appropriatedly to mainly focus on the user's input and responding with the output from the given file. An important part is where the user is asked to insert their RGB values in which is then set equal to the input variable in the program. Then with the given input, the text is then printed out such as "red=(255, 0, 0)".
For the second deliverale, this was brought up by giving the user the ability to interact with the colors and have them play with it as well. 

New update: There are several functions that ask for the users' input to either continue the loop or to decide on which function to use from the class. It became more user friendly which also limits the user from inputing a variable that was not ask or given. 
```
do{
  
    cout << "Menu\n----\n";
    cout << "(C)olor input test\n";
    cout << "(O)pen file\n";
    cout << "(H)ex converter\n";
    cout << "(L)ist of diseases\n";
    cout << "(Q)uit\n";
    
    cin >> input;
   
   cin.ignore();
   
  }while (input != 'O' && input != 'o' && input != 'L' && input != 'l' && input != 'C' && input !='c' && input != 'Q' && input != 'q' && input !='H' && input !='h');
  return input; 
```
### Decisions

The decision that I have put in my program is to be able to restart the loop without manually running the program again. I also added a condition in where the file was not inputed correctly by the user in which will responed with a response and a request from my first loop. More decisions will be added in the future deliverables especially when more files are given to be opened and actions to be used in the given file. 
I added more decisions into my program such as the boolean statement which helped withe a iteration from the previous deliverable. This gave the user the ability to interact and state that the information was false. As for other improvements, it was added onto the functions as it became even more interactive with certain return type functions.

New Update: More decision were made as well as fixing one of my functions as well. The function previously asked the users input then eiter skipped one statement or continued on without printing it out. This was improved by adding in a new function and reduced the amount of lines that it previously had. Other decisions were created, but it holds the same prupose as the color print function. 
```
 color_msg ="\u001b[0;34m This sentence has both colors:\u001b[0;32m blue and green.\n"; 
  disease = "trianopia.\n";
  check_eyes(color_msg,disease);
  
  color_msg= "\u001b[0;33m This setence has both colors:\u001b[0;31m yellow and red.\n";
  disease = "tritanomaly.\n ";
  check_eyes(color_msg, disease);
```
The result is that it prints out like this:
```
Continue with (Y)es or any other character for no.
 This sentence has both colors: blue and green.
y
You have regular vision.
 This setence has both colors: yellow and red.
y
You have regular vision.
 This sentence has both colors: red and green.
n
You might have deuteranomaly.
```

### Iteration

I used several iterations to have my functions running properly and orderly. For example, the first do... while loop is to give the user the decision to whether they want to run the program again by opening another or the same file for a different output. My for loop is limited in finding the text that the user is looking for when they input the color they had in mind. This is used to find one color within the 8 colors and values that are given. 
One of the iteration that I have added was from the function char color_Shown(String). The do while is meant for the user to continue the program even when a wrong input has been inserted.

New update: The majority of the newly created functions are using do while loops as well as for loops. This helps the user in running the program as well as making it more user friendly. If the user uses an input that is not included in the menu or the function itself, it loops the function again untill the user uses a correct variable or terminates it by input 'Q'. 

```
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
```

### File Input and Output

For my first deliverable, I only imported one file in which writes out each color and labels their values in the RGB category. More files will be added with the hex value to determine which values are invalid or close to a certain color in our file. 

For my second deliverable, I built upon from the previous deliverable in which only displayd the value of the color that were given. Now, it calculates the value into hex and it prints out several colors as a test for the user. This test then tells the user what type of color blindness they might have depending on their reaction. This is supported by the color values from the previous file in which allows the user to play with the value. In my final deliverable, I am planning to improve this portion by allowing the user to get feedback by displaying the color that they played around using the hex value. 

New update: This program was placed in a function in my class for better readability. 

### Arrays/vectors
I only used one array to print out the list of types of blindness that the user will be given. This list serves a purpose of informing the user of the types as well as differentiating the types with a function that is given later. The user is shown two sets of colors in which the input is used to serve what color they might not be able to see or differentiate from one color to another. Like green and red. 
```
void vision::ListOfBlindness(){
 cout << "This is the list of the different types of color blindness:\n";
  string types [6]={ "tritanopia", "tritanomaly", "deuteranomaly", "protanomaly", "protanopia", "monochromacy"};
  for (int i=0; i<=5; i++){
  cout << types[i]  << endl;
  }
```
### Functions
My project is runned by functions as I created an interface in which the user is given the choice of what they want to do. This interface is supported the functions created as a shortcut as well as making the main.cpp look as clean as possible. 
Here is an example of the interface: 
```
 g++ -std=c++11 *.cpp -o cvp; ./cvp
Welcome to the Color Analyzer
=============================
Menu
----
(C)olor input test
(O)pen file
(H)ex converter
(L)ist of diseases
(Q)uit
```
Inside this interface, lay several functions by the use of if conditions as well as a do while loop. The user is given a char variable in which they can run a function of there choice.
Here is how the do while interface works: 
```
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
```

### Classes
My class is what pieces everything together. It serves to make the main.cpp more cleaner and simpler by placing the function definitions on another cpp. This is under the vision.h where all the prototype and important member variables are placed. 
```
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
```
Without a class, the main.cpp would look cluttered and overwhelming for the user as well for a fellow programmer. The main.cpp is only used to call in the function with a new data type called vision Type. This is used before the function which calls the function that is within the class. 