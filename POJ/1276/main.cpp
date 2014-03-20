#include <iostream>
#include <memory.h>

using namespace std;

bool possible[100001];

int value[11];
int number[11];

int requestCash;
int numOfBills;

int main()
{
    while (cin>>requestCash)
    {
        cin>>numOfBills;
        for (int i=0;i<numOfBills;i++)
        {
            cin>>number[i]>>value[i];
        }
        memset(possible,0,sizeof(possible));
        possible[0]=true;
        for (int i=0;i<numOfBills;i++)
        {
            int tmp=1;
            int rest=number[i];
            int current;
            while (rest>0)
            {
                if (rest-tmp >= 0)
                {
                    rest-=tmp;
                    current=tmp;
                    tmp*=2;
                } else
                {
                    current=rest;
                    rest=0;
                }
                for (int j=requestCash;j>=value[i]*current;j--)
                    possible[j]=possible[j] || possible[j-value[i]*current];
            }
        }
        for (int i=requestCash;i>=0;i--)
            if (possible[i])
        {
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}
