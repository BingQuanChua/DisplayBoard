/**********|**********|**********|
Course: Programming Fundamentals
Year: 2019/2020 Trimester 1
Name: Chua Bing Quan
**********|**********|**********/

#include <iostream>
#include <string>
#include <fstream>
//#include <cctype>
using namespace std;

void delay(int R);   // Function that performs delay when called
void clearScreen();  // Function that performs system ("cls")
void movement(int x, int y, int X, int Y);  // Function that performs the movement of text based on user input details
void displayMessage(char C, int x, int y, int X, int Y);  // Function that display the text characters into the displayBoard array
void rotate90deg(int x, int y);    // Function that performs 90 degree rotation to the text when called
void rotateN90deg(int x, int y);   // Function that performs -90 degree rotation to the text when called
void mirror(int x, int y);         // Function that performs mirror effect to the text when called
bool wrapAround(string wrap);           // Function to convert user's choice of wrap-around effect to boolean for switch function
int stringToInt(string direction);      // Function to convert user's choice of direction to integer for switch function
int stringRotateToInt(string rotation); // Function to convert user's choice of rotation to integer for switch function
void direct(int c);    // Function that prints the choice of direction in the user interface
void wr(int w);        // Function that prints the choice of wrap-around effect in the user interface
void ro(int r);        // Function that prints the choice of rotation in the user interface

char displayBoard[500][500];  // Declaring a very huge 2D array
char drawingChar;
string message;
string direction,
       wrap,
       rotation;
int speed;
int times;
char inception = 'N';

int main()
{
    int rows, columns,
        boardRows, boardColumns;
    string filename;

    cout << "      Input Format: " << endl;
    cout << "  -Drawing Character" << endl;
    cout << "  -Speed of Refresh Cycle, from 1 to 10, with 10 being the fastest" << endl;
    cout << "  -Phrase, maximum 25 characters" << endl;
    cout << "  -Anchor Point, rows and columns" << endl;
    cout << "  -Board Size,   rows and columns" << endl;
    cout << "  -Direction   (lr: right, rl: left, ud: down, du: up, st: stationary)" << endl;
    cout << "  -Wrap-Around (wr: wrap-around, no: no wrap-around)" << endl;
    cout << "  -Rotation    (rot90: rotate 90 degrees, rot-90: rotate -90 degrees, mr: mirror, no: no rotation)" << endl << endl;
    cout << "Please enter a file name to run the program." << endl;
    cout << " example : 'sample.txt' " << endl;
    cout << "Enter 'E' if you want to exit the program." << endl << endl;
    cout << "File Name => ";
    cin >> filename;

    while(!(filename == "E"|| filename == "e"))
    {
        ifstream inputFile;
        inputFile.open(filename);
        inputFile >> drawingChar;
        inputFile >> speed;
        inputFile.ignore();                        // This line ignores the '\n' behind the speed
        getline(inputFile,message,'\n');           // This line ignores '\n' in the message
        inputFile >> rows >> columns;
        inputFile >> boardRows >> boardColumns;
        inputFile >> direction >> wrap >> rotation;

        clearScreen();
	    for(int i = 0; i<2; i++)
    	{
    	    cout << endl << "   Reading." << endl;
	     	clearScreen();
		    cout << endl << "   Reading.." << endl;
		    clearScreen();
    		cout << endl << "   Reading..." << endl;
	     	clearScreen();
		    cout << endl << "   Reading...." << endl;
		    clearScreen();
    	}

	    if(!inputFile.fail()) // File successfully opened, checking errors
        {
            int error = 0;
            cout << "##################################" << endl;
            cout << "          ERROR DETECTED          " << endl;
            cout << "##################################" << endl << endl;
            if(!isprint(drawingChar))
            {
                cout << "ERROR!: You've input an unprintable drawing character" << endl;
                cout << "        Please try using another drawing character." << endl;
                error +=1;
            }
            if(speed < 1 || speed > 10)
            {
                cout << "ERROR!: Refresh cycle is only from 1 to 10." << endl;
                cout << "        Your input: " << speed << endl;
                error +=1;
            }
            if(message.size()>25) // Message would be at most 25 characters
            {
                cout << "ERROR!: The message should not be more than 25 characters." << endl;
                cout << "        Please input a shorter message. Current length: " << message.size() << endl;
                error +=1;
            }
            if(boardRows > 39 || boardColumns > 170) // The maximum size of the display board that can fits into full-screen perfectly
            {
                cout << "ERROR!: Board size too large. Recommended largest size: 39 and 170" << endl;
                cout << "        One or more of your input is too large. Your input: " << boardRows << " and " << boardColumns << endl;
                error +=1;
            }
            if(boardRows < 20 || boardColumns < 40)
            {
                cout << "ERROR!: Board size too small, should be at least 20 and 40" << endl;
                cout << "        One or more of your input is too small. Your input: " << boardRows << " and " << boardColumns << endl;
                error +=1;
            }
            if(direction != "lr" && direction != "rl" && direction != "ud" && direction != "du" && direction != "st")
            {
                cout << "ERROR!: The program does not accept your direction input." << endl;
                cout << "        Only 'lr', 'rl', 'ud', 'du' or 'st' is accepted." << endl;
                error +=1;
            }
            if(wrap != "wr" && wrap != "no")
            {
                cout << "ERROR!: The program does not accept your wrap-around input." << endl;
                cout << "        Only 'wr' or 'no' is accepted." << endl;
                error +=1;
            }
            if(rotation != "rot90" && rotation != "rot-90" && rotation != "mr" && rotation != "no")
            {
                cout << "ERROR!: The program does not accept your rotation input." << endl;
                cout << "        Only 'rot90', 'rot-90', 'mr' or 'no' is accepted." << endl;
                error +=1;
            }

            if(error == 0) // If no error found
            {
                clearScreen();
                cout << "##################################" << endl;
                cout << "          INPUT SUCCESS!          " << endl;
                cout << "##################################" << endl << endl;
                cout << "     File Name     : " << filename << endl;
                cout << "      Message      : " << message << endl;
                cout << " Drawing Character : " << drawingChar << endl;
                cout << "   Rows & Columns  : " << rows << " " << columns << endl;
	            cout << "   Size of Board   : " << boardRows << " " << boardColumns << endl;
	            cout << "       Speed       : " << speed << endl;
	            cout << "     Direction     : ";  direct(stringToInt(direction));
	            cout << "    Wrap-Around    : ";  wr(wrapAround(wrap));
	            cout << "     Rotation      : ";  ro(stringRotateToInt(rotation));
                cout << endl;
                inputFile.close();

                cout << "Would you like to have 'Inception' Effect? (Y/N): ";
                cin >> inception;
                while(toupper(inception) != 'Y' && toupper(inception) != 'N')
                {
                    cout << "                 *Please answer only with Y or N: ";
                    cin >> inception;
                } // while loop in case user inputs anything other than Y or N

                cout << "How many time steps would you like?" << endl;
                cout << "                  time steps => ";
                cin >> times;
                while(times <= 0)
                {
                    cout << "Time steps must be greater than 0!" << endl;
                    cout << "                 *time steps => ";
	                cin >> times;
                } // while loop in case user inputs time step smaller or equal to zero
                clearScreen();
                movement(columns+200, rows+200, boardColumns, boardRows);
            }
            else // Error message pops up if error of input is detected
                {
                    cout << endl << "Your input has " << error << " error(s)." << endl;
                    cout << "Please correct your input and try to run the program again." << endl << endl;
                }
        }

        else // If the file name given is not found
        {
            cout << "##################################" << endl;
            cout << "          Input FAILED :(         " << endl;
            cout << "##################################" << endl << endl;
            cout << "File name is not found. Please check your file name and location." << endl << endl;
        }

        cout << "Please enter file name to run another program." << endl;  // Asks user for another round
        cout << " example : 'sample.txt' " << endl;
        cout << "Enter 'E' if you want to exit the program." << endl << endl;
        cout << "File Name => ";
        cin >> filename;

    }
    return 0;

}

