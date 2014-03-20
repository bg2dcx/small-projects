#include <iostream>

using namespace std;

char grid[10][10];

char best[100];
char current[100];
bool visited[10][10];

int r,c,n;
int bestNum;
int rowInc[6]={1,0,-1,0,-1,1};
int colInc[6]={0,1,0,-1,0,0};
int maxLen[10];
int numBot;
void initialize()
{
    for (int i=0;i<10;i++)
        for (int j=0;j<10;j++)
            grid[i][j]='\0';
    for (int i=0;i<100;i++)
    {
        best[i]='\0';
        current[i]='\0';
    }
    bestNum=0;
}

void dfs(int currentRow, int currentCol, int currentLen, int startPos)
{
    if (currentRow==0 && (currentLen%n)==0 && currentCol>startPos && numBot>0)
    {
        if (currentLen>bestNum)
        {
            for (int i=0;i<currentLen;i++)
                best[i]=current[i];
            bestNum=currentLen;
        }
    }
    int nextRow,nextCol;
    for (int i=0;i<6;i++)
    {
        nextRow=currentRow+rowInc[i];
        nextCol=currentCol+colInc[i];
        if ((currentRow%2)==0 && (i==4 || i==5))
        {
            nextCol=currentCol+1;
        }
        if ((currentRow%2)==1 && (i==4 || i == 5))
        {
            nextCol=currentCol-1;
        }
        if (nextRow>=0 && nextRow<r && nextCol>=0 && nextCol<maxLen[nextRow] && !visited[nextRow][nextCol])
        {
            if (currentLen>=n)
            {
                if (grid[nextRow][nextCol] == current[currentLen-n])
                {
                    if (nextRow==r-1)
                        numBot++;
                    current[currentLen]=grid[nextRow][nextCol];
                    visited[nextRow][nextCol]=true;
                    dfs(nextRow,nextCol,currentLen+1,startPos);
                    visited[nextRow][nextCol]=false;
                    current[currentLen]='\0';
                    if (nextRow==r-1)
                        numBot--;
                }
            } else
            {
                    if (nextRow==r-1)
                        numBot++;
                    current[currentLen]=grid[nextRow][nextCol];
                    visited[nextRow][nextCol]=true;
                    dfs(nextRow,nextCol,currentLen+1,startPos);
                    visited[nextRow][nextCol]=false;
                    current[currentLen]='\0';
                    if (nextRow==r-1)
                        numBot--;
            }
        }
    }
}

int main()
{
    cin>>r;
    while (r != 0)
    {
        cin>>c>>n;
        initialize();
        int length=c;
        for (int i=0;i<r;i++)
        {
            if (i%2 == 0)
             {
                 length=c;
                 maxLen[i]=c;
             }
            else
              {
                  length=c+1;
                  maxLen[i]=c+1;
              }
            for (int j=0;j<length;j++)
                cin>>grid[i][j];
        }
        for (int i=0;i<c-1;i++)
        {
            for (int k=0;k<10;k++)
                for (int kk=0;kk<10;kk++)
                visited[k][kk]=false;
            numBot=0;
            current[0]=grid[0][i];
            visited[0][i]=true;
            dfs(0,i,1,i);
        }
        if (bestNum <= n)
            cout<<"no solution\n";
        else
        {
            for (int i=0;i<bestNum;i++)
                cout<<best[i];
            cout<<endl;
        }
        cin>>r;
    }
}
