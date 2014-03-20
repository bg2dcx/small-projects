#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
long long a,b,d,c,r,x,y;
bool changed;

long long gcd (long long a, long long b)
{
    long long r;
    while (b!=0)
    {
        r=b;
        b=a%b;
        a=r;
    }
    return a;
}

void exGcd( long long a, long long b, long long *x, long long *y)
{
    if (b == 0)
    {
        *x=1;
        *y=0;
        return;
    }
    long long xx,yy;
    exGcd(b,a%b,&xx,&yy);
    *x=yy;
    *y=xx-a/b*yy;
}

int main()
{
    cin>>a>>b>>d;
    while (! (a== 0 && b==0 && d==0))
    {
        if (a == 0)
        {
            cout<<0<<' '<<d/b<<endl;
            cin>>a>>b>>d;
            continue;
        } else
        if (b == 0)
        {
            cout<<d/a<<' '<<0<<endl;
            cin>>a>>b>>d;
            continue;
        }
        r=gcd(a,b);
        d=d/r;
        a/=r;
        b/=r;
        exGcd(a,b,&x,&y);
        long long x1,y1,x2,y2;
        y1 = (y * d % a + a) % a;
        x1 = (d - b * y1) / a;
        if(x1 < 0) x1 = -x1;
        x2 = (x * d % b + b) % b;
        y2 = (d - a * x2) / b;
        if(y2 < 0) y2 = -y2;
        if(x1+y1 < x2+y2) printf("%I64d %I64d\n", x1, y1);
        else printf("%I64d %I64d\n", x2, y2);

        cin>>a>>b>>d;
    }
    return 0;
}
