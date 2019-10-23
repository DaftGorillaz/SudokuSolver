#include <iostream>
#include <fstream>
#include <string>
#include "sudokuSolver.h"

using namespace std;

int main(int argc, char *argv[])
{
  string fileName = argv[1];
  string userInput;
  sudokuSolver solve(fileName);

  cin >> userInput;
  solve.saveSolution(userInput);

}
