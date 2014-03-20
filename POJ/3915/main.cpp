#include <iostream>
#include <memory.h>
#include <fstream>
#define INF 1000

using namespace std;

ifstream fin("1.txt");

struct DATA
{
    int own,disown1,disown2;
};

struct QUERY
{
    int person,numOfOwned;
    char cards[4];
};

DATA status[19];
int numOfQueries,qMax;
char ownedCards[4][6];
QUERY queries[20];
int mini,ans;
int known,unknown1,unknown2;
bool findAns;

void init(int number)
{
    for (int i=1;i<=18;i++)
    {
        status[i].own=-1;
        status[i].disown1=-1;
        status[i].disown2=-1;
    }
    for (int i=0;i<5;i++)
    {
        status[ownedCards[number][i]-'A'+1].own=number;
        status[ownedCards[number][i]-'A'+1].disown1=unknown1;
        status[ownedCards[number][i]-'A'+1].disown2=unknown2;
    }
}

bool isOk(DATA aStatus, int person, bool owned)
{
    if (owned)
    {
        if (aStatus.disown1==person || aStatus.disown2==person || (aStatus.own != -1 && aStatus.own!=person))
            return false;
    }
    else
    {
        if (aStatus.own==person || (aStatus.disown1 != -1 && aStatus.disown1 != person && aStatus.disown2!=-1 && aStatus.disown2 != person))
            return false;
    }
    return true;
}

void change(int statusNum, int person,bool owned)
{
    if (owned)
    {
            status[statusNum].own=person;
            int theOther=unknown1;
            if (theOther == person)
                theOther=unknown2;
            status[statusNum].disown1=theOther;
            status[statusNum].disown2=0;
    } else
    {
            if (status[statusNum].disown1 == -1)
                status[statusNum].disown1=person;
            else
            {
                if (status[statusNum].disown2 == -1)
                    status[statusNum].disown2=person;
            }
            if (status[statusNum].own == -1 && status[statusNum].disown1 != -1 && status[statusNum].disown2 != -1)
            {
                for (int i=0;i<4;i++)
                    if (i != known && i !=status[statusNum].disown1 && i != status[statusNum].disown2)
                     status[statusNum].own=i;
            }
    }
}

int check()
{
    int sum=0;
    for (int i=1;i<19;i++)
        if (status[i].own == 0)
        sum++;
    return sum;
}

