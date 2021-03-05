//
// Created by Temesgen on 10/28/2019.
//

#include "Creature.h"
#include <iostream>

using namespace std;

Creature::Creature(int row, int column){
    this->row = row;
    this->column = column;
}

bool Creature::goNorth(Maze& maze){

    bool pass;


    if(maze.isClear(row - 1, column)){ //if position above you is clear
        row--;// travel to that position
        maze.markAsPath(row, column); //mark the position as "*"
        path = path + "N"; //update your path string
        //cout << maze << endl;
        if(maze.isExit(row, column))
            pass = true;
        else{
            pass = goNorth(maze); //recursive call
            if(!pass){ //explore all possible positions from then on
                pass = goEast(maze);
                if(!pass){
                    pass = goWest(maze);
                    if(!pass){ //if you hit a dead end
                        maze.markAsVisited(row, column); //change the path to "+"
                        row++; //update row, reversing back the way you came
                        path.pop_back(); //pop off end of string
                    }
                }
            }
        }
    }else{
        pass = false;
    }

    //cout << pass << endl;
    return pass;
}

bool Creature::goSouth(Maze& maze){ //exact same code as north, replacing goNorth with goSouth, and row-- with row++

    bool pass;


    if(maze.isClear(row + 1, column)){ //if position below you is clear
        row++;// travel to that position
        maze.markAsPath(row, column); //mark the previous position as "*"
        path = path + "S"; //update your path string
        //cout << maze << endl;
        if(maze.isExit(row, column))
            pass = true;
        else{
            pass = goSouth(maze); //recursive call
            if(!pass){ //explore all possible positions from then on
                pass = goEast(maze);
                if(!pass){
                    pass = goWest(maze);
                    if(!pass){ //if you hit a dead end
                        maze.markAsVisited(row, column); //change the path to "+"
                        row--; //update row, reversing back the way you came
                        path.pop_back(); //pop off end of string
                    }
                }
            }
        }
    }else{
        pass = false;
    }
    //cout << pass << endl;
    return pass;
}

bool Creature::goEast(Maze& maze){ //same logic as goNorth

    bool pass;


    if(maze.isClear(row, column + 1)){ //if position to the right is clear
        column++;// travel to that position
        maze.markAsPath(row, column); //mark the previous position as "*"
        path = path + "E"; //update your path string
        //cout << maze << endl;
        if(maze.isExit(row, column))
            pass = true;
        else{
            pass = goEast(maze); //recursive call
            if(!pass){ //explore all possible positions from then on
                pass = goSouth(maze);
                if(!pass){
                    pass = goNorth(maze);
                    if(!pass){ //if you hit a dead end
                        maze.markAsVisited(row, column); //change the path to "+"
                        column--; //update row, reversing back the way you came
                        path.pop_back(); //pop off end of string
                    }
                }
            }
        }
    }else{
        pass = false;
    }
    //cout << pass << endl;
    return pass;
}

bool Creature::goWest(Maze& maze){ //same logic as goNorth

    bool pass;


    if(maze.isClear(row, column - 1)){ //if position to the left is clear
        column--;// travel to that position
        maze.markAsPath(row, column); //mark the position as "*"
        path = path + "W"; //update your path string
        //cout << maze << endl;
        if(maze.isExit(row, column))
            pass = true;
        else{
            pass = goWest(maze); //recursive call
            if(!pass){ //explore all possible positions from then on
                pass = goSouth(maze);
                if(!pass){
                    pass = goNorth(maze);
                    if(!pass){ //if you hit a dead end
                        maze.markAsVisited(row, column); //change the path to "+"
                        column++; //update row, reversing back the way you came
                        path.pop_back(); //pop off end of string
                    }
                }
            }
        }
    }else{
        pass = false;
    }

    //cout << pass << endl;
    return pass;
}

string Creature::solve(Maze &maze){
    if(!maze.isClear(row, column)){ //if the user inputs a position already occupied
        cout << "Invalid starting position" << endl;
        exit(1); //exit to avoid further crashes
    }

    maze.markAsPath(row, column); //mark starting position
    if(row == maze.getRowExit() && column == maze.getColumnExit()){ //if you start at exit
        return path;
    }

    if(goNorth(maze)) //prioritize goNorth
        return path; //if goNorth succeeds, return its string directions
    if(goEast(maze))
        return path;
    if(goSouth(maze))
        return path;
    if(goWest(maze))
        return path;

    path = "X"; //if the maze has no exit, return X
    return path;
}

ostream &operator<<(ostream &out, const Creature &creature){
    out << "C(" << creature.column << "," << creature.row << ")";

    return out;
}




