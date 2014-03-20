#include <iostream>
#include <memory.h>
#include <fstream>
#define MAXN 450
#define MAXD 1134000
#define LEN 2520

using namespace std;

ifstream fin("1.txt");

int row,column,c1,c2,tmpDist;
char tmpChar;

int dist[MAXN][MAXN];

bool inQueue[MAXN];
int time[MAXN],spfaQueue[MAXN];

int main()
{
    fin>>row>>column;
 while ( !(row == 0 && column == 0))
 {
  memset(dist,0,sizeof(dist));
  for (int i=0;i<row;i++)
    {
        for (int j=1;j<=column;j++)
        {
            //west - east
            fin>>tmpDist;
            fin>>tmpChar;
            c1=i*(column+1)+j;
            c2=c1+1;
            if (tmpChar == '*')
            {
                dist[c1][c2]=tmpDist;
                dist[c2][c1]=tmpDist;
            } else
            {
                if (tmpChar == '>')
                    dist[c1][c2]=tmpDist;
                else
                    dist[c2][c1]=tmpDist;
            }
        }
        for (int j=1;j<=column+1;j++)
        {
            c1=i*(column+1)+j;
            c2=c1+column+1;
            fin>>tmpDist;
            fin>>tmpChar;
            if (tmpChar == '*')
            {
                dist[c1][c2]=tmpDist;
                dist[c2][c1]=tmpDist;
            } else
            {
                if (tmpChar == 'v')
                    dist[c1][c2]=tmpDist;
                else
                    dist[c2][c1]=tmpDist;
            }

        }
    }
    for (int j=1;j<=column;j++)
    {
        //west - east
        fin>>tmpDist;
        fin>>tmpChar;
        c1=row*(column+1)+j;
        c2=c1+1;
            if (tmpChar == '*')
        {
            dist[c1][c2]=tmpDist;
            dist[c2][c1]=tmpDist;
        } else
        {
            if (tmpChar == '>')
                dist[c1][c2]=tmpDist;
            else
                dist[c2][c1]=tmpDist;
        }
    }
    int destination=(row+1)*(column+1);
    for (int i=1;i<=destination;i++)
    {
        inQueue[i]=false;
        time[i]=MAXD;
    }
    time[1]=0;
    inQueue[1]=true;
    int tail=1,head=0;
    spfaQueue[head]=1;
    while (head != tail)
    {
        int current=spfaQueue[head];
        for (int k=1;k<=destination;k++)
            if (k!=current && dist[current][k]!=0)
        {
            if (LEN/dist[current][k]+time[current]<time[k])
            {
                time[k]=LEN/dist[current][k]+time[current];
                if (!inQueue[k])
                {
                    inQueue[k]=true;
                    spfaQueue[tail]=k;
                    tail=(tail+1)%MAXN;
                }
            }
        }
        inQueue[current]=false;
        head=(head+1)%MAXN;
    }
    if (time[destination] == MAXD)
        cout<<"Holiday"<<endl;
    else cout<<time[destination]<<" blips"<<endl;
    fin>>row>>column;
 }
    return 0;
}
