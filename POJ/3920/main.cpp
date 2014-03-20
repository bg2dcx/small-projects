#include <iostream>
#include <memory.h>
#define INF 100000000
using namespace std;

int dp[220][220], num[220];
int n,s,t;

int main()
{
    cin>>n;
  while (n!=0)
  {
    cin>>s>>t;
    memset(num,0,sizeof(num));
    for (int i=1;i<=n;i++)
    {
        cin>>num[i];
    }
    for (int i=0;i<=n+s;i++)
       for (int j=0;j<=n+s;j++)
        dp[i][j]=-INF;
    dp[0][0]=0;
    for (int i=1;i<=t;i++)
    {
        for (int k=i;k<=n+s;k++)
        {
            for (int j=1;j<=s;j++)
            {
                int tmp=k-j;
                if (tmp>=0 && dp[i-1][tmp] != -INF)
                {
                    if (dp[i-1][tmp]+num[k]>dp[i][k])
                        dp[i][k]=dp[i-1][tmp]+num[k];
                }
            }
        }
    }
    int ans=-INF;
    for (int i=n+1;i<=n+s;i++)
    {
        if (dp[t][i]>ans)
            ans=dp[t][i];
    }
    cout<<ans<<endl;
    cin>>n;
  }
    return 0;
}
