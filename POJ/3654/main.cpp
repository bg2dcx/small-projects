#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct RIGHT
{
    bool rights[40];
};

char str[100];

RIGHT admins[30];


void add_rights(char people[], char rights[])
{
    int pLen=strlen(people);
    int rLen=strlen(rights);
    for (int i=0;i<pLen;i++)
    {
        int pNum=people[i]-'A';
        for (int k=0;k<rLen;k++)
        {
            int rNum=rights[k]-'a';
            admins[pNum].rights[rNum]=true;
        }
    }
}

void delete_rights(char people[], char rights[])
{
    int pLen=strlen(people);
    int rLen=strlen(rights);
    for (int i=0;i<pLen;i++)
    {
        int pNum=people[i]-'A';
        for (int k=0;k<rLen;k++)
        {
            int rNum=rights[k]-'a';
            admins[pNum].rights[rNum]=false;
        }
    }
}

void equal_rights(char people[], char rights[])
{
    int pLen=strlen(people);
    int rLen=strlen(rights);
    for (int i=0;i<pLen;i++)
    {
        int pNum=people[i]-'A';
        for (int k=0;k<30;k++)
        {
            admins[pNum].rights[k]=false;
        }
        for (int k=0;k<rLen;k++)
        {
            int rNum=rights[k]-'a';
            admins[pNum].rights[rNum]=true;
        }
    }
}

void solve(char entry[],int len)
{
    int middle=len;
    for (int i=0;i<middle;i++)
        if (entry[i] == '-' || entry[i] =='+' || entry[i] == '=')
    {
        middle=i;
        break;
    }
    char people[100];
    char rights[100];
    for (int i=0;i<middle;i++)
        people[i]=entry[i];
    people[middle]='\0';
    for (int i=middle+1;i<len;i++)
        rights[i-middle-1]=entry[i];
    rights[len-middle-1]='\0';
    switch (entry[middle])
    {
        case '+':add_rights(people,rights);break;
        case '-':delete_rights(people,rights);break;
        case '=':equal_rights(people,rights);break;
    }
}

void init()
{
    for (int i=0;i<30;i++)
    {
        for (int k=0;k<30;k++)
            admins[i].rights[k]=false;
    }
}

bool noRight(int number)
{
    for (int i=0;i<26;i++)
        if (admins[number].rights[i])
            return false;
    return true;
}

bool sameRights(int p1, int p2)
{
    for (int i=0;i<26;i++)
        if (admins[p1].rights[i] != admins[p2].rights[i])
            return false;
    return true;
}

int main()
{
    FILE *fp;
    fp=fopen("eds.in","r");
    fscanf(fp,"%[^\n]",str);
    int caseNum=0;
    while (!(strlen(str) == 1 && str[0] == '#'))
    {
        int current=0;
        char tmp[100];
        int st=0;
        int length=strlen(str);
        init();
        while (current< length)
        {
            st=current;
            while (current<length && str[current] != ',')
            {
                tmp[current-st]=str[current];
                current++;
            }
            solve(tmp,current-st);
            current++;
        }
        caseNum++;
        cout<<caseNum<<':';
        int i=0;
        while (i<26)
        {

            if (!noRight(i))
            {
                int next=i;
                while (next<26 && sameRights(i,next))
                {
                    cout<<(char)(next+'A');
                    next++;
                    while (next<26 && noRight(next))
                        next++;
                }
                for (int j=0;j<26;j++)
                    if (admins[i].rights[j])
                        cout<<(char)(j+'a');
                i=next;
            }
            else i++;
        }
        cout<<endl;
        fscanf(fp,"%*c");
        fscanf(fp,"%[^\n]",str);
    }
    return 0;
}
