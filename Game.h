#ifndef GAME_H
#define GAME_H

#include <string>
#include "Player.h"
#include "Apple.h"

class Wall;
class Empty;

class Game {
    private:
        Player player;
        Apple apple;
        bool gameOver;
        char** grid;
        int rows;
        int columns; 
        int getUp() const;
        int getDown() const;
        int getLeft() const;
        int getRight() const;
        int getFromInput(const char c) const;
        std::string stringify();
        void flushBoard();

    public:
        Game();
        ~Game();
        void run();

};


#endif