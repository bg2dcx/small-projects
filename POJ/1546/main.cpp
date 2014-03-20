#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

char number[10];
int base1,base2;
int intnumber;
int noutput[500];
int numOfOutput;

int main()
{
    while (scanf("%s%d%d",number,&base1,&base2) != EOF)
    {
        int len=strlen(number);
        int tmp=1;
        intnumber=0;
        for (int i=len-1;i>=0;i--)
        {
            int current=0;
            if (number[i]>='A' && number[i]<='F')
                current=number[i]-'A'+10;
            else current=number[i]-'0';
            intnumber+=current*tmp;
            tmp*=base1;
        }
        noutput[0]=intnumber%base2;
        numOfOutput=0;
        intnumber/=base2;
        while (intnumber!=0)
        {
            numOfOutput++;
            noutput[numOfOutput]=intnumber%base2;
            intnumber/=base2;
        }
        if (numOfOutput>6)
        {
            cout<<"  ERROR"<<endl;
        }
        else
        {
                for (int i=6-numOfOutput;i>0;i--)
                    cout<<' ';
                for (int i=numOfOutput;i>=0;i--)
                {
                    if (noutput[i]>9)
                    {
                        char tmp='A'+noutput[i]-10;
                        cout<<tmp;
                    } else
                        cout<<noutput[i];
                }
                cout<<endl;
        }

    }

    return 0;
}
