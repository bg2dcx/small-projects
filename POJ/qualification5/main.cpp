#include <iostream>
#include <memory.h>
#define MAXN 130
#define MAXSTEPS 500
#define QMAX 200
using namespace std;

struct NODE
{
    int dist;
    bool possible[3];
} nodes[130][130];

int numOfcases;
int numOfSteps;
int stx,sty,edx,edy,ctx,cty,ntx,nty;
int spfaQueue[200][2];
bool inQueue[130][130];

void init()
{
    for (int i=0;i<MAXN;i++)
        for (int j=0;j<MAXN;j++)
    {
        nodes[i][j].dist=MAXSTEPS;
        for (int k=0;k<4;k++)
            nodes[i][j].possible[k]=false;
    }
}

void update_info(char direction)
{
    switch (direction)
    {
        case 'S': ntx=ctx+1;
                  nty=cty;
                  nodes[ctx][cty].possible[0]=true;
                  nodes[ntx][nty].possible[2]=true;
                  break;
        case 'E': ntx=ctx;
                  nty=cty+1;
                  nodes[ctx][cty].possible[1]=true;
                  nodes[ntx][nty].possible[3]=true;
                  break;
        case 'N': ntx=ctx-1;
                  nty=cty;
                  nodes[ctx][cty].possible[2]=true;
                  nodes[ntx][nty].possible[0]=true;
                  break;
        case 'W': ntx=ctx;
                  nty=cty-1;
                  nodes[ctx][cty].possible[3]=true;
                  nodes[ntx][nty].possible[1]=true;
                  break;
    }
}

int main()
{
    cin>>numOfcases;
    while (numOfcases--)
    {
        cin>>numOfSteps;
        init();
        stx=60;
        sty=60;
        ctx=stx;
        cty=sty;
        char tmp;
        for (int i=0;i<numOfSteps;i++)
        {
            cin>>tmp;
            update_info(tmp);
            ctx=ntx;
            cty=nty;
        }
        edx=ctx;
        edy=cty;
        int head=0, tail=1;
        memset(inQueue,0,sizeof(inQueue));
        inQueue[stx][sty]=true;
        spfaQueue[0][0]=stx;
        spfaQueue[0][1]=sty;
        nodes[stx][sty].dist=0;
        while (head != tail)
        {
            ctx=spfaQueue[head][0];
            cty=spfaQueue[head][1];
            for (int i=0;i<4;i++)
                if (nodes[ctx][cty].possible[i])
            {
                switch (i)
                {
                case 0: ntx=ctx+1;
                  nty=cty;
                  break;
                case 1: ntx=ctx;
                  nty=cty+1;
                  break;
                case 2: ntx=ctx-1;
                  nty=cty;
                  break;
                case 3: ntx=ctx;
                  nty=cty-1;
                  break;
                }
                if (nodes[ctx][cty].dist+1 < nodes[ntx][nty].dist)
                {
                    nodes[ntx][nty].dist=nodes[ctx][cty].dist+1;
                    if (!inQueue[ntx][nty])
                    {
                        spfaQueue[tail][0]=ntx;
                        spfaQueue[tail][1]=nty;
                        inQueue[ntx][nty]=true;
                        tail=(tail+1)%QMAX;
                    }
                }
            }
            inQueue[ctx][cty]=false;
            head=(head+1)%QMAX;
        }
        cout<<nodes[edx][edy].dist<<endl;
    }
    return 0;
}
