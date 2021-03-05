//
// Created by Temesgen on 10/22/2019.
//

#include "Maze.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Maze::Maze(string mazeFile){
    ifstream inFile;
    inFile.open(mazeFile); //open the file

    if(inFile){ //if inFile successfully opens the file
        inFile >> column >> row; //takes the first two ints
        cout << "Column: " << column << " Row: " << row << endl; //check
        inFile >> rowExit >> columnExit; //takes the second two ints, indicating exit position
        cout << "ColumnExit: " << columnExit << " RowExit: " << rowExit << endl; //check

        int i = 0;
        string line = "";

        getline(inFile, line); //takes care of the extra space between numbers and maze

        while(inFile){ //while there are more lines
            getline(inFile, line); //store the line in string line

            for(int j = 0; j < line.size(); j++){
                field[i][j] = line[j]; //fill the 2D char array
            }
            i++;
        }


    }else{
        cout << "Unable to open file " << mazeFile << endl;
        exit(1); //exits the code to avoid further crashes
    }

}

bool Maze::isClear(int row, int column) const {
    if(field[row][column] == ' ')
        return true;
    else
        return false;
}

bool Maze::isWall(int row, int column) const {
    if(field[row][column] == 'X' || field[row][column] == '#' )
        return true;
    else
        return false;
}

bool Maze::isPath(int row, int column) const {
    if(field[row][column] == '*')
        return true;
    else
        return false;
}

bool Maze::isVisited(int row, int column) const{
    if(field[row][column] == '+')
        return true;
    else
        return false;
}

bool Maze::isExit(int row, int column) const {
    if(row == this->rowExit && column == this->columnExit){
        return true;
    }else{
        return false;
    }
}

void Maze::markAsPath(int row, int column) {
    field[row][column] = '*';
}

void Maze::markAsVisited(int row, int column) {
    field[row][column] = '+';
}

ostream &operator<<(ostream &out, const Maze &maze) { //format the string and then send to output
    string s = to_string(maze.getColumn()) + " " + to_string(maze.getRow()) + "\n" +
            to_string(maze.getRowExit()) + " " + to_string(maze.getColumnExit()) + "\n";

    for(int i = 0; i < maze.row; i++){
        for(int j=0; j < maze.column; j++){
            s = s + maze.field[i][j];
        }
        s = s + "\n";
    }

    out << s;
    return out;
}

int Maze::getRow() const {
    return row;
}

int Maze::getColumn() const {
    return column;
}

int Maze::getRowExit() const {
    return rowExit;
}

int Maze::getColumnExit() const {
    return columnExit;
}
