#ifndef BODY_H
#define BODY_H

class Body {
    public:
        int x;
        int y;
        char ch;
        Body();
        Body& operator=(const Body& other);
};

#endif