#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

char number[100];

int ans,len,tmp;

int main()
{
    scanf("%s",number);
    while (!(strlen(number)==1 && number[0]=='0'))
    {
        len=strlen(number);
        tmp=1;
        ans=0;
        for (int i=len-1;i>=0;i--)
        {
            tmp=tmp*2;
            if (number[i]=='1')
                ans+=tmp-1;
            else if (number[i]=='2')
                ans+=2*(tmp-1);
        }
        cout<<ans<<endl;
        scanf("%s",number);
    }
}
