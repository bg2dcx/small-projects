#include <iostream>
#include <stdio.h>
#include <algorithm>
#define MAXN 20001
using namespace std;

struct NODE
{
    long long value,maxi;
};

struct STAR
{
    long long x,y1,y2,brightness;
};

NODE tree[MAXN<<2];
int n,w,h;
STAR points[MAXN<<1];
long long dy[MAXN<<1];
long long ans;

int cmp1(long long a, long long b)
{
    if (a<b)
        return 1;
    else return 0;
}

int cmp2(STAR a, STAR b)
{
    if (a.x<b.x)
        return 1;
    if (a.x==b.x && a.brightness<b.brightness)
        return 1;
    return 0;
}

void build_tree(int left, int right, int num)
{
    tree[num].maxi=0;
    tree[num].value=0;
    if (left == right)
        return;
    int m=(left+right)>>1;
    build_tree(left,m,num<<1);
    build_tree(m+1,right,num<<1|1);
}

void tree_update(int y1,int y2,int left,int right,int num,int bb)
{
    if (y1<=left && y2>=right)
    {
        tree[num].maxi+=bb;
        tree[num].value+=bb;
        if (tree[num].maxi>ans)
            ans=tree[num].maxi;
        return;
    }
    if (left == right)
        return;
    tree[num<<1].maxi+=tree[num].value;
    tree[num<<1].value+=tree[num].value;
    tree[num<<1|1].maxi+=tree[num].value;
    tree[num<<1|1].value+=tree[num].value;
    tree[num].value=0;
    int m=(left+right)>>1;
    if (y1<=m) tree_update(y1,y2,left,m,num<<1,bb);
    if (y2>m) tree_update(y1,y2,m+1,right,num<<1|1,bb);
    tree[num].maxi=tree[num<<1].maxi;
    if (tree[num<<1|1].maxi > tree[num].maxi)
        tree[num].maxi=tree[num<<1|1].maxi;
}

int findY(long long val, int k)
{
    int l=0;int r=k;
    while (l<=r)
    {
        int m=(l+r)/2;
        if (dy[m]<val)
            l=m+1;
        if (dy[m]>val)
            r=m-1;
        if (dy[m]==val)
            break;
    }
    return (l+r)/2;
}

int main()
{
    while (scanf("%d%d%d",&n,&w,&h) != EOF)
    {
        for (int i=0;i<n;i++)
        {
            int xx,yy,bb;
            scanf("%d%d%d",&xx,&yy,&bb);
            points[i<<1].x=xx;
            points[i<<1].y1=yy;
            points[i<<1].y2=(long long)yy+h-1;
            points[i<<1].brightness=bb;
            points[i<<1|1].x=(long long)xx+w;
            points[i<<1|1].y1=yy;
            points[i<<1|1].y2=(long long)yy+h-1;
            points[i<<1|1].brightness=-bb;
            dy[i<<1]=yy;
            dy[i<<1|1]=yy+h-1;
        }
        sort(dy,dy+2*n,cmp1);
        sort(points,points+2*n,cmp2);
        int k=0;
        for (int i=1;i<2*n;i++)
            if (dy[i] != dy[i-1])
        {
            k++;
            dy[k]=dy[i];
        }
        build_tree(0,k,1);
        ans=0;
        for (int i=0;i<2*n;i++)
        {
            int y1=findY(points[i].y1,k);
            int y2=findY(points[i].y2,k);
            tree_update(y1,y2,0,k,1,points[i].brightness);
        }
        cout<<ans<<endl;
    }
    return 0;
}
