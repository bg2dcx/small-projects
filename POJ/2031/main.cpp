#include <iostream>
#include <math.h>
#include <stdio.h>
#include <fstream>
#define LARGEDIST 40000000
using namespace std;

//ifstream fin("1.txt");

struct CELL
{
    double x,y,z,r;
};

struct NODE
{
    int st,ed;
    double dist;
};

int number;
double sum;

CELL cells[101];
NODE points[101];

double calc_dist(int a, int b)
{
    double dist=(cells[a].x-cells[b].x)*(cells[a].x-cells[b].x)+(cells[a].y-cells[b].y)*(cells[a].y-cells[b].y)+(cells[a].z-cells[b].z)*(cells[a].z-cells[b].z);
    dist=sqrt(dist);
    dist=dist-cells[a].r-cells[b].r;
    if (dist<0) dist=0;
    return dist;
}

int main()
{
    while (cin>>number)
    {
        if (number == 0)
            return 0;
        for (int i=0;i<number;i++)
            cin>>cells[i].x>>cells[i].y>>cells[i].z>>cells[i].r;
        sum=0;
        for (int i=1;i<number;i++)
        {
            points[i].st=0;
            points[i].ed=i;
            points[i].dist=calc_dist(0,i);
        }
        for (int i=1;i<number;i++)
        {
            int minnum=-1;
            double mindist=LARGEDIST;
            for (int k=i;k<number;k++)
                if (points[k].dist<mindist)
            {
                mindist=points[k].dist;
                minnum=k;
            }
            sum+=mindist;
            NODE tmp;
            tmp=points[minnum];
            points[minnum]=points[i];
            points[i]=tmp;
            for (int k=i+1;k<number;k++)
                if (calc_dist(tmp.ed,points[k].ed)<points[k].dist)
            {
                points[k].dist=calc_dist(tmp.ed,points[k].ed);
                points[k].st=tmp.ed;
            }
        }
        printf("%0.3lf\n",sum);
    }
    return 0;
}
