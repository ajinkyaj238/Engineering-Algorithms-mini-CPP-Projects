/**************************************************************************
* Project 1 TEAM 2
* author : Ajinkya Joshi, Anthony Chamoun
* Date : March 15, 2023
* File name : SodukoBoard.cpp - Solve Sudoku Puzzles using recursive algorithms
* Purpose : Reads in a puzzle of more from a files and solves them
* Usage : g++ SudokuBoard.cpp -o output
****************************************************************************/

#include "SudokuBoard.h"
#include <fstream>

using namespace std;

/**************************************************************************
 * Constructor
****************************************************************************/


/**
 * Initializes a new instance of the SudokuBoard class with the specified board size.
 * @param N: The size of the board
*/
SudokuBoard::SudokuBoard(int N) : boardSize(N)
{
    // Resize conflict matricies
    sdkMatrix.resize(N, N);
    c_rows.resize(N, N);
    c_cols.resize(N, N);
    c_sqs.resize(N, N);
    clearBoard();
}


/**************************************************************************
 * Starter methods
****************************************************************************/

/**
 * Clear the Sudoku board by setting all elements in the SDK matrix,
 * conflict rows, conflict columns, and conflict squares to Blank.
 * Parameters: None
 * Returns: None
 */
void SudokuBoard::clearBoard()
{
    // clears conflict matricies
    count = 0;
    for (int row = 0; row < boardSize; row++)
        for (int col = 0; col < boardSize; col++) {
            sdkMatrix[row][col] = Blank;
            c_rows[row][col] = Blank;
            c_cols[row][col] = Blank;
            c_sqs[row][col] = Blank;
        }
}


/**
 * Initializes the Sudoku board with values from a file input stream.
 * @param fin the input file stream to read values from
*/
void SudokuBoard::initializeBoard(ifstream& fin)
{
    int digit;
    char ch; // holds each value read from file
    clearBoard(); // clear the board first
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            fin >> ch;
            // If the read char is not Blank
            if (ch != '.') {
                digit = ch - '0';// Convert char to int
                sdkMatrix[i][j] = digit;
            }
        }
    }
}


/**************************************************************************
 * Methods involved in the algorithm
****************************************************************************/

/**
 * Check if the cell at the specified row and column position in the Sudoku board is empty or not.
 * @param row the row index of the cell to check
 * @param col the column index of the cell to check
 * @return true if the cell is empty, false otherwise
*/
bool SudokuBoard::findEmpty(int &row, int &col)
{
    // If the value of the cell at the specified position is Blank, return true
    if (sdkMatrix[row][col] == Blank)
    {
        return true;
    }

        // If the value of the cell at the specified position is not Blank, return false
    else
    {
        return false;
    }
}

/**
 * Checks for conflicts of a number in a given row, column, and 3x3 box square of the Sudoku board.
 * @param number The number to check for conflicts.
 * @param row The row to check for conflicts.
 * @param col The column to check for conflicts.
 * @return True if there are no conflicts, false if there are conflicts.
*/
bool SudokuBoard::checkConflicts(int &number, int &row, int &col)
{

    // checking for the row by iterating through each column in the row
    for(int colitr = 0; colitr < boardSize; colitr++)
    {
        if ((sdkMatrix[row][colitr] == number) && (colitr != col))
        {
            return false;
        }
    }

    // checking for the column by iterating through each row in the column
    for(int rowitr = 0; rowitr < boardSize; rowitr++)
    {
        if ((sdkMatrix[rowitr][col] == number) && (rowitr != row))
        {
            return false;
        }
    }

    // Checking each 3x3 square to find the box square integer division has been utilized.
    int box_y = row / 3; // y value is the row
    int box_x = col / 3; // x value is the col
    for(int colitr = (box_x*3); colitr < (box_x*3)+3; colitr++ )
        for(int rowitr = (box_y*3); rowitr < (box_y*3)+3; rowitr++ )
        {
            if ((sdkMatrix[rowitr][colitr] == number) && (colitr != col) && (rowitr != row))
            {
                return false;
            }
        }

    // if all for loops are satisfied - no conflict exists.
    return true;
}

