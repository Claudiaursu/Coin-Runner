#ifndef PLAYER_H
#define PLAYER_H
#include <string>

using namespace std;

class Player
{
    public:
        Player();
        ~Player();
        void Move(int Y, int X);
        int see_coins();
        int see_gems();
        bool portal_key;
        bool chest_unlocked;
        bool finish;

    private:
       int x;
       int y;
       int nr_of_coins;
       int nr_of_gems;

};

extern char map[20][121];
extern string message_chest;
extern string message_key;
extern string message_finish;



#endif // PLAYER_H
