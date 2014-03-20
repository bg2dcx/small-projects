#include <iostream>
#include <string.h>
using namespace std;
char str[30];
char vowels[5]={'a','e','i','o','u'};

bool isEnd(char s[])
{
    int len=strlen(s);
    if (len != 3) return false;
    if (s[0] != 'e') return false;
    if (s[1] != 'n') return false;
    if (s[2] != 'd') return false;
    return true;
}

bool isVowel(char tmp)
{
    for (int i=0;i<5;i++)
        if (vowels[i]==tmp)
        return true;
    return false;
}

int main()
{
    cin>>str;
    while (!isEnd(str))
    {
        int numOfVowels=0;
        bool OK=true;
        for (int i=0;i<strlen(str);i++)
        {
            for (int j=0;j<5;j++)
                if (str[i] == vowels[j])
                  numOfVowels++;
            if (str[i] != 'e' && str[i]!='o' && i!=0 && str[i]==str[i-1])
                OK=false;
            if (i>=2 && isVowel(str[i])==isVowel(str[i-1]) && isVowel(str[i-1])==isVowel(str[i-2]))
                OK=false;
        }
        if (numOfVowels==0)
            OK=false;
        cout<<'<'<<str<<"> ";
        if (OK)
            cout<<"is acceptable."<<endl;
        else cout<<"is not acceptable."<<endl;
        cin>>str;
    }
    return 0;
}
