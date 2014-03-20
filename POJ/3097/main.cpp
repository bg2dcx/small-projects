#include <iostream>
#include <stdio.h>
#include <math>
#define precesion 0.000001
using namespace std;

struct POINT{
    double x,y;
};

POINT centers[20];
double diameters[20];

double width,rightest, highest;
int n;

bool isOK(double xx, double yy, double dd, int number)
{
    if (xx-width>precesion || xx<-precesion || yy<-precesion)
        return false;
    if (yy-dd/2 < -precesion)
        return false;
    for (int i=0;i<number;i++)
    {
        double dist=sqrt((xx-centers[i].x)*(xx-centers[i].x)+(yy-centers[i].y)*(yy-centers[i].y));
        if (dist-(diameters[i]+dd)/2 < -precesion)
            return false;
    }
    return true;
}

int main()
{
    cin>>width;
    while ( !(width>-precesion && width<precesion))
    {
        cin>>n;
        rightest=0;
        for (int i=0;i<n;i++)
        {
            cin>>diameters[i];
            if (rightest+diameters[i]<width+precesion)
            {
                center[i].y=diameters[i]/2;
                if (i == 0)
                    centers[i].x=diameters[i]/2;
                else
                {
                    double xx=0;
                    for (int k=0;k<i;k++)
                    {
                        double tmp=(diameters[i]/2+diameters[k]/2)*(diameters[i]/2+diameters[k]/2)-(centers[k].y-centers[i].y)*(centers[k].y-centers[i].y);
                        if (tmp > 0)
                        {
                            if (sqrt(tmp)+centers[k].x >xx && isOK(sqrt(tmp)+centers[k].x,centers[i].y,diameters[i],i))
                                xx=sqrt(tmp)+centers[k].x;
                        }
                    }
                    centers[i].x=xx;
                }
                if (centers[i].x > rightest)
                    rightest=centers[i].x;
            } else
            {
                double yy=0;
                double xx=width-diameters[i]/2;
                for (int k=0;k<i;k++)
                  if (centers[k].x+diameters[k]/2-xx>-precesion)
                {
                    double tmp=(diameters[i]/2+diameters[k]/2)*(diameters[i]/2+diameters[k]/2)-(centers[k].x-xx)*(centers[k].y-xx);
                    if (tmp > 0)
                    {
                        if (sqrt(tmp)+centers[k].y > yy && isOK(xx,sqrt(tmp)+centers[k].y,diameters[i],i))
                            yy=sqrt(tmp)+centers[k].y
                    }
                }
                if (yy < precesion)
                    yy=10000;

            }
        }
    }
    return 0;
}
