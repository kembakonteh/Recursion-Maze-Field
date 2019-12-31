//
// Created by Kemba Konteh on 10/24/19.
//

#include "Maze.h"

/* Maze constructor requiring a valid file name */
Maze::Maze(string mazeFile)
{
    string line;
    ifstream ipFile( mazeFile.c_str() );
    ipFile >> this->width;
    ipFile >> this->height;
    ipFile >> this->rowExit;
    ipFile >> this->columnExit;
    getline(ipFile, line);
    for(int i = 0; i < this->height; i++)
    {
        getline(ipFile, line);
        //cout << line << endl;
        for(int j = 0; j < this->width; j++)
            this->field[i][j] = line[j];
        this->field[i][this->width] = '\0';
        //cout << this->field[i] << endl;
    }
    ipFile.close();
}
/* gets the width of the maze */
int Maze::GetWidth() const
{
    return this->width;
}

/* gets the height of the maze */
int Maze::GetHeight() const
{
    return this->height;
}

/* gets the exit row */
int Maze::GetRowExit() const
{
    return this->rowExit;
}
/* gets the exit column */
int Maze::GetColumnExit() const
{
    return this->columnExit;
}

/* checks if path is clear */
bool Maze::IsClear(int row, int column) const
{
    return (this->field[row][column] == ' ');
}

/* checks if there is a wall */
bool Maze::IsWall(int row, int column) const
{
    return (this->field[row][column] == 'X');
}

/* checks if the there is a path */
bool Maze::IsPath(int row, int column) const
{
    return (this->field[row][column] == '*');
}

/* checks if path is already visited or taken */
bool Maze::IsVisited(int row, int column) const
{
    return (this->field[row][column] == '+');
}

/* marks the maze with */
void Maze::MarkAsPath(int row, int column)
{
    this->field[row][column] = '*';
}

/* marks the maze with + */
void Maze::MarkAsVisited(int row, int column)
{
    this->field[row][column] = '+';
}

/* overloads output operator to follow the format provided while printing the maze */
ostream &operator<<(ostream &out, const Maze &maze)
{
    for(int i = 0; i < maze.height; i++)
    {
        out << maze.field[i];
        //for(int j = 0; j < maze.width; j++)
        //	out << maze.field[i][j];
        out << endl;
    }
    return out;
}
