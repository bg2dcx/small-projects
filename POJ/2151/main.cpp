#include <iostream>
#include <stdio.h>
#include <string.h>
#define MAXTEAMS 1000
#define MAXPROB 31
using namespace std;
double p[MAXTEAMS][MAXPROB];
double dp[MAXTEAMS][MAXPROB][MAXPROB];
double s[MAXTEAMS][MAXPROB];
int M,T,N;

int main()
{
    scanf("%d%d%d",&M,&T,&N);
    while ( !(M==0 && T==0 && N==0))
    {
        memset(p,0,sizeof(p));
        memset(dp,0,sizeof(dp));
        memset(s,0,sizeof(s));
        for (int i=0;i<T;i++)
        {
            for (int j=1;j<=M;j++)
                scanf("%lf",&p[i][j]);
            dp[i][0][0]=1;
            for (int j=1;j<=M;j++)
                dp[i][j][0]=dp[i][j-1][0]*(1.0-p[i][j]);
            for (int j=1;j<=M;j++)
                for (int k=1;k<=j;k++)
                dp[i][j][k]=dp[i][j-1][k]*(1.0-p[i][j])+dp[i][j-1][k-1]*p[i][j];
            s[i][0]=dp[i][M][0];
            for (int j=1;j<=M;j++)
                s[i][j]=s[i][j-1]+dp[i][M][j];
        }
        double p1=1.0;
        double p2=1.0;
        for (int i=0;i<T;i++)
        {
            p1*=(1.0-s[i][0]);
            p2*=s[i][N-1]-s[i][0];
        }
        printf("%0.3f\n",p1-p2);
        scanf("%d%d%d",&M,&T,&N);
    }
    return 0;
}
