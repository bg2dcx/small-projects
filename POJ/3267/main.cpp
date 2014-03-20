#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int dp[301];
char words[601][26];
int len[601];
char message[302];
int w,l;

bool similar(int wordNum, int ed)
{
    int st=ed-strlen(words[wordNum])+1;
    int len=strlen(words[wordNum]);
    if (st<1) return false;
    for (int i=0;i<len;i++)
        if (message[st+i] != words[wordNum][i])
        return false;
    return true;
}
int main (){
    FILE *fp;
    fp=fopen("1.txt","r");
    fscanf(fp,"%d%d",&w,&l);
    fscanf(fp,"%s",message);
    for (int i=0;i<w;i++)
        {
            fscanf(fp,"%s",words[i]);
            len[i]=strlen(words[i]);
        }
    for (int i=l;i>0;i--)
        message[i]=message[i-1];
    memset(dp,0,sizeof(dp));
    for (int i=1;i<=l;i++)
    {
        dp[i]=dp[i-1]+1;
        int numRemove=10000;
        for (int k=0;k<w;k++)
        {
            int wordpos=len[k]-1;
            int messagepos=i;
            while (wordpos>=0 && messagepos>0 && i-messagepos+1-len[k]<dp[i])
            {
                if (message[messagepos] == words[k][wordpos])
                    wordpos--;
                messagepos--;
            }
            if (wordpos<0)
                numRemove=i-messagepos-len[k];
            else
                numRemove=i-messagepos;
            if (dp[i]>dp[messagepos]+numRemove)
                dp[i]=dp[messagepos]+numRemove;

        }
    }
    cout<<dp[l]<<endl;
    return 0;
}