/**
 * Finds the row index of the first empty cell in the Sudoku board.
 * @return The index of the first empty row, or 10 if the board is full.
*/
int SudokuBoard::emptyFinderrow()
{
    for(int row = 0; row < boardSize; row++)
        for(int col = 0; col < boardSize; col++)
        {
            if(findEmpty(row, col) == true)
            {
                return row;
            }
        }

    return 10;
}
/**
 * Finds the index of the first empty cell's column by iterating through the Sudoku board matrix row by row.
 * @return an integer representing the index of the first empty cell's column, or 10 if not found.
 */
int SudokuBoard::emptyFindercol()
{
    // iterate through each row of the matrix
    for(int row = 0; row < boardSize; row++)
        // iterate through each column of the matrix in the row
        for(int col = 0; col < boardSize; col++)
        {
            // if an empty cell is found, return its column index
            if(findEmpty(row, col) == true)
            {
                return col;
            }
        }

    // if no empty cell is found, return 10
    return 10;
}


/**
 * Recursive function to solve a Sudoku puzzle
 * @param recur an integer reference to keep track of the number of recursive calls
 * @param backtrack an integer reference to keep track of the number of times the function backtracks
 * @return a boolean value indicating if the Sudoku puzzle has been successfully solved
*/
bool SudokuBoard::solveSudoku(int& recur, int& backtrack)
{
    recur += 1; // increase the recursive call count

    // if there are no empty cells left, the puzzle is solved
    if(emptyFindercol() == 10 || emptyFinderrow() == 10)
    {
        return true;
    }
    else
    {
        int row = emptyFinderrow();
        int col = emptyFindercol();
        // iterate through possible values for the cell
        for(int number = 1; number < boardSize + 1; number++)
        {
            // check if the value conflicts with any values in the row, column, or 3x3 box
            if (checkConflicts(number,row,col))
            {
                // if there are no conflicts, assign the value to the cell and recursively call the function
                sdkMatrix[row][col] = number;

                bool solution = solveSudoku(recur, backtrack);
                if (solution == false)
                {
                    backtrack++;
                }
                if (solution == true)
                {
                    return true;
                }

                // if a solution is not found, backtrack by resetting the cell value to Blank
                sdkMatrix[row][col] = Blank;
            }
        }

        // if all possible values have been tried and a solution has not been found, backtrack
        return false;
    }
}

/**************************************************************************/



/**
 * Prints out the current state of the sudoku board to both the console and a specified output file.
 * @param out - An output file to write the sudoku board to.
 * @return void
*/
void SudokuBoard::printSudoku(ofstream& out)
{
    // Prints the board to console
    for (int i = 1; i <= boardSize; i++)
    {
        if ((i - 1) % SquareSize == 0)
        {
            for (int j = 1; j <= boardSize + 1; j++)
                cout << "---";
            cout << endl;
        }
        for (int j = 1; j < boardSize + 1; j++)
        {
            if ((j - 1) % SquareSize == 0)
                cout << "|";
            if (sdkMatrix[i - 1][j - 1] != Blank)
                cout << " " << sdkMatrix[i - 1][j - 1] << " "; // prints out number
            else
                cout << " - "; // prints blank indicating no number.
        }
        cout << "|";
        cout << endl;
    }
    cout << " -";
    for (int j = 1; j <= boardSize - 1; j++)
        cout << "---";
    cout << "-";
    cout << endl;

    // Prints the board to the output file
    for (int i = 1; i <= boardSize; i++)
    {
        if ((i - 1) % SquareSize == 0)
        {
            for (int j = 1; j <= boardSize + 1; j++)
                out << "---";
            out << endl;
        }
        for (int j = 1; j < boardSize + 1; j++)
        {
            if ((j - 1) % SquareSize == 0)
                out << "|";
            if (sdkMatrix[i - 1][j - 1] != Blank)
                out << " " << sdkMatrix[i - 1][j - 1] << " "; // prints out number
            else
                out << " - "; // prints blank indicating no number.
        }
        out << "|";
        out << endl;
    }
    out << " -";
    for (int j = 1; j <= boardSize - 1; j++)
        out << "---";
    out << "-";
    out << endl;
}


