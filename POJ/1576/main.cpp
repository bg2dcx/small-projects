#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
ifstream fin("1.txt");

int numOfPlayers,numOfCards,numOfPieces;
bool win;

char board[100];
char card[3];
int pos[5];

bool play(int player, char card[])
{
    int len=strlen(card);
    for (int i=1;i<=len;i++)
    {
        int current=pos[player]+1;
        while (current<numOfPieces && board[current]!=card[i-1])
            current++;
        if (current>=numOfPieces-1)
            if (!win)
        {
            return true;
        }
        pos[player]=current;
    }
    return false;
}

int main()
{
    fin>>numOfPlayers>>numOfPieces>>numOfCards;
    win=false;
    while (numOfPlayers !=0)
    {
        for (int i=0;i<numOfPieces;i++)
            fin>>board[i];
        for (int i=0;i<=numOfPlayers;i++)
            pos[i]=-1;
        for (int i=1;i<=numOfCards;i++)
        {
            fin>>card;
            int player=i%numOfPlayers;
            if (player ==0)
                player=numOfPlayers;
            if (!win)
            {
                win=play(player,card);
                if (win)
                {
                    cout<<"Player "<<player<<" won after "<<i<<" cards."<<endl;
                }
            }
        }
        if (!win)
            cout<<"No player won after "<<numOfCards<<" cards."<<endl;
        fin>>numOfPlayers>>numOfPieces>>numOfCards;
        win=false;
    }
    return 0;
}
