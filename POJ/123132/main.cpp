#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
using namespace std;

double sum;
int n;
int main()
{
cin>>n;
sum = 0;
for (int i=1;i<=n;i++)
    sum+=2*(i-1)/pow(2,i-1);
cout<<sum;
}
