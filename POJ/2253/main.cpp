#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <math.h>
#define INF 100000000
#define precision 0.00001;

using namespace std;

struct POINT{
    int x,y;
};
int n;
int caseNum;
double dist[300];
POINT points[300];
bool inQueue[300];
int spfaqueue[300];

double calc_dist(int a, int b)
{
    double tmp=(points[a].x-points[b].x)*(points[a].x-points[b].x)+(points[a].y-points[b].y)*(points[a].y-points[b].y);
    return sqrt(tmp);
}

double find_max(double a, double b)
{
    if (a>b) return a;
    else return b;
}

int main()
{
    cin>>n;
    caseNum=0;
    while (n != 0)
    {
        caseNum++;
        for (int i=0;i<n;i++)
        {
            cin>>points[i].x>>points[i].y;
            dist[i]=INF;
        }
        int head=0, tail=1;
        memset(inQueue,0,sizeof(inQueue));
        dist[0]=0;
        spfaqueue[0]=0;
        inQueue[0]=true;
        while (head != tail)
        {
            int current=spfaqueue[head];
            for (int i=0;i<n;i++)
                if (i!=current)
            {
                double tmp=calc_dist(current,i);
                tmp=find_max(dist[current],tmp);
                if (tmp<dist[i])
                {
                    dist[i]=tmp;
                    if (!inQueue[i])
                    {
                        inQueue[i]=true;
                        spfaqueue[tail]=i;
                        tail=(tail+1)%300;
                    }
                }
            }
            inQueue[current]=false;
            head=(head+1)%300;
        }
        printf("Scenario #%d\n",caseNum);
        printf("Frog Distance = %0.3lf\n",dist[1]);
        printf("\n");
        cin>>n;
    }
    return 0;
}
