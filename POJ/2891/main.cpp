#include <iostream>
typedef long long LL;
using namespace std;
LL a,b,lcm,current,d,k;
int n;
bool fail;

LL exGcd(LL a, LL b, LL *x, LL *y)
{
    if (b == 0)
    {
        *x=1;
        *y=0;
        return a;
    }
    LL xx,yy,c;
    c=exGcd(b,a%b,&xx,&yy);
    *x=yy;
    *y=xx-a/b*yy;
    return c;
}

int main()
{
    while (cin>>n)
    {
        cin>>a>>b;
        lcm=a;current=b;
        fail=false;
        for (int i=1;i<n;i++)
        {
            cin>>a>>b;
            b=(b-current+a)%a;
            LL x,y;
            d=exGcd(lcm,a,&x,&y);
            if (b%d ==0)
            {
                k=x*(b/d)%a;
            } else fail=true;
            current+=k*lcm;
            lcm=lcm/d*a;
            current=(current%lcm+lcm)%lcm;
        }
        if (fail)
            cout<<-1<<endl;
        else cout<<current<<endl;
    }

    return 0;
}
