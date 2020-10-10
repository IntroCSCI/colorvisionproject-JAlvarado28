Color Accuracy Project
## Description

Pull the color values from the imported website code provided by the user. These values should be within 0 and 255 (dec). Then tell the user what colors are present, based off of what RGB value each color is mostly made up of, or blended with. Then tell the user what colors there are.

## Developer

Jesus Alvarado

## Example

To run the program, give the following commands:

```
g++ --std=c++11 main.cpp -o cvp
./cvp
```

Here is an example of the program running:

```
cout << "Analyze another color (y/n)?" << endl; 
cin >> choice;
cin.ignore();
reader.close();
```

## C++ Guide

### Variables and Data Types

There are several variables that are being used in which are seperated by 4 categories. The int (lines, chars) are used to write out the file that is being open. This gives it a more clean appearance as well as being the source of the file being printed out. The string (file, color, input) are used to open the file, label the text=color, and input is the result of one of the user's action. These work to open the file as well as initialize our functions in the program. Fstream (reader) is where the files will be opened and printed out. The string (r, g, b) is where the user would input their actions which will give us an output back on the color that is related to it. This is achieved by using the vector (text) to find and print out the result the user is looking for. 

### Input and Output

The input and output have been used appropriatedly to mainly focus on the user's input and responding with the output from the given file. An important part is where the user is asked to insert their RGB values in which is then set equal to the input variable in the program. Then with the given input, the text is then printed out such as "red=(255, 0, 0)".


### Decisions

The decision that I have put in my program is to be able to restart the loop without manually running the program again. I also added a condition in where the file was not inputed correctly by the user in which will responed with a response and a request from my first loop. More decisions will be added in the future deliverables especially when more files are given to be opened and actions to be used in the given file. 


### Iteration

I used several iterations to have my functions running properly and orderly. For example, the first do... while loop is to give the user the decision to whether they want to run the program again by opening another or the same file for a different output. My for loop is limited in finding the text that the user is looking for when they input the color they had in mind. This is used to find one color within the 8 colors and values that are given. 


### File Input and Output

For my first deliverable, I only imported one file in which writes out each color and labels their values in the RGB category. More files will be added with the hex value to determine which values are invalid or close to a certain color in our file. 
