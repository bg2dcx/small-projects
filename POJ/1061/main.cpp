#include <iostream>

using namespace std;

long long x,y,m,n,L,r;

int gcd(long long a, long long b)
{
    long long r;
    while (b != 0)
    {
        r=b;
        b=a%b;
        a=r;
    }
    return a;
}

void exGcd( long long a, long long b, long long *x, long long *y )
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
    *y=xx - (a/b)*yy;
}

int main()
{
    cin>>x>>y>>m>>n>>L;
    long long a=n-m;
    long long b=L;
    r=gcd(a,b);
    long long c=x-y;
    if (c % r != 0)
    {
        cout<<"Impossible\n";
        return 0;
    }
    a/=r;
    b/=r;
    c/=r;
    long long k1,k2;
    exGcd(a,b,&k1,&k2);
    long long t = c*k1/b;
    long long ans=c*k1-t*b;
    if (ans<0)
        ans+=b;
    cout<<ans<<endl;
    return 0;
}
