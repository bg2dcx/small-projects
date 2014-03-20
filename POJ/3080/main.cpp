#include <iostream>
#include <memory.h>
#include <string>

using namespace std;

string s1,s2,ansStr;
string str[11];
int ans,m,numOfCases;
int next[100];

int kmp(string s1, string s2)
{
    memset(next,0,sizeof(next));
    next[0]=-1;
    int j=-1;
    int maxi=0;
    int length=s1.size();
    for (int i=1;i<length;i++)
    {
        while (j != -1 && s1[j+1]!=s1[i]) j=next[j];
        if (s1[j+1] == s1[i]) j++;
        next[i]=j;
    }
    j=-1;
    for (int i=0;i<60;i++)
    {
        while (j != -1 && s1[j+1]!= s2[i]) j=next[j];
        if (s1[j+1] == s2[i]) j++;
        if (j>maxi) maxi=j;
        if (j == length-1) break;
    }
    return maxi;
}

int main()
{
    cin>>numOfCases;
    for (int cases=0;cases<numOfCases;cases++)
    {
        cin>>m;
        ans=0;
        for (int i=0;i<m;i++)
            cin>>str[i];
        int len=str[0].length();
        for (int i=0;i<=len-3;i++)
        {
            s1=str[0].substr(i);
            int maximum=100;
            for (int j=1;j<m;j++)
            {
                s2=str[j];
                int tmp=kmp(s1,s2)+1;
                if (tmp<maximum)
                    maximum=tmp;
            }
            if (ans<maximum)
            {
                ans=maximum;
                ansStr=s1.substr(0,maximum);
            }
            else if (ans==maximum && s1.substr(0,maximum)<ansStr)
            {
                ans=maximum;
                ansStr=s1.substr(0,maximum);
            }
        }
        if (ans<3)
            cout<<"no significant commonalities"<<endl;
        else cout<<ansStr<<endl;
    }
    return 0;
}
