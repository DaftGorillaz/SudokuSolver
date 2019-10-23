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
  for(int i=0;i<9;i++)
  {
    getline(file,line);
    stringstream fullLine(line);
    for(int j=0;j<9;j++)
    {
      fullLine << line;
      fullLine >> line[j];
      if(line[j]>'9'||line[j]<'0')
        line[j]='0';
      grid[i][j]=line[j];
    }
  }
  makeGrid();
  do
  {
  isFull();
  if(isFull() == false);
    solveIt();
  }
  while(isFull()==false);
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

      if(!(grid[row][column] <'0' || grid[row][column] > '9'))
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
  cout << endl;
}

bool sudokuSolver::isFull()
{
  for(int row = 0; row < 9; row++)
    for(int column = 0; column < 9; column++)
      if(grid[row][column]<'10'&&grid[row][column]>'0')
        return true;
  return false;
}

void sudokuSolver::solveIt()
{

    for(int row = 0; row < 9; row++)
    {
      for(int column = 0; column < 9; column++)
      {
        if(grid[row][column]=='0')
        {
          //Take the Coordinate
          CoordinateRow = row;
          CoordinateColumn = column;
          possibleAnswer();
          cout << "Possible values for (" << CoordinateRow << "," << CoordinateColumn << ") = {";
          for(int i=0;i<sizeof(possibleArray);i++)
          {
            cout << possibleArray[i] << ",";
            int count = 0;

            //counts how many zeroes in the possibleArray
            for (i:possibleArray)
            {
              if (possibleArray[i] == 0)
              count++;
            }

            //Checks to see if
            if (count == 8)
            {
              for (int j=0; j<9; j++)
              {
                if (possibleArray[i] !=0)
                {
                  grid[CoordinateRow][CoordinateColumn] << possibleArray[i];
                  possibleAnswer();
                }
              }
            }
          }
          cout << "}" << endl;
        }
      }
    }
  makeGrid();
  cout << "Save the solution? y/n" << endl;
}
void sudokuSolver::possibleAnswer()
{
  //resets array
  for(int i = 0; i < 9; i++)
  {
    possibleArray[i] = '1';
  }
  //for horizontal entries
  for(int column = 0; column < 9; column++)
  {
    if(grid[CoordinateRow][column] != '0')
    {
      switch(grid[CoordinateRow][column])
      {
      case '1':
        possibleArray[0] = '0';
        break;
      case '2':
        possibleArray[1] = '0';
        break;
      case '3':
        possibleArray[2] = '0';
        break;
      case '4':
        possibleArray[3] = '0';
        break;
      case '5':
        possibleArray[4] = '0';
        break;
      case '6':
        possibleArray[5] = '0';
        break;
      case '7':
        possibleArray[6] = '0';
        break;
      case '8':
        possibleArray[7] = '0';
        break;
      case '9':
        possibleArray[8] = '0';
        break;
      }
    }
  }
  //for vertical entries
  for(int row = 0; row < 9; row++)
  {
    if(grid[row][CoordinateColumn] != '0')
    {
      switch(grid[row][CoordinateColumn])
      {
      case '1':
        possibleArray[0] = '0';
        break;
      case '2':
        possibleArray[1] = '0';
        break;
      case '3':
        possibleArray[2] = '0';
        break;
      case '4':
        possibleArray[3] = '0';
        break;
      case '5':
        possibleArray[4] = '0';
        break;
      case '6':
        possibleArray[5] = '0';
        break;
      case '7':
        possibleArray[6] = '0';
        break;
      case '8':
        possibleArray[7] = '0';
        break;
      case '9':
        possibleArray[8] = '0';
        break;
      }
    }
  }
  //for 3x3
  int boxRow = 0, boxColumn = 0;

  if(CoordinateRow >= 0 && CoordinateRow <= 2)
  {
    boxRow = 0;
  }
  else if(CoordinateRow  >= 3 && CoordinateRow  <=5)
  {
    boxRow  = 3;
  }
  else
  {
    boxRow  = 6;
  }

  if(CoordinateColumn >= 0 && CoordinateColumn <= 2)
  {
    boxColumn = 0;
  }
  else if(CoordinateColumn >= 3 && CoordinateColumn <= 5)
  {
    boxColumn = 3;
  }
  else
  {
    boxColumn = 6;
  }

  for(int row = boxRow; row < boxRow+3 ; row++)
  {
    for(int column = boxColumn; column < boxColumn+3 ; column++)
    {
      if(grid[row][column] != '0')
      {
        switch(grid[row][column])
        {
        case '1':
          possibleArray[0] = '0';
          break;
        case '2':
          possibleArray[1] = '0';
          break;
        case '3':
          possibleArray[2] = '0';
          break;
        case '4':
          possibleArray[3] = '0';
          break;
        case '5':
          possibleArray[4] = '0';
          break;
        case '6':
          possibleArray[5] = '0';
          break;
        case '7':
          possibleArray[6] = '0';
          break;
        case '8':
          possibleArray[7] = '0';
          break;
        case '9':
          possibleArray[8] = '0';
          break;
        }
      }
    }
  }

  for(int i = 0; i < 9 ; i++)
  {
    if(possibleArray[i] == '1')
    {
      switch(i)
      {
      case 0:
        possibleArray[i] = '1';
        break;
      case 1:
        possibleArray[i] = '2';
        break;
      case 2:
        possibleArray[i] = '3';
        break;
      case 3:
        possibleArray[i] = '4';
        break;
      case 4:
        possibleArray[i] = '5';
        break;
      case 5:
        possibleArray[i] = '6';
        break;
      case 6:
        possibleArray[i] = '7';
        break;
      case 7:
        possibleArray[i] = '8';
        break;
      case 8:
        possibleArray[i] = '9';
        break;
      }
    }
    else
    {
      possibleArray[i] = '0';
    }
  }
}
