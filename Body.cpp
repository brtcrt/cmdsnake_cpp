#include "Body.h"

Body::Body() {
    this->ch = 'o';
    this->x = 0;
    this->y = 0;
}

Body& Body::operator=(const Body& other) {
    if (this == &other) {
        return *this;
    }

    x = other.x;
    y = other.y;
    return *this;
}