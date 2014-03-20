#include <iostream>
#include <memory.h>
using namespace std;

int mark[6050];

int interval[8];

int number;

int ball;

int main()
{
    cin>>number;
    while (number != 0)
    {
       bool crash=false;
       for (int i=1;i<=number;i++)
            cin>>interval[i];
        memset(mark,0,sizeof(mark));
        ball=0;
        for (int i=1;i<21;i++)
        {
            int nextTime=i%number;
            if (nextTime==0)
                nextTime=number;
            nextTime=interval[nextTime]+i;
            if (mark[i] ==0)
            {
                ball++;
                mark[i]=ball;
            }
            if (nextTime<21)
            {
                if (mark[nextTime]==0)
                    mark[nextTime]=mark[i];
                else
                {
                    crash=true;
                    break;
                }
            }
        }
        if (crash)
            cout<<"CRASH\n";
        else
        {
            int current=1;
            int sum=0;
            while (sum<20)
            {
                if (mark[current] != 0)
                {
                    sum++;
                    cout<<(char)(mark[current]-1+'A');
                }
                current++;
            }
            cout<<endl;
        }
        cin>>number;
    }
    return 0;
}
