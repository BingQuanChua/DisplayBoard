/**********|**********|**********|
Course: Programming Fundamentals
Year: 2019/2020 Trimester 1
Name: Chua Bing Quan
**********|**********|**********/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void delay(int R);
void clearScreen();
void callString(string message, char displayBoard[][400],int x, int y);

int main()
{
    string message;  //message that the user enter
    int x, y,        //co-ordinates for anchor dot
        direction,   //scrolling direction for string
        times,       //how many time steps does the user wants
        speed;       //speed of time step refresh cycle

    cout << "Please enter a message." << endl;
    getline(cin,message);
    //cout << message.size() << endl;     //this was used to confirm spaces are read & yes spaces are read
    while(message.size() > 25)            //display error message if users input more than 25 characters
    {
        cout << endl << "ERROR!! Maximum 25 characters." << endl;
        cout << "Please enter a shorter message." << endl;
        getline(cin,message);
    }


    cout << endl << "Please enter an anchor dot.(COLUMNS, ROWS)" << endl;
    cout << "         +------------------------------+ <--(39,19)" << endl;
    cout << "         |                              |      39th column," << endl;
    cout << "         |         s a m p l e          |      19th row." << endl;
    cout << "         |        d i s p l a y         |" << endl;
    cout << "         |          b o a r d           |" << endl;
    cout << "         |                              |" << endl;
    cout << "(0,0)--> +------------------------------+" << endl;
    cout << "  0th column," << endl;
    cout << "  0th row." << endl;
    cout << endl << "Please enter in the format of COLUMNS, ROWS" << endl;
    cin >> x >> y;                        //no error message because users are free to enter any co-ordinates they want


    cout << endl << "Please enter moving direction:" << endl;
    cout << setw(10) << "1-LEFT" << endl;
    cout << setw(11) << "2-RIGHT" << endl;
    cout << setw(8) << "3-UP" << endl;
    cout << setw(10) << "4-DOWN" << endl;
    cout << setw(16) << "5-STATIONARY" << endl;
    cin >> direction;
    switch(direction)                     //just in case the user enter anything other than 1,2,3,4 or 5
    {
        case 1: cout << "The message will be moving to the LEFT."; break;
        case 2: cout << "The message will be moving to the RIGHT."; break;
        case 3: cout << "The message will be moving UPWARDS."; break;
        case 4: cout << "The message will be moving DOWNWARDS."; break;
        case 5:
        default: cout << "The message will be STATIONARY."; break;
    }


    cout << endl << endl << "Please enter time steps:" << endl;
    cin >> times;
    while(times < 0)                      //time steps cannot be negative value
    {
        cout << "ERROR!! Time steps cannot be a negative value." << endl;
        cout << "Please enter time steps: ";
        cin >> times;
    }


    cout << endl << "Please enter speed of refresh cycle." << endl;
    cout << "(in a scale of 1~10, with 10 being the fastest):" << endl;
    cin >> speed;
    while(speed < 1 || speed > 10)        //only accepts input from 1 to 10
    {
        cout << "ERROR!! Please enter a number between 1~10: ";
        cin >> speed;
    }

    delay(1);
    clearScreen();

    char displayBoard[200][400];
    switch(direction)
    {
        case 1:
            for(int left=0; left<=times; left++)
            {
                callString(message, displayBoard, x, y);
                delay(speed);
                clearScreen();
                x-=1;
            }
            break;
        case 2:
            for(int right=0; right<=times; right++)
            {
                callString(message, displayBoard, x, y);
                delay(speed);
                clearScreen();
                x+=1;
            }
            break;
        case 3:
            for(int up=0; up<=times; up++)
            {
                callString(message, displayBoard, x, y);
                delay(speed);
                clearScreen();
                y+=1;

                if(y>25)
                {
                    delay(speed);
                    y = 0;
                }
            }
            break;
        case 4:
            for(int down=0; down<=times; down++)
            {
                callString(message, displayBoard, x, y);
                delay(speed);
                clearScreen();
                y-=1;

                if(y<0)
                {
                    delay(speed);
                    y = 25;
                }
            }
            break;
        default:
            for(int station=0; station<=times; station++)
            {
                callString(message, displayBoard, x, y);
                delay(speed);
                clearScreen();
            }
            break;
    }

    return 0;
}

void delay(int R)
{
   for( int t = 0; t < (300000000/R); t++ )
   { }
}

void clearScreen()
{
   system( "cls" );
}

