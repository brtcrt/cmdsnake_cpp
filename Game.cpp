#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Game.h"
#include "Empty.h"
#include "Wall.h"
#include "Player.h"
#include "Body.h"
#include "Apple.h"

Game::Game() {
    this->rows = 11;
    this->columns = 11;
    this->grid = new char*[rows];
    this->apple = Apple(7, 5);
    this->player = Player(3, 5);
    this->gameOver = false;

    std::srand(std::time(0));

    for (int i = 0; i < rows; i++)
    {
        grid[i] = new char[columns];
    }
    flushBoard();

}

Game::~Game() {
    for (int i = 0; i < rows; i++) {
        delete[] grid[i];
    }
    delete[] grid;
}
void Game::flushBoard() {
    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < columns; x++) {
            if ((x == 0 || x == columns - 1) && (y != 0 || y != rows - 1)) {
                grid[y][x] = '|';
            } else if ((x != 0 || x != columns - 1) && (y == 0 || y == rows - 1)) {
                grid[y][x] = '-';
            } else {
                grid[y][x] = ' ';
                grid[y][x] = ' ';
            }
        }
    }
    grid[0][0] = '+';
    grid[0][columns - 1] = '+';
    grid[rows - 1][0] = '+';
    grid[rows - 1][columns - 1] = '+';
}

int Game::getUp() const {
    if (player.y == 1) return -1;
    if (player.y == apple.y + 1 && player.x == apple.x) return 1;
    const Body* body = player.getBody();
    for (int i = 0; i < player.getSize(); i++) {
        Body b = body[i];
        if (player.y == b.y + 1 && player.x == b.x) return -1; 
    }
    return 0; 
} 
int Game::getDown() const {
    if (player.y == rows - 2) return -1;
    if (player.y == apple.y - 1 && player.x == apple.x) return 1;
    const Body* body = player.getBody();
    for (int i = 0; i < player.getSize(); i++) {
        Body b = body[i];
        if (player.y == b.y - 1 && player.x == b.x) return -1; 
    }
    return 0;
} 
int Game::getLeft() const {
    if (player.x == 1) return -1;
    if (player.x == apple.x + 1 && player.y == apple.y) return 1;
    const Body* body = player.getBody();
    for (int i = 0; i < player.getSize(); i++) {
        Body b = body[i];
        if (player.y == b.y && player.x == b.x + 1) return -1; 
    }
    return 0;
} 
int Game::getRight() const {
    if (player.x == columns - 2) return -1;
    if (player.x == apple.x - 1 && player.y == apple.y) return 1;
    const Body* body = player.getBody();
    for (int i = 0; i < player.getSize(); i++) {
        Body b = body[i];
        if (player.y == b.y && player.x == b.x - 1) return -1; 
    }
    return 0;
} 

int Game::getFromInput(const char c) const {
    switch (c)
    {
    case 'w':
        return getUp();
        break;
    case 'd':
        return getRight();
        break;
    case 's':
        return getDown();
        break;
    case 'a':
        return getLeft();
        break;
    default:
        break;
    }
    return 0;
}

std::string Game::stringify() {
    std::string board = "";
    flushBoard();
    grid[apple.y][apple.x] = apple.ch;
    grid[player.y][player.x] = player.ch;
    const Body* body = player.getBody();
    for (int i = 0; i < player.getSize(); i++) {
        grid[body[i].y][body[i].x] = body[i].ch;
    }
    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < columns; x++) {
            board +=  " ";
            board += grid[y][x];
            board +=  " ";
        }
        board += "\n";
    }
    return board;
}

void Game::run() {
    while (!gameOver)
    {
        char input;
        std::cin >> input;
        int res = getFromInput(input);
        switch (res)
        {
            case -1:
                gameOver = true;
                std::cout << "GAME OVER!" << std::endl;
                std::cout << "SCORE: " << player.getSize() << std::endl;
                break;
            case 0:
                player.move(input);
                std::cout << stringify();
                break;
            case 1:
            {
                bool acceptableApple = false;
                int randX;
                int randY;
                do
                {
                    randX = 1 + std::rand() % (columns - 2);
                    randY = 1 + std::rand() % (rows - 2);
                    if (randX != player.x && randY != player.y && !player.clashesWithBody(randX, randY)) acceptableApple = true;
                } while (!acceptableApple);
                
                apple.setPosition(randX, randY);
                player.grow();
                player.move(input);
                std::cout << stringify();
                break;
            }
            default:
                std::cout << "Not a valid move.";
                break;
        }
    }   
}