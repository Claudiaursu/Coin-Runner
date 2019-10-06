#include <iostream>
#include "Player.h"
#include "Windows.h"
#include <string>
#include <conio.h>
#define LIGHTMAGENTA 13
#include <windows.h>
#include <mmsystem.h>

using namespace std;

bool gamerunning=true;
Player player;

int main()
{
 HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);

    while(gamerunning)
    {
        SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY );

        system("cls");
        for(int i=0; i<20; i++)
        {
            cout<< map[i]<<endl;

        }

        SetConsoleTextAttribute(h,FOREGROUND_GREEN);
        cout<<"Coins: "<<player.see_coins()<<endl;

        SetConsoleTextAttribute(h,13);
        cout<<"Gems: "<<player.see_gems()<<endl;

         if(GetAsyncKeyState(VK_SPACE))
        {
            message_chest=" ";
            player.chest_unlocked=false;
            message_key=" ";
        }

        SetConsoleTextAttribute(h,FOREGROUND_BLUE);
        if(player.chest_unlocked)cout<<message_chest;

        SetConsoleTextAttribute(h,FOREGROUND_RED);
        if(player.portal_key) cout<<message_key;
        if(player.finish)
        { cout<<message_finish;
          PlaySound(TEXT("finish.wav"),NULL,SND_SYNC);
        }

        if(GetAsyncKeyState(VK_SPACE))
        {
            message_chest=" ";
            player.chest_unlocked=false;
        }

        system("pause>nul");

        if(GetAsyncKeyState(VK_UP))
            player.Move(-1,0);

         if(GetAsyncKeyState(VK_DOWN))
            player.Move(1,0);

         if(GetAsyncKeyState(VK_RIGHT))
            player.Move(0,1);

         if(GetAsyncKeyState(VK_LEFT))
            player.Move(0,-1);
    }

      return 0;
}
