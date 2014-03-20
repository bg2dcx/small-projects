#include <iostream>

using namespace std;

int number,prev;

int main()
{
    cin>>number;
    while (number != 0)
    {
        for (int i=0;i<number;i++)
        {
            int tmp;
            cin>>tmp;
            if (i == 0)
            {
                prev=tmp;
                cout<<prev<<' ';
            }
            else
            {
                if (tmp != prev)
                {
                    cout<<tmp<<' ';
                    prev=tmp;
                }
            }
        }
        cout<<'$'<<endl;
        cin>>number;
    }
    return 0;
}