void delay(int R)
{
    for(int i=0; i < 300000000/R; i++) // Input R is speed, the greater the value of R, the shorter the delayed period
    {}
}

void clearScreen()
{
    system ("cls");
}

void movement(int x, int y, int X, int Y) // x is the column and y is the row, just like the coordinates
{                                         // X is the x-axis and Y is the y-axis, just like the a plane
    int length = message.size()*6;
    switch(stringToInt(direction))
    {
        case 1:
        for(int left=0; left < times; left++)  //rl: right to left
        {
            displayMessage(drawingChar, x, y, X, Y);
            delay(speed);
            clearScreen();
            x-=1;

            if(wrapAround(wrap))                     // There are 4 cases for wrap-around:
            {                                        //     1. The user decides not to have wrap-around
                if(rotation == "rot90")              //     2. Wrapping-around while the text is rotated 90 degrees
                {                                    //     3. Wrapping-around while the text is rotated -90 degrees
                    if(x < 200)                      //     4. Wrapping-around (normal & mirrored)
                    {
                        x = X+200+6;
                    }
                }
                else
                    if(rotation == "rot-90")
                    {
                        if(x < 200-6)
                        {
                            x = X+200;
                        }
                    }
                    else
                    {
                        if(x < 200-length)
                        {
                            x = X+200;
                        }
                    }
            }
        }
        break;

        case 2:
        for(int right=0; right < times; right++)  //lr: left to right
        {
            displayMessage(drawingChar, x, y, X, Y);
            delay(speed);
            clearScreen();
            x+=1;

            if(wrapAround(wrap))
            {
                if(rotation == "rot90")
                {
                    if(x > X+200+6)
                    {
                        x = 200;
                    }
                }
                else
                    if(rotation == "rot-90")
                    {
                        if(x > X+200)
                        {
                            x = 200-6;
                        }
                    }
                    else
                    {
                        if(x > X+200)
                        {
                            x = 200-length;
                        }
                    }
            }
        }
        break;

        case 3:
        for(int up=0; up < times; up++)  //du: down to up
        {
            displayMessage(drawingChar, x, y, X, Y);
            delay(speed);
            clearScreen();
            y+=1;

            if(wrapAround(wrap))
            {
                if(rotation == "rot90")
                {
                    if(y > Y+200+length)
                    {
                        y = 200;
                    }
                }
                else
                    if(rotation == "rot-90")
                    {
                        if(y > Y+200)
                        {
                            y = 200-length;
                        }
                    }
                    else
                    {
                        if(y > Y+200+6)
                        {
                            y = 200;
                        }
                    }
            }
        }
        break;

        case 4:
        for(int down=0; down < times; down++)  //ud: up to down
        {
            displayMessage(drawingChar, x, y, X, Y);
            delay(speed);
            clearScreen();
            y-=1;

            if(wrapAround(wrap))
            {
                if(rotation == "rot90")
                {
                    if(y < 200)
                    {
                        y = Y+200+length;
                    }

                }
                else
                    if(rotation == "rot-90")
                    {
                        if(y < 200-length)
                        {
                            y = Y+200;
                        }
                    }
                    else
                    {
                        if(y < 200)
                        {
                            y = Y+200+6;
                        }
                    }
            }
        }
        break;

        default:
        for(int station=0; station < times; station++)  //stationary
        {
            displayMessage(drawingChar, x, y, X, Y);
            delay(speed);
            clearScreen();
        }
        break;
    }

}

