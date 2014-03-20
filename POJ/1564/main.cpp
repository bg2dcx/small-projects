#include <iostream>
#include <algorithm>

using namespace std;

int numbers[20];
bool use[20];
int n,t;
bool findAns;

int cmp(int a, int b)
{
    if (a>b)
        return 1;
    else return 0;
}

void print_ans()
{
    bool first=true;
    for (int i=0;i<n;i++)
        if (use[i])
    {
        if (!first)
        {
            cout<<'+';
        }
        cout<<numbers[i];
        first=false;
    }
    cout<<endl;
}

void dfs(int pos, int num, int sum)
{
    if (sum==t)
    {
        print_ans();
        findAns=true;
        return;
    }
    if (sum>t)
     return;
    int next=pos+1;
    if (next<n)
    {
        if (numbers[next]!=numbers[pos] || (numbers[next]==numbers[pos] && use[pos]))
        {
            use[next]=true;
            dfs(next,num+1,sum+numbers[next]);
            use[next]=false;
        }
        dfs(next,num,sum);
    }
}

int main()
{
    cin>>t>>n;
    while (! (t==0 && n==0))
    {
        for (int i=0;i<n;i++)
            cin>>numbers[i];
        cout<<"Sums of "<<t<<':'<<endl;
        sort(numbers,numbers+n,cmp);
        findAns=false;
        for (int i=0;i<n;i++)
            use[i]=false;
        int current=0;
        while (current<n)
        {
            use[current]=true;
            dfs(current,1,numbers[current]);
            use[current]=false;
            while (current+1<n && numbers[current]==numbers[current+1])
                current++;
            current++;
        }

        if (!findAns)
            cout<<"NONE"<<endl;
        cin>>t>>n;
    }
}
