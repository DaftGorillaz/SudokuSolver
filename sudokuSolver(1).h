#include <fstream>

using namespace std;

#ifndef SUDOKUSOLVER_H
#define SUDOKUSOLVER_H

class sudokuSolver
{
  public:
    sudokuSolver(string);
    void openFile(string);
    void saveSolution(string);
    void makeGrid();
    void solveIt();
    bool isFull();
    char possibleAnswer();

  private:
    fstream file;
    string fileName;
    string line;

    char grid[9][9] = {{0}};
    int possibleArray[] = {};
    int i = 0;
    int j = 0;
};

#endif // SUDOKUSOLVER_H
