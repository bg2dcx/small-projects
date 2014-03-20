#include <iostream>
#include <algorithm>

using namespace std;


int cmp(int a, int b)
{
    if (a<b)
        return 1;
    else return 0;
}
struct NODE
{
    int previous,next;
};

NODE stones[50002];
NODE testStones[50002];

int dist[50002];

int n,m,l;

bool test(int minlength)
{
    int sum=0;
    for (int i=0;i<=n+1;i++)
        testStones[i]=stones[i];
    for (int i=1;i<n+1;i++)
    {
        int prev=testStones[i].previous;
        if (dist[i]-dist[prev] < minlength)
        {
            testStones[i+1].previous=prev;
            testStones[prev].next=i+1;
            sum++;
        }
        if (sum>m)
            return false;

    }
    int current=testStones[n+1].previous;
    while (current != 0)
    {
        int next=testStones[current].next;
        int prev=testStones[current].previous;
        if (dist[next]-dist[current]<minlength)
        {
            sum++;
            testStones[prev].next=next;
            testStones[next].previous=prev;
        }
        if (sum>m)
            return false;
        current=prev;
    }
    if (sum==m)
        if (dist[testStones[0].next]<minlength)
         return false;
    return true;
}

int main()
{
    cin>>l>>n>>m;
    for (int i=1;i<=n;i++)
        cin>>dist[i];
    sort(dist+1,dist+n+1,cmp);
    stones[0].previous=-1;
    stones[0].next=1;
    dist[0]=0;
    dist[n+1]=l;
    for (int i=1;i<=n+1;i++)
    {
        stones[i].previous=i-1;
        stones[i].next=i+1;
    }
    int lowerbound=1;
    int upperbound=l;
    int mid;
    int ans=-1;
    while (lowerbound<=upperbound)
    {
        mid=(lowerbound+upperbound)/2;
        if (test(mid))
        {
            if (mid>ans)
                ans=mid;
            lowerbound=mid+1;
        } else
        {
            upperbound=mid-1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
