#include <iostream>
#include <memory.h>
using namespace std;

int value[5][5]={{5,-1,-2,-1,-3},
                 {-1,5,-3,-2,-4},
                 {-2,-3,5,-2,-2},
                 {-1,-2,-2,5,-1},
                 {-3,-4,-2,-1,0}};
int str1[200],str2[200];
int dp[101][101];
int numOfCases,len1,len2;

int encode(char cc)
{
    int tmp=4;
    switch (cc)
    {
        case 'A':tmp=0;break;
        case 'C':tmp=1;break;
        case 'G':tmp=2;break;
        case 'T':tmp=3;break;
    }
    return tmp;
}

int main()
{
    cin>>numOfCases;
    for (int c=0;c<numOfCases;c++)
    {
        cin>>len1;
        char tmp;
        for (int i=1;i<=len1;i++)
        {
            cin>>tmp;
            str1[i]=encode(tmp);
        }
        cin>>len2;
        for (int i=1;i<=len2;i++)
        {
            cin>>tmp;
            str2[i]=encode(tmp);
        }
        memset(dp,0,sizeof(dp));
        for (int i=1;i<=len1;i++)
            dp[i][0]=dp[i-1][0]+value[str1[i]][4];
        for (int i=1;i<=len2;i++)
            dp[0][i]=dp[0][i-1]+value[4][str2[i]];
        for (int i=1;i<=len1;i++)
            for (int j=1;j<=len2;j++)
        {
            dp[i][j]=dp[i-1][j-1]+value[str1[i]][str2[j]];
            if (dp[i-1][j]+value[str1[i]][4] > dp[i][j])
                dp[i][j]=dp[i-1][j]+value[str1[i]][4];
            if (dp[i][j-1]+value[4][str2[j]] > dp[i][j])
                dp[i][j]=dp[i][j-1]+value[4][str2[j]];
        }
        cout<<dp[len1][len2]<<endl;
    }
    return 0;
}
