#include "Player.h"
#include <iostream>
#include <cstdlib>


using namespace std;

char map[20][121]={
"|------------------------------------------------|-----------|------------------------------|----|                    ",
"|@            $                         $        |>>>>       |                              | $  | To finish the game,",
"|                     ----------     |           [                     ----|     ----            | you need to get THE",
"|---|----   ------                   |      -----|>>>>    -------|         |             -----|--| GOLDEN CHEST.      ",
"| $ |          |        +         ---|           |               |   +            |           |  |                    ",
"|              |              |          |       |     |-----    |      -------   |----          | ~ portal key=10$   ",
"|      -----|--|--|           |          |-----  |-----|                                         | % precious gem=5$  ",
"|           |  ~  |    -------|          |$      |  %  |   |-------                      |-------| ) 1st chest gate=2%",
"| -----     |     |                              |--*--|   |          |    +      --|--?-|   THE | < final gate=5%    ",
"|     |     |--U--|         ---|--    |----------|         | +    ----|             )    < GOLDEN| + coin chest=get 4$",
"|     | +                      |      |     $    |       $ |          |----|      --|--?-|  CHEST|                    ",
"| $   |                  |            |    ------|---|-----|          | %  |             |-------|                    ",
"|      ----------        | $          |          | % |                |-*--|    |---             |                    ",
"|                        |--------    |          |   |           $|             |      |---------|                    ",
"|--*--|       + |----                            |-*-|     -------|     +       |      |  $$     |                    ",
"|  %  |         |              |-*-|         >>>>|                |                    |         | TO WIN THE GOLDEN  ",
"|-----|   ------|------|--     |   |----         ]    --|--*--|        ----| + ----        |--*--| CHEST you need 5%  ",
"|                   $  |       | % |         >>>>|      |  %  |            |               |  %  |                    ",
"|----------------------|-------|---|-------------|------|-----|------------|---------------|-----|                    "};

string message_chest=" ";
string message_key=" ";
string message_finish=" ";

Player::Player()
{
    x=y=1;
   nr_of_coins=0;
   nr_of_gems=0;
  chest_unlocked=false;

}

Player::~Player()
{
    //dtor
}

void Player::Move(int Y, int X)
{
    int newx=x+X;
    int newy=y+Y;

    if(map[y][newx]==' ' || map[newy][x]==' ')
    {
        map[y][x]=' ';
        x=x+X;
        y=y+Y;
        map[y][x]='@';
    }

    if(map[y][newx]=='$')
    {
        nr_of_coins++;
        map[y][x]=' ';
        x=x+X;
        map[y][x]='@';
    }

    if(map[newy][x]=='$')
    {
        nr_of_coins++;
        map[y][x]=' ';
        y=y+Y;
        map[y][x]='@';
    }

    if( map[y][newx]=='+' )
       {
        map[y][x]=' ';
        x=x+X;
        map[y][x]='@';
       chest_unlocked=true;
     message_chest="You have unlocked a coin chest! Press Space to clear the message.";
        map[y-1][x]='$';
        map[y+1][x]='$';
        map[y][x-1]='$';
        map[y][x+1]='$';
       }

    if( map[newy][x]=='+' )
    {
        map[y][x]=' ';
        y=y+Y;
        map[y][x]='@';
        chest_unlocked=true;
        message_chest="\nYou have unlocked a coin chest! Press Space to clear the message.\n";
        map[y-1][x]='$';
        map[y+1][x]='$';
        map[y][x-1]='$';
        map[y][x+1]='$';
    }
    if(map[newy][x]=='U'&& nr_of_coins>=10)
    {  map[y][x]=' ';
       y=y+Y;
       map[y][x]='@';
       nr_of_coins-=10;

    }
    if(map[y][newx]=='~' || map[newy][x]=='~' )
    {
        map[y][x]=' ';
        x=x+X;
        y=y+Y;
        map[y][x]='@';
        portal_key=true;
        message_key="\nCongratulations!You got the key to the other world! Press Space to clear the message.\n";
    }
    if(map[y][newx]==']'&& portal_key==true && X>0)
    {
        map[y][x]=' ';
        map[2][51]='@';
        x=51;
        y=2;
    }
    if(map[y][newx]=='['&& X<0 )
    {
        map[y][x]=' ';
        y=16;
        x=48;
        map[y][x]='@';
    }
    if((map[y][newx]=='*' || map[newy][x]=='*') && nr_of_coins >= 5)
    {
        map[y][x]=' ';
        x=x+X;
        y=y+Y;
        map[y][x]='@';
    }
    if(map[y][newx]=='%' || map[newy][x]=='%')
    {
        map[y][x]=' ';
        x=x+X;
        y=y+Y;
        map[y][x]='@';
        nr_of_gems++;
        nr_of_coins-=5;
    }
    if(map[y][newx]==')' && nr_of_gems >=2 )
    {
        map[y][x]=' ';
        x=x+X;
        map[y][x]='@';
        nr_of_gems-=2;

    }
    if(map[y][newx]=='<' && nr_of_gems >=5 )
    {
        map[y][x]=' ';
        x=x+X;
        map[y][x]='@';
        nr_of_gems-=5;
        finish=true;
        message_finish="\nCONGRATULATIONS! YOU WON THE GOLDEN CHEST!";
    }
}

int Player::see_coins()
{
    return nr_of_coins;
}

int Player::see_gems()
{
    return nr_of_gems;
}
