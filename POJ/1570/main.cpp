#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
ifstream fin("1.txt");
struct ITEM
{
    char name[30];
};

struct EXRATE
{
    int num1,num2;
};

int len,numOfItems;
ITEM items[100];

EXRATE rate[100][100];
bool searched[100];

int create_number(char cc[])
{
    int len=strlen(cc);
    int number=0;
    for (int i=0;i<len;i++)
        number=number*10+(cc[i]-'0');
    return number;
}

bool similar(ITEM a, char cc[])
{
    int len=strlen(a.name);
    if (len != strlen(cc))
        return false;
    for (int i=0;i<len;i++)
        if (a.name[i] != cc[i])
        return false;
    return true;
}

int find_item(char tmp[])
{
    int itemNum=-1;
    for (int i=0;i<numOfItems;i++)
        if (similar(items[i],tmp))
    {
            itemNum=i;
            break;
    }
    if (itemNum==-1)
    {
        for (int i=0;i<30;i++)
            items[numOfItems].name[i]=tmp[i];
        itemNum=numOfItems;
        numOfItems++;
    }
    return itemNum;
}

int gcd(int a, int b)
{
    int tmp;
    while (b != 0)
    {
        tmp=a;
        a=b;
        b=tmp%b;
    }
    return a;
}

void bfs(int item1,int item2)
{
    int bfsqueue[101];
    memset(searched,0,sizeof(searched));
    int head=0;
    int tail=1;
    bfsqueue[head]=item1;
    while (head<tail)
    {
        int current=bfsqueue[head];
        searched[current]=true;
        for (int i=0;i<numOfItems;i++)
            if (!searched[i] && rate[current][i].num1 != -1)
        {
            int a=rate[item1][current].num1;
            int b=rate[item1][current].num2;
            int c=rate[current][i].num1;
            int d=rate[current][i].num2;
            bfsqueue[tail]=i;
            tail++;
            if (rate[item1][i].num1 == -1)
            {
                int tmp=gcd(a*c,b*d);
                rate[item1][i].num1=a*c/tmp;
                rate[item1][i].num2=b*d/tmp;
                rate[i][item1].num1=b*d/tmp;
                rate[i][item1].num2=a*c/tmp;
            }
        }
        head++;
    }
}

void solve(int item1, int item2)
{
    if (rate[item1][item2].num1 != -1)
    {
        int num1=rate[item1][item2].num1;
        int num2=rate[item1][item2].num2;
        int c=gcd(num1,num2);
        cout<<num1/c<<" "<<items[item1].name<<" = "<<num2/c<<' '<<items[item2].name<<endl;
        return;
    }

    bfs(item1,item2);
    if (rate[item1][item2].num1 != -1)
    {
        int num1=rate[item1][item2].num1;
        int num2=rate[item1][item2].num2;
        int c=gcd(num1,num2);
        cout<<num1/c<<" "<<items[item1].name<<" = "<<num2/c<<' '<<items[item2].name<<endl;
        return;
    }
    cout<<"? "<<items[item1].name<<" = ? "<<items[item2].name<<endl;
}

int main()
{
    char tmp[30];
    fin>>tmp;
    numOfItems=0;
    for (int i=0;i<100;i++)
        for (int j=0;j<100;j++)
    {
        rate[i][j].num1=-1;
        rate[i][j].num2=-1;
        if (i == j)
        {
            rate[i][j].num1=1;
            rate[i][j].num2=1;
        }
    }
    while (tmp[0] != '.')
    {
        if (tmp[0]=='!')
        {
            fin>>tmp;
            int num1=create_number(tmp);
            fin>>tmp;
            int item1=find_item(tmp);
            fin>>tmp;
            fin>>tmp;
            int num2=create_number(tmp);
            fin>>tmp;
            int item2=find_item(tmp);
            rate[item1][item2].num1=num1;
            rate[item1][item2].num2=num2;
            rate[item2][item1].num1=num2;
            rate[item2][item1].num2=num1;
            fin>>tmp;
            continue;
        }
        if (tmp[0] == '?')
        {
            fin>>tmp;
            int item1=find_item(tmp);
            fin>>tmp;
            fin>>tmp;
            int item2=find_item(tmp);
            if (item1==-1 || item2==-1)
            {
                cout<<"? "<<items[item1].name<<" = ? "<<items[item2].name<<endl;
                fin>>tmp;
                continue;
            }
            solve(item1,item2);
            fin>>tmp;
            continue;
        }
    }
    return 0;
}
