#include "Apple.h"

Apple::Apple() {
    this->x = 0;
    this->y = 0;
    this->ch = '#';
}

Apple::Apple(const int x, const int y) {
    this->x = x;
    this->y = y;
    this->ch = '#';
}

void Apple::setPosition(const int x, const int y) {
    this->x = x;
    this->y = y;
}