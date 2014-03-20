#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

ifstream fin("1.txt");

struct POINT{
    char name;
    int x,y;
};

POINT points[26];

int cmp(POINT a, POINT b)
{
    if (a.name<b.name)
        return 1;
    else return 0;
}

int n,caseNum,numAns;
int main()
{
    caseNum=0;
    fin>>n;
    while (n != 0)
    {
        caseNum++;
        cout<<"Point set "<<caseNum<<":";
        numAns=0;
        for (int i=0;i<n;i++)
            fin>>points[i].name>>points[i].x>>points[i].y;
        sort(points,points+n,cmp);
        for (int a=0;a<n;a++)
        {
            for (int b=0;b<n;b++)
                if (points[a].y == points[b].y && points[b].x>points[a].x)
            {
                for (int c=0;c<n;c++)
                    if (points[b].x == points[c].x && points[c].y<points[b].y)
                {
                    for (int d=0;d<n;d++)
                        if (points[d].y == points[c].y)
                    {
                        if (points[d].x == points[a].x)
                        {
                            if (numAns%10 == 0)
                            {
                                cout<<endl;
                            }
                            numAns++;
                            cout<<' '<<points[a].name<<points[b].name<<points[c].name<<points[d].name;
                        }
                    }
                }
            }
        }
        if (numAns==0)
            cout<<" No rectangles";
        cout<<endl;
        fin>>n;
    }

    return 0;
}
