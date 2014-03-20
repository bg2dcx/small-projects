#include <iostream>
#include <stdio.h>

using namespace std;
int numbers[9];
bool numAhead;
int main()
{
    int tmp;
    while ( scanf("%d",&tmp) != EOF)
    {
        numbers[0]=tmp;
        for (int i=1;i<9;i++)
            cin>>numbers[i];
        numAhead=false;
        for (int i=0;i<9;i++)
            if (numbers[i]!=0)
        {
            if (numAhead)
            {
                if (numbers[i]>0)
                {
                    cout<<" + ";
                    if ( (numbers[i]!=1) || ( (numbers[i]==1) && (i==8) ) )  cout<<numbers[i];
                    if (i<8) cout<<'x';
                    if (i<7) cout<<'^'<<8-i;
                }
                if (numbers[i] < 0)
                {
                    cout<<" - ";
                    if ( (numbers[i]!=-1) || ( (numbers[i]==-1) && (i==8) ) ) cout<<-numbers[i];
                    if (i<8) cout<<'x';
                    if (i<7) cout<<'^'<<8-i;
                }
            } else
            {
                 if (numbers[i]>0)
                {
                    if ( (numbers[i]!=1) || ( (numbers[i]==1) && (i==8) ) ) cout<<numbers[i];
                    if (i<8) cout<<'x';
                    if (i<7) cout<<'^'<<8-i;
                    numAhead=true;
                }
                if (numbers[i] < 0)
                {
                    if ( (numbers[i]!=-1) || ( (numbers[i]==-1) && (i==8) ) ) cout<<'-'<<-numbers[i];
                    if ( (numbers[i]==-1) && (i<8) ) cout<<"-";
                    if (i<8) cout<<'x';
                    if (i<7) cout<<'^'<<8-i;
                    numAhead=true;
                }
            }
        }
        if (!numAhead) cout<<0;
        cout<<endl;
    }
}