void callString(string message, char displayBoard[][400], int x, int y)
{
    //declare the display board, setting every square to ' '.
    for(int j = 19; j >= 0; j--)            //counting down from 19th row to the 0th of display board
    {
        for(int i = 0; i <= 39; i++)        //counting up from the 0th column to the 39th of display board
        {
            displayBoard[j][i]=' ';         //assigning every square to empty spaces
        }
    }

    for(int c=0; c < message.size(); c++)
    {
        switch(message[c])
        {
            case 'A':
            case 'a': displayBoard[  y  ][ x+2 ] = '#';    //y is the row, just like y axis
                      displayBoard[ y-1 ][ x+1 ] = '#';    //x is the column, just like x axis
                      displayBoard[ y-1 ][ x+3 ] = '#';
                      displayBoard[ y-2 ][  x  ] = '#';
                      displayBoard[ y-2 ][ x+4 ] = '#';
                      displayBoard[ y-3 ][  x  ] = '#';
                      displayBoard[ y-3 ][ x+4 ] = '#';
                      displayBoard[ y-4 ][  x  ] = '#';
                      displayBoard[ y-4 ][ x+1 ] = '#';
                      displayBoard[ y-4 ][ x+2 ] = '#';
                      displayBoard[ y-4 ][ x+3 ] = '#';
                      displayBoard[ y-4 ][ x+4 ] = '#';
                      displayBoard[ y-5 ][  x  ] = '#';
                      displayBoard[ y-5 ][ x+4 ] = '#';
                      displayBoard[ y-6 ][  x  ] = '#';
                      displayBoard[ y-6 ][ x+4 ] = '#';
                      break;
            case 'B':
            case 'b': displayBoard[  y  ][  x  ] = '#';
                      displayBoard[  y  ][ x+1 ] = '#';
                      displayBoard[  y  ][ x+2 ] = '#';
                      displayBoard[  y  ][ x+3 ] = '#';
                      displayBoard[ y-1 ][  x  ] = '#';
                      displayBoard[ y-1 ][ x+4 ] = '#';
                      displayBoard[ y-2 ][  x  ] = '#';
                      displayBoard[ y-2 ][ x+4 ] = '#';
                      displayBoard[ y-3 ][  x  ] = '#';
                      displayBoard[ y-3 ][ x+1 ] = '#';
                      displayBoard[ y-3 ][ x+2 ] = '#';
                      displayBoard[ y-3 ][ x+3 ] = '#';
                      displayBoard[ y-4 ][  x  ] = '#';
                      displayBoard[ y-4 ][ x+4 ] = '#';
                      displayBoard[ y-5 ][  x  ] = '#';
                      displayBoard[ y-5 ][ x+4 ] = '#';
                      displayBoard[ y-6 ][  x  ] = '#';
                      displayBoard[ y-6 ][ x+1 ] = '#';
                      displayBoard[ y-6 ][ x+2 ] = '#';
                      displayBoard[ y-6 ][ x+3 ] = '#';
                      break;
            case 'C':
            case 'c': displayBoard[  y  ][ x+1 ] = '#';
                      displayBoard[  y  ][ x+2 ] = '#';
                      displayBoard[  y  ][ x+3 ] = '#';
                      displayBoard[ y-1 ][  x  ] = '#';
                      displayBoard[ y-1 ][ x+4 ] = '#';
                      displayBoard[ y-2 ][  x  ] = '#';
                      displayBoard[ y-3 ][  x  ] = '#';
                      displayBoard[ y-4 ][  x  ] = '#';
                      displayBoard[ y-5 ][  x  ] = '#';
                      displayBoard[ y-5 ][ x+4 ] = '#';
                      displayBoard[ y-6 ][ x+1 ] = '#';
                      displayBoard[ y-6 ][ x+2 ] = '#';
                      displayBoard[ y-6 ][ x+3 ] = '#';
                      break;
            case 'D':
            case 'd': displayBoard[  y  ][  x  ] = '#';
                      displayBoard[  y  ][ x+1 ] = '#';
                      displayBoard[  y  ][ x+2 ] = '#';
                      displayBoard[  y  ][ x+3 ] = '#';
                      displayBoard[ y-1 ][  x  ] = '#';
                      displayBoard[ y-1 ][ x+4 ] = '#';
                      displayBoard[ y-2 ][  x  ] = '#';
                      displayBoard[ y-2 ][ x+4 ] = '#';
                      displayBoard[ y-3 ][  x  ] = '#';
                      displayBoard[ y-3 ][ x+4 ] = '#';
                      displayBoard[ y-4 ][  x  ] = '#';
                      displayBoard[ y-4 ][ x+4 ] = '#';
                      displayBoard[ y-5 ][  x  ] = '#';
                      displayBoard[ y-5 ][ x+4 ] = '#';
                      displayBoard[ y-6 ][  x  ] = '#';
                      displayBoard[ y-6 ][ x+1 ] = '#';
                      displayBoard[ y-6 ][ x+2 ] = '#';
                      displayBoard[ y-6 ][ x+3 ] = '#';
                      break;
            case 'E':
            case 'e': displayBoard[  y  ][  x  ] = '#';
                      displayBoard[  y  ][ x+1 ] = '#';
                      displayBoard[  y  ][ x+2 ] = '#';
                      displayBoard[  y  ][ x+3 ] = '#';
                      displayBoard[  y  ][ x+4 ] = '#';
                      displayBoard[ y-1 ][  x  ] = '#';
                      displayBoard[ y-2 ][  x  ] = '#';
                      displayBoard[ y-3 ][  x  ] = '#';
                      displayBoard[ y-3 ][ x+1 ] = '#';
                      displayBoard[ y-3 ][ x+2 ] = '#';
                      displayBoard[ y-3 ][ x+3 ] = '#';
                      displayBoard[ y-4 ][  x  ] = '#';
                      displayBoard[ y-5 ][  x  ] = '#';
                      displayBoard[ y-6 ][  x  ] = '#';
                      displayBoard[ y-6 ][ x+1 ] = '#';
                      displayBoard[ y-6 ][ x+2 ] = '#';
                      displayBoard[ y-6 ][ x+3 ] = '#';
                      displayBoard[ y-6 ][ x+4 ] = '#';
                      break;
            case 'F':
            case 'f': displayBoard[  y  ][  x  ] = '#';
                      displayBoard[  y  ][ x+1 ] = '#';
                      displayBoard[  y  ][ x+2 ] = '#';
                      displayBoard[  y  ][ x+3 ] = '#';
                      displayBoard[  y  ][ x+4 ] = '#';
                      displayBoard[ y-1 ][  x  ] = '#';
                      displayBoard[ y-2 ][  x  ] = '#';
                      displayBoard[ y-3 ][  x  ] = '#';
                      displayBoard[ y-3 ][ x+1 ] = '#';
                      displayBoard[ y-3 ][ x+2 ] = '#';
                      displayBoard[ y-3 ][ x+3 ] = '#';
                      displayBoard[ y-4 ][  x  ] = '#';
                      displayBoard[ y-5 ][  x  ] = '#';
                      displayBoard[ y-6 ][  x  ] = '#';
                      break;
            case 'G':
            case 'g': displayBoard[  y  ][ x+1 ] = '#';
                      displayBoard[  y  ][ x+2 ] = '#';
                      displayBoard[  y  ][ x+3 ] = '#';
                      displayBoard[  y  ][ x+4 ] = '#';
                      displayBoard[ y-1 ][  x  ] = '#';
                      displayBoard[ y-2 ][  x  ] = '#';
                      displayBoard[ y-3 ][  x  ] = '#';
                      displayBoard[ y-4 ][  x  ] = '#';
                      displayBoard[ y-4 ][ x+3 ] = '#';
                      displayBoard[ y-4 ][ x+4 ] = '#';
                      displayBoard[ y-5 ][  x  ] = '#';
                      displayBoard[ y-5 ][ x+4 ] = '#';
                      displayBoard[ y-6 ][ x+1 ] = '#';
                      displayBoard[ y-6 ][ x+2 ] = '#';
                      displayBoard[ y-6 ][ x+3 ] = '#';
                      displayBoard[ y-6 ][ x+4 ] = '#';
                      break;
            case 'H':
            case 'h': displayBoard[  y  ][  x  ] = '#';
                      displayBoard[  y  ][ x+4 ] = '#';
                      displayBoard[ y-1 ][  x  ] = '#';
                      displayBoard[ y-1 ][ x+4 ] = '#';
                      displayBoard[ y-2 ][  x  ] = '#';
                      displayBoard[ y-2 ][ x+4 ] = '#';
                      displayBoard[ y-3 ][  x  ] = '#';
                      displayBoard[ y-3 ][ x+1 ] = '#';
                      displayBoard[ y-3 ][ x+2 ] = '#';
                      displayBoard[ y-3 ][ x+3 ] = '#';
                      displayBoard[ y-3 ][ x+4 ] = '#';
                      displayBoard[ y-4 ][  x  ] = '#';
                      displayBoard[ y-4 ][ x+4 ] = '#';
                      displayBoard[ y-5 ][  x  ] = '#';
                      displayBoard[ y-5 ][ x+4 ] = '#';
                      displayBoard[ y-6 ][  x  ] = '#';
                      displayBoard[ y-6 ][ x+4 ] = '#';
                      break;
            case 'I':
            case 'i': displayBoard[  y  ][ x+1 ] = '#';
                      displayBoard[  y  ][ x+2 ] = '#';
                      displayBoard[  y  ][ x+3 ] = '#';
                      displayBoard[ y-1 ][ x+2 ] = '#';
                      displayBoard[ y-2 ][ x+2 ] = '#';
                      displayBoard[ y-3 ][ x+2 ] = '#';
                      displayBoard[ y-4 ][ x+2 ] = '#';
                      displayBoard[ y-5 ][ x+2 ] = '#';
                      displayBoard[ y-6 ][ x+1 ] = '#';
                      displayBoard[ y-6 ][ x+2 ] = '#';
                      displayBoard[ y-6 ][ x+3 ] = '#';
                      break;
            case 'J':
            case 'j': displayBoard[  y  ][ x+4 ] = '#';
                      displayBoard[ y-1 ][ x+4 ] = '#';
                      displayBoard[ y-2 ][ x+4 ] = '#';
                      displayBoard[ y-3 ][ x+4 ] = '#';
                      displayBoard[ y-4 ][ x+4 ] = '#';
                      displayBoard[ y-5 ][  x  ] = '#';
                      displayBoard[ y-5 ][ x+4 ] = '#';
                      displayBoard[ y-6 ][ x+1 ] = '#';
                      displayBoard[ y-6 ][ x+2 ] = '#';
                      displayBoard[ y-6 ][ x+3 ] = '#';
                      break;
            case 'K':
            case 'k': displayBoard[  y  ][  x  ] = '#';
                      displayBoard[  y  ][ x+4 ] = '#';
                      displayBoard[ y-1 ][  x  ] = '#';
                      displayBoard[ y-1 ][ x+3 ] = '#';
                      displayBoard[ y-2 ][  x  ] = '#';
                      displayBoard[ y-2 ][ x+2 ] = '#';
                      displayBoard[ y-3 ][  x  ] = '#';
                      displayBoard[ y-3 ][ x+1 ] = '#';
                      displayBoard[ y-4 ][  x  ] = '#';
                      displayBoard[ y-4 ][ x+2 ] = '#';
                      displayBoard[ y-5 ][  x  ] = '#';
                      displayBoard[ y-5 ][ x+3 ] = '#';
                      displayBoard[ y-6 ][  x  ] = '#';
                      displayBoard[ y-6 ][ x+4 ] = '#';
                      break;
            case 'L':
            case 'l': displayBoard[  y  ][  x  ] = '#';
                      displayBoard[ y-1 ][  x  ] = '#';
                      displayBoard[ y-2 ][  x  ] = '#';
                      displayBoard[ y-3 ][  x  ] = '#';
                      displayBoard[ y-4 ][  x  ] = '#';
                      displayBoard[ y-5 ][  x  ] = '#';
                      displayBoard[ y-6 ][  x  ] = '#';
                      displayBoard[ y-6 ][ x+1 ] = '#';
                      displayBoard[ y-6 ][ x+2 ] = '#';
                      displayBoard[ y-6 ][ x+3 ] = '#';
                      displayBoard[ y-6 ][ x+4 ] = '#';
                      break;
            case 'M':
            case 'm': displayBoard[  y  ][  x  ] = '#';
                      displayBoard[  y  ][ x+4 ] = '#';
                      displayBoard[ y-1 ][  x  ] = '#';
                      displayBoard[ y-1 ][ x+1 ] = '#';
                      displayBoard[ y-1 ][ x+3 ] = '#';
                      displayBoard[ y-1 ][ x+4 ] = '#';
                      displayBoard[ y-2 ][  x  ] = '#';
                      displayBoard[ y-2 ][ x+2 ] = '#';
                      displayBoard[ y-2 ][ x+4 ] = '#';
                      displayBoard[ y-3 ][  x  ] = '#';
                      displayBoard[ y-3 ][ x+2 ] = '#';
                      displayBoard[ y-3 ][ x+4 ] = '#';
                      displayBoard[ y-4 ][  x  ] = '#';
                      displayBoard[ y-4 ][ x+4 ] = '#';
                      displayBoard[ y-5 ][  x  ] = '#';
                      displayBoard[ y-5 ][ x+4 ] = '#';
                      displayBoard[ y-6 ][  x  ] = '#';
                      displayBoard[ y-6 ][ x+4 ] = '#';
                      break;
            case 'N':
            case 'n': displayBoard[  y  ][  x  ] = '#';
                      displayBoard[  y  ][ x+4 ] = '#';
                      displayBoard[ y-1 ][  x  ] = '#';
                      displayBoard[ y-1 ][ x+4 ] = '#';
                      displayBoard[ y-2 ][  x  ] = '#';
                      displayBoard[ y-2 ][ x+1 ] = '#';
                      displayBoard[ y-2 ][ x+4 ] = '#';
                      displayBoard[ y-3 ][  x  ] = '#';
                      displayBoard[ y-3 ][ x+2 ] = '#';
                      displayBoard[ y-3 ][ x+4 ] = '#';
                      displayBoard[ y-4 ][  x  ] = '#';
                      displayBoard[ y-4 ][ x+3 ] = '#';
                      displayBoard[ y-4 ][ x+4 ] = '#';
                      displayBoard[ y-5 ][  x  ] = '#';
                      displayBoard[ y-5 ][ x+4 ] = '#';
                      displayBoard[ y-6 ][  x  ] = '#';
                      displayBoard[ y-6 ][ x+4 ] = '#';
                      break;
            case 'O':
            case 'o': displayBoard[  y  ][ x+1 ] = '#';
                      displayBoard[  y  ][ x+2 ] = '#';
                      displayBoard[  y  ][ x+3 ] = '#';
                      displayBoard[ y-1 ][  x  ] = '#';
                      displayBoard[ y-1 ][ x+4 ] = '#';
                      displayBoard[ y-2 ][  x  ] = '#';
                      displayBoard[ y-2 ][ x+4 ] = '#';
                      displayBoard[ y-3 ][  x  ] = '#';
                      displayBoard[ y-3 ][ x+4 ] = '#';
                      displayBoard[ y-4 ][  x  ] = '#';
                      displayBoard[ y-4 ][ x+4 ] = '#';
                      displayBoard[ y-5 ][  x  ] = '#';
                      displayBoard[ y-5 ][ x+4 ] = '#';
                      displayBoard[ y-6 ][ x+1 ] = '#';
                      displayBoard[ y-6 ][ x+2 ] = '#';
                      displayBoard[ y-6 ][ x+3 ] = '#';
                      break;
            case 'P':
            case 'p': displayBoard[  y  ][  x  ] = '#';
                      displayBoard[  y  ][ x+1 ] = '#';
                      displayBoard[  y  ][ x+2 ] = '#';
                      displayBoard[  y  ][ x+3 ] = '#';
                      displayBoard[ y-1 ][  x  ] = '#';
                      displayBoard[ y-1 ][ x+4 ] = '#';
                      displayBoard[ y-2 ][  x  ] = '#';
                      displayBoard[ y-2 ][ x+4 ] = '#';
                      displayBoard[ y-3 ][  x  ] = '#';
                      displayBoard[ y-3 ][ x+1 ] = '#';
                      displayBoard[ y-3 ][ x+2 ] = '#';
                      displayBoard[ y-3 ][ x+3 ] = '#';
                      displayBoard[ y-4 ][  x  ] = '#';
                      displayBoard[ y-5 ][  x  ] = '#';
                      displayBoard[ y-6 ][  x  ] = '#';
                      break;
            case 'Q':
            case 'q': displayBoard[  y  ][ x+1 ] = '#';
                      displayBoard[  y  ][ x+2 ] = '#';
                      displayBoard[  y  ][ x+3 ] = '#';
                      displayBoard[ y-1 ][  x  ] = '#';
                      displayBoard[ y-1 ][ x+4 ] = '#';
                      displayBoard[ y-2 ][  x  ] = '#';
                      displayBoard[ y-2 ][ x+4 ] = '#';
                      displayBoard[ y-3 ][  x  ] = '#';
                      displayBoard[ y-3 ][ x+4 ] = '#';
                      displayBoard[ y-4 ][  x  ] = '#';
                      displayBoard[ y-4 ][ x+2 ] = '#';
                      displayBoard[ y-4 ][ x+4 ] = '#';
                      displayBoard[ y-5 ][  x  ] = '#';
                      displayBoard[ y-5 ][ x+3 ] = '#';
                      displayBoard[ y-6 ][ x+1 ] = '#';
                      displayBoard[ y-6 ][ x+2 ] = '#';
                      displayBoard[ y-6 ][ x+4 ] = '#';
                      break;
            case 'R':
            case 'r': displayBoard[  y  ][  x  ] = '#';
                      displayBoard[  y  ][ x+1 ] = '#';
                      displayBoard[  y  ][ x+2 ] = '#';
                      displayBoard[  y  ][ x+3 ] = '#';
                      displayBoard[ y-1 ][  x  ] = '#';
                      displayBoard[ y-1 ][ x+4 ] = '#';
                      displayBoard[ y-2 ][  x  ] = '#';
                      displayBoard[ y-2 ][ x+4 ] = '#';
                      displayBoard[ y-3 ][  x  ] = '#';
                      displayBoard[ y-3 ][ x+1 ] = '#';
                      displayBoard[ y-3 ][ x+2 ] = '#';
                      displayBoard[ y-3 ][ x+3 ] = '#';
                      displayBoard[ y-4 ][  x  ] = '#';
                      displayBoard[ y-4 ][ x+2 ] = '#';
                      displayBoard[ y-5 ][  x  ] = '#';
                      displayBoard[ y-5 ][ x+3 ] = '#';
                      displayBoard[ y-6 ][  x  ] = '#';
                      displayBoard[ y-6 ][ x+4 ] = '#';
                      break;
            case 'S':
            case 's': displayBoard[  y  ][ x+1 ] = '#';
                      displayBoard[  y  ][ x+2 ] = '#';
                      displayBoard[  y  ][ x+3 ] = '#';
                      displayBoard[ y-1 ][  x  ] = '#';
                      displayBoard[ y-1 ][ x+4 ] = '#';
                      displayBoard[ y-2 ][  x  ] = '#';
                      displayBoard[ y-3 ][ x+1 ] = '#';
                      displayBoard[ y-3 ][ x+2 ] = '#';
                      displayBoard[ y-3 ][ x+3 ] = '#';
                      displayBoard[ y-4 ][ x+4 ] = '#';
                      displayBoard[ y-5 ][  x  ] = '#';
                      displayBoard[ y-5 ][ x+4 ] = '#';
                      displayBoard[ y-6 ][ x+1 ] = '#';
                      displayBoard[ y-6 ][ x+2 ] = '#';
                      displayBoard[ y-6 ][ x+3 ] = '#';
                      break;
            case 'T':
            case 't': displayBoard[  y  ][  x  ] = '#';
                      displayBoard[  y  ][ x+1 ] = '#';
                      displayBoard[  y  ][ x+2 ] = '#';
                      displayBoard[  y  ][ x+3 ] = '#';
                      displayBoard[  y  ][ x+4 ] = '#';
                      displayBoard[ y-1 ][ x+2 ] = '#';
                      displayBoard[ y-2 ][ x+2 ] = '#';
                      displayBoard[ y-3 ][ x+2 ] = '#';
                      displayBoard[ y-4 ][ x+2 ] = '#';
                      displayBoard[ y-5 ][ x+2 ] = '#';
                      displayBoard[ y-6 ][ x+2 ] = '#';
                      break;
            case 'U':
            case 'u': displayBoard[  y  ][  x  ] = '#';
                      displayBoard[  y  ][ x+4 ] = '#';
                      displayBoard[ y-1 ][  x  ] = '#';
                      displayBoard[ y-1 ][ x+4 ] = '#';
                      displayBoard[ y-2 ][  x  ] = '#';
                      displayBoard[ y-2 ][ x+4 ] = '#';
                      displayBoard[ y-3 ][  x  ] = '#';
                      displayBoard[ y-3 ][ x+4 ] = '#';
                      displayBoard[ y-4 ][  x  ] = '#';
                      displayBoard[ y-4 ][ x+4 ] = '#';
                      displayBoard[ y-5 ][  x  ] = '#';
                      displayBoard[ y-5 ][ x+4 ] = '#';
                      displayBoard[ y-6 ][ x+1 ] = '#';
                      displayBoard[ y-6 ][ x+2 ] = '#';
                      displayBoard[ y-6 ][ x+3 ] = '#';
                      break;
            case 'V':
            case 'v': displayBoard[  y  ][  x  ] = '#';
                      displayBoard[  y  ][ x+4 ] = '#';
                      displayBoard[ y-1 ][  x  ] = '#';
                      displayBoard[ y-1 ][ x+4 ] = '#';
                      displayBoard[ y-2 ][  x  ] = '#';
                      displayBoard[ y-2 ][ x+4 ] = '#';
                      displayBoard[ y-3 ][  x  ] = '#';
                      displayBoard[ y-3 ][ x+4 ] = '#';
                      displayBoard[ y-4 ][  x  ] = '#';
                      displayBoard[ y-4 ][ x+4 ] = '#';
                      displayBoard[ y-5 ][ x+1 ] = '#';
                      displayBoard[ y-5 ][ x+3 ] = '#';
                      displayBoard[ y-6 ][ x+2 ] = '#';
                      break;
            case 'W':
            case 'w': displayBoard[  y  ][  x  ] = '#';
                      displayBoard[  y  ][ x+4 ] = '#';
                      displayBoard[ y-1 ][  x  ] = '#';
                      displayBoard[ y-1 ][ x+4 ] = '#';
                      displayBoard[ y-2 ][  x  ] = '#';
                      displayBoard[ y-2 ][ x+4 ] = '#';
                      displayBoard[ y-3 ][  x  ] = '#';
                      displayBoard[ y-3 ][ x+2 ] = '#';
                      displayBoard[ y-3 ][ x+4 ] = '#';
                      displayBoard[ y-4 ][  x  ] = '#';
                      displayBoard[ y-4 ][ x+2 ] = '#';
                      displayBoard[ y-4 ][ x+4 ] = '#';
                      displayBoard[ y-5 ][  x  ] = '#';
                      displayBoard[ y-5 ][ x+1 ] = '#';
                      displayBoard[ y-5 ][ x+3 ] = '#';
                      displayBoard[ y-5 ][ x+4 ] = '#';
                      displayBoard[ y-6 ][  x  ] = '#';
                      displayBoard[ y-6 ][ x+4 ] = '#';
                      break;
            case 'X':
            case 'x': displayBoard[  y  ][  x  ] = '#';
                      displayBoard[  y  ][ x+4 ] = '#';
                      displayBoard[ y-1 ][  x  ] = '#';
                      displayBoard[ y-1 ][ x+4 ] = '#';
                      displayBoard[ y-2 ][ x+1 ] = '#';
                      displayBoard[ y-2 ][ x+3 ] = '#';
                      displayBoard[ y-3 ][ x+2 ] = '#';
                      displayBoard[ y-4 ][ x+1 ] = '#';
                      displayBoard[ y-4 ][ x+3 ] = '#';
                      displayBoard[ y-5 ][  x  ] = '#';
                      displayBoard[ y-5 ][ x+4 ] = '#';
                      displayBoard[ y-6 ][  x  ] = '#';
                      displayBoard[ y-6 ][ x+4 ] = '#';
                      break;
            case 'Y':
            case 'y': displayBoard[  y  ][  x  ] = '#';
                      displayBoard[  y  ][ x+4 ] = '#';
                      displayBoard[ y-1 ][  x  ] = '#';
                      displayBoard[ y-1 ][ x+4 ] = '#';
                      displayBoard[ y-2 ][ x+1 ] = '#';
                      displayBoard[ y-2 ][ x+3 ] = '#';
                      displayBoard[ y-3 ][ x+2 ] = '#';
                      displayBoard[ y-4 ][ x+2 ] = '#';
                      displayBoard[ y-5 ][ x+2 ] = '#';
                      displayBoard[ y-6 ][ x+2 ] = '#';
                      break;
            case 'Z':
            case 'z': displayBoard[  y  ][  x  ] = '#';
                      displayBoard[  y  ][ x+1 ] = '#';
                      displayBoard[  y  ][ x+2 ] = '#';
                      displayBoard[  y  ][ x+3 ] = '#';
                      displayBoard[  y  ][ x+4 ] = '#';
                      displayBoard[ y-1 ][ x+4 ] = '#';
                      displayBoard[ y-2 ][ x+3 ] = '#';
                      displayBoard[ y-3 ][ x+2 ] = '#';
                      displayBoard[ y-4 ][ x+1 ] = '#';
                      displayBoard[ y-5 ][  x  ] = '#';
                      displayBoard[ y-6 ][  x  ] = '#';
                      displayBoard[ y-6 ][ x+1 ] = '#';
                      displayBoard[ y-6 ][ x+2 ] = '#';
                      displayBoard[ y-6 ][ x+3 ] = '#';
                      displayBoard[ y-6 ][ x+4 ] = '#';
                      break;
            case '0': displayBoard[  y  ][ x+1 ] = '#';
                      displayBoard[  y  ][ x+2 ] = '#';
                      displayBoard[  y  ][ x+3 ] = '#';
                      displayBoard[ y-1 ][  x  ] = '#';
                      displayBoard[ y-1 ][ x+4 ] = '#';
                      displayBoard[ y-2 ][  x  ] = '#';
                      displayBoard[ y-2 ][ x+3 ] = '#';
                      displayBoard[ y-2 ][ x+4 ] = '#';
                      displayBoard[ y-3 ][  x  ] = '#';
                      displayBoard[ y-3 ][ x+2 ] = '#';
                      displayBoard[ y-3 ][ x+4 ] = '#';
                      displayBoard[ y-4 ][  x  ] = '#';
                      displayBoard[ y-4 ][ x+1 ] = '#';
                      displayBoard[ y-4 ][ x+4 ] = '#';
                      displayBoard[ y-5 ][  x  ] = '#';
                      displayBoard[ y-5 ][ x+4 ] = '#';
                      displayBoard[ y-6 ][ x+1 ] = '#';
                      displayBoard[ y-6 ][ x+2 ] = '#';
                      displayBoard[ y-6 ][ x+3 ] = '#';
                      break;
            case '1': displayBoard[  y  ][ x+2 ] = '#';
                      displayBoard[ y-1 ][ x+1 ] = '#';
                      displayBoard[ y-1 ][ x+2 ] = '#';
                      displayBoard[ y-2 ][ x+2 ] = '#';
                      displayBoard[ y-3 ][ x+2 ] = '#';
                      displayBoard[ y-4 ][ x+2 ] = '#';
                      displayBoard[ y-5 ][ x+2 ] = '#';
                      displayBoard[ y-6 ][ x+1 ] = '#';
                      displayBoard[ y-6 ][ x+2 ] = '#';
                      displayBoard[ y-6 ][ x+3 ] = '#';
                      break;
            case '2': displayBoard[  y  ][ x+1 ] = '#';
                      displayBoard[  y  ][ x+2 ] = '#';
                      displayBoard[  y  ][ x+3 ] = '#';
                      displayBoard[ y-1 ][  x  ] = '#';
                      displayBoard[ y-1 ][ x+4 ] = '#';
                      displayBoard[ y-2 ][ x+4 ] = '#';
                      displayBoard[ y-3 ][ x+2 ] = '#';
                      displayBoard[ y-3 ][ x+3 ] = '#';
                      displayBoard[ y-4 ][ x+1 ] = '#';
                      displayBoard[ y-5 ][  x  ] = '#';
                      displayBoard[ y-6 ][  x  ] = '#';
                      displayBoard[ y-6 ][ x+1 ] = '#';
                      displayBoard[ y-6 ][ x+2 ] = '#';
                      displayBoard[ y-6 ][ x+3 ] = '#';
                      displayBoard[ y-6 ][ x+4 ] = '#';
                      break;
            case '3': displayBoard[  y  ][  x  ] = '#';
                      displayBoard[  y  ][ x+1 ] = '#';
                      displayBoard[  y  ][ x+2 ] = '#';
                      displayBoard[  y  ][ x+3 ] = '#';
                      displayBoard[  y  ][ x+4 ] = '#';
                      displayBoard[ y-1 ][ x+4 ] = '#';
                      displayBoard[ y-2 ][ x+3 ] = '#';
                      displayBoard[ y-3 ][ x+2 ] = '#';
                      displayBoard[ y-3 ][ x+3 ] = '#';
                      displayBoard[ y-4 ][ x+4 ] = '#';
                      displayBoard[ y-5 ][  x  ] = '#';
                      displayBoard[ y-5 ][ x+4 ] = '#';
                      displayBoard[ y-6 ][ x+1 ] = '#';
                      displayBoard[ y-6 ][ x+2 ] = '#';
                      displayBoard[ y-6 ][ x+3 ] = '#';
                      break;
            case '4': displayBoard[  y  ][ x+3 ] = '#';
                      displayBoard[ y-1 ][ x+2 ] = '#';
                      displayBoard[ y-1 ][ x+3 ] = '#';
                      displayBoard[ y-2 ][ x+1 ] = '#';
                      displayBoard[ y-2 ][ x+3 ] = '#';
                      displayBoard[ y-3 ][  x  ] = '#';
                      displayBoard[ y-3 ][ x+3 ] = '#';
                      displayBoard[ y-4 ][  x  ] = '#';
                      displayBoard[ y-4 ][ x+1 ] = '#';
                      displayBoard[ y-4 ][ x+2 ] = '#';
                      displayBoard[ y-4 ][ x+3 ] = '#';
                      displayBoard[ y-4 ][ x+4 ] = '#';
                      displayBoard[ y-5 ][ x+3 ] = '#';
                      displayBoard[ y-6 ][ x+3 ] = '#';
                      break;
            case '5': displayBoard[  y  ][  x  ] = '#';
                      displayBoard[  y  ][ x+1 ] = '#';
                      displayBoard[  y  ][ x+2 ] = '#';
                      displayBoard[  y  ][ x+3 ] = '#';
                      displayBoard[  y  ][ x+4 ] = '#';
                      displayBoard[ y-1 ][  x  ] = '#';
                      displayBoard[ y-2 ][  x  ] = '#';
                      displayBoard[ y-2 ][ x+1 ] = '#';
                      displayBoard[ y-2 ][ x+2 ] = '#';
                      displayBoard[ y-2 ][ x+3 ] = '#';
                      displayBoard[ y-3 ][ x+4 ] = '#';
                      displayBoard[ y-4 ][ x+4 ] = '#';
                      displayBoard[ y-5 ][  x  ] = '#';
                      displayBoard[ y-5 ][ x+4 ] = '#';
                      displayBoard[ y-6 ][ x+1 ] = '#';
                      displayBoard[ y-6 ][ x+2 ] = '#';
                      displayBoard[ y-6 ][ x+3 ] = '#';
                      break;
            case '6': displayBoard[  y  ][ x+2 ] = '#';
                      displayBoard[  y  ][ x+3 ] = '#';
                      displayBoard[  y  ][ x+4 ] = '#';
                      displayBoard[ y-1 ][ x+1 ] = '#';
                      displayBoard[ y-2 ][  x  ] = '#';
                      displayBoard[ y-3 ][  x  ] = '#';
                      displayBoard[ y-3 ][ x+1 ] = '#';
                      displayBoard[ y-3 ][ x+2 ] = '#';
                      displayBoard[ y-3 ][ x+3 ] = '#';
                      displayBoard[ y-4 ][  x  ] = '#';
                      displayBoard[ y-4 ][ x+4 ] = '#';
                      displayBoard[ y-5 ][  x  ] = '#';
                      displayBoard[ y-5 ][ x+4 ] = '#';
                      displayBoard[ y-6 ][ x+1 ] = '#';
                      displayBoard[ y-6 ][ x+2 ] = '#';
                      displayBoard[ y-6 ][ x+3 ] = '#';
                      break;
            case '7': displayBoard[  y  ][  x  ] = '#';
                      displayBoard[  y  ][ x+1 ] = '#';
                      displayBoard[  y  ][ x+2 ] = '#';
                      displayBoard[  y  ][ x+3 ] = '#';
                      displayBoard[  y  ][ x+4 ] = '#';
                      displayBoard[ y-1 ][ x+4 ] = '#';
                      displayBoard[ y-2 ][ x+3 ] = '#';
                      displayBoard[ y-3 ][ x+2 ] = '#';
                      displayBoard[ y-4 ][ x+1 ] = '#';
                      displayBoard[ y-5 ][ x+1 ] = '#';
                      displayBoard[ y-6 ][ x+1 ] = '#';
                      break;
            case '8': displayBoard[  y  ][ x+1 ] = '#';
                      displayBoard[  y  ][ x+2 ] = '#';
                      displayBoard[  y  ][ x+3 ] = '#';
                      displayBoard[ y-1 ][  x  ] = '#';
                      displayBoard[ y-1 ][ x+4 ] = '#';
                      displayBoard[ y-2 ][  x  ] = '#';
                      displayBoard[ y-2 ][ x+4 ] = '#';
                      displayBoard[ y-3 ][ x+1 ] = '#';
                      displayBoard[ y-3 ][ x+2 ] = '#';
                      displayBoard[ y-3 ][ x+3 ] = '#';
                      displayBoard[ y-4 ][  x  ] = '#';
                      displayBoard[ y-4 ][ x+4 ] = '#';
                      displayBoard[ y-5 ][  x  ] = '#';
                      displayBoard[ y-5 ][ x+4 ] = '#';
                      displayBoard[ y-6 ][ x+1 ] = '#';
                      displayBoard[ y-6 ][ x+2 ] = '#';
                      displayBoard[ y-6 ][ x+3 ] = '#';
                      break;
            case '9': displayBoard[  y  ][ x+1 ] = '#';
                      displayBoard[  y  ][ x+2 ] = '#';
                      displayBoard[  y  ][ x+3 ] = '#';
                      displayBoard[ y-1 ][  x  ] = '#';
                      displayBoard[ y-1 ][ x+4 ] = '#';
                      displayBoard[ y-2 ][  x  ] = '#';
                      displayBoard[ y-2 ][ x+4 ] = '#';
                      displayBoard[ y-3 ][ x+1 ] = '#';
                      displayBoard[ y-3 ][ x+2 ] = '#';
                      displayBoard[ y-3 ][ x+3 ] = '#';
                      displayBoard[ y-3 ][ x+4 ] = '#';
                      displayBoard[ y-4 ][ x+4 ] = '#';
                      displayBoard[ y-5 ][ x+3 ] = '#';
                      displayBoard[ y-6 ][  x  ] = '#';
                      displayBoard[ y-6 ][ x+1 ] = '#';
                      displayBoard[ y-6 ][ x+2 ] = '#';
                      break;
            case '!': displayBoard[  y  ][ x+2 ] = '#';
                      displayBoard[ y-1 ][ x+2 ] = '#';
                      displayBoard[ y-2 ][ x+2 ] = '#';
                      displayBoard[ y-3 ][ x+2 ] = '#';
                      displayBoard[ y-4 ][ x+2 ] = '#';
                      displayBoard[ y-6 ][ x+2 ] = '#';
                      break;
            case '?': displayBoard[  y  ][ x+1 ] = '#';
                      displayBoard[  y  ][ x+2 ] = '#';
                      displayBoard[  y  ][ x+3 ] = '#';
                      displayBoard[ y-1 ][  x  ] = '#';
                      displayBoard[ y-1 ][ x+4 ] = '#';
                      displayBoard[ y-2 ][ x+4 ] = '#';
                      displayBoard[ y-3 ][ x+3 ] = '#';
                      displayBoard[ y-4 ][ x+2 ] = '#';
                      displayBoard[ y-6 ][ x+2 ] = '#';
                      break;
            default: break;                //other symbols, including space will be considered as a space
        }
        x+=6;                              //move 6 units from previous anchor dot to the next character
    }

    for(int j = 19; j >= 0; j--)
    {
        for(int i = 0; i <= 39; i++)
        {
            cout << displayBoard[j][i];    //printing out the whole display board with the newly assigned characters
        }
        cout << endl;
    }
}

