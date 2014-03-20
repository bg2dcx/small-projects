
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#define INF 99999999
using namespace std;
struct list
{
    double x;
    double y;
    double z;
    double r;
}point[100001];
double juli(int i,int j)
{
    double len;
    len=sqrt((point[i].x-point[j].x)*(point[i].x-point[j].x)
            +(point[i].y-point[j].y)*(point[i].y-point[j].y)
            +(point[i].z-point[j].z)*(point[i].z-point[j].z));
    if(len-point[i].r-point[j].r<0)return 0;
    return len-point[i].r-point[j].r;
}
int main()
{
    int i,j,n;
    double map[101][101];
    while(scanf("%d",&n)&&n)
    {
        memset(map,0,sizeof(map));
        for(i=0;i<n;i++)
        {
            cin>>point[i].x>>point[i].y>>point[i].z>>point[i].r;
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i!=j)
                {
                    map[i][j]=juli(i,j);
                }
            }
        }
        double low[101];
        int visit[101];
        memset(visit,0,sizeof(visit));
        visit[0]=1;
        for(i=0;i<n;i++)
        {
            low[i]=map[0][i];
        }
        double sum;
        sum=0;
        for(i=0;i<n;i++)
        {
            double min;
            int ipos;
            min=INF;
            for(j=0;j<n;j++)
            {
                if(!visit[j]&&min>low[j])
                {
                    min=low[j];
                    ipos=j;
                }
            }
            if(min==INF)break;
            sum+=min;
            cout<<ipos<<' '<<min<<endl;
            visit[ipos]=1;
            for(j=0;j<n;j++)
            {
                if(low[j]>map[ipos][j])
                {
                    low[j]=map[ipos][j];
                }
            }
        }
        printf("%.3fn",sum);
    }
    return 0;
}
