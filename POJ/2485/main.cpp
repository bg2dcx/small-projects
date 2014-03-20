#include <iostream>
#define MAXN 501

using namespace std;

struct highway
{
    int stcity;
    int edcity;
    int distance;
};

int numOfCases, numOfcities;
int dist[MAXN][MAXN];
highway roads[MAXN];
int prim(int firstCity)
{
    int ans=0;
    for (int i=1;i<=numOfcities;i++)
    {
        roads[i].stcity=firstCity;
        roads[i].edcity=i;
        roads[i].distance=dist[firstCity][i];
    }
    for (int i=firstCity+1;i<=numOfcities;i++)
    {
        int mindist=MAXN*70000;
        int minnum=-1;
        for (int k=i;k<=numOfcities;k++)
            if (roads[k].distance<mindist)
        {
            mindist=roads[k].distance;
            minnum=k;
        }
        int tmpstCity=roads[minnum].stcity;
        int tmpedCity=roads[minnum].edcity;
        int tmpdist=roads[minnum].distance;
        roads[minnum].stcity=roads[i].stcity;
        roads[minnum].edcity=roads[i].edcity;
        roads[minnum].distance=roads[i].distance;
        roads[i].stcity=tmpstCity;
        roads[i].edcity=tmpedCity;
        roads[i].distance=tmpdist;
        if (tmpdist>ans)
        {
            ans=tmpdist;
        }
        for (int k=i+1;k<=numOfcities;k++)
            if (dist[tmpedCity][roads[k].edcity] < roads[k].distance)
        {
            roads[k].distance=dist[tmpedCity][roads[k].edcity];
            roads[k].stcity=tmpedCity;
        }
    }
    return ans;
}

int main()
{
    cin>>numOfCases;
    for (int cases=1;cases<=numOfCases;cases++)
    {
        cin>>numOfcities;
        for (int i=1;i<=numOfcities;i++)
            for (int j=1;j<=numOfcities;j++)
        {
            cin>>dist[i][j];
        }
        int answer=prim(1);
        cout<<answer<<endl;
    }
    return 0;
}
