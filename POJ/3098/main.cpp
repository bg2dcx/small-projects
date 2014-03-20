#include <iostream>
#include <stdio.h>
#include <string.h>
#define MAXL 30

using namespace std;

struct TERM
{
    char mayInclude[30];
    char mustInclude[30];
    char notInclude[30];
    int numMay, numMust, numNot;
} terms[30];

char words[110][30];
char tmp[90];
int numOfWords,numofTerms;

bool isOkay(int wordNum, TERM theTerm)
{
    int len=strlen(words[wordNum]);
    //mayInclude
    bool shown=false;
    for (int i=0;i<theTerm.numMay;i++)
    {
        for (int j=0;j<len;j++)
            if (words[wordNum][j] == theTerm.mayInclude[i])
            shown=true;
    }
    if (!shown && theTerm.numMay!=0)
       return false;
    //mustInclude
    for (int i=0;i<theTerm.numMust;i++)
    {
        shown=false;
        for (int j=0;j<len;j++)
            if (words[wordNum][j] == theTerm.mustInclude[i])
              shown=true;
        if (!shown)
            return false;
    }
    //notInclude
    for (int i=0;i<theTerm.numNot;i++)
    {
        for (int j=0;j<len;j++)
            if (words[wordNum][j] == theTerm.notInclude[i])
              return false;
    }
    return true;
}

bool smaller(int num1, int num2)
{
    int len=strlen(words[num1]);
    if (strlen(words[num2])<strlen(words[num1]))
        len=strlen(words[num2]);
    for (int i=0;i<len;i++)
        if (words[num1][i]>words[num2][i])
         return false;
        else if (words[num1][i]<words[num2][i])
            return true;
    if (strlen(words[num1]) < strlen(words[num2]))
        return true;
    else return false;
}

int main()
{
    scanf("%s",tmp);
    while (!(strlen(tmp)==1 && tmp[0]=='#'))
    {
        numOfWords=0;
        while (!(strlen(tmp)==1 && tmp[0]=='*'))
        {
            for (int i=0;i<strlen(tmp);i++)
                words[numOfWords][i]=tmp[i];
            words[numOfWords][strlen(tmp)]='\0';
            numOfWords++;
            scanf("%s",tmp);
        }
        //sort the words
        for (int i=0;i<numOfWords;i++)
        {
            int best=i;
            for (int k=i+1;k<numOfWords;k++)
                if (smaller(k,best))
                   best=k;
            if (best != i)
            {
                char cc;
                for (int k=0;k<MAXL;k++)
                {
                    cc=words[i][k];
                    words[i][k]=words[best][k];
                    words[best][k]=cc;
                }
            }
        }
        scanf("%s",tmp);
        while (!(strlen(tmp)==2 && tmp[0]=='*' && tmp[1]=='*'))
        {
            numofTerms=1;
            int flag=0;
            int current=0;
            int len=strlen(tmp);
            for (int i=0;i<30;i++)
            {
                terms[i].numNot=0;
                terms[i].numMust=0;
                terms[i].numMay=0;
            }
            while (current<len)
            {
                if (tmp[current] == '|')
                {
                    flag=0;
                    numofTerms++;
                } else
                if (tmp[current] == '+')
                {
                    flag=1;
                } else
                if (tmp[current] == '-')
                {
                    flag=2;
                } else
                {
                    switch (flag)
                    {
                        case 0: terms[numofTerms].mayInclude[terms[numofTerms].numMay]=tmp[current];
                                terms[numofTerms].numMay++;
                                break;
                        case 1: terms[numofTerms].mustInclude[terms[numofTerms].numMust]=tmp[current];
                                terms[numofTerms].numMust++;
                                break;
                        case 2: terms[numofTerms].notInclude[terms[numofTerms].numNot]=tmp[current];
                                terms[numofTerms].numNot++;
                                break;
                    }
                }
                current++;
            }
            int ans=-1;
            for (int i=0;i<numOfWords;i++)
            {
                bool OK=false;
                for (int k=1;k<=numofTerms;k++)
                {
                    OK=isOkay(i,terms[k]);
                    if (OK) break;
                }
                if (OK)
                {
                    ans=i;
                    break;
                }
            }
            if (ans != -1)
                cout<<words[ans]<<endl;
            else
                cout<<"NONE"<<endl;
           scanf("%s",tmp);
        }
        cout<<'$'<<endl;
        scanf("%s",tmp);
    }
    return 0;
}
