#include <iostream>
#include <algorithm>

using namespace std;

struct POINT{
    int x,y;
};

POINT points[50002];
POINT pointStack[50002];
POINT stPoint;
int numOfPoints,stackSize,stnumber;


int crossMultiply(POINT p0, POINT p1, POINT p2, POINT p3)
{
    return (p1.x-p0.x)*(p3.y-p2.y)-(p3.x-p2.x)*(p1.y-p0.y);
}


int dist(POINT p1, POINT p2)
{
    return  (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
}


int cmp(POINT a, POINT b)
{
    int m=crossMultiply(stPoint,a,stPoint,b);
    if (m>0) return 1;
    if (m<0) return 0;
    if (dist(stPoint,a)>dist(stPoint,b))
        return 1;
    else return 0;
}

int main()
{
    cin>>numOfPoints;
    stPoint.x=100000000;
    stPoint.y=100000000;
    stnumber=-1;
    for (int i=0;i<numOfPoints;i++)
        {
            cin>>points[i].x>>points[i].y;
            if (points[i].y<stPoint.y || (points[i].y== stPoint.y && points[i].x<stPoint.x))
            {
                stPoint.x=points[i].x;
                stPoint.y=points[i].y;
                stnumber=i;
            }
        }
    if (numOfPoints<3)
    {
        cout<<dist(points[0],points[1])<<endl;
        return 0;
    }
    points[stnumber]=points[0];
    points[0]=stPoint;
    sort(points+1,points+numOfPoints,cmp);

    //other cases
    stackSize=3;
    pointStack[0]=points[0];
    pointStack[1]=points[1];
    pointStack[2]=points[2];
    points[numOfPoints]=points[0];
    for (int i=3;i<=numOfPoints;i++)
    {
        while (stackSize>2 && crossMultiply(pointStack[stackSize-2],points[i],pointStack[stackSize-2],pointStack[stackSize-1]) >= 0 )
        {
            stackSize--;
        }
        pointStack[stackSize]=points[i];
        stackSize++;
    }
    int maxdist=0;
    for (int i=1;i<stackSize;i++)
        for (int j=0;j<i;j++)
    {
        int tmp=dist(pointStack[i],pointStack[j]);
        if (tmp>maxdist)
            maxdist=tmp;
    }
    cout<<maxdist<<endl;
    return 0;
}
