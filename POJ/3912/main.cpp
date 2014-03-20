#include <iostream>
#include <algorithm>
#include <fstream>
#define INF 2000000000
#define MAXN 90
using namespace std;
ifstream fin("1.txt");



struct DATA
{
    int pos;
    bool isStart;
};


int roads[50][2];
DATA points[90];
int w,s,p;
bool inQueue[90];
int spfaQueue[90];
int dist[90];
int pre[90];

int cmp(DATA a, DATA b)
{
    if (a.pos<b.pos)
        return 1;
    else return 0;
}

int find_dist(int p1, int p2)
{
    if (p1 == p2)
        return -1;
    for (int i=0;i<p-1;i++)
        if (roads[i][0]==points[p1].pos && roads[i][1]==points[p2].pos)
        return 0;
    if (p1>p2)
        return -1;
    if (points[p1].isStart)
        return -1;
    int st=points[p1].pos;
    int sum=0;
    for (int i=p1+1;i<p2;i++)
    {
        int tmp=points[i].pos-st;
        if (tmp%s == 0 && points[i].isStart)
        {
            int ed=points[i].pos-1;
            int rest=s-1;
            int ctpoint=i-1;
            while (rest>0 && points[ctpoint].pos==ed && points[ctpoint].isStart)
            {
                ed--;
                ctpoint--;
                rest--;
            }
            if (rest == 0)
                return -1;
            sum+=(ed-st)/s;
            if ((ed-st)%s != 0)
                sum++;
            st=ed;
        }
    }
    sum+=(points[p2].pos-st)/s;
    if ((points[p2].pos-st)%s !=0)
        sum++;
    return sum;
}

int main()
{
    fin>>w;
    while (w != 0)
    {
        fin>>s>>p;
        for (int i=0;i<p;i++)
        {
            fin>>roads[i][0]>>roads[i][1];
            points[i<<1].pos=roads[i][0];
            points[i<<1].isStart=true;
            points[(i<<1)|1].pos=roads[i][1];
            points[i<<1|1].isStart=false;
        }
        points[p<<1].pos=0;
        points[p<<1].isStart=false;
        points[p<<1|1].pos=w;
        points[p<<1|1].isStart=false;
        p++;
        sort(points,points+p*2,cmp);
        int k=p*2-1;
        for (int i=0;i<=k;i++)
        {
            inQueue[i]=false;
            dist[i]=INF;
        }
        dist[0]=0;
        int head=0,tail=1;
        spfaQueue[0]=0;
        while (head != tail)
        {
            int current=spfaQueue[head];
            for (int i=0;i<=k;i++)
            {
                int tmp=find_dist(current,i);
                if (tmp != -1)
                {
                    if (dist[current]+tmp<dist[i])
                    {
                        dist[i]=dist[current]+tmp;
                        if (!inQueue[i])
                        {
                            spfaQueue[tail]=i;
                            pre[i]=current;
                            inQueue[i]=true;
                            tail=(tail+1)%MAXN;

                        }
                    }
                }
            }
            inQueue[current]=false;
            head=(head+1)%MAXN;
        }
        for (int i=0;i<=k;i++)
            if (points[i].pos == w)
              cout<<dist[i]<<endl;
        fin>>w;
    }
    return 0;
}
