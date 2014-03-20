#include <iostream>

// -1 inconsistency 0 determined 1 cannot be determined
using namespace std;

bool biggerThan[27][27];
int numOfBigger[27];
int n,m;

int topo(int number)
{
    int tmpNum[27];
    for (int i=1;i<=number;i++)
        tmpNum[i]=numOfBigger[i];
    int findAns=0;
    int rest=number;
    int biggest=-1;
    int biggestNum=0;
    while (rest>=1)
    {
        biggest=-1;
        biggestNum=0;
        for (int i=1;i<=number;i++)
            if (tmpNum[i]==0)
        {
            biggest=i;
            biggestNum++;
        }
        if (biggestNum>1) findAns=1;
        if (biggest==-1) return -1;
        tmpNum[biggest]=-1;
        for (int i=1;i<=number;i++)
            if (biggerThan[biggest][i])
            tmpNum[i]--;
        rest--;
    }
    return findAns;
}

void print_ans(int number)
{
    char answer[27];
    int rest=number;
    while (rest>0)
    {
        int biggest=0;
        for (int i=1;i<=number;i++)
            if (numOfBigger[i]==0)
        {
            biggest=i;
            break;
        }
        answer[number-rest]=biggest+'A'-1;
        numOfBigger[biggest]=-1;
        for (int i=1;i<=number;i++)
            if (biggerThan[biggest][i])
                numOfBigger[i]--;
        rest--;
    }
    for (int i=number-1;i>-1;i--)
        cout<<answer[i];
    cout<<'.'<<endl;
}

void init()
{
    for (int i=0;i<27;i++)
    {
        numOfBigger[i]=0;
        for (int j=0;j<27;j++)
            biggerThan[i][j]=false;
    }
}

int main()
{
    cin>>m>>n;
    while ( !(n==0 && m==0))
    {
        init();
        char tmp[3];
        int findAns=1;
        for (int i=1;i<=n;i++)
        {
            for (int j=0;j<3;j++)
                cin>>tmp[j];
            biggerThan[tmp[2]-'A'+1][tmp[0]-'A'+1]=true;
            numOfBigger[tmp[0]-'A'+1]++;
            if (findAns==1)
            {
                findAns=topo(m);
                if (findAns == 0)
                {
                    cout<<"Sorted sequence determined after "<<i<<" relations: ";
                    print_ans(m);
                }
                if (findAns==-1)
                {
                    cout<<"Inconsistency found after "<<i<<" relations."<<endl;
                }
            }
        }
        if (findAns==1)
            cout<<"Sorted sequence cannot be determined."<<endl;
        cin>>m>>n;
    }
    return 0;
}