/**
 * Sets the conflict arrays for the current SudokuBoard object based on the current state of the board.
 * The conflict arrays are used to keep track of which numbers are already present in each row, column and sub-square.
 * This function iterates over each cell of the board, and for each non-zero cell value, it updates the corresponding
 * conflict arrays.
 * @return void
 */
void SudokuBoard::setConflict() {
    // does exactly that
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            if (sdkMatrix[i][j] != 0) {
                int k = sdkMatrix[i][j];
                int a = findLocation(j, i);
                c_rows[j][k - 1] = 1;
                c_cols[i][k - 1] = 1;
                c_sqs[a][k - 1] = 1;
            }
        }
    }
}


/**
 * This method prints the conflicts on the Sudoku board to both the console and a given output file.
 * It starts by printing square conflicts to the console, followed by row conflicts, and then column conflicts.
 * It then prints the same information to a text file.
 * @param out The output file to write to
*/
void SudokuBoard::printConflict(ofstream& out) {
    cout << "square conflicts" << endl;
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            cout << c_sqs[i][j];
        }
        cout << endl;
    }
    cout << "row conflicts" << endl;
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            cout << c_cols[i][j];
        }
        cout << endl;
    }
    cout << "col conflicts" << endl;
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            cout << c_rows[i][j];
        }
        cout << endl;
    }

    // prints same thing to textfile
    out << "square conflicts" << endl;
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            out << c_sqs[i][j];
        }
        out << endl;
    }
    out << "col conflicts" << endl;
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            out << c_cols[i][j];
        }
        out << endl;
    }
    out << "row conflicts" << endl;
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            out << c_rows[i][j];
        }
        out << endl;
    }
}


/**
 * Given the row and column numbers, returns the location (0-8) of the corresponding 3x3 subgrid.
 * @param row: integer representing the row number (0-based index)
 * @param col: integer representing the column number (0-based index)
 * @return integer representing the location of the 3x3 subgrid (0-8)
 */
int SudokuBoard::findLocation(int row, int col) {
    // determine the location based on the row and column numbers
    if (row + 1 <= boardSize / 3) {
        if (col + 1 <= boardSize / 3) {
            return 0;
        }
        else if (col + 1 <= 2 * (boardSize / 3)) {
            return 3;
        }
        else if (col + 1 <= boardSize) {
            return 6;
        }
    }
    if (row + 1 <= 2 * (boardSize / 3)) {
        if (col + 1 <= boardSize / 3) {
            return 1;
        }
        else if (col + 1 <= 2 * (boardSize / 3)) {
            return 4;
        }
        else if (col + 1 <= boardSize) {
            return 7;
        }
    }
    if (row + 1 <= boardSize) {
        if (col + 1 <= boardSize / 3) {
            return 2;
        }
        else if (col + 1 <= 2 * (boardSize / 3)) {
            return 5;
        }
        else if (col + 1 <= boardSize) {
            return 8;
        }
    }
}



/**************************************************************************
* Project 1 TEAM 2
* author          :Ajinkya Joshi, Anthony Chamoun
* Date            :March 15th, 2023
* File name       :main.cpp
* Purpose         :Solve sudoku boards
 **************************************************************************/

#include <fstream>
#include <iostream>
#include "SudokuBoard.h"
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;


