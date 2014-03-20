#include <iostream>
#include <stdio.h>
#include <algorithm>
#define MAXN 25001

using namespace std;

struct POINT
{
    int l,r;
    bool covered;
};
struct DATA
{
    int pos,num;
};
DATA posters[MAXN];
POINT nodes[3*MAXN];
bool flag;
int cases, numOfPosts;


bool cmp1(DATA a, DATA b)
{
    if (a.pos<b.pos)
        return true;
    else return false;
}

bool cmp2(DATA a, DATA b)
{
    if (a.num>b.num) return true;
    if (a.num == b.num && a.pos<b.pos)
        return true;
    return false;
}

void build_tree(int left, int right, int num)
{
    nodes[num].l=left;
    nodes[num].r=right;
    nodes[num].covered=false;
    if (left==right) return;
    int mid=(left+right)>>1;
    build_tree(left,mid,num<<1);
    build_tree(mid+1,right,(num<<1)+1);
}

void query(int left, int right, int num)
{
    if (nodes[num].covered) return;
    if (nodes[num].l == left && nodes[num].r == right)
    {
        flag=true;
        nodes[num].covered=true;
        return;
    }
    if (right<=nodes[num<<1].r)
        query(left,right,num<<1);
    else
    if (left>=nodes[(num<<1)+1].l)
        query(left,right,(num<<1)+1);
    else
    {
        query(left,nodes[num<<1].r,num<<1);
        query(nodes[(num<<1)+1].l,right,(num<<1)+1);
    }
    nodes[num].covered=nodes[num<<1].covered & nodes[(num<<1)+1].covered;
}

int main()
{
    scanf("%d",&cases);
    for (int c=0;c<cases;c++)
    {
        scanf("%d",&numOfPosts);
        for (int i=0;i<numOfPosts;i++)
        {
            scanf("%d",&(posters[2*i].pos));
            scanf("%d",&(posters[2*i+1].pos));
            posters[2*i].num=i;
            posters[2*i+1].num=i;
        }
        sort(posters,posters+numOfPosts*2,cmp1);
        int k=0, pre=0;
        for (int i=0;i<numOfPosts*2;i++)
            if (posters[i].pos != pre)
        {
            k++;
            pre=posters[i].pos;
            posters[i].pos=k;
        } else
        {
            posters[i].pos=k;
        }
        build_tree(1,k,1);
        int sum=0;
        sort(posters,posters+2*numOfPosts,cmp2);
        for (int i=0;i<numOfPosts*2;i=i+2)
        {
            int left=posters[i].pos;
            int right=posters[i+1].pos;
            flag=false;
            query(left,right,1);
            if (flag)
                sum++;
        }
        cout<<sum<<endl;
    }
    return 0;
}
