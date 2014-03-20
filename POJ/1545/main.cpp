#include <iostream>
#include <stdio.h>
#include <string.h>
#define MAXN 100

using namespace std;
int dist[27];
int bfsqueue[100];
bool connected[27][27];
int n;
float value[27];
void initialize()
{
    for (int i=0;i<27;i++)
    {
        dist[i]=MAXN;
        bfsqueue[i]=-1;
        value[i]=-1;
        for (int j=0;j<27;j++)
            connected[i][j]=false;
    }
}

double calcValue(int number)
{
    float ans=value[number];
    for (int i=0;i<dist[number];i++)
        ans*=0.95;
    return ans;
}

int main()
{
    while ( scanf("%d",&n) != EOF )
    {
        initialize();
        for (int i=0;i<n;i++)
        {
            char tmpname;
            char linkedplanets[30];
            float tmpvalue;
            //scanf("%c",&tmpname);
            scanf("\n%c%f%s",&tmpname,&tmpvalue,linkedplanets);
            value[tmpname+1-'A']=tmpvalue;
            int len=strlen(linkedplanets);
            for (int j=0;j<len;j++)
                if (linkedplanets[j] == '*')
            {
                connected[0][tmpname+1-'A']=true;
                connected[tmpname+1-'A'][0]=true;
            }  else
            {
                    connected[tmpname+1-'A'][linkedplanets[j]+1-'A']=true;
                    connected[linkedplanets[j]+1-'A'][tmpname+1-'A']=true;
            }
        }
        int head=0;
        int tail=1;
        bfsqueue[head]=0;
        dist[0]=0;
        while (head<tail)
        {
            int current=bfsqueue[head];
            for (int k=0;k<27;k++)
                if (connected[current][k] && dist[current]+1<dist[k])
                {
                    bfsqueue[tail]=k;
                    dist[k]=dist[current]+1;
                    tail++;
                }
            head++;
        }
        float maxvalue=0;
        int maxplanet=0;
        for (int k=1;k<27;k++)
            if (dist[k]!=MAXN)
            {
                float tmp=calcValue(k);
                if (tmp>maxvalue)
                {
                    maxvalue=tmp;
                    maxplanet=k;
                }
            }
        char tmpname;
        tmpname='A'+maxplanet-1;
        cout<<"Import from "<<tmpname<<endl;
    }


    return 0;
}
