#include <iostream>
#include <memory.h>
#include <stdio.h>
using namespace std;

int incx[8]={-1,-1,0,1,1,1,0,-1};
int incy[8]={0,1,1,1,0,-1,-1,-1};

char grid[101][101];
int flag[101][101];
int m,n;
int ans;

void bfs(int posx, int posy)
{
    flag[posx][posy]=1;
    int nextx=posx;
    int nexty=posy;
    for (int i=0;i<8;i++)
    {
        nextx=posx+incx[i];
        nexty=posy+incy[i];
        if (nextx>=0 && nextx<n && nexty>=0 && nexty<m && grid[nextx][nexty]=='@' && flag[nextx][nexty]==0)
            bfs(nextx,nexty);
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    while ( !(n==0 && m==0))
    {
        for (int x=0;x<n;x++)
            scanf("%s",grid[x]);
        memset(flag,0,sizeof(flag));
        ans=0;
        for (int x=0;x<n;x++)
            for (int y=0;y<m;y++)
            if (grid[x][y] == '@' && flag[x][y]==0)
            {
                ans++;
                bfs(x,y);
            }
        cout<<ans<<endl;
        scanf("%d%d",&n,&m);
    }
    return 0;
}
