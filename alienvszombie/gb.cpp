#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // for system()
#include <ctime>   // for time() in srand( time(NULL) );
#include <iomanip> // for setw()
using namespace std;
// CLASS BOARD
class Board
{
private:
    vector<vector<char>> map_; // convention to put trailing underscore
    int row_, column_;         // to indicate private data
public:
    void init(int row, int column);
    void display() const;
    void setObject(int col, int row, char object);
};

// CREATE EMPTY ROWS & RESIZE IT AND PUT RANDOM CHAR INTO THE ARRAY VECTOR
void Board::init(int row, int column)
{
    row_ = row;
    column_ = column;
    char objects[] = {' ', ' ', ' ', 'h', 'r', 'p', '>', '<', '^', 'v'};
    char alien[] = {'A'};
    int noOfObjects = 10; // number of objects in the objects array
    // create dynamic 2D array using vector
    map_.resize(column_); // create empty rows
    for (int i = 0; i < column_; ++i)
    {
        map_[i].resize(row_); // resize each row
    }

    // put random characters into the vector array
    for (int i = 0; i < column_; ++i)
    {
        for (int j = 0; j < row_; ++j)
        {
            int objNo = rand() % noOfObjects;
            map_[i][j] = objects[objNo];
        }
    }
    // set the center of the map to 'A'
    map_[column_ / 2][row_ / 2] = 'A';
}

// DISPLAY BOARD
void Board::display() const
{
    cout << "                                         " << endl;
    cout << "         .: Alien vs Zombie :.           " << endl;
    cout << "                                         " << endl;
    cout << endl;
    // for each row
    for (int i = 0; i < column_; ++i)
    {
        // display upper border of the row
        cout << "  ";
        for (int j = 0; j < row_; ++j)
        {
            cout << "+-";
        }
        cout << "+" << endl;
        // display row number
        cout << setw(2) << (i + 1);
        // display cell content and border of each column
        for (int j = 0; j < row_; ++j)
        {
            cout << "|" << map_[i][j];
        }
        cout << "|" << endl;
    }
    // display lower border of the last row
    cout << "  ";
    for (int j = 0; j < row_; ++j)
    {
        cout << "+-";
    }
    cout << "+" << endl;
    // display column number
    cout << "  ";
    for (int j = 0; j < row_; ++j)
    {
        int digit = (j + 1) / 10;
        cout << " ";
        if (digit == 0)
            cout << " ";
        else
            cout << digit;
    }
    cout << endl;
    cout << "  ";
    for (int j = 0; j < row_; ++j)
    {
        cout << " " << (j + 1) % 10;
    }
    cout << endl
         << endl;
}
void charattributes() // declare function with void return type and no parameters
{
    int z = 3;                                            // initialize the number of zombies to generate
    int life[] = {50, 100, 100, 150, 150, 200, 250, 300}; // array of possible life values for zombies
    int numoflife = 8;                                    // the number of possible life values

    int zombiettack[] = {5, 10, 10, 15, 20, 25, 30}; // array of possible attack values for zombies
    int numofzombie = 7;                             // the number of possible attack values

    int range[] = {1, 2, 3, 4, 5}; // array of possible range values for zombies
    int numofrange = 5;            // the number of possible range values

    // print the attributes of the Alien character
    cout << "Alien    : Life 100 , Attack " << endl;

    // generate the attributes for each zombie and print them
    for (int w = 0; w < z; ++w)
    {
        int objlife = rand() % numoflife;     // randomly select a life value for this zombie
        int objzomatt = rand() % numofzombie; // randomly select an attack value for this zombie
        int objrange = rand() % numofrange;   // randomly select a range value for this zombie

        // ensure that attack is not higher than life
        if (objzomatt > objlife)
            objzomatt = objlife / 2;

        // ensure that range is not larger than any dimension of the game board
        int row_ = 0;    // or any other initial value
        int column_ = 0; // or any other initial value

        if (objrange > min(row_, column_))
            objrange = min(row_, column_) / 2;

        cout << "Zombie " << w + 1 << " : Life " << life[objlife] << ", Attack " << zombiettack[objzomatt] << ", Range " << range[objrange] << endl;
    }
}

// CALLING DISPLAY FUNCTION
void displayBoard(int row, int column)
{
    Board board;
    board.init(row, column);
    board.display();
}

// ACCEPT ODD NUMBERS
void oddNumbers(int &a)
{
    do
    {
        cin >> a;
        if (a & 2 != 0 && a != 1)
        {
            break;
        }
        else
        {
            cout << " Please enter ODD number only except 1! => ";
        }
    } while (a % 2 == 0 || a == 1);
    return;
}

int main()
{
    srand(1);          // use this for fixed map during testing
    srand(time(NULL)); // try this for random map

    int row, column;
    cout << "Enter the row (odd number only except 1): ";
    oddNumbers(row);
    cout << "Enter the column (odd number only except 1): ";
    oddNumbers(column);
    displayBoard(row, column);
    charattributes(); // call the charattributes function

    return 0;
}
