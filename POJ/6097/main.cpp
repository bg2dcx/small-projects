#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

char str[100];
char str1[100], str2[100];

int main()
{
    scanf("%[^\n]",str);
    scanf("%*c");
    while (strcmp(str,"END") != 0)
    {
        if (str[0] != '\"')
        {
            cout<<"not a quine"<<endl;
            scanf("%[^\n]",str);
            scanf("%*c");
            continue;
        }
        int pos=1;
        while (pos < strlen(str))
        {
            if (str[pos] == '\"')
                break;
            pos++;
        }
        if ( !(pos+1 < strlen(str) && str[pos+1]==' '))
        {
            cout<<"not a quine"<<endl;
            scanf("%[^\n]",str);
            scanf("%*c");
            continue;
        }
        bool isQ=true;
        for (int i=1;i<pos;i++)
        {
            if (pos+i+1 >=strlen(str) )
            {
                isQ=false;
                break;
            }
            if (str[i] != str[pos+i+1])
            {
                isQ=false;
                break;
            }
        }
        if ( pos * 2 + 1!= strlen(str))
            isQ=false;
        if (!isQ)
        {
            cout<<"not a quine"<<endl;
            scanf("%[^\n]",str);
            scanf("%*c");
            continue;
        }
        cout<<"Quine(";
        for (int i=1;i<pos;i++)
            cout<<str[i];
        cout<<")\n";
        scanf("%[^\n]",str);
        scanf("%*c");
    }
    return 0;
}
