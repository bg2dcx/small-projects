#include <iostream>

using namespace std;
bool isPrime[10001];
int bfsqueue[20001];
int dist[10000];
int caseNumber,stNumber,edNumber,head,tail;

void getPrimes()
{
    int st=2;
    for (int i=3;i<100001;i++)
        isPrime[i]=true;
    isPrime[1]=false;
    isPrime[2]=true;
    isPrime[0]=false;
    int current=st;
    while (st<5000)
    {
        current=st*2;
        while (current<=10000)
        {
            isPrime[current]=false;
            current+=st;
        }
        st++;
        while (st<5000 && !isPrime[st])
            st++;
    }
}

void initialize()
{
    head=0;tail=0;
    for (int i=0;i<10000;i++)
        dist[i]=20000;
    for (int i=0;i<20000;i++)
        bfsqueue[i]=0;
}

int createNum(int oldNum,int newdigit,int position)
{
    int tmp=1;
    for (int i=1;i<=position;i++)
        tmp=tmp*10;
    int tmp2=tmp/10;
    return oldNum/tmp*tmp+newdigit*tmp2+oldNum%tmp2;
}
int main()
{
    getPrimes();
    cin>>caseNumber;
    for (int cases=0;cases<caseNumber;cases++)
    {
        initialize();
        cin>>stNumber>>edNumber;
        dist[stNumber]=0;
        bfsqueue[tail]=stNumber;
        tail++;
        while (head<tail)
        {
            int current=bfsqueue[head];
            if (current == edNumber)
            {
                cout<<dist[current]<<endl;
                break;
            }
            for (int newNum=0;newNum<10;newNum++)
                for (int pos=1;pos<5;pos++)
            {
                int tmp=createNum(current,newNum,pos);
                if (isPrime[tmp] && tmp>1000)
                   if (dist[tmp]>dist[current]+1)
                {
                    bfsqueue[tail]=tmp;
                    dist[tmp]=dist[current]+1;
                    tail++;
                }
            }
            head++;
        }
    }
    return 0;

}
