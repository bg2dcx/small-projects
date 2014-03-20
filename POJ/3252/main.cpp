#include <iostream>

using namespace std;
int comb[35][35];
void init_comb()
{
    for (int i=0;i<32;i++)
    {
        comb[i][0]=1;
        comb[0][i]=0;
    }
    comb[0][0]=1;

    for (int i=1;i<32;i++)
        for (int j=1;j<32;j++)
            comb[i][j]=comb[i-1][j-1]+comb[i-1][j];
}

int st,ed;
int bin[50];
int len;
int make_bin(int n)
{
    int tmp[50];
    int l=0;
    if (n == 0)
    {
        bin[0]=0;
        return 1;
    }
    while (n>0)
    {
        tmp[l]=n%2;
        l++;
        n/=2;
    }
    for (int i=0;i<l;i++)
        bin[i]=tmp[l-i-1];
    return l;
}
int solve(int number)
{
    if (number == 0) return 0;
    len=make_bin(number);
    int sum=0;
    for (int i=2;i<len;i++)
        for (int j=(i+1)/2;j<i;j++)
            sum+=comb[i-1][j];
    int ZeroNeeded=(len+1)/2;
    for (int i=1;i<len;i++)
        if (bin[i] == 1)
            for (int j=ZeroNeeded-1;j<len-i;j++)
                sum+=comb[len-i-1][j];
        else ZeroNeeded--;
    return sum;
}
int main()
{
    cin>>st>>ed;
    init_comb();
    cout<<solve(ed+1)-solve(st);
    return 0;
}
