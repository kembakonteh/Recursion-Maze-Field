#include <iostream>
#include "Creature.h"

int main() {
    //Maze maze("maze0.txt");
    //Maze maze("maze1.txt");
    Maze maze("maze2.txt");
    //cout << "Width of Maze: " << maze.GetWidth() << endl;
    //cout << "Height of Maze: " << maze.GetHeight() << endl;
    //cout << "Exit Row: " << maze.GetRowExit() << endl;
    //cout << "Exit Column: " << maze.GetColumnExit() << endl;
    //cout << maze.IsWall(6,9) << endl;
    //cout << maze.IsWall(6,2) << endl;
    //cout << maze.IsClear(6,2) << endl;
    //cout << maze.IsClear(6,9) << endl;
    cout << endl << maze << endl;

    //Creature creature(6,22);
    //Creature creature(11,7);
    //Creature creature(5,3);
    Creature creature(4,3);
    //Creature creature(4,3);
    cout << creature << endl;
    cout << "\n\nPath taken by creature to exit maze:\n\t" << creature.Solve( maze ) << endl;
    cout << endl << maze << endl;

    return 0;
}