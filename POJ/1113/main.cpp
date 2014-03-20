#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#define PI 3.1415926535

using namespace std;

struct POINT{
    int x,y;
};

POINT points[1002],pointStack[1002],stPoint;
int numOfPoints,stackSize,l,stNum;
double ans;

int crossMultiply(POINT p0, POINT p1,POINT p2, POINT p3)
{
    return (p1.x-p0.x)*(p3.y-p2.y)-(p3.x-p2.x)*(p1.y-p0.y);
}

double dist(POINT a, POINT b)
{
    double tmp=(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
    tmp=sqrt(tmp);
    return tmp;
}

int cmp(POINT a, POINT b)
{
    int m=crossMultiply(stPoint,a,stPoint,b);
    if (m>0) return 1;
    if (m<0) return 0;
    double len1=dist(stPoint,a);
    double len2=dist(stPoint,b);
    if (len1>len2)
        return 1;
    return 0;
}

int main()
{
    cin>>numOfPoints>>l;
    stPoint.x=100000000;
    stPoint.y=100000000;
    for (int i=0;i<numOfPoints;i++)
    {
        cin>>points[i].x>>points[i].y;
        if (points[i].y<stPoint.y || (points[i].y==stPoint.y && points[i].x<stPoint.x))
        {
            stNum=i;
            stPoint=points[i];
        }
    }
    points[stNum]=points[0];
    points[0]=stPoint;
    sort(points+1,points+numOfPoints,cmp);
    stackSize=3;
    pointStack[0]=points[0];
    pointStack[1]=points[1];
    pointStack[2]=points[2];
    points[numOfPoints]=stPoint;
    for (int i=3;i<=numOfPoints;i++){
        while (stackSize>2 && crossMultiply(pointStack[stackSize-2],points[i],pointStack[stackSize-2],pointStack[stackSize-1]) >=0 )
            stackSize--;
        pointStack[stackSize]=points[i];
        stackSize++;
    }
    ans=2*PI*l;
    for (int i=1;i<stackSize;i++)
    {
        ans+=dist(pointStack[i-1],pointStack[i]);
    }
    printf("%0.0lf",ans);
}
