#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct WORD{
    char c[7];
};

WORD words[102];
char scrabled[7];

int numOfWords;

int cmp(WORD a,WORD b)
{
    int len1=strlen(a.c);
    int len2=strlen(b.c);
    int len=len1;
    if (len2<len)
        len=len2;
    for (int i=0;i<len;i++)
    {
        if (b.c[i]<a.c[i])
            return 0;
        if (a.c[i]<b.c[i])
            return 1;
    }
    if (len2<len1) return 0;
    return 1;
}

bool similar(int number)
{
    int len=strlen(scrabled);
    if (len != strlen(words[number].c))
        return false;
    bool used[7];
    for (int i=0;i<7;i++)
        used[i]=false;
    bool findAns=false;
    for (int i=0;i<len;i++)
    {
        findAns=false;
        for (int j=0;j<len;j++)
            if ((!used[j]) && words[number].c[j] == scrabled[i])
        {
            used[j]=true;
            findAns=true;
            break;
        }
        if (!findAns) return false;
    }
    return true;
}

int main()
{
    scanf("%s",scrabled);
    numOfWords=0;
    while (scrabled[0] != 'X')
    {
        for (int i=0;i<7;i++)
            words[numOfWords].c[i]=scrabled[i];
        numOfWords++;
        scanf("%s",scrabled);
    }

    sort(words,words+numOfWords,cmp);
    scanf("%s",scrabled);
    while (scrabled[0] != 'X')
    {
        bool findAns=false;
        for (int i=0;i<numOfWords;i++)
            if (similar(i))
        {
            cout<<words[i].c<<endl;
            findAns=true;
        }
        if (!findAns)
            cout<<"NOT A VALID WORD"<<endl;
        cout<<"******"<<endl;
        scanf("%s",scrabled);
    }
    return 0;
}
