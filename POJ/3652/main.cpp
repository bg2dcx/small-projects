#include <iostream>
#include <memory.h>
using namespace std;


bool alwaysOne[16];
bool alwaysZero[16];
bool used[70000];

int a,b,c,s,x;

void init(int number)
{
    for (int i=0;i<16;i++)
    {
        alwaysOne[i]=true;
        alwaysZero[i]=true;
    }
    int current=0;
    while (number>0)
    {
        if  (  (1&number) == 1   )
        {
            alwaysZero[current]=false;
        } else
            alwaysOne[current]=false;
        number/=2;
        current++;
    }
    for (int i=current;i<16;i++)
        alwaysOne[i]=false;
}

void solve(int number)
{
    int current=0;
    used[number]=true;
    while (number > 0)
    {
        if  (  (1&number) == 1   )
        {
            alwaysZero[current]=false;
        } else
            alwaysOne[current]=false;
        number/=2;
        current++;
    }
    for (int i=current;i<16;i++)
        alwaysOne[i]=false;
}

int main()
{
    cin>>a;
    while (a != 0)
    {
        cin>>b>>c>>s;
        init(s);
        memset(used,0,sizeof(used));
        used[s]=true;
        x=((a*s)%c+b%c)%c;
        while (!used[x])
        {
            solve(x);
            x=((a*x)%c+b%c)%c;
        }
        for (int i=15;i>=0;i--)
        {
            if (alwaysOne[i])
                cout<<1;
            else if (alwaysZero[i])
                cout<<0;
            else cout<<'?';
        }
        cout<<endl;
        cin>>a;
    }
    return 0;
}
