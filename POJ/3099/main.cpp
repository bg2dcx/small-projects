#include <iostream>
#include <stdlib.h>
#include <fstream>
#define MAXD 10000000
using namespace std;

ifstream fin("1.txt");
struct DATA
{
    int x,y,z;
    int id;
} planets[1010];

int n, maxi,ans1,ans2;

struct NODE
{
    int dest;
    NODE *next;
} road[1010];



void init()
{
    for (int i=0;i<1010;i++)
    {
        road[i].dest=-1;
        road[i].next=NULL;
    }
}

int dist(int p1, int p2)
{
    return (planets[p1].x-planets[p2].x)*(planets[p1].x-planets[p2].x)
            +(planets[p1].y-planets[p2].y)*(planets[p1].y-planets[p2].y)
            +(planets[p1].z-planets[p2].z)*(planets[p1].z-planets[p2].z);
}

int spfa(int st)
{
    int spfaQueue[1010];
    bool inQueue[1010];
    int dist[1010];
    for (int i=0;i<n;i++)
    {
        dist[i]=MAXD;
        inQueue[i]=false;
    }
    dist[st]=0;
    inQueue[st]=true;
    spfaQueue[0]=st;
    int head=0,tail=1;
    while (head != tail)
    {
        int current=spfaQueue[head];
        NODE *nextn=&(road[current]);
        while (nextn != NULL)
        {
            int next=nextn->dest;
            if (dist[current]+1 < dist[next])
            {
                dist[next]=dist[current]+1;
                if (!inQueue[next])
                {
                    inQueue[next]=true;
                    spfaQueue[tail]=next;
                    tail=(tail+1)%1010;
                }
            }
            nextn=nextn->next;
        }
        inQueue[current]=false;
        head=(head+1)%1010;
    }
    int sum=0;
    for (int i=0;i<n;i++)
        if (dist[i]>sum)
            sum=dist[i];
    return sum;
}

void addRoad(int st, int ed)
{
    if (road[st].dest==-1)
    {
        road[st].dest=ed;
    } else
    {
        NODE *p=&(road[st]);
        while (p->next != NULL)
            p=p->next;
        NODE *q;
        q=(NODE *)malloc(sizeof(NODE));
        q->dest=ed;
        q->next=NULL;
        p->next=q;
    }
}

int main()
{
    fin>>n;
    while (n !=0)
    {
        init();
        for (int i=0;i<n;i++)
        {
            fin>>planets[i].id>>planets[i].x>>planets[i].y>>planets[i].z;
            if (i != 0)
            {
                double minDist=dist(0,i);
                int tmp=0;
                for (int k=1;k<i;k++)
                    if (dist(k,i)<minDist)
                    {
                        tmp=k;
                        minDist=dist(k,i);
                    }
                addRoad(tmp,i);
                addRoad(i,tmp);
            }
        }
        maxi=10000000;
        ans1=-1;
        ans2=-1;
        bool getTwo=false;
        for (int i=0;i<n;i++)
        {
            if (spfa(i) < maxi)
            {
                maxi=spfa(i);
                ans1=i;
                getTwo=false;
            } else if (spfa(i) == maxi)
            {
                ans2=i;
                getTwo=true;
            }
        }
        if (getTwo)
        {
            if (planets[ans1].id < planets[ans2].id)
                cout<<planets[ans1].id<<' '<<planets[ans2].id<<endl;
            else
                cout<<planets[ans2].id<<' '<<planets[ans1].id<<endl;
        } else
        cout<<planets[ans1].id<<endl;
        fin>>n;
    }
    return 0;
}
