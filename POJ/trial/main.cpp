#include <iostream>
#include <string.h>
using namespace std;

char str[50];

int main()
{
    cin>>str;
    int len=strlen(str);
    for (int i=0;i<len;i++)
        cout<<(int)str[i]<<' ';
    cout<<endl;
    return 0;
}
