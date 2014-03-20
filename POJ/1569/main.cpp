#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("1.txt");



struct POINT
{
    int x,y;
    char name;
};

POINT points[16];
int numOfMonuments;
int ansMonu[3];
int ansArea;

int cmp(POINT a, POINT b)
{
    if (a.name<b.name)
        return true;
    else return false;
}

int calc_area(POINT a, POINT b, POINT c)
{
    int tmp=(a.x-b.x)*(a.y-c.y)-(a.x-c.x)*(a.y-b.y);
    tmp=abs(tmp);
    return tmp;
}

bool solve(int number, int a, int b, int c, int area)
{
    bool outside=false;
    int tmp=calc_area(points[number],points[a],points[b])+calc_area(points[number],points[a],points[c]);
    if (tmp>area) outside=true;
    tmp=calc_area(points[number],points[b],points[a])+calc_area(points[number],points[b],points[c]);
    if (tmp>area) outside=true;
    tmp=calc_area(points[number],points[c],points[a])+calc_area(points[number],points[c],points[b]);
    if (tmp>area) outside=true;
    return outside;
}

int main()
{
    fin>>numOfMonuments;
    while (numOfMonuments != 0)
    {
        for (int i=0;i<numOfMonuments;i++)
        {
            fin>>points[i].name;
            fin>>points[i].x>>points[i].y;
        }
        sort(points,points+numOfMonuments,cmp);
        ansArea=0;
        for (int i=2;i<numOfMonuments;i++)
            for (int j=i-1;j>0;j--)
               for (int k=j-1;k>=0;k--)
        {
            int tmp=calc_area(points[i],points[j],points[k]);
            if (tmp > ansArea)
            {
                bool OK=true;
                for (int tt=0;tt<numOfMonuments;tt++)
                    if (tt!=i && tt!= j && tt!= k)
                {
                    OK=solve(tt,i,j,k,tmp);
                    if (!OK) break;
                }
                if (OK)
                {
                    ansArea=tmp;
                    ansMonu[0]=i;
                    ansMonu[1]=j;
                    ansMonu[2]=k;
                }
            }
        }
        for (int i=2;i>=0;i--)
            cout<<points[ansMonu[i]].name;
        cout<<endl;
        fin>>numOfMonuments;
    }
    return 0;
}
