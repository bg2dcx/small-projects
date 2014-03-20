#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

char s1[1000],s2[1000],tmp[1000];
int numOfCases, len1,len2,current;
bool findAns;

int main()
{
    scanf("%d",&numOfCases);
    while (numOfCases--)
    {
        scanf("%s%s",s1,s2);
        len1=strlen(s1);
        len2=strlen(s2);
        current=-1;
        findAns=false;
        for (int i=0;i<len1;i++)
        {
            if (s2[current+1] == s1[i])
            {
                current++;
            }
            if (current == len2-1)
            {
                findAns=true;
                break;
            }
        }
        if (!findAns)
        {
            for (int i=0;i<len2;i++)
                tmp[i]=s2[i];
            for (int i=0;i<len2;i++)
                s2[i]=tmp[len2-i-1];
            current=-1;
            for (int i=0;i<len1;i++)
            {
                if (s2[current+1]== s1[i])
                    current++;
                if (current == len2-1)
                {
                    findAns=true;
                    break;
                }
            }
        }
        if (findAns)
            cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
