#include <iostream>
#include <stdio.h>
#include <fstream>
#define INF 0xfffffff;
#define balance 0.000001

using namespace std;
ifstream fin("1.txt");



struct POINT
{
    double x,y;
};



POINT points[22][2];
int numOfPoints;
double ans;
bool findAns;

POINT calc_interception(POINT a, POINT a0, POINT b, POINT b0)
{
    POINT ans;
    if (b.x == b0.x)
    {
        double k=(a0.y-a.y)/(a0.x-a.x);
        ans.x=b.x;
        ans.y=a0.y+(ans.x-a0.x)*k;
        return ans;
    }
    double k1=(a0.y-a.y)/(a0.x-a.x);
    double k2=(b0.y-b.y)/(b0.x-b.x);
    if (k1 == k2)
    {
        ans.y=0-INF;
        ans.x=0-INF;
        return ans;
    }
    double x=(a.y-b.y+k2*b.x-k1*a.x)/(k2-k1);
    double y=a.y-k1*(a.x-x);
    ans.x=x;
    ans.y=y;
    return ans;
}


bool checkblock(POINT a, POINT b, int number)
{
    POINT interception=calc_interception(a,b,points[number][0],points[number][1]);
    if ((interception.y>points[number][1].y && interception.y<points[number][0].y)
        || (interception.y-points[number][1].y>-balance && interception.y-points[number][1].y<balance)
        || (interception.y-points[number][0].y>-balance && interception.y-points[number][0].y<balance))
        return false;
    return true;
}

double find_intercept(POINT a, POINT b, int num1, int num2)
{
    if (num1<0)
        return 0-INF;
    POINT tmp=calc_interception(a,b,points[num1][0],points[num2][0]);
    double ans=tmp.x;
    if (ans<=points[num1][0].x || ans>points[num2][0].x ||(ans-points[num1][0].x>-balance && ans-points[num1][0].x<balance))
    {
        POINT tmp2=calc_interception(a,b,points[num1][1],points[num2][1]);
        if (tmp2.x>tmp.x)
            ans=tmp2.x;
    }
    return ans;
}

bool solve(POINT a, POINT b)
{
    bool blocked=false;
    double answer=0;
    for (int i=0;i<numOfPoints;i++)
    {
        blocked=checkblock(a,b,i);
        if (blocked)
        {
            answer=find_intercept(a,b,i-1,i);
            break;
        }
    }
    if (!blocked) return true;
    if (answer>ans)
        ans=answer;
    return false;
}

int main()
{
    fin>>numOfPoints;
    while (numOfPoints != 0)
    {
        for (int i=0;i<numOfPoints;i++)
        {
            fin>>points[i][0].x>>points[i][0].y;
            points[i][1].x=points[i][0].x;
            points[i][1].y=points[i][0].y-1;
        }
        ans=INF;
        ans=-ans;
        findAns=false;
        for (int i=1;i<numOfPoints;i++)
            {
                for (int inum=0;inum<2;inum++)
                {
                    for (int j=0;j<i;j++)
                    {
                        for (int jnum=0;jnum<2;jnum++)
                        {
                            findAns=solve(points[i][inum],points[j][jnum]);
                            if (findAns)
                                break;
                        }
                        if (findAns) break;
                    }
                    if (findAns) break;
                }
                if (findAns) break;
            }
        if (findAns) printf("Through all the pipe.\n");
            else printf("%0.2lf\n",ans);
        fin>>numOfPoints;
    }
    return 0;
}
