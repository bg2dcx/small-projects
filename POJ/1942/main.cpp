#include <iostream>

using namespace std;
long long a,b;

long long calculate(long long a, long long b)
{
    long long sum=a+b;
    long long cnt=a;
    long long ans=1;
    if (b<a) cnt=b;
    long long division=cnt;
    while (cnt--)
    {
        ans*=sum--;
        while ( (division>1) && (ans%division == 0))
            ans/=division--;
    }
    return ans;
}

int main()
{
    cin>>a>>b;
    while ( !(a==0 && b==0))
    {
        cout<<calculate(a,b)<<endl;
        cin>>a>>b;
    }
    return 0;
}
