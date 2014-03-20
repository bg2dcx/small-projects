#include <iostream>
#include <stdio.h>
#include <string.h>
char message[80];
int plaincode[80];
int ciphercode[80];
int n,len;

using namespace std;

int main()
{
    scanf("%d",&n);
    while (n != 0)
    {
        scanf("%s",message);
        len=strlen(message);
        for (int i=0;i<len;i++)
        {
            if (message[i] == '_')
               ciphercode[i]=0;
            if (message[i] == '.')
                ciphercode[i]=27;
            if (message[i]>='a' && message[i]<='z')
                ciphercode[i]=message[i]-'a'+1;
        }
        for (int i=0;i<len;i++)
        {
            int tmp=(ciphercode[i]+i)%28;
            plaincode[n*i%len]=tmp;
        }
        for (int i=0;i<len;i++)
        {
            if (plaincode[i]==0)
                cout<<'_';
            else if (plaincode[i]==27)
                cout<<'.';
            else
            {
                char c=plaincode[i]+'a'-1;
                cout<<c;
            }
        }
        cout<<endl;
        scanf("%d",&n);
    }
    return 0;
}
