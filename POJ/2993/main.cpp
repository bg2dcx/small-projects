#include <iostream>
#include <string.h>

using namespace std;

char board[9][9];
bool isWhite[9][9];
char line[256];
int linelength;
int main()
{
    cin.getline(line,256);
    linelength=strlen(line);
    int prev,next;
    prev=0;
    for (int i=1;i<=8;i++)
        for (int j=1;j<=8;j++)
        board[i][j]='!';
    while (line[prev] != ' ' && prev<linelength) prev++;
    while (prev<linelength)
    {
        next=prev+1;
        while ( line[next]!=',' && next<linelength) next++;
        if (next-prev == 3)
        {
            int row=line[prev+2]-'0';
            int col=line[prev+1]-'a'+1;
            board[row][col]='P';
        }
        if (next-prev == 4)
        {
            int row=line[prev+3]-'0';
            int col=line[prev+2]-'a'+1;
            board[row][col]=line[prev+1];
        }
        prev=next;
    }
    cin.getline(line,256);
    linelength=strlen(line);
    prev=0;
    while (line[prev] != ' ' && prev<linelength) prev++;
    while (prev<linelength)
    {
        next=prev+1;
        while ( line[next]!=',' && next<linelength) next++;
        if (next-prev == 3)
        {
            int row=line[prev+2]-'0';
            int col=line[prev+1]-'a'+1;
            board[row][col]='p';
        }
        if (next-prev == 4)
        {
            int row=line[prev+3]-'0';
            int col=line[prev+2]-'a'+1;
            board[row][col]=line[prev+1]+'k'-'K';
        }
        prev=next;
    }
    for (int i=8;i>0;i--)
    {
        cout<<"+---+---+---+---+---+---+---+---+"<<endl;
        for (int j=1;j<9;j++)
        {
            cout<<'|';
            char tmp;
            if ( (i+j)%2==1)
                tmp='.';
             else tmp=':';
            cout<<tmp;
            if (board[i][j]=='!')
                cout<<tmp;
              else cout<<board[i][j];
            cout<<tmp;
        }
        cout<<'|'<<endl;
    }
    cout<<"+---+---+---+---+---+---+---+---+"<<endl;
    return 0;
}
