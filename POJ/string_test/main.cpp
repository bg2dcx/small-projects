#include <stdio.h>
#include <string.h>
#include <math.h>
__int64 xiang[100000],xishu[100000];
__int64 mod=9901;
int main()
{
    __int64 deal(__int64 p,__int64 n);
    __int64 i,j,n,m,s,t,top,res,key;
    while(scanf("%I64d %I64d",&n,&m)!=EOF)
    {
        if(n==0)
        {
            printf("0\n");
            continue;
        }
        memset(xiang,0,sizeof(xiang));
        memset(xishu,0,sizeof(xishu));
        for(i=2,top=0;i<=(int)(sqrt((double)(n))+0.01);)
        {
            if(n%i==0)
            {
                while(n%i==0)
                {
                    xiang[top]=i; xishu[top]++;
                    n=n/i;
                }
            }
            top++;
            if(i==2)
            {
                i=3;
            }else
            {
                i+=2;
            }
        }
        if(n!=1)
        {
            xiang[top]=n;
            xishu[top]++;
            top++;
        }
        for(i=0,res=1;i<=top-1;i++)
        {
            t=deal(xiang[i],xishu[i]*m);
            res=(res*t)%mod;
        }
        printf("%I64d\n",res);
    }
    return 0;
}
__int64 f(__int64 p,__int64 n)
{
    __int64 res=1;
    p=p%mod;
    while(n>1)
    {
        if(n&1)
        {
            res=(res*p)%mod;
        }
        p=(p*p)%mod;
        n=n/2;
    }
    return ((res*p)%mod);
}
__int64 deal(__int64 p,__int64 n)
{
    __int64 t;
    if(n==0)
    {
        return 1;
    }
    if(n%2)
    {
        t=deal(p,n/2);
        return (((1+f(p,n/2+1))%mod)*(t%mod))%mod;
    }else
    {
        t=deal(p,n/2-1);
        return ((((1+f(p,n/2+1))%mod)*(t%mod))%mod+f(p,n/2)%mod)%mod;
    }
}

