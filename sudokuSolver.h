#include <fstream>

using namespace std;

#ifndef SUDOKUSOLVER_H
#define SUDOKUSOLVER_H

class sudokuSolver
{
  public:
    sudokuSolver(string);
    void saveSolution(string);
    void makeGrid();
    void solveIt();
    bool isFull();
    void possibleAnswer();


  private:
    fstream file;
    string fileName;
    string line;
    char grid[9][9];
    char possibleArray[9];
    int CoordinateRow, CoordinateColumn;
};

#endif // SUDOKUSOLVER_H
