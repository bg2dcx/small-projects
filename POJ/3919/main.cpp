#include <iostream>
#include <math.h>
#include <fstream>
#define INF 1000000000
#define precision 0.0000001
using namespace std;

ifstream fin("1.txt");

struct TOWER
{
    int x,y,strength;
};

struct DATA
{
    int x,y;
};

DATA points[20];
TOWER towers[20];
int prev,numOfPoints,numOfTowers,number;

double signal(int pNum, int tNum)
{
    double tmp=((double)towers[tNum].strength) * towers[tNum].strength;
    tmp/=((towers[tNum].x-points[pNum].x)*(towers[tNum].x-points[pNum].x)+(towers[tNum].y-points[pNum].y)*(towers[tNum].y-points[pNum].y));
    return tmp;
}

double signal(double x1, double y1, int x2, int y2, int power)
{
    return (power/ ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));

}

int find_best(double x, double y)
{
    double ans=0;
    int ansNum=-1;
    for (int i=0;i<numOfTowers;i++)
        if (signal(x,y,towers[i].x,towers[i].y,towers[i].strength) - ans > precision)
    {
        ans=signal(x,y,towers[i].x,towers[i].y,towers[i].strength);
        ansNum=i;
    }
    return ansNum;
}

double solve(int p1, int p2, double rest)
{
    double len=(points[p1].x-points[p2].x)*(points[p1].x-points[p2].x)+(points[p1].y-points[p2].y)*(points[p1].y-points[p2].y);
    len=sqrt(len);
    double incx=(points[p2].x-points[p1].x)*((1-rest)/len);
    double incy=(points[p2].y-points[p1].y)*((1-rest)/len);
    double currentx=points[p1].x+incx;
    double currenty=points[p1].y+incy;
    int best=find_best(currentx,currenty);
    if (best != prev)
    {
        cout<<'('<<number<<','<<(char) (best+'A')<<')'<<' ';
        prev=best;
    }
    number++;
    rest=len-(1-rest);
    incx=(points[p2].x-points[p1].x)*(1/len);
    incy=(points[p2].y-points[p1].y)*(1/len);
    while (rest >=1)
    {
        currentx+=incx;
        currenty+=incy;
        best=find_best(currentx,currenty);
        if (best != prev)
        {
            cout<<'('<<number<<','<<(char) (best+'A')<<')'<<' ';
            prev=best;
        }
        rest-=1;
        number++;
    }
    return rest;

}

int main()
{
    fin>>numOfTowers;
  while (numOfTowers!=0)
  {
    fin>>numOfPoints;
    for (int i=0;i<numOfTowers;i++)
        fin>>towers[i].x>>towers[i].y>>towers[i].strength;
    numOfPoints++;
    for (int i=0;i<numOfPoints;i++)
        fin>>points[i].x>>points[i].y;
    prev=-1;
    double tmp=0;
    if (find_best(points[0].x,points[0].y) != prev)
    {
        cout<<'('<<0<<','<<(char) (find_best(points[0].x,points[0].y)+'A')<<')'<<' ';
        prev=find_best(points[0].x,points[0].y);
    }
    number=1;
    for (int i=1;i<numOfPoints;i++)
    {
         tmp=solve(i-1,i,tmp);
    }
    if (tmp >= 0.5)
    {
        if (find_best(points[numOfPoints-1].x,points[numOfPoints-1].y) != prev)
        {
            cout<<'('<<number<<','<<(char) (find_best(points[numOfPoints-1].x,points[numOfPoints-1].y)+'A')<<')';
        }
    }
    cout<<endl;
    fin>>numOfTowers;
  }
    return 0;
}
