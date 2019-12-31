//
// Created by Kemba Konteh on 10/24/19.
//

#ifndef ASS3_MAZE_H
#define ASS3_MAZE_H

#include <fstream>
#include <string>
using namespace std;
int const MAXSIZE = 100;

class Maze {

private:
    int width, height;
    int rowExit, columnExit;
    char field[MAXSIZE][MAXSIZE];

public:
    // Maze constructor requiring a valid file name
    explicit Maze(string mazeFile);

    // gets the width
    int GetWidth() const;
    // gets the height
    int GetHeight() const;
    // gets the row exit row
    int GetRowExit() const;
    // gets the exit column
    int GetColumnExit() const;

    // checker methods
    // checks if path is clear
    bool IsClear(int row, int column) const;
    // checks if there is a wall
    bool IsWall(int row, int column) const;
    // checks if there is a path
    bool IsPath(int row, int column) const;
    // checks if the path has already been visited
    bool IsVisited(int row, int column) const;

    // mark the maze with *
    void MarkAsPath(int row, int column);

    // mark the maze with +
    void MarkAsVisited(int row, int column);

    // overloads output operator to follow the format provided while printing the maze
    friend ostream &operator<<(ostream &out, const Maze &maze);


};


#endif //ASS3_MAZE_H