void displayMessage(char C, int x, int y, int X, int Y)
{
    for(int j = 499; j >= 0; j--)            // Counting down from 499th row to the 0th of display board
    {
        for(int i = 0; i <= 499; i++)        // Counting up from the 0th column to the 499th of display board
        {
            displayBoard[j][i]=' ';          // Assigning every square to empty spaces
        }
    }

    for(int c=0; c < message.size(); c++)
    {
        if(inception == 'Y'|| inception == 'y')  // In case the user decides to have inception effect,
        {                                        //  the display character becomes the string character's own character
            C = message[c];
        }

        switch(message[c])
        {
            case 'A':                                         // The character map for each alphabet and numbers, including ? and !
            case 'a': displayBoard[  y  ][ x+2 ] = C;         //       [ x ][x-1][x-2][x-3][x-4]
                      displayBoard[ y-1 ][ x+1 ] = C;         //  [ y ]            #
                      displayBoard[ y-1 ][ x+3 ] = C;         //  [y-1]       #         #
                      displayBoard[ y-2 ][  x  ] = C;         //  [y-2]  #                   #
                      displayBoard[ y-2 ][ x+4 ] = C;         //  [y-3]  #                   #
                      displayBoard[ y-3 ][  x  ] = C;         //  [y-4]  #    #    #    #    #
                      displayBoard[ y-3 ][ x+4 ] = C;         //  [y-5]  #                   #
                      displayBoard[ y-4 ][  x  ] = C;         //  [y-6]  #                   #
                      displayBoard[ y-4 ][ x+1 ] = C;
                      displayBoard[ y-4 ][ x+2 ] = C;
                      displayBoard[ y-4 ][ x+3 ] = C;
                      displayBoard[ y-4 ][ x+4 ] = C;
                      displayBoard[ y-5 ][  x  ] = C;
                      displayBoard[ y-5 ][ x+4 ] = C;
                      displayBoard[ y-6 ][  x  ] = C;
                      displayBoard[ y-6 ][ x+4 ] = C;
                      break;
            case 'B':
            case 'b': displayBoard[  y  ][  x  ] = C;
                      displayBoard[  y  ][ x+1 ] = C;
                      displayBoard[  y  ][ x+2 ] = C;
                      displayBoard[  y  ][ x+3 ] = C;
                      displayBoard[ y-1 ][  x  ] = C;
                      displayBoard[ y-1 ][ x+4 ] = C;
                      displayBoard[ y-2 ][  x  ] = C;
                      displayBoard[ y-2 ][ x+4 ] = C;
                      displayBoard[ y-3 ][  x  ] = C;
                      displayBoard[ y-3 ][ x+1 ] = C;
                      displayBoard[ y-3 ][ x+2 ] = C;
                      displayBoard[ y-3 ][ x+3 ] = C;
                      displayBoard[ y-4 ][  x  ] = C;
                      displayBoard[ y-4 ][ x+4 ] = C;
                      displayBoard[ y-5 ][  x  ] = C;
                      displayBoard[ y-5 ][ x+4 ] = C;
                      displayBoard[ y-6 ][  x  ] = C;
                      displayBoard[ y-6 ][ x+1 ] = C;
                      displayBoard[ y-6 ][ x+2 ] = C;
                      displayBoard[ y-6 ][ x+3 ] = C;
                      break;
            case 'C':
            case 'c': displayBoard[  y  ][ x+1 ] = C;
                      displayBoard[  y  ][ x+2 ] = C;
                      displayBoard[  y  ][ x+3 ] = C;
                      displayBoard[ y-1 ][  x  ] = C;
                      displayBoard[ y-1 ][ x+4 ] = C;
                      displayBoard[ y-2 ][  x  ] = C;
                      displayBoard[ y-3 ][  x  ] = C;
                      displayBoard[ y-4 ][  x  ] = C;
                      displayBoard[ y-5 ][  x  ] = C;
                      displayBoard[ y-5 ][ x+4 ] = C;
                      displayBoard[ y-6 ][ x+1 ] = C;
                      displayBoard[ y-6 ][ x+2 ] = C;
                      displayBoard[ y-6 ][ x+3 ] = C;
                      break;
            case 'D':
            case 'd': displayBoard[  y  ][  x  ] = C;
                      displayBoard[  y  ][ x+1 ] = C;
                      displayBoard[  y  ][ x+2 ] = C;
                      displayBoard[  y  ][ x+3 ] = C;
                      displayBoard[ y-1 ][  x  ] = C;
                      displayBoard[ y-1 ][ x+4 ] = C;
                      displayBoard[ y-2 ][  x  ] = C;
                      displayBoard[ y-2 ][ x+4 ] = C;
                      displayBoard[ y-3 ][  x  ] = C;
                      displayBoard[ y-3 ][ x+4 ] = C;
                      displayBoard[ y-4 ][  x  ] = C;
                      displayBoard[ y-4 ][ x+4 ] = C;
                      displayBoard[ y-5 ][  x  ] = C;
                      displayBoard[ y-5 ][ x+4 ] = C;
                      displayBoard[ y-6 ][  x  ] = C;
                      displayBoard[ y-6 ][ x+1 ] = C;
                      displayBoard[ y-6 ][ x+2 ] = C;
                      displayBoard[ y-6 ][ x+3 ] = C;
                      break;
            case 'E':
            case 'e': displayBoard[  y  ][  x  ] = C;
                      displayBoard[  y  ][ x+1 ] = C;
                      displayBoard[  y  ][ x+2 ] = C;
                      displayBoard[  y  ][ x+3 ] = C;
                      displayBoard[  y  ][ x+4 ] = C;
                      displayBoard[ y-1 ][  x  ] = C;
                      displayBoard[ y-2 ][  x  ] = C;
                      displayBoard[ y-3 ][  x  ] = C;
                      displayBoard[ y-3 ][ x+1 ] = C;
                      displayBoard[ y-3 ][ x+2 ] = C;
                      displayBoard[ y-3 ][ x+3 ] = C;
                      displayBoard[ y-4 ][  x  ] = C;
                      displayBoard[ y-5 ][  x  ] = C;
                      displayBoard[ y-6 ][  x  ] = C;
                      displayBoard[ y-6 ][ x+1 ] = C;
                      displayBoard[ y-6 ][ x+2 ] = C;
                      displayBoard[ y-6 ][ x+3 ] = C;
                      displayBoard[ y-6 ][ x+4 ] = C;
                      break;
            case 'F':
            case 'f': displayBoard[  y  ][  x  ] = C;
                      displayBoard[  y  ][ x+1 ] = C;
                      displayBoard[  y  ][ x+2 ] = C;
                      displayBoard[  y  ][ x+3 ] = C;
                      displayBoard[  y  ][ x+4 ] = C;
                      displayBoard[ y-1 ][  x  ] = C;
                      displayBoard[ y-2 ][  x  ] = C;
                      displayBoard[ y-3 ][  x  ] = C;
                      displayBoard[ y-3 ][ x+1 ] = C;
                      displayBoard[ y-3 ][ x+2 ] = C;
                      displayBoard[ y-3 ][ x+3 ] = C;
                      displayBoard[ y-4 ][  x  ] = C;
                      displayBoard[ y-5 ][  x  ] = C;
                      displayBoard[ y-6 ][  x  ] = C;
                      break;
            case 'G':
            case 'g': displayBoard[  y  ][ x+1 ] = C;
                      displayBoard[  y  ][ x+2 ] = C;
                      displayBoard[  y  ][ x+3 ] = C;
                      displayBoard[  y  ][ x+4 ] = C;
                      displayBoard[ y-1 ][  x  ] = C;
                      displayBoard[ y-2 ][  x  ] = C;
                      displayBoard[ y-3 ][  x  ] = C;
                      displayBoard[ y-4 ][  x  ] = C;
                      displayBoard[ y-4 ][ x+3 ] = C;
                      displayBoard[ y-4 ][ x+4 ] = C;
                      displayBoard[ y-5 ][  x  ] = C;
                      displayBoard[ y-5 ][ x+4 ] = C;
                      displayBoard[ y-6 ][ x+1 ] = C;
                      displayBoard[ y-6 ][ x+2 ] = C;
                      displayBoard[ y-6 ][ x+3 ] = C;
                      displayBoard[ y-6 ][ x+4 ] = C;
                      break;
            case 'H':
            case 'h': displayBoard[  y  ][  x  ] = C;
                      displayBoard[  y  ][ x+4 ] = C;
                      displayBoard[ y-1 ][  x  ] = C;
                      displayBoard[ y-1 ][ x+4 ] = C;
                      displayBoard[ y-2 ][  x  ] = C;
                      displayBoard[ y-2 ][ x+4 ] = C;
                      displayBoard[ y-3 ][  x  ] = C;
                      displayBoard[ y-3 ][ x+1 ] = C;
                      displayBoard[ y-3 ][ x+2 ] = C;
                      displayBoard[ y-3 ][ x+3 ] = C;
                      displayBoard[ y-3 ][ x+4 ] = C;
                      displayBoard[ y-4 ][  x  ] = C;
                      displayBoard[ y-4 ][ x+4 ] = C;
                      displayBoard[ y-5 ][  x  ] = C;
                      displayBoard[ y-5 ][ x+4 ] = C;
                      displayBoard[ y-6 ][  x  ] = C;
                      displayBoard[ y-6 ][ x+4 ] = C;
                      break;
            case 'I':
            case 'i': displayBoard[  y  ][ x+1 ] = C;
                      displayBoard[  y  ][ x+2 ] = C;
                      displayBoard[  y  ][ x+3 ] = C;
                      displayBoard[ y-1 ][ x+2 ] = C;
                      displayBoard[ y-2 ][ x+2 ] = C;
                      displayBoard[ y-3 ][ x+2 ] = C;
                      displayBoard[ y-4 ][ x+2 ] = C;
                      displayBoard[ y-5 ][ x+2 ] = C;
                      displayBoard[ y-6 ][ x+1 ] = C;
                      displayBoard[ y-6 ][ x+2 ] = C;
                      displayBoard[ y-6 ][ x+3 ] = C;
                      break;
            case 'J':
            case 'j': displayBoard[  y  ][ x+4 ] = C;
                      displayBoard[ y-1 ][ x+4 ] = C;
                      displayBoard[ y-2 ][ x+4 ] = C;
                      displayBoard[ y-3 ][ x+4 ] = C;
                      displayBoard[ y-4 ][ x+4 ] = C;
                      displayBoard[ y-5 ][  x  ] = C;
                      displayBoard[ y-5 ][ x+4 ] = C;
                      displayBoard[ y-6 ][ x+1 ] = C;
                      displayBoard[ y-6 ][ x+2 ] = C;
                      displayBoard[ y-6 ][ x+3 ] = C;
                      break;
            case 'K':
            case 'k': displayBoard[  y  ][  x  ] = C;
                      displayBoard[  y  ][ x+4 ] = C;
                      displayBoard[ y-1 ][  x  ] = C;
                      displayBoard[ y-1 ][ x+3 ] = C;
                      displayBoard[ y-2 ][  x  ] = C;
                      displayBoard[ y-2 ][ x+2 ] = C;
                      displayBoard[ y-3 ][  x  ] = C;
                      displayBoard[ y-3 ][ x+1 ] = C;
                      displayBoard[ y-4 ][  x  ] = C;
                      displayBoard[ y-4 ][ x+2 ] = C;
                      displayBoard[ y-5 ][  x  ] = C;
                      displayBoard[ y-5 ][ x+3 ] = C;
                      displayBoard[ y-6 ][  x  ] = C;
                      displayBoard[ y-6 ][ x+4 ] = C;
                      break;
            case 'L':
            case 'l': displayBoard[  y  ][  x  ] = C;
                      displayBoard[ y-1 ][  x  ] = C;
                      displayBoard[ y-2 ][  x  ] = C;
                      displayBoard[ y-3 ][  x  ] = C;
                      displayBoard[ y-4 ][  x  ] = C;
                      displayBoard[ y-5 ][  x  ] = C;
                      displayBoard[ y-6 ][  x  ] = C;
                      displayBoard[ y-6 ][ x+1 ] = C;
                      displayBoard[ y-6 ][ x+2 ] = C;
                      displayBoard[ y-6 ][ x+3 ] = C;
                      displayBoard[ y-6 ][ x+4 ] = C;
                      break;
            case 'M':
            case 'm': displayBoard[  y  ][  x  ] = C;
                      displayBoard[  y  ][ x+4 ] = C;
                      displayBoard[ y-1 ][  x  ] = C;
                      displayBoard[ y-1 ][ x+1 ] = C;
                      displayBoard[ y-1 ][ x+3 ] = C;
                      displayBoard[ y-1 ][ x+4 ] = C;
                      displayBoard[ y-2 ][  x  ] = C;
                      displayBoard[ y-2 ][ x+2 ] = C;
                      displayBoard[ y-2 ][ x+4 ] = C;
                      displayBoard[ y-3 ][  x  ] = C;
                      displayBoard[ y-3 ][ x+2 ] = C;
                      displayBoard[ y-3 ][ x+4 ] = C;
                      displayBoard[ y-4 ][  x  ] = C;
                      displayBoard[ y-4 ][ x+4 ] = C;
                      displayBoard[ y-5 ][  x  ] = C;
                      displayBoard[ y-5 ][ x+4 ] = C;
                      displayBoard[ y-6 ][  x  ] = C;
                      displayBoard[ y-6 ][ x+4 ] = C;
                      break;
            case 'N':
            case 'n': displayBoard[  y  ][  x  ] = C;
                      displayBoard[  y  ][ x+4 ] = C;
                      displayBoard[ y-1 ][  x  ] = C;
                      displayBoard[ y-1 ][ x+4 ] = C;
                      displayBoard[ y-2 ][  x  ] = C;
                      displayBoard[ y-2 ][ x+1 ] = C;
                      displayBoard[ y-2 ][ x+4 ] = C;
                      displayBoard[ y-3 ][  x  ] = C;
                      displayBoard[ y-3 ][ x+2 ] = C;
                      displayBoard[ y-3 ][ x+4 ] = C;
                      displayBoard[ y-4 ][  x  ] = C;
                      displayBoard[ y-4 ][ x+3 ] = C;
                      displayBoard[ y-4 ][ x+4 ] = C;
                      displayBoard[ y-5 ][  x  ] = C;
                      displayBoard[ y-5 ][ x+4 ] = C;
                      displayBoard[ y-6 ][  x  ] = C;
                      displayBoard[ y-6 ][ x+4 ] = C;
                      break;
            case 'O':
            case 'o': displayBoard[  y  ][ x+1 ] = C;
                      displayBoard[  y  ][ x+2 ] = C;
                      displayBoard[  y  ][ x+3 ] = C;
                      displayBoard[ y-1 ][  x  ] = C;
                      displayBoard[ y-1 ][ x+4 ] = C;
                      displayBoard[ y-2 ][  x  ] = C;
                      displayBoard[ y-2 ][ x+4 ] = C;
                      displayBoard[ y-3 ][  x  ] = C;
                      displayBoard[ y-3 ][ x+4 ] = C;
                      displayBoard[ y-4 ][  x  ] = C;
                      displayBoard[ y-4 ][ x+4 ] = C;
                      displayBoard[ y-5 ][  x  ] = C;
                      displayBoard[ y-5 ][ x+4 ] = C;
                      displayBoard[ y-6 ][ x+1 ] = C;
                      displayBoard[ y-6 ][ x+2 ] = C;
                      displayBoard[ y-6 ][ x+3 ] = C;
                      break;
            case 'P':
            case 'p': displayBoard[  y  ][  x  ] = C;
                      displayBoard[  y  ][ x+1 ] = C;
                      displayBoard[  y  ][ x+2 ] = C;
                      displayBoard[  y  ][ x+3 ] = C;
                      displayBoard[ y-1 ][  x  ] = C;
                      displayBoard[ y-1 ][ x+4 ] = C;
                      displayBoard[ y-2 ][  x  ] = C;
                      displayBoard[ y-2 ][ x+4 ] = C;
                      displayBoard[ y-3 ][  x  ] = C;
                      displayBoard[ y-3 ][ x+1 ] = C;
                      displayBoard[ y-3 ][ x+2 ] = C;
                      displayBoard[ y-3 ][ x+3 ] = C;
                      displayBoard[ y-4 ][  x  ] = C;
                      displayBoard[ y-5 ][  x  ] = C;
                      displayBoard[ y-6 ][  x  ] = C;
                      break;
            case 'Q':
            case 'q': displayBoard[  y  ][ x+1 ] = C;
                      displayBoard[  y  ][ x+2 ] = C;
                      displayBoard[  y  ][ x+3 ] = C;
                      displayBoard[ y-1 ][  x  ] = C;
                      displayBoard[ y-1 ][ x+4 ] = C;
                      displayBoard[ y-2 ][  x  ] = C;
                      displayBoard[ y-2 ][ x+4 ] = C;
                      displayBoard[ y-3 ][  x  ] = C;
                      displayBoard[ y-3 ][ x+4 ] = C;
                      displayBoard[ y-4 ][  x  ] = C;
                      displayBoard[ y-4 ][ x+2 ] = C;
                      displayBoard[ y-4 ][ x+4 ] = C;
                      displayBoard[ y-5 ][  x  ] = C;
                      displayBoard[ y-5 ][ x+3 ] = C;
                      displayBoard[ y-6 ][ x+1 ] = C;
                      displayBoard[ y-6 ][ x+2 ] = C;
                      displayBoard[ y-6 ][ x+4 ] = C;
                      break;
            case 'R':
            case 'r': displayBoard[  y  ][  x  ] = C;
                      displayBoard[  y  ][ x+1 ] = C;
                      displayBoard[  y  ][ x+2 ] = C;
                      displayBoard[  y  ][ x+3 ] = C;
                      displayBoard[ y-1 ][  x  ] = C;
                      displayBoard[ y-1 ][ x+4 ] = C;
                      displayBoard[ y-2 ][  x  ] = C;
                      displayBoard[ y-2 ][ x+4 ] = C;
                      displayBoard[ y-3 ][  x  ] = C;
                      displayBoard[ y-3 ][ x+1 ] = C;
                      displayBoard[ y-3 ][ x+2 ] = C;
                      displayBoard[ y-3 ][ x+3 ] = C;
                      displayBoard[ y-4 ][  x  ] = C;
                      displayBoard[ y-4 ][ x+2 ] = C;
                      displayBoard[ y-5 ][  x  ] = C;
                      displayBoard[ y-5 ][ x+3 ] = C;
                      displayBoard[ y-6 ][  x  ] = C;
                      displayBoard[ y-6 ][ x+4 ] = C;
                      break;
            case 'S':
            case 's': displayBoard[  y  ][ x+1 ] = C;
                      displayBoard[  y  ][ x+2 ] = C;
                      displayBoard[  y  ][ x+3 ] = C;
                      displayBoard[ y-1 ][  x  ] = C;
                      displayBoard[ y-1 ][ x+4 ] = C;
                      displayBoard[ y-2 ][  x  ] = C;
                      displayBoard[ y-3 ][ x+1 ] = C;
                      displayBoard[ y-3 ][ x+2 ] = C;
                      displayBoard[ y-3 ][ x+3 ] = C;
                      displayBoard[ y-4 ][ x+4 ] = C;
                      displayBoard[ y-5 ][  x  ] = C;
                      displayBoard[ y-5 ][ x+4 ] = C;
                      displayBoard[ y-6 ][ x+1 ] = C;
                      displayBoard[ y-6 ][ x+2 ] = C;
                      displayBoard[ y-6 ][ x+3 ] = C;
                      break;
            case 'T':
            case 't': displayBoard[  y  ][  x  ] = C;
                      displayBoard[  y  ][ x+1 ] = C;
                      displayBoard[  y  ][ x+2 ] = C;
                      displayBoard[  y  ][ x+3 ] = C;
                      displayBoard[  y  ][ x+4 ] = C;
                      displayBoard[ y-1 ][ x+2 ] = C;
                      displayBoard[ y-2 ][ x+2 ] = C;
                      displayBoard[ y-3 ][ x+2 ] = C;
                      displayBoard[ y-4 ][ x+2 ] = C;
                      displayBoard[ y-5 ][ x+2 ] = C;
                      displayBoard[ y-6 ][ x+2 ] = C;
                      break;
            case 'U':
            case 'u': displayBoard[  y  ][  x  ] = C;
                      displayBoard[  y  ][ x+4 ] = C;
                      displayBoard[ y-1 ][  x  ] = C;
                      displayBoard[ y-1 ][ x+4 ] = C;
                      displayBoard[ y-2 ][  x  ] = C;
                      displayBoard[ y-2 ][ x+4 ] = C;
                      displayBoard[ y-3 ][  x  ] = C;
                      displayBoard[ y-3 ][ x+4 ] = C;
                      displayBoard[ y-4 ][  x  ] = C;
                      displayBoard[ y-4 ][ x+4 ] = C;
                      displayBoard[ y-5 ][  x  ] = C;
                      displayBoard[ y-5 ][ x+4 ] = C;
                      displayBoard[ y-6 ][ x+1 ] = C;
                      displayBoard[ y-6 ][ x+2 ] = C;
                      displayBoard[ y-6 ][ x+3 ] = C;
                      break;
            case 'V':
            case 'v': displayBoard[  y  ][  x  ] = C;
                      displayBoard[  y  ][ x+4 ] = C;
                      displayBoard[ y-1 ][  x  ] = C;
                      displayBoard[ y-1 ][ x+4 ] = C;
                      displayBoard[ y-2 ][  x  ] = C;
                      displayBoard[ y-2 ][ x+4 ] = C;
                      displayBoard[ y-3 ][  x  ] = C;
                      displayBoard[ y-3 ][ x+4 ] = C;
                      displayBoard[ y-4 ][  x  ] = C;
                      displayBoard[ y-4 ][ x+4 ] = C;
                      displayBoard[ y-5 ][ x+1 ] = C;
                      displayBoard[ y-5 ][ x+3 ] = C;
                      displayBoard[ y-6 ][ x+2 ] = C;
                      break;
            case 'W':
            case 'w': displayBoard[  y  ][  x  ] = C;
                      displayBoard[  y  ][ x+4 ] = C;
                      displayBoard[ y-1 ][  x  ] = C;
                      displayBoard[ y-1 ][ x+4 ] = C;
                      displayBoard[ y-2 ][  x  ] = C;
                      displayBoard[ y-2 ][ x+4 ] = C;
                      displayBoard[ y-3 ][  x  ] = C;
                      displayBoard[ y-3 ][ x+2 ] = C;
                      displayBoard[ y-3 ][ x+4 ] = C;
                      displayBoard[ y-4 ][  x  ] = C;
                      displayBoard[ y-4 ][ x+2 ] = C;
                      displayBoard[ y-4 ][ x+4 ] = C;
                      displayBoard[ y-5 ][  x  ] = C;
                      displayBoard[ y-5 ][ x+1 ] = C;
                      displayBoard[ y-5 ][ x+3 ] = C;
                      displayBoard[ y-5 ][ x+4 ] = C;
                      displayBoard[ y-6 ][  x  ] = C;
                      displayBoard[ y-6 ][ x+4 ] = C;
                      break;
            case 'X':
            case 'x': displayBoard[  y  ][  x  ] = C;
                      displayBoard[  y  ][ x+4 ] = C;
                      displayBoard[ y-1 ][  x  ] = C;
                      displayBoard[ y-1 ][ x+4 ] = C;
                      displayBoard[ y-2 ][ x+1 ] = C;
                      displayBoard[ y-2 ][ x+3 ] = C;
                      displayBoard[ y-3 ][ x+2 ] = C;
                      displayBoard[ y-4 ][ x+1 ] = C;
                      displayBoard[ y-4 ][ x+3 ] = C;
                      displayBoard[ y-5 ][  x  ] = C;
                      displayBoard[ y-5 ][ x+4 ] = C;
                      displayBoard[ y-6 ][  x  ] = C;
                      displayBoard[ y-6 ][ x+4 ] = C;
                      break;
            case 'Y':
            case 'y': displayBoard[  y  ][  x  ] = C;
                      displayBoard[  y  ][ x+4 ] = C;
                      displayBoard[ y-1 ][  x  ] = C;
                      displayBoard[ y-1 ][ x+4 ] = C;
                      displayBoard[ y-2 ][ x+1 ] = C;
                      displayBoard[ y-2 ][ x+3 ] = C;
                      displayBoard[ y-3 ][ x+2 ] = C;
                      displayBoard[ y-4 ][ x+2 ] = C;
                      displayBoard[ y-5 ][ x+2 ] = C;
                      displayBoard[ y-6 ][ x+2 ] = C;
                      break;
            case 'Z':
            case 'z': displayBoard[  y  ][  x  ] = C;
                      displayBoard[  y  ][ x+1 ] = C;
                      displayBoard[  y  ][ x+2 ] = C;
                      displayBoard[  y  ][ x+3 ] = C;
                      displayBoard[  y  ][ x+4 ] = C;
                      displayBoard[ y-1 ][ x+4 ] = C;
                      displayBoard[ y-2 ][ x+3 ] = C;
                      displayBoard[ y-3 ][ x+2 ] = C;
                      displayBoard[ y-4 ][ x+1 ] = C;
                      displayBoard[ y-5 ][  x  ] = C;
                      displayBoard[ y-6 ][  x  ] = C;
                      displayBoard[ y-6 ][ x+1 ] = C;
                      displayBoard[ y-6 ][ x+2 ] = C;
                      displayBoard[ y-6 ][ x+3 ] = C;
                      displayBoard[ y-6 ][ x+4 ] = C;
                      break;
            case '0': displayBoard[  y  ][ x+1 ] = C;
                      displayBoard[  y  ][ x+2 ] = C;
                      displayBoard[  y  ][ x+3 ] = C;
                      displayBoard[ y-1 ][  x  ] = C;
                      displayBoard[ y-1 ][ x+4 ] = C;
                      displayBoard[ y-2 ][  x  ] = C;
                      displayBoard[ y-2 ][ x+3 ] = C;
                      displayBoard[ y-2 ][ x+4 ] = C;
                      displayBoard[ y-3 ][  x  ] = C;
                      displayBoard[ y-3 ][ x+2 ] = C;
                      displayBoard[ y-3 ][ x+4 ] = C;
                      displayBoard[ y-4 ][  x  ] = C;
                      displayBoard[ y-4 ][ x+1 ] = C;
                      displayBoard[ y-4 ][ x+4 ] = C;
                      displayBoard[ y-5 ][  x  ] = C;
                      displayBoard[ y-5 ][ x+4 ] = C;
                      displayBoard[ y-6 ][ x+1 ] = C;
                      displayBoard[ y-6 ][ x+2 ] = C;
                      displayBoard[ y-6 ][ x+3 ] = C;
                      break;
            case '1': displayBoard[  y  ][ x+2 ] = C;
                      displayBoard[ y-1 ][ x+1 ] = C;
                      displayBoard[ y-1 ][ x+2 ] = C;
                      displayBoard[ y-2 ][ x+2 ] = C;
                      displayBoard[ y-3 ][ x+2 ] = C;
                      displayBoard[ y-4 ][ x+2 ] = C;
                      displayBoard[ y-5 ][ x+2 ] = C;
                      displayBoard[ y-6 ][ x+1 ] = C;
                      displayBoard[ y-6 ][ x+2 ] = C;
                      displayBoard[ y-6 ][ x+3 ] = C;
                      break;
            case '2': displayBoard[  y  ][ x+1 ] = C;
                      displayBoard[  y  ][ x+2 ] = C;
                      displayBoard[  y  ][ x+3 ] = C;
                      displayBoard[ y-1 ][  x  ] = C;
                      displayBoard[ y-1 ][ x+4 ] = C;
                      displayBoard[ y-2 ][ x+4 ] = C;
                      displayBoard[ y-3 ][ x+2 ] = C;
                      displayBoard[ y-3 ][ x+3 ] = C;
                      displayBoard[ y-4 ][ x+1 ] = C;
                      displayBoard[ y-5 ][  x  ] = C;
                      displayBoard[ y-6 ][  x  ] = C;
                      displayBoard[ y-6 ][ x+1 ] = C;
                      displayBoard[ y-6 ][ x+2 ] = C;
                      displayBoard[ y-6 ][ x+3 ] = C;
                      displayBoard[ y-6 ][ x+4 ] = C;
                      break;
            case '3': displayBoard[  y  ][  x  ] = C;
                      displayBoard[  y  ][ x+1 ] = C;
                      displayBoard[  y  ][ x+2 ] = C;
                      displayBoard[  y  ][ x+3 ] = C;
                      displayBoard[  y  ][ x+4 ] = C;
                      displayBoard[ y-1 ][ x+4 ] = C;
                      displayBoard[ y-2 ][ x+3 ] = C;
                      displayBoard[ y-3 ][ x+2 ] = C;
                      displayBoard[ y-3 ][ x+3 ] = C;
                      displayBoard[ y-4 ][ x+4 ] = C;
                      displayBoard[ y-5 ][  x  ] = C;
                      displayBoard[ y-5 ][ x+4 ] = C;
                      displayBoard[ y-6 ][ x+1 ] = C;
                      displayBoard[ y-6 ][ x+2 ] = C;
                      displayBoard[ y-6 ][ x+3 ] = C;
                      break;
            case '4': displayBoard[  y  ][ x+3 ] = C;
                      displayBoard[ y-1 ][ x+2 ] = C;
                      displayBoard[ y-1 ][ x+3 ] = C;
                      displayBoard[ y-2 ][ x+1 ] = C;
                      displayBoard[ y-2 ][ x+3 ] = C;
                      displayBoard[ y-3 ][  x  ] = C;
                      displayBoard[ y-3 ][ x+3 ] = C;
                      displayBoard[ y-4 ][  x  ] = C;
                      displayBoard[ y-4 ][ x+1 ] = C;
                      displayBoard[ y-4 ][ x+2 ] = C;
                      displayBoard[ y-4 ][ x+3 ] = C;
                      displayBoard[ y-4 ][ x+4 ] = C;
                      displayBoard[ y-5 ][ x+3 ] = C;
                      displayBoard[ y-6 ][ x+3 ] = C;
                      break;
            case '5': displayBoard[  y  ][  x  ] = C;
                      displayBoard[  y  ][ x+1 ] = C;
                      displayBoard[  y  ][ x+2 ] = C;
                      displayBoard[  y  ][ x+3 ] = C;
                      displayBoard[  y  ][ x+4 ] = C;
                      displayBoard[ y-1 ][  x  ] = C;
                      displayBoard[ y-2 ][  x  ] = C;
                      displayBoard[ y-2 ][ x+1 ] = C;
                      displayBoard[ y-2 ][ x+2 ] = C;
                      displayBoard[ y-2 ][ x+3 ] = C;
                      displayBoard[ y-3 ][ x+4 ] = C;
                      displayBoard[ y-4 ][ x+4 ] = C;
                      displayBoard[ y-5 ][  x  ] = C;
                      displayBoard[ y-5 ][ x+4 ] = C;
                      displayBoard[ y-6 ][ x+1 ] = C;
                      displayBoard[ y-6 ][ x+2 ] = C;
                      displayBoard[ y-6 ][ x+3 ] = C;
                      break;
            case '6': displayBoard[  y  ][ x+2 ] = C;
                      displayBoard[  y  ][ x+3 ] = C;
                      displayBoard[  y  ][ x+4 ] = C;
                      displayBoard[ y-1 ][ x+1 ] = C;
                      displayBoard[ y-2 ][  x  ] = C;
                      displayBoard[ y-3 ][  x  ] = C;
                      displayBoard[ y-3 ][ x+1 ] = C;
                      displayBoard[ y-3 ][ x+2 ] = C;
                      displayBoard[ y-3 ][ x+3 ] = C;
                      displayBoard[ y-4 ][  x  ] = C;
                      displayBoard[ y-4 ][ x+4 ] = C;
                      displayBoard[ y-5 ][  x  ] = C;
                      displayBoard[ y-5 ][ x+4 ] = C;
                      displayBoard[ y-6 ][ x+1 ] = C;
                      displayBoard[ y-6 ][ x+2 ] = C;
                      displayBoard[ y-6 ][ x+3 ] = C;
                      break;
            case '7': displayBoard[  y  ][  x  ] = C;
                      displayBoard[  y  ][ x+1 ] = C;
                      displayBoard[  y  ][ x+2 ] = C;
                      displayBoard[  y  ][ x+3 ] = C;
                      displayBoard[  y  ][ x+4 ] = C;
                      displayBoard[ y-1 ][ x+4 ] = C;
                      displayBoard[ y-2 ][ x+3 ] = C;
                      displayBoard[ y-3 ][ x+2 ] = C;
                      displayBoard[ y-4 ][ x+1 ] = C;
                      displayBoard[ y-5 ][ x+1 ] = C;
                      displayBoard[ y-6 ][ x+1 ] = C;
                      break;
            case '8': displayBoard[  y  ][ x+1 ] = C;
                      displayBoard[  y  ][ x+2 ] = C;
                      displayBoard[  y  ][ x+3 ] = C;
                      displayBoard[ y-1 ][  x  ] = C;
                      displayBoard[ y-1 ][ x+4 ] = C;
                      displayBoard[ y-2 ][  x  ] = C;
                      displayBoard[ y-2 ][ x+4 ] = C;
                      displayBoard[ y-3 ][ x+1 ] = C;
                      displayBoard[ y-3 ][ x+2 ] = C;
                      displayBoard[ y-3 ][ x+3 ] = C;
                      displayBoard[ y-4 ][  x  ] = C;
                      displayBoard[ y-4 ][ x+4 ] = C;
                      displayBoard[ y-5 ][  x  ] = C;
                      displayBoard[ y-5 ][ x+4 ] = C;
                      displayBoard[ y-6 ][ x+1 ] = C;
                      displayBoard[ y-6 ][ x+2 ] = C;
                      displayBoard[ y-6 ][ x+3 ] = C;
                      break;
            case '9': displayBoard[  y  ][ x+1 ] = C;
                      displayBoard[  y  ][ x+2 ] = C;
                      displayBoard[  y  ][ x+3 ] = C;
                      displayBoard[ y-1 ][  x  ] = C;
                      displayBoard[ y-1 ][ x+4 ] = C;
                      displayBoard[ y-2 ][  x  ] = C;
                      displayBoard[ y-2 ][ x+4 ] = C;
                      displayBoard[ y-3 ][ x+1 ] = C;
                      displayBoard[ y-3 ][ x+2 ] = C;
                      displayBoard[ y-3 ][ x+3 ] = C;
                      displayBoard[ y-3 ][ x+4 ] = C;
                      displayBoard[ y-4 ][ x+4 ] = C;
                      displayBoard[ y-5 ][ x+3 ] = C;
                      displayBoard[ y-6 ][  x  ] = C;
                      displayBoard[ y-6 ][ x+1 ] = C;
                      displayBoard[ y-6 ][ x+2 ] = C;
                      break;
            case '!': displayBoard[  y  ][ x+2 ] = C;
                      displayBoard[ y-1 ][ x+2 ] = C;
                      displayBoard[ y-2 ][ x+2 ] = C;
                      displayBoard[ y-3 ][ x+2 ] = C;
                      displayBoard[ y-4 ][ x+2 ] = C;
                      displayBoard[ y-6 ][ x+2 ] = C;
                      break;
            case '?': displayBoard[  y  ][ x+1 ] = C;
                      displayBoard[  y  ][ x+2 ] = C;
                      displayBoard[  y  ][ x+3 ] = C;
                      displayBoard[ y-1 ][  x  ] = C;
                      displayBoard[ y-1 ][ x+4 ] = C;
                      displayBoard[ y-2 ][ x+4 ] = C;
                      displayBoard[ y-3 ][ x+3 ] = C;
                      displayBoard[ y-4 ][ x+2 ] = C;
                      displayBoard[ y-6 ][ x+2 ] = C;
                      break;
            default: break;                // Other symbols, including space will be considered as a space
        }
        x+=6;                              // Move 6 units from previous anchor dot to the next character
    }

    switch(stringRotateToInt(rotation))    // Switch statement for checking whether the user decides to have any rotation effect
    {
        case 1: rotate90deg(x, y); break;
        case 2: rotateN90deg(x, y); break;
        case 3: mirror(x, y); break;
        default: break;
    }

    for(int j = Y+200; j >= 200; j--)
    {
        for(int i = 200; i <= X+200; i++)
        {
            cout << displayBoard[j][i];    // Printing out the whole display board with the newly assigned characters
        }
        cout << endl;
    }

}

