#include <iostream>
#define MAXN 102
using namespace std;
// N=0 E=1 S=2 W=3 L=-1 R=+1

int room[MAXN][MAXN];
int robot[MAXN][3];
int a,b,n,m,numOfCases;
void init()
{
    for (int i=0;i<MAXN;i++)
        for (int j=0;j<MAXN;j++)
            room[i][j]=0;
}
int main()
{
    cin>>numOfCases;
    for (int c=0;c<numOfCases;c++)
    {
        cin>>a>>b;
        cin>>n>>m;
        init();
        for (int i=1;i<=n;i++)
        {
            cin>>robot[i][1]>>robot[i][2];
            room[robot[i][1]][robot[i][2]]=i;
            char tmp;
            cin>>tmp;
            switch (tmp)
            {
                case 'N':   robot[i][0]=0;
                            break;
                case 'E':   robot[i][0]=1;
                            break;
                case 'S':   robot[i][0]=2;
                            break;
                case 'W':   robot[i][0]=3;
            }
        }
        bool findAns=false;
        for (int i=0;i<m;i++)
        {
            char tmp;
            int robotnum,repeatnum;
            cin>>robotnum>>tmp>>repeatnum;
            if (!findAns)
            {
                if (tmp == 'L')
                {
                    repeatnum=repeatnum%4;
                    robot[robotnum][0]=(robot[robotnum][0]+4-repeatnum)%4;
                }
                if (tmp == 'R')
                {
                    repeatnum=repeatnum%4;
                    robot[robotnum][0]=(robot[robotnum][0]+repeatnum)%4;
                }
                if (tmp == 'F')
                {
                    int nextx=robot[robotnum][1];
                    int nexty=robot[robotnum][2];
                    switch (robot[robotnum][0])
                    {
                        case 0: nexty+=repeatnum;
                                break;
                        case 1: nextx+=repeatnum;
                                break;
                        case 2: nexty-=repeatnum;
                                break;
                        case 3: nextx-=repeatnum;
                                break;
                    }
                    int incx=0;
                    if (nextx>robot[robotnum][1]) incx=1;
                    if (nextx<robot[robotnum][1]) incx=-1;
                    int incy=0;
                    if (nexty<robot[robotnum][2]) incy=-1;
                    if (nexty>robot[robotnum][2]) incy=1;
                    int rest=repeatnum;
                    int currentx=robot[robotnum][1];
                    int currenty=robot[robotnum][2];
                    while (rest>0 && currentx+incx>0 && currentx+incx<=a && currenty+incy>0 && currenty+incy<=b)
                    {
                        currentx=currentx+incx;
                        currenty+=incy;
                        if (room[currentx][currenty] != 0)
                        {
                            cout<<"Robot "<<robotnum<<" crashes into robot "<<room[currentx][currenty]<<endl;
                            findAns=true;
                            break;
                        }
                        rest--;
                    }
                    if ((nextx<=0 || nextx>a || nexty<=0 || nexty>b) && (!findAns))
                    {
                        cout<<"Robot "<<robotnum<<" crashes into the wall"<<endl;
                        findAns=true;
                    }
                    if (!findAns)
                    {
                           room[nextx][nexty]=robotnum;
                           room[robot[robotnum][1]][robot[robotnum][2]]=0;
                           robot[robotnum][1]=nextx;
                           robot[robotnum][2]=nexty;
                    }
                }
            }
        }
        if (!findAns) cout<<"OK"<<endl;
    }
    return 0;
}
