#include <iostream>
#include <string>
#define MAX_NUMBER 27
using namespace std;
int character_value;
string word;
int comb[27][27];
int input_word[11];
int len;
int max_value;
void comb_initialize()
{
    for (int i=0;i<MAX_NUMBER;i++)
    {
        comb[0][i]=1;
        comb[i][0]=0;
    }
    comb[0][0]=1;
    for (int m=1;m<MAX_NUMBER;m++)
        for (int n=1;n<=m;n++)
          comb[n][m]=comb[n-1][m-1]+comb[n][m-1];
}
int main()
{
    comb_initialize();
    getline(cin,word);
    len=word.length();
    max_value=0;
    for (int i=1;i<=len;i++)
    {
        character_value=word[i-1]-'a'+1;
        if (character_value <= max_value)
        {
            cout<<0<<endl;
            return 0;
        }
        input_word[i]=character_value;
        max_value=character_value;
    }
    int sum=1;
    for (int i=1;i<len;i++)
        sum+=comb[i][26];
    for (int position=1;position<=len;position++)
    {
        for (int smaller_value=input_word[position-1]+1;smaller_value<input_word[position];smaller_value++)
            sum+=comb[len-position][26-smaller_value];
    }
    cout<<sum;
    return 0;
}
