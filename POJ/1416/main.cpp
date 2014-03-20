#include <iostream>

using namespace std;

bool isShredded[5],maxshred[5];
int maxNum; int numOfMax;
int GoalNum,stNum,stNumlen;
int number[7];

void seperate_num(int n)
{
    for (int i=0;i<7;i++)
        number[i]=0;
    stNumlen=0;
    int tmp[7];
    while (n>0)
    {
        stNumlen++;
        tmp[stNumlen]=n%10;
        n=n/10;
    }
    for (int i=1;i<=stNumlen;i++)
        number[i]=tmp[stNumlen+1-i];
}

int calc()
{
    int sum=0;
    int tmp=number[1];
    for (int i=1;i<stNumlen;i++)
    {
        if (isShredded[i])
        {
            sum=sum+tmp;
            tmp=number[i+1];
        } else
         tmp=tmp*10+number[i+1];
    }
    sum=sum+tmp;
    return sum;
}

void dfs(int numpos)
{
    if (numpos==stNumlen)
    {
        int tmp=calc();
        if (tmp>maxNum && tmp<=GoalNum)
        {
            maxNum=tmp;
            for (int i=1;i<=stNumlen;i++)
                maxshred[i]=isShredded[i];
            numOfMax=1;
        } else if (tmp==maxNum)
        {
            numOfMax++;
        }
    } else {
        isShredded[numpos]=true;
        dfs(numpos+1);
        isShredded[numpos]=false;
        dfs(numpos+1);
    }
}

int main()
{
    cin>>GoalNum>>stNum;
    while ( !(GoalNum==0 && stNum==0))
    {
        maxNum=0;numOfMax=0;
        if (GoalNum==stNum)
        {
            cout<<GoalNum<<' '<<GoalNum<<endl;
            cin>>GoalNum>>stNum;
            continue;
        }
        seperate_num(stNum);
        dfs(1);
        if (numOfMax>1){
            cout<<"rejected"<<endl;
            cin>>GoalNum>>stNum;
            continue;
        } else
        if (numOfMax==0)
        {
            cout<<"error"<<endl;
            cin>>GoalNum>>stNum;
        } else
        {
            cout<<maxNum<<' ';
            for (int i=1;i<stNumlen;i++)
            {
                cout<<number[i];
                if (maxshred[i]) cout<<' ';
            }
            cout<<number[stNumlen]<<endl;
            cin>>GoalNum>>stNum;
        }
    }
    return 0;
}
