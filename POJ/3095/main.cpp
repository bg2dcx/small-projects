#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
ifstream fin("1.txt");
char str[90];
int len;


int judge(int pos)
{
    if (str[pos] == '.')
        return 100;
    if (str[pos] == '_')
        return 0;

    if (str[pos] == '/')
    {
        int prev=pos-1;
        while (prev>=0 && str[prev]=='_')
            prev--;
        if (prev<0 || str[prev]=='.')
            return 100;
        else return 0;
    }

    if (str[pos] == '\\')
    {
        int next=pos+1;
        while (next<len && str[next]=='_')
            next++;
        if (next>=len || str[next]=='.')
            return 100;
        else return 0;
    }

    if (str[pos] == '|')
    {
        int ans=0;
        int prev=pos-1;
        while (prev>=0 && str[prev]=='_')
            prev--;
        if (prev<0 || str[prev]=='.')
            ans+=50;
        int next=pos+1;
        while (next<len && str[next]=='_')
            next++;
        if (next>=len || str[next]=='.')
            ans+=50;
        return ans;
    }
    return 0;
}

int main()
{
    fin>>str;
    while (! ( strlen(str) == 1 && str[0] == '#'))
    {
        len=strlen(str);
        double sum=0;
        for (int i=0;i<len;i++)
        {
            sum+=judge(i);
        }
        sum/=len;
        int ans=(int)sum;
        if (ans > sum)
            ans--;
        cout<<ans<<endl;
        fin>>str;
    }
    return 0;
}
