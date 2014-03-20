#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("1.txt");

char board[4][4];
int n,ans;

void dfs(int x, int y, int numOfRooks, bool putit)
{
    if (x>=n || y>=n)
        return;
    int numNow=numOfRooks;
    if (putit)
    {
        bool OK=true;
        for (int i=x-1;i>=0;i--)
        {
            if ( board[i][y] == 'X') break;
            if (board[i][y] == 'R')
            {
                OK=false;
                break;
            }
        }
        if (!OK) return;
        for (int i=x+1;i<n;i++)
        {
            if ( board[i][y] == 'X') break;
            if (board[i][y] == 'R')
            {
                OK=false;
                break;
            }
        }
        if (!OK) return;
        for (int j=y-1;j>=0;j--)
        {
            if (board[x][j] == 'X') break;
            if (board[x][j] == 'R')
            {
                OK=false;
                break;
            }
        }
        for (int j=y+1;j<n;j++)
        {
            if (board[x][j] == 'X') break;
            if (board[x][j] == 'R')
            {
                OK=false;
                break;
            }
        }
        if (!OK) return;
        board[x][y]='R';
        numNow++;
    }
    if (numNow>ans)
        ans=numNow;
    int nextx=x;
    int nexty=y+1;
    if (nexty==n)
    {
        nextx++;
        nexty=0;
    }
    if (nextx <n && nexty<n && board[nextx][nexty] != 'X')
        dfs(nextx,nexty,numNow,true);
    dfs(nextx,nexty,numNow,false);
    if (putit)
    {
        board[x][y]='.';
    }
}

int main()
{
    fin>>n;
    while (n != 0)
    {
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                fin>>board[i][j];
        ans=0;
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                if (board[i][j] == '.')
                    dfs(i,j,0,true);
        cout<<ans<<endl;
        fin>>n;
    }
    return 0;
}
