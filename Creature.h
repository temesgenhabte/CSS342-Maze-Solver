//
// Created by Temesgen on 10/28/2019.
//

#ifndef HW3_RECURSION_CREATURE_H
#define HW3_RECURSION_CREATURE_H


#include "Maze.h"

using namespace std;

class Creature{
public:
    Creature(int row, int column);

    /**
     * This method checks all possible paths of the spot just above the current position recursively.
     * Calls the other "GO" methods which all contain recursive movements as well
     * @param maze
     * @return
     */
    bool goNorth(Maze& maze);

    /**
     * This method checks all possible paths of the spot just below the current position recursively.
     * Calls the other "GO" methods which all contain recursive movements as well
     * @param maze
     * @return
     */
    bool goSouth(Maze& maze);

    /**
     * This method checks all possible paths of the spot just to the right the current position recursively.
     * Calls the other "GO" methods which all contain recursive movements as well
     * @param maze
     * @return
     */
    bool goEast(Maze& maze);

    /**
     * This method checks all possible paths of the spot just to the left the current position recursively.
     * Calls the other "GO" methods which all contain recursive movements as well
     * @param maze
     * @return
     */
    bool goWest(Maze& maze);

    /**
     * This method checks calls all of the Go methods, prioritizing North, then East, South, and West.
     * @param maze
     * @return
     */
    string solve(Maze &maze);

    //prints creature current position as: C(column, row)
    friend ostream &operator<<(ostream &out, const Creature &creature);



private:
    string path = "";
    int column;
    int row;
};


#endif //HW3_RECURSION_CREATURE_H
