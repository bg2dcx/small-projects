#include <iostream>
#include <memory.h>

using namespace std;

int n,current,numOfSheets;
int halves[100][5];

int main()
{
    cin>>n;
    while (n != 0)
    {
        numOfSheets=n/4;
        memset(halves,0,sizeof(halves));
        if (n%4 != 0) numOfSheets++;
        current=1;
        for (int i=1;i<=numOfSheets;i++)
        {
              for (int k=1;k<=2;k++)
              {
                halves[i][k]=current;
                current++;
                if (current>n) break;
              }
              if (current>n) break;
        }
        for (int i=numOfSheets;i>0;i--)
        {
            for (int k=3;k<=4;k++)
            {
                if (current > n) break;
                halves[i][k]=current;
                current++;
                if (current > n) break;
            }
            if (current > n) break;
        }
        cout<<"Printing order for "<<n<<" pages:"<<endl;
        for (int i=1;i<=numOfSheets;i++)
        {
            cout<<"Sheet "<<i<<", front: ";
            if (halves[i][4] == 0)
                cout<<"Blank, ";
             else
                cout<<halves[i][4]<<", ";
             cout<<halves[i][1]<<endl;
            if (! (halves[i][2]==0 && halves[i][3]==0))
            {
                cout<<"Sheet "<<i<<", back : "<<halves[i][2]<<", ";
                if (halves[i][3]==0)
                    cout<<"Blank"<<endl;
                 else
                    cout<<halves[i][3]<<endl;
            }
        }
        cin>>n;
    }
    return 0;
}
