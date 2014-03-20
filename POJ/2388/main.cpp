
#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int cows[1000001];
int n;

int cmp (int a, int b)
{
    if (a<b)
        return 1;
    else return 0;
}


void qsort(int numbers[],int st, int ed)
{
    int i,j,x;
    i=st;j=ed;x=numbers[i];
    do
    {
        while (j>i && numbers[j]>=x) j--;
        if (j>i)
        {
            numbers[i]=numbers[j];
            i++;
        }
        while (j>i && numbers[i]<=x) i++;
        if (i<j)
        {
            numbers[j]=numbers[i];
            j--;
        }
    } while (i != j);
    numbers[i]=x;
    i++;
    j--;
    if (st<j) qsort(numbers,st,j);
    if (i<ed) qsort(numbers,i,ed);
}

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",&cows[i]);
    qsort(cows,0,n-1);
    cout<<cows[n/2];
    return 0;
}
