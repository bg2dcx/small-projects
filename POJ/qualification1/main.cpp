#include <iostream>

using namespace std;

int n,x;

int main()
{
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>x;
        if ( (x%2)==0)
            cout<<x<<" is even\n";
        else cout<<x<<" is odd\n";
    }
    return 0;
}
