#include <iostream>

using namespace std;
int board[8][8];
bool row[8],column[8];
int n,k;
int result;

void initialize()
{
    result=0;
    for (int i=0;i<8;i++)
    {
        for (int j=0;j<8;j++)
        {
            board[i][j]=-1;
        }
        row[i]=false;
        column[i]=false;
    }
}

int board_search(int step,int stx)
{
    if (step>k)
        return 1;
    int result=0;
    int nextx=stx+1;
    if (nextx>=n) return 0;
    for (int i=nextx;i<n;i++)
        if (row[i])
        for (int j=0;j<n;j++)
         if (column[j] && board[i][j]==0)
    {
        board[i][j]=step;
        row[i]=false;
        column[j]=false;
        result+=board_search(step+1,i);
        board[i][j]=0;
        row[i]=true;
        column[j]=true;
    }
    return result;

}
int main()
{
    cin>>n>>k;
    while ( ! (n==-1 && k==-1))
    {
        initialize();
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
        {
            char tmp;
            cin>>tmp;
            if (tmp=='#')
            {
                board[i][j]=0;
                row[i]=true;
                column[j]=true;
            }
            if (tmp=='.')
                board[i][j]=-1;
        }
        for (int i=0;i<n;i++)
            if (row[i])
            for (int j=0;j<n;j++)
                if (column[j] && board[i][j]==0)
        {
            board[i][j]=1;
            row[i]=false;
            column[j]=false;
            result+=board_search(2,i);
            board[i][j]=0;
            row[i]=true;
            column[j]=true;
        }
        cout<<result<<endl;
        cin>>n>>k;
    }

    return 0;
}