void rotate90deg(int x, int y)  // This function flips the message 90 degrees clockwise row by row, and prints column by column
{
    int length = message.size()*6;
    x-=length;

        for(int i = 0; i < length; i++)
        {
            displayBoard[ y-i ][ x-6 ] = displayBoard[ y-6 ][ x+i ];
            displayBoard[ y-i ][ x-5 ] = displayBoard[ y-5 ][ x+i ];
            displayBoard[ y-i ][ x-4 ] = displayBoard[ y-4 ][ x+i ];
            displayBoard[ y-i ][ x-3 ] = displayBoard[ y-3 ][ x+i ];
            displayBoard[ y-i ][ x-2 ] = displayBoard[ y-2 ][ x+i ];
            displayBoard[ y-i ][ x-1 ] = displayBoard[ y-1 ][ x+i ];
            displayBoard[ y-i ][  x  ] = displayBoard[  y  ][ x+i ];
            displayBoard[ y-6 ][ x+i ] = ' ';
            displayBoard[ y-5 ][ x+i ] = ' ';
            displayBoard[ y-4 ][ x+i ] = ' ';
            displayBoard[ y-3 ][ x+i ] = ' ';
            displayBoard[ y-2 ][ x+i ] = ' ';
            displayBoard[ y-1 ][ x+i ] = ' ';
        }
        for(int i = 1; i < length; i++)
        {
            displayBoard[ y ][ x+i ] = ' ';
        }
}

