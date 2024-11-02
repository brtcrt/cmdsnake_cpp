#include <iostream>

#include "Player.h"
#include "Body.h"

Player::Player() {
    this->parts = nullptr;
    this->size = 0;
    this->justGrew = false;
    this->x = 0;
    this->y = 0;
    this->ch = 'O';
}

Player::Player(const int x, const int y) {
    this->justGrew = false;
    this->parts = nullptr;
    this->size = 0;
    this->ch = 'O';
    this->x = x;
    this->y = y;
}

Player::~Player() {
    delete[] parts;
}

void Player::grow() {
    Body* temp = parts;
    this->parts = new Body[size + 1];
    justGrew = true;
    for (int i = 0; i < size; i++) {
        parts[i] = temp[i];
    }
    parts[size].x = x;
    parts[size].y = y;
    size++;
    delete[] temp;
}

bool Player::clashesWithBody(const int x, const int y) const {
    for (int i = 0; i < size; i++) {
        if (parts[i].x == x && parts[i].y == y) return true;
    }
    return false;
}

int Player::getSize() const {
    return this->size;
}

const Body* Player::getBody() const {
    return this->parts;
} 

void Player::moveBody() {
    if (size < 1) return;
    for (int i = 0; i < size - 1; i++) {
        parts[i] = parts[i + 1];
    }
    parts[size - 1].x = x;
    parts[size - 1].y = y;
}
/**
 * w -> up
 * d -> right
 * s -> down
 * a -> left
 */
void Player::move(const char direction) {
    if (!justGrew) {
        moveBody();
    }
    switch (direction)
    {
    case 'w':
        y--;
        break;
    case 'd':
        x++;
        break;
    case 's':
        y++;
        break;
    case 'a':
        x--;
        break;
    default:
        break;
    }
    justGrew = false;
}