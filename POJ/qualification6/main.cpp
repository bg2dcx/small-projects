#include <iostream>
#include <memory.h>
using namespace std;

int formula[7][7]={ {0,0,0,0,0,0,1},
                    {0,0,0,0,0,1,1},
                    {0,0,0,0,1,2,1},
                    {0,0,0,1,3,3,1},
                    {0,0,1,4,6,4,1},
                    {0,1,5,10,10,5,1},
                    {1,6,15,20,15,6,1}};
int n,x;
int num[7],sum[7];
int ans[7];


int main()
{
    memset(sum,0,sizeof(sum));
    memset(ans,0,sizeof(ans));
    cin>>n;
    for (int i=n;i>=0;i--)
      cin>>num[i];
    ans[0]=num[0];
    sum[0]=num[0];
    for (int i=1;i<=n;i++)
    {
        sum[i]=0;
        int current=1;
        for (int j=0;j<=n;j++)
        {
            sum[i]+=current*num[j];
            current*=i;
        }
    }
    for (int i=1;i<=n;i++)
    {
        ans[i]=sum[i];
        for (int j=0;j<i;j++)
            ans[i]-=formula[i][6-j]*ans[j];
    }
    for (int i=0;i<=n;i++)
        cout<<ans[i]<<' ';
    cout<<endl;
    return 0;
}
