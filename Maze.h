//
// Created by Temesgen on 10/22/2019.
//

#ifndef HW3_RECURSION_MAZE_H
#define HW3_RECURSION_MAZE_H

#include <iostream>

using namespace std;


class Maze {
public:
    //constructor
    explicit Maze(string mazeFile);

    //checks that the inputted position is clear (" ")
    bool isClear(int row, int column) const;

    //Checks if the position is a wall (X or #)
    bool isWall(int row, int column) const;

    //Checks if the position is part of the path to escape (*)
    bool isPath(int row, int column) const;

    //Checks if the position is visited but not part of the path (+)
    bool isVisited(int row, int column) const;

    //Checks if the position is equal to the position of an exit
    bool isExit(int row, int column) const;

    int getRow() const;
    int getColumn() const;
    int getRowExit() const;
    int getColumnExit() const;

    //mark the field with *
    void markAsPath(int row, int column);

    //mark the field with +
    void markAsVisited(int row, int column);

    //Maze constructor requiring a valid file name
    friend ostream &operator<<(ostream &out, const Maze &maze);


private:
    int row;
    int column;
    int rowExit;
    int columnExit;
    const static int MAX_ROW = 100;
    const static int MAX_COLUMN = 100;
    char field[MAX_ROW][MAX_COLUMN];

};


#endif //HW3_RECURSION_MAZE_H