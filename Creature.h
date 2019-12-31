//
// Created by Kemba Konteh on 10/24/19.
//

#ifndef ASS3_CREATURE_H
#define ASS3_CREATURE_H

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "Maze.h"

using namespace std;

class Creature {
    private:


        int row;
        int col;

        // moves the creature north
        bool moveNorth(Maze &m, Creature creature1);


        // moves the creature east
        bool moveEast(Maze &m, Creature creature1);


        // moves the creature west
        bool moveWest(Maze &m, Creature creature1);

        // moves the creature south
        bool moveSouth(Maze &m, Creature creature1);

        //list to store path - string
        list<string> list1;


    public:

    // the creature constructor
        Creature(int row, int col);

    // prints current location of creature, for example C(7,3)
        friend ostream &operator<<(ostream &out, const Creature &creature);


    // returns a string in the form of NNEEN
    // (where N means North, E means East, etc)
    // that will let the creature get to the exit
    // if creature cannot get to the exit, returns "X"
        string Solve(Maze &Maze);



    };

#endif //ASS3_CREATURE_H
