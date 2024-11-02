#ifndef PLAYER_H
#define PLAYER_H


class Body;

class Player {
    private:
        Body* parts;
        int size;
        bool justGrew;
        void moveBody();
    public:
        int x;
        int y;
        char ch;
        Player();
        Player(const int x, const int y);
        ~Player();
        int getSize() const;
        void grow();
        void move(const char direction);
        bool clashesWithBody(const int x, const int y) const;
        const Body* getBody() const;

};


#endif