void rotateN90deg(int x, int y)  // This function flips the message 90 degrees anticlockwise row by row, and prints column by column
{
    int length = message.size()*6;
    x-=length;

    for(int i = 1; i < length; i++)
    {
        displayBoard[ y+i ][  x  ] = displayBoard[  y  ][ x+i ];
        displayBoard[  y  ][ x+i ] = ' ';
    }
    for(int i = 0; i < length; i++)
    {
        displayBoard[ y+i ][ x+1 ] = displayBoard[ y-1 ][ x+i ];
        displayBoard[ y+i ][ x+2 ] = displayBoard[ y-2 ][ x+i ];
        displayBoard[ y+i ][ x+3 ] = displayBoard[ y-3 ][ x+i ];
        displayBoard[ y+i ][ x+4 ] = displayBoard[ y-4 ][ x+i ];
        displayBoard[ y+i ][ x+5 ] = displayBoard[ y-5 ][ x+i ];
        displayBoard[ y+i ][ x+6 ] = displayBoard[ y-6 ][ x+i ];
        displayBoard[ y-1 ][ x+i ] = ' ';
        displayBoard[ y-2 ][ x+i ] = ' ';
        displayBoard[ y-3 ][ x+i ] = ' ';
        displayBoard[ y-4 ][ x+i ] = ' ';
        displayBoard[ y-5 ][ x+i ] = ' ';
        displayBoard[ y-6 ][ x+i ] = ' ';
    }
}

