#include <iostream>
#include <memory.h>
using namespace std;
char str1[5002],str2[5002];
int dp[2][5002];
int n,m;
int main()
{
    cin>>n;
    m=n;
    for (int i=1;i<=n;i++)
    {
        cin>>str1[i];
        str2[n+1-i]=str1[i];
    }
    int current=0;
    memset(dp,0,sizeof(dp));
    for (int i=1;i<=n;i++)
    {
        int previous=current;
        current=(1+current)%2;
        dp[current][0]=0;
        for (int j=1;j<=n;j++)
        {
            if (str1[i] == str2[j])
                dp[current][j]=dp[previous][j-1]+1;
            else
            {
                dp[current][j]=dp[previous][j];
                if (dp[current][j-1]>dp[current][j])
                    dp[current][j]=dp[current][j-1];
            }
        }
    }
    cout<<n-dp[current][n]<<endl;
    return 0;
}