int main() {
    int recursiveCount; // # of recursive calls
    int backtracksCount; // # of backtracks involved for each board
    int boardCount = 0; // # of Boards from file
    int boardSize = 9;
    int solved = 0; // # of boards solved
    int nosolve = 0; // # of boards not solved

    vector<int> recur;
    vector<int> backtr;

    // Create SudokuBoard object
    SudokuBoard* sdk = new SudokuBoard(boardSize);
    // Open the data file and verify it opens successfully


    // opens sudoku input file
    ifstream fin;
    fin.open("/Users/ajinkyajoshi/CLionProjects/algo_project_2/Sudoku3Puzzles.txt");
    if (!fin)
    {
        cerr << "Cannot open 'sudoku1.txt'" << endl;
        exit(1);
    }

    // opens and creates output file
    ofstream out;
    out.open("/Users/ajinkyajoshi/CLionProjects/algo_project_2/Output.txt");
    if (!out) {
        cerr << "Cannot open file << endl";
        exit(1);
    }

    // Each iterations solves a NEW board from the input file
    while (fin && fin.peek() != 'Z') {
        recursiveCount = 0; // Reset # of recursive calls
        backtracksCount = 0; // Reset # of backtrack calls
        boardCount++; // New board to be solved
        // Initialize sudoku matrix

        sdk->initializeBoard(fin); // reads Sudoku from file
        // Print sudoku
        cout << "\n***** NEW SUDOKU PUZZLE... ******" << endl;
        out << "\n***** NEW SUDOKU PUZZLE... ******" << endl;

        sdk->printSudoku(out); // print the board on the terminal
        // ******** Evaluate and print conflicts *****
        // If found, print out the resulting solution and final conflicts

        // finds and prints initial conflicts of the board
        sdk->setConflict();
        sdk->printConflict(out);


        if (sdk->solveSudoku(recursiveCount, backtracksCount))
        {
            // one more solved
            solved++;
            /* Print completed board
              * print the conflicts
              * print # of recursive calls
              * print # of backtrack calls
              * */
            cout << "\nComplete Solution Found." << endl;
            cout << "\nCompleted board ..." << endl;
            out << "\nComplete Solution Found." << endl;
            out << "\nCompleted board ..." << endl;
            sdk -> printSudoku(out);

            // adds recursive and backtracks to a vector
            recursiveCount -= 1;
            recur.push_back(recursiveCount);
            backtr.push_back(backtracksCount);

            cout << "Recursive calls: " << recursiveCount << endl;
            cout << "Backtracks: " << backtracksCount << endl;
            out << "Recursive calls: " << recursiveCount << endl;
            out << "Backtracks: " << backtracksCount << endl;
            /* Print completed board
             * print the conflicts
             * print # of recursive calls
             * print # of backtrack calls
             * */
        }

        else {
            // one more not solved
            nosolve++;
            /* Print incompleted board */
            cout << "\nNo Solution Found...!" << endl;
            cout << "\nIncomplete board ..." << endl;
            out << "\nNo Solution Found...!" << endl;
            out << "\nIncomplete board ..." << endl;

        }
    }

    // ****** Post processing info **********
    cout << "Number of boards solved: " << solved << endl;
    cout << "Number of Boards with no solution: " << nosolve <<endl;
    out << "Number of boards solved: " << solved << endl;
    out << "Number of Boards with no solution: " << nosolve << endl;

    // calculates and puts into text file recursive and backtrack info
    cout << "Minimum # of Recursive calls: " << *min_element(recur.begin(), recur.end()) << endl;
    cout << "Maximum # of Recursive calls: " << *max_element(recur.begin(), recur.end()) << endl;
    cout << "Average # of Recursive calls: " << accumulate(recur.begin(), recur.end(), 0.0) / recur.size() << endl;
    out << "Minimum # of Recursive calls: " << *min_element(recur.begin(), recur.end()) << endl;
    out << "Maximum # of Recursive calls: " << *max_element(recur.begin(), recur.end()) << endl;
    out << "Average # of Recursive calls: " << accumulate(recur.begin(), recur.end(), 0.0) / recur.size() << endl;

    cout << "Minimum # of BackTrack calls: " << *min_element(backtr.begin(), backtr.end()) << endl;
    cout << "Maximum # of BackTrack calls: " << *max_element(backtr.begin(), backtr.end()) << endl;
    cout << "Average # of BackTrack calls: " << accumulate(backtr.begin(), backtr.end(), 0.0) / backtr.size() << endl;
    out << "Minimum # of BackTrack calls: " << *min_element(backtr.begin(), backtr.end()) << endl;
    out << "Maximum # of BackTrack calls: " << *max_element(backtr.begin(), backtr.end()) << endl;
    out << "Average # of BackTrack calls: " << accumulate(backtr.begin(), backtr.end(), 0.0) / backtr.size() << endl;

    // over
    cout << "\n***** Solver Terminating... ******" << endl;
    out << "\n***** Solver Terminating... ******" << endl;

    // closes file, deletes object and ends program
    out.close();
    fin.close();
    delete sdk;
    return 0;
}


