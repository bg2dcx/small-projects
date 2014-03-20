#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#define MAXN 10001

using namespace std;
 long long pie[MAXN];
 int numOfCases, numOfPies, numOfFriends;
 long long maxpie;

 int cmp(long long a, long long b)
 {
     if (a>b)
        return 1;
     else return 0;
 }

 bool test(long long pieceSize, int numOfPeople)
 {
     for (int i=0;i<numOfPies;i++)
     {
         long long tmp=pie[i];
         while (tmp>=pieceSize)
         {
             tmp-=pieceSize;
             numOfPeople--;
             if (numOfPeople==0)
                return true;
         }
     }
     return false;
 }

int main()
{
    cin>>numOfCases;
    while (numOfCases--)
    {
        cin>>numOfPies>>numOfFriends;
        numOfFriends++;
        maxpie=0;
        for (int i=0;i<numOfPies;i++)
        {
            long long tmp;
            cin>>tmp;
            tmp=tmp*tmp*100000;
            if (tmp>maxpie)
                maxpie=tmp;
            pie[i]=tmp;
        }
        sort(pie,pie+numOfPies,cmp);
        long long lowerbound=0;
        long long upperbound=maxpie;
        long long mid;
        long long ans=0;
        while (lowerbound<=upperbound)
        {
            mid=(lowerbound+upperbound)/2;
            bool feedback=test(mid,numOfFriends);
            if (feedback)
            {
                if (mid>ans)
                    ans=mid;
                lowerbound=mid+1;
            } else
             {
                upperbound=mid-1;
             }
        }
        double output= ((double) ans) /100000;
        output*=3.1415926535897932384626433832795028841971693993751058;
        printf("%0.4f\n",output);
    }
    return 0;
}
