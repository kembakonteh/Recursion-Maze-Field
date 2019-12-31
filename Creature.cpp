//
// Created by Kemba Konteh on 10/24/19.
//



/* This program demonstrates how a creature that is placed at a certain point in a maze finds its way out of the
    maze field by finding the exit */

#include "Creature.h"

/* creature constructor */
Creature::Creature(int row, int col) {
    this->row = row;
    this->col = col;
}

/* This is the solve method that helps solve the maze.
 returns a string in the form of NNEEN
 (where N means North, E means East, etc)
 that will let the creature get to the exit
 if creature cannot get to the exit, returns "X"*/
string Creature::Solve(Maze &maze) {
    bool successful;
    string path = "";
    if(maze.IsWall(this->row, this->col))
    {
        cout << "Ops! haha you have placed the creature on a wall!";
        return "";
    }
    if (!maze.IsWall(this->row, this->col)) {
        successful = moveNorth(maze, *this);
        if (!successful)
            successful = moveEast(maze, *this);
        if (!successful)
            successful = moveWest(maze, *this);
        if (!successful)
            successful = moveSouth(maze, *this);
        if(!successful){
            maze.MarkAsVisited(row, col);
        }
        if (successful && list1.size() != 0) {
            maze.MarkAsPath(row, col);
            list<string>::iterator ite;
            for (ite = list1.begin(); ite != list1.end(); ite++) {
                path += *ite;
            }
        }
        return path;
    } else {
        cout << "Lets place the creature in the maze: " << endl;
        return path;
    }
}

/* Method that helps creature move in the north direction to find a path */

bool Creature::moveNorth(Maze &maze, Creature creature1) {
    bool successful = false;
    int c = creature1.row;
    int in = creature1.row - 1;
    creature1.row = c;
    if (maze.IsClear(in, creature1.col) && creature1.col < maze.GetWidth() && in < maze.GetHeight() &&
        in >= 0 && creature1.col >= 0 && !maze.IsVisited(in, creature1.col)) {
        creature1.row -= 1;
        maze.MarkAsPath(creature1.row, creature1.col);
        list1.push_back("N");
        if (maze.GetRowExit() == creature1.row && maze.GetColumnExit() == creature1.col)
            successful = true;

        else {
            if (!maze.IsPath(creature1.row - 1, creature1.col)) {
                successful = moveNorth(maze, creature1);
            }
            if (!successful) {
                successful = moveWest(maze, creature1);

                if (!successful) {
                    successful = moveEast(maze, creature1);

                    if (!successful) {
                        maze.MarkAsVisited(creature1.row, creature1.col);
                        list1.pop_back();
                        creature1.row = c;
                    }
                }
            }

        }
    }
    return successful;
}

/* Method moves creature in the east direction to find an exit path */
bool Creature::moveEast(Maze &m, Creature creature1) {
    bool success= false;
    int c = creature1.col;
    int in = c + 1;
    creature1.col = c;
    if (m.IsClear(creature1.row, in) && in < m.GetWidth() && creature1.row < m.GetHeight() &&
        !m.IsVisited(creature1.row, in)) {
        creature1.col += 1;
        list1.push_back("E");
        m.MarkAsPath(creature1.row, creature1.col);
        if (m.GetRowExit() == row && m.GetColumnExit() == col)
            success = true;
        else {
            if (!m.IsPath(creature1.row, creature1.col + 1)) {
                success = moveEast(m, creature1);
            }
            if (!success) {
                success = moveNorth(m, creature1);
                if (!success) {
                    success = moveSouth(m, creature1);
                    if (!success) {
                        m.MarkAsVisited(creature1.row, creature1.col);
                        list1.pop_back();
                        creature1.col = c;
                    }
                }
            }

        }

    }
    return success;
}
/* Method moves creature in the west direction to find an exit path */
bool Creature::moveWest(Maze &m, Creature creature1) {
    bool successful= false;
    int c = creature1.col;
    int in = creature1.col - 1;
    creature1.col = c;
    if (m.IsClear(creature1.row, in) && creature1.row < m.GetHeight() && in < m.GetWidth() && in >= 0 && creature1.row >= 0 &&
        !m.IsVisited(creature1.row, in)) {
        creature1.col -= 1;
        list1.push_back("W");
        m.MarkAsPath(creature1.row, creature1.col);
        if (m.GetRowExit() == row && m.GetColumnExit() == col)
            successful = true;
        else {
            if (!m.IsPath(creature1.row, creature1.col - 1)) {
                successful = moveWest(m, creature1);
            }
            if (!successful) {
                successful = moveNorth(m, creature1);
                if (!successful) {
                    successful = moveSouth(m, creature1);
                    if (!successful) {
                        m.MarkAsVisited(creature1.row, creature1.col);
                        list1.pop_back();
                        creature1.col = c;
                    }
                }
            }

        }


    }
    return successful;
}

/* Method moves creature in the south direction to find an exit path */
bool Creature::moveSouth(Maze &m, Creature creature1) {
    bool successful = false;
    int c = creature1.row;
    int in = creature1.row + 1;
    creature1.row = c;
    if (m.IsClear(in, creature1.col) && creature1.col <= m.GetWidth() && in <= m.GetHeight() && creature1.col >= 0 && in >= 0 &&
        !m.IsVisited(in, creature1.col)) {
        creature1.row += 1;
        list1.push_back("S");
        m.MarkAsPath(creature1.row, creature1.col);
        if (m.GetRowExit() == creature1.row && m.GetColumnExit() == creature1.col)
            successful = true;

        else {
            if (!m.IsPath(creature1.row + 1, creature1.col)) {
                successful = moveSouth(m, creature1);
            }

            if (!successful) {
                successful = moveWest(m, creature1);

                if (!successful) {
                    successful = moveEast(m, creature1);

                    if (!successful) {
                        m.MarkAsVisited(creature1.row, creature1.col);
                        list1.pop_back();
                        creature1.row = c;
                    }
                }
            }

        }

    }

    return successful;
}


/* prints current location of creature, for example C(7,3) */
ostream &operator<<(ostream &out, const Creature &creature) {
    out << "(" << creature.row << ", ";
    out << creature.col << ")";
    return out;

}