void mirror(int x, int y)  // This function flips the message by vertical rotation
{
    int length = message.size()*6;
    x-=length;

    char temp1[length];                                        // y    #        #   #
    char temp2[length];                                        //y-1  # #       #   #
    char temp3[length];                                        //y-2 #   #      #####
    for(int i = 0, j = x; i < length; i++, j++)                //y-3 #   #  =>  #   # As you can see, the 4th row remains unchanged
    {                                                          //y-4 #####      #   # while the first 3 rows interchange with the
        temp1[  i  ] = displayBoard[  y  ][  j  ];             //y-5 #   #       # #  last 3 rows
        temp2[  i  ] = displayBoard[ y-1 ][  j  ];             //y-6 #   #        #
        temp3[  i  ] = displayBoard[ y-2 ][  j  ];  //This loop replaces the first 3 rows with the last 3 rows

        displayBoard[  y  ][  j  ] = displayBoard[ y-6 ][  j  ];
        displayBoard[ y-1 ][  j  ] = displayBoard[ y-5 ][  j  ];
        displayBoard[ y-2 ][  j  ] = displayBoard[ y-4 ][  j  ];  //This loop stores the first 3 rows to a 3 temporary arrays

        displayBoard[ y-6 ][  j  ] = temp1[  i  ];
        displayBoard[ y-5 ][  j  ] = temp2[  i  ];
        displayBoard[ y-4 ][  j  ] = temp3[  i  ];  //This loop replaces the last 3 rows with the rows stored in the array
    }
}

