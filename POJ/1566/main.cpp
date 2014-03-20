#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

char haiku[300];
char vowels[6]={'a','e','i','o','u','y'};
char ending[5]={'e','/','o','/','i'};
int haikuSyllables[3]={5,7,5};

int length,numOfSyllables;
bool findAns;

bool isSame(char str1[],char str2[])
{
    int len1=strlen(str1);
    int len2=strlen(str2);
    if (len1 != len2)
        return false;
    for (int i=0;i<len1;i++)
        if (str1[i] != str2[i])
        return false;
    return true;
}

bool isVowel(char c)
{
    for (int i=0;i<6;i++)
        if (c == vowels[i])
            return true;
    return false;
}

int main()
{
    scanf("%[^\n]",&haiku);
    while (!isSame(haiku,ending))
    {
        length=strlen(haiku);
        haiku[length]='/';
        length++;
        findAns=false;
        int current=-1;
        for (int i=0;i<3;i++)
        {
            numOfSyllables=0;
            current++;
            while (haiku[current]!='/')
            {
                if (isVowel(haiku[current]))
                {
                    numOfSyllables++;
                    while (isVowel(haiku[current+1]))
                        current++;
                }
                current++;
            }
            if (numOfSyllables != haikuSyllables[i])
            {
                cout<<i+1<<endl;
                findAns=true;
                break;
            }
        }
        if (!findAns)
            cout<<"Y"<<endl;
        char tmp;
        scanf("%c",&tmp);
        scanf("%[^\n]",&haiku);
    }
    return 0;
}
