#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;



char output[22][80][90];
char input[22][80][90];
int length[80];
char tmp[90];
int flag[80];
int numOfCols;
int numOfRows;

int main()
{
    FILE *fp;
    fp=fopen("fab.in","r");
    fscanf(fp,"%[^\n]",tmp);
    fscanf(fp,"%*c");
    while (tmp[0] != '*')
    {
        for (int i=0;i<strlen(tmp);i++)
        {
            if (tmp[i] == '<')
                flag[i]=0;
            if (tmp[i] == '=')
                flag[i]=1;
            if (tmp[i] == '>')
                flag[i]=2;
        }
        numOfCols=strlen(tmp);
        memset(length,0,sizeof(length));
        fscanf(fp,"%[^\n]",tmp);
        fscanf(fp,"%*c");
        numOfRows=0;
        while (!(tmp[0]=='<' || tmp[0]=='=' || tmp[0]=='>' || tmp[0]=='*'))
        {
            int pre=0;
            int current=-1;
            for (int i=0;i<numOfCols;i++)
            {
                current++;
                pre=current;
                while (current<strlen(tmp) && tmp[current]!='&')
                    current++;
                if (current-pre>length[i])
                    length[i]=current-pre;
                for (int j=pre;j<current;j++)
                    input[numOfRows][i][j-pre]=tmp[j];
                input[numOfRows][i][current-pre]='\0';
            }
            numOfRows++;
            fscanf(fp,"%[^\n]",tmp);
            fscanf(fp,"%*c");
        }
        int total=0;
        for (int i=0;i<numOfCols;i++)
            total+=length[i]+3;
        total+=1;
        cout<<'@';
        for (int i=1;i<total-1;i++)
            cout<<'-';
        cout<<"@\n";
       for (int k=0;k<numOfRows;k++)
       {
        for (int i=0;i<numOfCols;i++)
        {
            if (flag[i] == 0)
            {
                cout<<"| ";
                for (int j=0;j<strlen(input[k][i]);j++)
                    cout<<input[k][i][j];
                for (int j=strlen(input[k][i]);j<length[i];j++)
                    cout<<' ';
                cout<<" ";
            }
            if (flag[i] == 2)
            {
                cout<<"| ";
                for (int j=0;j<length[i]-strlen(input[k][i]);j++)
                    cout<<' ';
                for (int j=0;j<strlen(input[k][i]);j++)
                    cout<<input[k][i][j];
                cout<<" ";
            }
            if (flag[i] == 1)
            {
                cout<<"| ";
                for (int j=0;j<(length[i]-strlen(input[k][i]))/2;j++)
                    cout<<' ';
                for (int j=0;j<strlen(input[k][i]);j++)
                    cout<<input[k][i][j];
                for (int j=0;j<length[i]-strlen(input[k][i])-(length[i]-strlen(input[k][i]))/2;j++)
                    cout<<' ';
                cout<<" ";
            }
        }
        cout<<"|"<<endl;
        if (k == 0)
        {
            cout<<"|";
            for (int i=0;i<numOfCols;i++)
            {
                for (int j=0;j<length[i]+2;j++)
                    cout<<'-';
                if (i<numOfCols-1)
                    cout<<'+';
                else cout<<'|';
            }
            cout<<endl;
        }
       }
        cout<<'@';
        for (int i=1;i<total-1;i++)
            cout<<'-';
        cout<<"@\n";
    }
    return 0;
}
