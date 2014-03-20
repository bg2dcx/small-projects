#include <iostream>
#include <memory.h>
#define MAXI 100
using namespace std;

bool isDNum[MAXI];
int digitadition(int n)
{
    int rest=n;
    int ans=n;
    while (rest>0)
    {
        ans+=rest%10;
        rest/=10;
    }
    return ans;
}

int main()
{
    for (int i=0;i<MAXI;i++)
        isDNum[i]=true;
    isDNum[1]=true;
    int current=1;
    while (current<MAXI)
    {
        int next=digitadition(current);
        while (next<MAXI && isDNum[next])
        {
            isDNum[next]=false;
            next=digitadition(next);
        }
        current++;
        while (current<MAXI && !isDNum[current]) current++;
    }
    for (int i=1;i<MAXI;i++)
        if (isDNum[i])
        cout<<i<<endl;
    return 0;
}