void solve(int qNum, int qUsed,int numKnown)
{
    if (qNum>qMax)
    {
        int nums[4];
        nums[1]=nums[0]=nums[2]=nums[3]=0;
        for (int i=1;i<=18;i++)
        if (status[i].own != -1)
            nums[status[i].own]++;
        if (nums[0]>3 || nums[1]>5 || nums[2]>5 ||nums[3]>5)
            findAns=false;
        if (! (nums[0] == 3 || nums[1]+nums[2]+nums[3]==15))
            findAns=false;
        for (int i=0;i<3;i++)
            if (status[ownedCards[0][i]-'A'+1].own ==1 || status[ownedCards[0][i]-'A'+1].own ==2 ||status[ownedCards[0][i]-'A'+1].own ==3)
              findAns=false;
        return;
    }
    int nums[4];
    nums[1]=nums[0]=nums[2]=nums[3]=0;
    for (int i=1;i<=18;i++)
        if (status[i].own != -1)
            nums[status[i].own]++;
    if (nums[0]>3 || nums[1]>5 || nums[2]>5 ||nums[3]>5)
        return;
    if (queries[qNum].person == known)
    {
        solve(qNum+1,qUsed,numKnown);
        return;
    }
    QUERY curr=queries[qNum];
    DATA tmpStatus[19];
    if (curr.numOfOwned == 3)
    {
        for (int i=0;i<3;i++)
        {
            int tmp=curr.cards[i]-'A'+1;
            if (!isOk(status[tmp],curr.person,true))
                return;
        }
        for (int i=1;i<=18;i++)
            tmpStatus[i]=status[i];
        for (int i=0;i<3;i++)
        {
            int tmp=curr.cards[i]-'A'+1;
            change(tmp,curr.person,true);
        }
        int number=check();             //need to implement it
        if (numKnown == 3)
            solve(qNum+1,qUsed,3);
        else
            solve(qNum+1,qNum,number);
        for (int i=1;i<=18;i++)
            status[i]=tmpStatus[i];
    }
    if (curr.numOfOwned == 0)
    {
        for (int i=0;i<3;i++)
        {
            int tmp=curr.cards[i]-'A'+1;
            if (!isOk(status[tmp],curr.person,false))
                return;
        }
        for (int i=1;i<=18;i++)
            tmpStatus[i]=status[i];
        for (int i=0;i<3;i++)
        {
            int tmp=curr.cards[i]-'A'+1;
            change(tmp,curr.person,false);
        }
        int number=check();             //need to implement it
        if (numKnown == 3)
            solve(qNum+1,qUsed,3);     // need change . ,may get 0 before the others
        else
            solve(qNum+1,qNum,number);
        for (int i=1;i<=18;i++)
            status[i]=tmpStatus[i];
    }
    if (curr.numOfOwned == 1)
    {
        for (int k=0;k<3;k++)
        {
            bool OK=true;
            for (int i=0;i<3;i++)
            {
                int tmp=curr.cards[i]-'A'+1;
                if (i == k)
                {
                    if (!isOk(status[tmp],curr.person,true))
                        OK=false;
                } else
                {
                    if (!isOk(status[tmp],curr.person,false))
                        OK=false;
                }
            }
            if (!OK)
                continue;
            for (int i=1;i<=18;i++)
                tmpStatus[i]=status[i];
            for (int i=0;i<3;i++)
            {
                int tmp=curr.cards[i]-'A'+1;
                if (i == k)
                    change(tmp,curr.person,true);
                 else
                    change(tmp,curr.person,false);
            }
            int number=check();             //need to implement it
            if (numKnown == 3)
                solve(qNum+1,qUsed,3);
            else
                solve(qNum+1,qNum,number);
            for (int i=1;i<=18;i++)
                status[i]=tmpStatus[i];
        }
    }
    if (curr.numOfOwned == 2)
    {
        for (int k=0;k<3;k++)
        {
            bool OK=true;
            for (int i=0;i<3;i++)
            {
                int tmp=curr.cards[i]-'A'+1;
                if (i == k)
                {
                    if (!isOk(status[tmp],curr.person,false))
                        OK=false;
                } else
                {
                    if (!isOk(status[tmp],curr.person,true))
                        OK=false;
                }
            }
            if (!OK)
                continue;
            for (int i=1;i<=18;i++)
                tmpStatus[i]=status[i];
            for (int i=0;i<3;i++)
            {
                int tmp=curr.cards[i]-'A'+1;
                if (i == k)
                    change(tmp,curr.person,false);
                 else
                    change(tmp,curr.person,true);
            }
            int number=check();             //need to implement it
            if (numKnown == 3)
                solve(qNum+1,qUsed,3);
            else
                solve(qNum+1,qNum,number);
            for (int i=1;i<=18;i++)
                status[i]=tmpStatus[i];
        }
    }
}

int main()
{
    fin>>numOfQueries;
    while (numOfQueries != 0)
    {
        for (int i=1;i<=3;i++)
            fin>>ownedCards[i];
        fin>>ownedCards[0];
        for (int i=1;i<=numOfQueries;i++)
        {
            fin>>queries[i].person>>queries[i].cards>>queries[i].numOfOwned;
        }
        ans=INF;
        int l=1, r= numOfQueries;
        while (l<=r)
        {
            findAns=true;
            qMax=(l+r)>>1;
            mini=0;
            known=1;
            unknown1=2;
            unknown2=3;
            init(1);
            solve(1,0,5);
            if (findAns)
            {
                if (qMax<ans)
                    ans=qMax;
                r=qMax-1;
            } else
            {
                l=qMax+1;
            }
        }
      l=1;
      r=numOfQueries;
      while (l<=r)
      {
            findAns=true;
            qMax=(l+r)>>1;
            known=2;
            unknown1=1;
            unknown2=3;
            init(2);
            solve(1,0,5);
            if (findAns)
            {
                if (qMax<ans)
                    ans=qMax;
                r=qMax-1;
            } else
            {
                l=qMax+1;
            }
      }
      l=1;
      r=numOfQueries;
      while (l<=r)
      {
            findAns=true;
            qMax=(l+r)>>1;
            known=3;
            unknown1=1;
            unknown2=2;
            init(3);
            solve(1,0,5);
            if (findAns)
            {
                if (qMax<ans)
                    ans=qMax;
                r=qMax-1;
            } else
            {
                l=qMax+1;
            }
      }
      if (ans == INF)
            cout<<"?"<<endl;
      else cout<<ans<<endl;
      fin>>numOfQueries;
    }
    return 0;
}
