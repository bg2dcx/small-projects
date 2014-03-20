#include <iostream>

using namespace std;
int number;

int hashtable[606061];
int nums[61],nlist[61];
int totaln,timer;
int totalcomb, totalperm;

bool check(int x, int y, int z){
    int tmp;
    if (x<y) {
        tmp=x;
        x=y;
        y=tmp;
    }
    if (x<z) {
        tmp=x;
        x=z;
        z=tmp;
    }
    if (y<z){
        tmp=y;
        y=z;
        z=tmp;
    }
    if (hashtable[x*10000+y*100+z] != timer) {
        hashtable[x*10000+y*100+z] = timer;
        return true;
    } else return false;
}

int main()
{
    timer=0;
    int x,y;
    for (int i=0;i<61;i++)
        nlist[i]=0;
    nlist[50]=1;
    for (int i=0;i<21;i++)
    {
        nlist[i]=1;
        nlist[2*i]=1;
        nlist[3*i]=1;
    }
    totaln=0;
    for (int i=0;i<61;i++)
       if (nlist[i] == 1){
            nums[totaln]=i;
            totaln++;
    }

    cin>>number;
    while ( number > 0) {
        timer++;
        totalcomb=totalperm=0;
        if ( number > 180) {
                cout<<"THE SCORE OF "<<number<<" CANNOT BE MADE WITH THREE DARTS."<<endl;
                for (int i=0;i<70;i++) cout<<"*";
                cout<<endl;
                cin>>number;
                continue;
        }

        for (x=0;x<totaln;x++)
            for (y=0;y<totaln;y++)
        {
                    if ((nums[x]+nums[y] > number) || (number-nums[x]-nums[y] > 60)) continue;
                    if ( nlist[number-nums[x]-nums[y]] == 0 ) continue;
                    totalperm++;
                    if (check(nums[x],nums[y],number-nums[x]-nums[y])) totalcomb++;
        }

        if (totalcomb !=0 ){
            cout<<"NUMBER OF COMBINATIONS THAT SCORES "<<number<<" IS "<<totalcomb<<"."<<endl;
            cout<<"NUMBER OF PERMUTATIONS THAT SCORES "<<number<<" IS "<<totalperm<<"."<<endl;
            for (int i=0;i<70;i++) cout<<"*";
            cout<<endl;
        } else {
            cout<<"THE SCORE OF "<<number<<" CANNOT BE MADE WITH THREE DARTS."<<endl;
            for (int i=0;i<70;i++) cout<<"*";
            cout<<endl;
        }
    cin>>number;
    }
    cout<<"END OF OUTPUT"<<endl;
    return 0;
}
