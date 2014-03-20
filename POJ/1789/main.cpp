#include <iostream>

using namespace std;

char carType[2001][8];
bool selected[2000];
int tree[2001][3];
int numOfNodes;
int ans;

int dist(int num1,int num2)
{
    int sum=0;
    for (int i=0;i<7;i++)
    {
        if (carType[num1][i] != carType[num2][i])
            sum++;
    }
    return sum;
}
int main()
{
    cin>>numOfNodes;
    while (numOfNodes!=0)
    {
        ans=0;
        for (int i=0;i<numOfNodes;i++)
        {
            for (int k=0;k<7;k++)
                cin>>carType[i][k];
            selected[i]=false;
            tree[i][0]=0;
            tree[i][1]=i;
            tree[i][2]=dist(0,i);
        }
        selected[0]=true;
        for (int i=1;i<numOfNodes;i++)
        {
            int minDist=5000;
            int minNum=-1;
            for (int k=i;k<numOfNodes;k++)
                if (tree[k][2]<minDist)
            {
                minDist=tree[k][2];
                minNum=k;
            }
            ans+=minDist;
            int tmp[3];
            for (int k=0;k<3;k++)
                tmp[k]=tree[minNum][k];
            for (int k=0;k<3;k++)
                tree[minNum][k]=tree[i][k];
            for (int k=0;k<3;k++)
                tree[i][k]=tmp[k];
            selected[tree[i][1]]=true;
            int addedNode=tree[i][1];
            for (int k=i+1;k<numOfNodes;k++)
            {
                int dis=dist(addedNode,tree[k][1]);
                if (dis<tree[k][2])
                {
                    tree[k][2]=dis;
                    tree[k][0]=addedNode;
                }
            }
        }
        cout<<"The highest possible quality is 1/"<<ans<<'.'<<endl;
        cin>>numOfNodes;
    }

}
