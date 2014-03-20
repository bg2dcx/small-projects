#include <iostream>
#define MAXN 12
using namespace std;

int numOfRows,numOfCols,StPos;

int step[MAXN][MAXN];
char grid[MAXN][MAXN];

void init()
{
    for (int i=0;i<MAXN;i++)
        for (int j=0;j<MAXN;j++)
        step[i][j]=-1;
}

void solve(int posx,int posy)
{
    char direction=grid[posx][posy];
    int incx=0;
    int incy=0;
    switch (direction)
    {
        case 'S': incx=1; incy=0;
                break;
        case 'N': incx=-1;incy=0;
                break;
        case 'W': incx=0; incy=-1;
                break;
        case 'E': incx=0; incy=1;
                break;
    }
    int nextx=posx+incx;
    int nexty=posy+incy;
    if (nextx<1 || nexty<1 || nextx>numOfRows || nexty>numOfCols)
    {
        cout<<step[posx][posy]<<" step(s) to exit"<<endl;
        return;
    } else
        if (step[nextx][nexty] != -1)
        {
            cout<<step[nextx][nexty]-1<<" step(s) before a loop of "<<step[posx][posy]-step[nextx][nexty]+1<<" step(s)"<<endl;
            return;
        } else
        {
            step[nextx][nexty]=step[posx][posy]+1;
            solve(nextx,nexty);
        }
}

int main()
{
    cin>>numOfRows>>numOfCols>>StPos;
    while (! (numOfCols==0 && numOfRows==0 && StPos==0))
    {
        init();
        for (int i=1;i<=numOfRows;i++)
            for (int j=1;j<=numOfCols;j++)
        {
            cin>>grid[i][j];
        }
        step[1][StPos]=1;
        solve(1,StPos);
        cin>>numOfRows>>numOfCols>>StPos;
    }
    return 0;
}
