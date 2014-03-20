#include <iostream>
#include <memory.h>
#define MAXN 100
using namespace std;

int opt[105];
int s[101];
int r,c;
int days;

int main()
{
    cin>>days;
    cin>>r>>c;
    for (int i=1;i<=days;i++)
        cin>>s[i];
    memset(opt,0,sizeof(opt));
    for (int i=days;i>0;i--)
    {
        opt[i]=s[i]*r+opt[i+1];
        if (4*c+opt[i+4]<opt[i])
            opt[i]=4*c+opt[i+4];
    }
    cout<<opt[1];
    return 0;
}
