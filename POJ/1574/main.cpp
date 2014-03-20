#include <iostream>
#include <memory.h>
using namespace std;

int triangles[7][3];
bool used[7];
char cc;
int ans;

void dfs(int sum, int last, int first, int num)
{
    if (num>6)
    {
        if (last == first && sum>ans)
            ans=sum;
        return;
    }
    for (int k=1;k<6;k++)
      if (!used[k])
        for (int i=0;i<3;i++)
        {
            int outer=triangles[k][i];
            int newLast=triangles[k][(i+1)%3];
            int toBeMatched=triangles[k][(i+2)%3];
            used[k]=true;
            if (toBeMatched == last)
                dfs(sum+outer,newLast,first,num+1);
            used[k]=false;
        }
}

int main()
{
    cc='*';
    while (cc == '*')
    {
        for (int i=0;i<6;i++)
            for (int j=0;j<3;j++)
            cin>>triangles[i][j];
        ans=0;
        memset(used,0,sizeof(used));
        used[0]=true;
        for (int j=0;j<3;j++)
        {
            dfs(triangles[0][j],triangles[0][(j+1)%3],triangles[0][(j+2)%3],2);
        }
        if (ans ==0)
            cout<<"none"<<endl;
        else cout<<ans<<endl;
        cin>>cc;
    }
    return 0;
}
