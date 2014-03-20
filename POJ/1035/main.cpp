#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int cmp(const int a, const int b)
{
    if (a>b) return 0;
        else return 1;
}

struct WORD
{
    char chars[16];
    int len;
};

struct NODE
{
    NODE * next;
    int num;
};

NODE hashtable[400];
WORD dictionary[10001];
int answers[10001];
int numOfWords, numOfCases;
char tmp[16];
int tmplen;
FILE *fp;

void insert_hash(int number, int key)
{
    if (hashtable[key].num==-1)
    {
        hashtable[key].num=number;
    } else
        {
            NODE *p=&hashtable[key];
            while (p->next != NULL)
                p=p->next;
            NODE *q=(NODE *)malloc(sizeof(NODE));
            p->next=q;
            q->next=NULL;
            q->num=number;
        }
}

bool check_replace(int number)
{
    int dif=0;
    for (int i=0;i<tmplen;i++)
        if (tmp[i]!= dictionary[number].chars[i])
            dif++;
    if (dif == 0) return true;
    if (dif == 1 )
    {
        answers[0]++;
        answers[answers[0]]=number;
    }
    return false;
}

void check_delete(int number)
{
    for (int i=0;i<dictionary[number].len;i++)
    {
        int dif=0;
        int st=-1;
        for (int j=0;j<dictionary[number].len;j++)
            if (i != j)
        {
            st++;
            if (dictionary[number].chars[j] != tmp[st])
            {
                dif++;
                break;
            }
        }
        if (dif==0)
        {
                answers[0]++;
                answers[answers[0]]=number;
                return;
        }
    }
}

void check_insert(int number)
{
    for (int i=0;i<tmplen;i++)
    {
        int dif=0;
        int st=-1;
        for (int j=0;j<tmplen;j++)
            if (i != j)
        {
            st++;
            if (tmp[j] != dictionary[number].chars[st])
            {
                dif++;
                break;
            }
        }
        if (dif==0)
        {
            answers[0]++;
            answers[answers[0]]=number;
            return;
        }
    }
}

bool check_hash(int key)
{
    if (hashtable[key].num==-1)
        return false;
    NODE *p=&hashtable[key];
    while (true)
    {
        if (dictionary[p->num].len+1==tmplen)
            check_insert(p->num);
        if (dictionary[p->num].len==tmplen)
        {
            bool isSame=false;
            isSame=check_replace(p->num);
            if (isSame)
                return true;
        }
        if (dictionary[p->num].len-1==tmplen)
            check_delete(p->num);
        if (p->next != NULL)
            p=p->next;
         else break;
    }
}

int main()
{
    fp=fopen("input.txt","r");
    fscanf(fp,"%s",tmp);
    for (int i=0;i<400;i++)
        hashtable[i].num=-1;
    while (tmp[0] != '#')
    {
        numOfWords++;
        dictionary[numOfWords].len=strlen(tmp);
        int sum=0;
        for (int i=0;i<dictionary[numOfWords].len;i++)
        {
            dictionary[numOfWords].chars[i]=tmp[i];
            sum+=tmp[i]-'a'+1;
        }
        insert_hash(numOfWords,sum);
        fscanf(fp,"%s",tmp);
    }
    fscanf(fp,"%s",tmp);
    while (tmp[0] != '#')
    {
        int sum=0;
        answers[0]=0;
        for (int i=0;i<strlen(tmp);i++)
            sum+=tmp[i]-'a'+1;
        tmplen=strlen(tmp);
        bool findAns=false;
        for (int i=sum-26;i<=sum+26;i++)
            if (i>0)
            {
                    findAns=check_hash(i);
                    if (findAns) break;
            }
        if (findAns)
            cout<<tmp<<" is correct"<<endl;
          else{
            sort(answers+1,answers+answers[0]+1,less<int>());
            cout<<tmp<<':';
            for (int i=1;i<=answers[0];i++)
                cout<<' '<<dictionary[answers[i]].chars;
            cout<<endl;
        }
        fscanf(fp,"%s",tmp);
    }
    return 0;
}