bool wrapAround(string wrap)  // This function produces a flag for the program to know whether the user wanted to do wrap-around
{
    bool wr = false;   //using boolean function since it is a yes/no answer
    if(wrap == "wr")
        wr = true;
    return wr; //returns True/False value to switch function
}

int stringToInt(string direction)  // This function converts the user input for direction to integers, for later switch statement
{
    int move;
    if(direction == "rl") //translating user input to numbers for switch function in movement
        move = 1;
    else
        if(direction == "lr")
            move = 2;
        else
            if(direction == "du")
                move = 3;
            else
                if(direction == "ud")
                    move = 4;
                else
                    move = 5;   //if the user enter st, the string will be stationary
    return move; //returns the value of move to switch function
}

int stringRotateToInt(string rotation)  //This function converts the user input for rotation to integers, for later switch statement
{
    int rotate;
    if(rotation == "rot90")    //translating user input to numbers for switch function in displayMessage,
        rotate = 1;            //to decide the rotation of the string
    else
        if(rotation == "rot-90")
            rotate = 2;
        else
            if(rotation == "mr")
                rotate = 3;
            else
                rotate = 4;    //if the user enter no, the string will not rotate
    return rotate; //returns the value of rotate to switch function
}

void direct(int c) //This function prints the choice of direction in the user interface
{
    switch(c)
    {
        case 1: cout << "To the Left" << endl; break;
        case 2: cout << "To the Right" << endl; break;
        case 3: cout << "Moving Upwards" << endl; break;
        case 4: cout << "Moving Downwards" << endl; break;
        default: cout << "Stationary" << endl; break;
    }
}

void wr(int w)     //This function prints the choice for warp-around in the user interface
{
    if(w)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

void ro(int r)     //This function prints the choice of rotation in the user interface
{
    switch(r)
    {
        case 1: cout << "Rotate 90 degrees" << endl; break;
        case 2: cout << "Rotate -90 degrees" << endl; break;
        case 3: cout << "Mirror" << endl; break;
        default: cout << "No" << endl; break;
    }
}
