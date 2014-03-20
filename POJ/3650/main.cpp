#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

char specialChars[7]={' ','!','$','%','(',')','*'};
int specialNumbers[6]={20,21,24,25,28,29};

void output(char cc)
{
    for (int i=0;i<=5;i++)
        if (cc == specialChars[i])
         {
             cout<<"%"<<specialNumbers[i];
             return;
         }
    if (cc == '*')
    {
         cout<<"%2a";
         return;
    }
    cout<<cc;
}

char str[100];

int main()
{
    FILE *fp;
    fp=fopen("1.txt","r");
    fscanf(fp,"%[^\n]",str);
    while ( !(strlen(str) == 1 && str[0] == '#'))
    {
        for (int i=0;i<strlen(str);i++)
            output(str[i]);
        cout<<endl;
        fscanf(fp,"%*c");
        fscanf(fp,"%[^\n]",str);
    }
    return 0;
}
