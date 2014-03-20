#include <iostream>

using namespace std;

int tmp[3];
int n;

int main()
{
       cin>>n;
       cout<<"Gnomes:"<<endl;
       for (int i=0;i<n;i++)
       {
           bool ordered=true;
           for (int i=0;i<3;i++)
             cin>>tmp[i];
           for (int i=1;i<3;i++)
             if (tmp[i]>tmp[i-1])
                ordered=false;
           if (ordered)
           {
               cout<<"Ordered"<<endl;
               continue;
           }
           ordered=true;
           for (int i=1;i<3;i++)
              if (tmp[i]<tmp[i-1])
                ordered=false;
           if (ordered)
              cout<<"Ordered"<<endl;
           else
               cout<<"Unordered"<<endl;
       }
       return 0;
}
