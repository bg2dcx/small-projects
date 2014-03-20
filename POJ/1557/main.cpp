#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
using namespace std;

int n,r,refnamelength;
char name[10000][12];
int namelength[10000];
int dimention[10000],byteSize[10000];
int boundpairs[10000][11][2];
int elementnumber[10000][12];
int baseAdd[10000];

bool is_same_name(char inputName[],int nameNumber)
{
    if (refnamelength != namelength[nameNumber] ) return false;
    for (int i=1;i<=refnamelength;i++)
        if (inputName[i] != name[nameNumber][i]) return false;
    return true;
}

int main()
{
    cin>>n>>r;
    for (int i=0;i<n;i++)
    {
        char tmp[12];
        scanf("%s",tmp);
        namelength[i]=strlen(tmp);
        for (int j=1;j<=namelength[i];j++)
            name[i][j]=tmp[j-1];
        cin>>baseAdd[i];
        cin>>byteSize[i];
        cin>>dimention[i];
        for (int j=0;j<dimention[i];j++)
            cin>>boundpairs[i][j][0]>>boundpairs[i][j][1];
        elementnumber[i][dimention[i]]=1;
        for (int j=dimention[i]-1;j>0;j--)
            elementnumber[i][j]=elementnumber[i][j+1]*(boundpairs[i][j][1]-boundpairs[i][j][0]+1);
    }
    for (int i=0;i<r;i++)
    {
        char tmp[12];
        scanf("%s",tmp);
        char refname[12];
        refnamelength=strlen(tmp);
        for (int j=1;j<=refnamelength;j++)
            refname[j]=tmp[j-1];
        int refnumber=-1;
        for (int k=0;k<n;k++)
            if (is_same_name(refname,k))
            {
                refnumber=k;
                break;
            }
        int refpos[12];
        for (int j=0;j<dimention[refnumber];j++)
            cin>>refpos[j];
        int result=0;
        for (int j=0;j<dimention[refnumber];j++)
            result=result+elementnumber[refnumber][j+1]*(refpos[j]-boundpairs[refnumber][j][0]);
        result=result*byteSize[refnumber]+baseAdd[refnumber];
        for (int j=0;j<refnamelength;j++)
            cout<<refname[j+1];
        cout<<'[';
        for (int j=0;j<dimention[refnumber];j++)
        {
            cout<<refpos[j];
            if (j != dimention[refnumber]-1 ) cout<<", ";
        }
        cout<<"] = "<<result<<endl;
    }

    return 0;
}
