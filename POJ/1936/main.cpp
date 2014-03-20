#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

char s1[100001],s2[100001];
int len1,len2;
bool findAns;

int main()
{
    while (scanf("%s%s",s1,s2) != EOF)
    {
        len1=strlen(s1);
        len2=strlen(s2);
        if (len1>len2)
            cout<<"No"<<endl;
        int current=-1;
        findAns=false;
        for (int i=0;i<len2;i++)
        {
            if (s2[i]==s1[current+1])
                current++;
            if (current==len1-1)
            {
                findAns=true;
                break;
            }
        }
        if (findAns)
            cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
