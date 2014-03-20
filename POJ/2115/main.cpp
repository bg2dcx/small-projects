#include <iostream>
typedef long long LL;
LL a,b,c,k,p,r;
using namespace std;

int exGcd(LL a, LL b, LL *x, LL *y)
{
    if (b == 0)
    {
        *x=1;
        *y=0;
        return a;
    }
    LL xx,yy;
    LL c=exGcd(b,a%b,&xx,&yy);
    *x=yy;
    *y=xx-a/b*yy;
    return c;
}

int main()
{
    cin>>a>>b>>c>>k;
    while (! (a == 0 && b == 0 && c == 0 && k == 0))
    {
        p=1;
        while (k--)
        {
            p*=2;
        }
        r=(b-a+p)%p;
        LL x,y,d;
        d=exGcd(c,p,&x,&y);
        if (r%d ==0)
        {
            LL ans=x*(r/d);
            ans=ans%(p/d);
            if (ans<0) ans+=(p/d);
            cout<<ans<<endl;
        } else
         cout<<"FOREVER"<<endl;
        cin>>a>>b>>c>>k;
    }
    return 0;
}
