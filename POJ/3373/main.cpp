#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;
char str[101];
int num1[101],num2[101];
int flag[101][10005];
int k;
int len;
int getY(int num[])
{
    int j;
    int m=0;
    for(j=len-1;j>=0;j--)
    {
        m=(m*10+num[j])%k;
    }
    return m;
}

void init()
{
    int i;
    for(i=0;i<len;i++)
    {
        num1[i] = num2[i] = str[len-1-i]-'0';
    }
    memset(flag,0,sizeof(flag));
}
bool dfs(int pos,int num,int m)
{
    int i,j;
    if(m==0)
    {
        for(i=len-1;i>=0;i--)printf("%d",num1[i]);
        printf("\n");
        return true;
    }

    if(pos<0 || num<=flag[pos][m] || num==0)
    {
        return false;
    }
    for(i=pos;i>=0;i--)
    {
        for(j=0;j<num2[i];j++)
        {
            if(i==len-1 && j==0)
            {
                continue;//±ÜÃâÇ°µ¼0;
            }
            num1[i]=j;
            int a=getY(num1);
            if(dfs(i-1,num-1,a))
            {
                return true;
            }
        }
        num1[i]=num2[i];
    }
    for(i=0;i<=pos;i++)
    {
        for(j=num2[i]+1;j<=9;j++)
        {
            if(j==0 && i==len-1)
            {
                continue;
            }
            num1[i]=j;
            int a=getY(num1);
            if(dfs(i-1,num-1,a))
            {
                return true;
            }
        }
        num1[i]=num2[i];
    }
    flag[pos][m]=num;
    return false;
}
void solve()
{
    int i;
    int m=getY(num1);
    for(i=1;i<=5;i++)
    {
        if(dfs(len-1,i,m))return;
    }
}
int main()
{
    while(~scanf("%s%d",str,&k))
    {
        len = strlen(str);
        init();
        solve();

    }
}
