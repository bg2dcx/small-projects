#include <iostream>

using namespace std;

int inc[22];
int pnumber[22];
int caseNumber, parenNumber;

int main()
{
    cin>>caseNumber;
    for (int cases=0;cases<caseNumber;cases++)
    {
        cin>>parenNumber;
        pnumber[0]=0;
        for (int i=1;i<=parenNumber;i++)
        {
            cin>>pnumber[i];
            inc[i]=pnumber[i]-pnumber[i-1]-1;
        }
        for (int i=1;i<=parenNumber;i++)
        {
            int rest=inc[i];
            int current=i;
            while (rest<0 && current>1)
            {
                current--;
                rest=rest+inc[current];
            }
            cout<<i-current+1<<' ';
        }
        cout<<endl;
    }
    return 0;
}
