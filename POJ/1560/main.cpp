#include <iostream>
//#include <fstream>

using namespace std;
bool isInSet[27];
int letters[27];
int result[27][27];
int n;
//ifstream fin("SEMIGRP.IN");
void init()
{
    for (int i=0;i<27;i++)
    {
        isInSet[i]=false;
        letters[i]=-1;
        for (int j=0;j<27;j++)
            result[i][j]=-1;
    }
}

void get_input(int number)
{
    char tmp;
    for (int i=0;i<number;i++)
    {
        cin>>tmp;
        letters[i]=tmp-'a';
        isInSet[letters[i]]=true;
    }
    for (int i=0;i<number;i++)
        for (int j=0;j<number;j++)
    {
        cin>>tmp;
        result[letters[i]][letters[j]]=tmp-'a';
    }
}

void first_output(int number)
{
    ////first row
    cout<<"S = {";
    for (int i=0;i<number;i++)
    {
        char tmp;
        tmp='a'+letters[i];
        cout<<tmp;
        if (i <number-1) cout<<',';
    }
    cout<<'}'<<endl;
    ////second row
    cout<<" #|";
    for (int i=0;i<number;i++)
    {
        char tmp;
        tmp='a'+letters[i];
        cout<<tmp;
    }
    cout<<endl;
    ////third row
    cout<<" -+";
    for (int i=0;i<number;i++)
        cout<<'-';
    cout<<endl;
    ////the rest
    for (int i=0;i<number;i++)
    {
        cout<<' ';
        char tmp;
        tmp='a'+letters[i];
        cout<<tmp<<'|';
        for (int j=0;j<number;j++)
        {
            tmp='a'+result[letters[i]][letters[j]];
            cout<<tmp;
        }
        cout<<endl;
    }
    //a blank line
    cout<<endl;
}

void output_dashes()
{
    for (int i=0;i<30;i++)
        cout<<'-';
    cout<<endl;
    cout<<endl;
}
void solve(int number)
{
    for (int i=0;i<26;i++)
        if (isInSet[i])
        for (int j=0;j<26;j++)
            if (isInSet[j])
    {
        if (! isInSet[result[i][j]])
        {
            cout<<"NOT A SEMIGROUP: ";
            char tmp;
            tmp='a'+i;
            cout<<tmp<<'#';
            tmp='a'+j;
            cout<<tmp<<" = ";
            tmp='a'+result[i][j];
            cout<<tmp<<"  WHICH IS NOT AN ELEMENT OF THE SET"<<endl;
            output_dashes();
            return;
        }
    }
    for (int i=0;i<26;i++)
        if (isInSet[i])
        for (int j=0;j<26;j++)
            if (isInSet[j])
            for (int k=0;k<26;k++)
                if (isInSet[k])
    {
        if ( result[result[i][j]][k] != result[i][result[j][k]])
        {
            cout<<"NOT A SEMIGROUP: (";
            char tmp;
            tmp='a'+i;
            cout<<tmp<<'#';
            tmp='a'+j;
            cout<<tmp<<")#";
            tmp='a'+k;
            cout<<tmp<<" IS NOT EQUAL TO ";
            tmp='a'+i;
            cout<<tmp<<"#(";
            tmp='a'+j;
            cout<<tmp<<'#';
            tmp='a'+k;
            cout<<tmp<<')'<<endl;
            output_dashes();
            return;
        }
    }
    for (int i=0;i<26;i++)
        if (isInSet[i])
        for (int j=0;j<26;j++)
            if (isInSet[j])
    {
        if (result[i][j] != result[j][i])
        {
            cout<<"SEMIGROUP BUT NOT COMMUTATIVE  (";
            char tmp;
            tmp='a'+i;
            cout<<tmp<<'#';
            tmp='a'+j;
            cout<<tmp<<" IS NOT EQUAL TO ";
            cout<<tmp<<'#';
            tmp='a'+i;
            cout<<tmp<<')'<<endl;
            output_dashes();
            return;
        }
    }
    cout<<"COMMUTATIVE SEMIGROUP"<<endl;
    output_dashes();
}

int main()
{
    cin>>n;
    while (n != 0)
    {
        init();
        get_input(n);
        first_output(n);
        solve(n);
        cin>>n;
    }
    return 0;
}
