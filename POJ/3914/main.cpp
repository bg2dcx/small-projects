#include <iostream>
#include <string.h>
using namespace std;

int dulls[21];

struct PROGRAM
{
    int memory;
    char names[30];
} programs[10];

int inUse[21];

int n, p ,s ,tmp, current;


void add_program(int number)
{
    current+=programs[number].memory;
    int len=strlen(programs[number].names);
    for (int i=0;i<len;i++)
    {
        int tmp=programs[number].names[i]-'A'+1;
        if (inUse[tmp] == 0)
            current+=dulls[tmp];
        inUse[tmp]++;
    }
}

void remove_program(int number)
{
    current-=programs[number].memory;
    int len=strlen(programs[number].names);
    for (int i=0;i<len;i++)
    {
        int tmp=programs[number].names[i]-'A'+1;
        inUse[tmp]--;
        if (inUse[tmp] == 0)
            current-=dulls[tmp];
    }
}

int main()
{
    cin>>n;
    while (n!=0)
    {
        cin>>p>>s;
        for (int i=1;i<=n;i++)
            cin>>dulls[i];
        for (int i=1;i<=p;i++)
            cin>>programs[i].memory>>programs[i].names;
        memset(inUse,0,sizeof(inUse));
        int maxi=0;
        current=0;
        for (int i=0;i<s;i++)
        {
            cin>>tmp;
            if (tmp>0)
                add_program(tmp);
            else remove_program(-tmp);
            if (current>maxi)
                maxi=current;
        }
        cout<<maxi<<endl;
        cin>>n;
    }
    return 0;
}
