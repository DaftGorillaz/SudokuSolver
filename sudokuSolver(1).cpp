#include "sudokuSolver.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
sudokuSolver::sudokuSolver(string fileName)
{
  file.open(fileName.c_str(), ios::in | ios::out);
  cout << "Now opening: " << fileName << endl << endl;
  int i=0;
  stringstream fullLine(line);
  while(i<9)
  {
    getline(file,line);

    for(int j=0;j<9;j++)
    {
      fullLine << line;
      fullLine >> line[j];

      if(!(line[j] > '0' && line[j] <= '9'))
         {
            line[j] = '0';
         }
      grid[i][j] = line[j];
    }
      i++;
  }
  makeGrid();
  cout << "Save the solution? y/n" << endl;
}

void sudokuSolver::saveSolution(string userInput)
{
  if (userInput == "y")
  {
    file.open(fileName.c_str(), fstream::out | fstream::in);
    for(int row = 0; row < 9; row++)
    {
      for(int column = 0; column < 9; column++)
      {
        file << grid[row][column];
      }
      cout << endl;
    }
    file.close();
  }
  else
  {
    file.close();
  }
}

void sudokuSolver::makeGrid()
{
  for(int row=0;row<9;row++)
  {
    for(int column=0;column<9;column++)
    {
      if(column == 3 || column == 6)
      {
        cout << "|#|";
      }
      else
      {
        cout << "|";
      }

      if(grid[row][column] != '-')
      {
        cout << " " << grid[row][column] << " ";
      }
      else
      {
        cout << "   ";
      }
    }
    cout << "|";
    cout << endl;
    if (row == 2 || row == 5)
    {
      cout << "=============#=============#=============" << endl;
      cout << "|# # # # # # # # # # # # # # # # # # # #|" << endl;
      cout << "=============#=============#=============" << endl;
    }
    else
    {
      cout << "------------|#|-----------|#|------------" << endl;
    }
  }
}

bool sudokuSolver::isFull()
{
  for(int row = 0; row < 9; row++)
  {
    for(int column = 0; column < 9; column++)
    {
      if(grid[row][column] == '-')
      {
        return false;
      }
    }
  }
  return true;
}

char sudokuSolver::possibleAnswer()
{
  for(int x = 1; x < 10; x++)
  {
    possibleArray[x] = 0;
  }

  //for horizontal entries
  for(int y = 0; y < 9; y++)
  {
    if(!grid[i][y] == 0)
    {
      possibleArray[grid[i][y]] = 1;
    }
  }

  //for vertical entries
  for(int x = 0; x < 0; x++)
  {
    if(!grid[x][j] == 0)
    {
      possibleArray[grid[x][j]] = 1;
    }
  }

  //for 3x3
  int k = 0;
  int l = 0;

  if(i >= 0 && i <= 2)
  {
    k = 0;
  }
  else if(i >= 3 && i <=5)
  {
    k = 3;
  }
  else
  {
    k = 6;
  }

  if(j >= 0 && j <= 2)
  {
    l = 0;
  }
  else if(j >= 3 && j <= 5)
  {
    l = 3;
  }
  else
  {
    l = 6;
  }

  for(int x = k; x < k+3; x++)
  {
    for(int y = l; y < l+3; y++)
    {
      if(!grid[x][y] == 0)
      {
        possibleArray[grid[x][y]] = 1;
      }
    }
  }

  for(int x = 1; x < 10; x++)
  {
    if(possibleArray[x] == 0)
    {
      possibleArray[x] = x;
    }
    else
    {
      possibleArray[x] = 0;
    }
  }
}

void sudokuSolver::solveIt()
{
  int possibilities = {};

  //if board is full, there is no need to solve it further

  if(isFull())
  {
    makeGrid();
  }
  else
  {
    //find the first vacant spot
    for(int x = 0; x < 9; x++)
    {
      for(int y = 0; y < 9; y++)
      {
        if(grid[x][y] == 0)
        {
          i = x;
          j = y;
          break;
        }
        else
        {
          continue;
        }
      }

      break;
    }

    //get all possiblities for i,j
    possibilities = possibleAnswer();
  }
}
