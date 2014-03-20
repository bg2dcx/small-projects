#include <iostream>
#include <stdio.h>
#define MAXN 1020
#define MAXMONEY 400000000
#define precision 0.00001
using namespace std;

struct STONE
{
    int a;
    int b;
    double price;
} stones[MAXN];

double price[MAXN];

int n, aa,bb,hh, st ,ed;

void dfs(int width, double currentM)
{
    if (currentM-price[ed] > -precision)
        return;
    if (currentM < price[width])
        price[width]=currentM;
    for (int i=0;i<n;i++)
        if (stones[i].a == width)
    {
        int tmp=stones[i].b;
        if (currentM+stones[i].price-price[tmp] < precision)
        {
            dfs(tmp,currentM+stones[i].price);
        }
    } else
        if (stones[i].b == width)
    {
        int tmp=stones[i].a;
        if (currentM+stones[i].price-price[tmp] < precision)
        {
            dfs(tmp,currentM+stones[i].price);
        }
    }
}

int main()
{
    cin>>n;
    while (n != 0)
    {
        for (int i=0;i<n;i++)
        {
            cin>>aa>>bb>>hh;
            stones[i].a=aa;
            stones[i].b=bb;
            stones[i].price=(aa+bb)*hh*0.01;
        }
        cin>>st>>ed;
        for (int i=0;i<MAXN;i++)
            price[i]=MAXMONEY;
        dfs(st,0);
        printf("%.2f\n",price[ed]);
        cin>>n;
    }
    return 0;
}
