#ifndef APPLE_H
#define APPLE_H


class Apple {
    public:
        Apple();
        Apple(const int x, const int y);
        void setPosition(const int x, const int y);
        int x;
        int y;
        char ch;
};


#endif