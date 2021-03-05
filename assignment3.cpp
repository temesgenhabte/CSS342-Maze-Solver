//
// Created by Temesgen on 10/30/2019.
//

#include <iostream>
#include "Maze.h"
#include "Creature.h"

using namespace std;

int main() {
    /**
     * TESTING ALL MAZES
     */
    Maze maze1("maze.txt");
    cout << maze1 << endl;

    Creature c1(1, 7);
    string result = "";
    result = c1.solve(maze1);

    cout << result << endl;
    cout << maze1 << endl;
    cout << c1 << endl;

    Maze maze2("mazeSimple.txt");
    cout << maze2 << endl;

    Creature c2(1, 6);
    string result2 = "";
    result2 = c2.solve(maze2);

    cout << result2 << endl;
    cout << maze2 << endl;
    cout << c2 << endl;

    Maze maze3("maze0.txt");
    cout << maze3 << endl;

    Creature c3(2, 7);
    string result3 = "";
    //c.goNorth(maze);
    result3 = c3.solve(maze3);

    cout << result3 << endl;
    cout << maze3 << endl;
    cout << c3 << endl;

    Maze maze4("maze1.txt");
    cout << maze4 << endl;

    Creature c4(1, 1);
    string result4 = "";
    result4 = c4.solve(maze4);

    cout << result4 << endl;
    cout << maze4 << endl;
    cout << c4 << endl;

    Maze maze5("maze2.txt");
    cout << maze5 << endl;

    Creature c5(1, 6);
    string result5 = "";
    result5 = c5.solve(maze5);

    cout << result5 << endl;
    cout << maze5 << endl;
    cout << c5 << endl;

}