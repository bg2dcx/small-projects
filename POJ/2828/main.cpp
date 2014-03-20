#include <iostream>
#include <stdio.h>
#define MAXN 200001
using namespace std;

int tree[MAXN<<2];
int pos[MAXN],value[MAXN];
int ans[MAXN];
int n;
int ansId;

void build_tree(int l, int r,int num)
{
    tree[num]=r-l+1;
    if (l == r) return;
    int m=(l+r)>>1;
    build_tree(l,m,num<<1);
    build_tree(m+1,r,(num<<1)+1);
}

void query(int position, int l, int r, int num)
{
    tree[num]--;
    if (l == r)
    {
        ansId=l;
        return;
    }
    int m=(l+r)>>1;
    if (tree[num<<1] >= position)
        query(position,l,m,num<<1);
    else
    {
        position-=tree[num<<1];
        query(position,m+1,r,(num<<1)+1);
    }
}

int main()
{

 while (scanf("%d",&n) != EOF)
  {
    for (int i=0;i<n;i++)
        scanf("%d%d",&pos[i],&value[i]);
    build_tree(1,n,1);
    for (int i=n-1;i>=0;i--)
    {
        query(pos[i]+1,1,n,1);
        ans[ansId]=i;
    }
    for (int i=1;i<=n;i++)
        printf("%d ",value[ans[i]]);
    printf("\n");
  }
  return 0;
}
