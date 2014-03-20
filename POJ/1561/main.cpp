#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//ifstream fin("BEAR.IN");


int dimention, height,width,numOfPieces;
string pieces[101][26];
int tag[101][4];
int board[11][11];
bool inUse[101];
bool dfs(int posx, int posy)
{
    bool findAns=false;
    for (int i=0;i<numOfPieces;i++)
        if (!inUse[i])
    {
        bool suitable=true;
        if (posx != 0)
        {
             if (tag[i][1]+tag[board[posx-1][posy]][3] != 0)
                suitable=false;
             if (posx == dimention-1)
                if (tag[i][3] !=0)
                    suitable=false;
        } else if (tag[i][1] != 0) suitable=false;

        if (posy != 0)
        {
            if (tag[i][0]+tag[board[posx][posy-1]][2] != 0)
                suitable=false;
            if (posy==dimention-1)
                if (tag[i][2] != 0)
                    suitable=false;
        } else if (tag[i][0] !=0 ) suitable=false;

        if (suitable)
        {
            board[posx][posy]=i;
            inUse[i]=true;
            if (posx==dimention-1 && posy==dimention-1)
                return true;
            int nextx=posx+1;
            int nexty=posy;
            if (nextx==dimention)
            {
                nextx=0;
                nexty++;
            }
            findAns=dfs(nextx,nexty);
            if (findAns) return true;
            inUse[i]=false;
            board[posx][posy]=-1;
        }
    }
    return false;
}
int main()
{
    cin>>dimention>>height>>width;
    for (int i=0;i<dimention;i++)
        for (int j=0;j<dimention;j++)
            board[i][j]=-1;
    for (int i=0;i<101;i++)
        inUse[i]=false;
    string tmp;
    getline(cin,tmp);
    numOfPieces=dimention*dimention;
    for (int i=0;i<numOfPieces;i++)
    {
        for (int j=0;j<height;j++)
            {
                getline(cin,pieces[i][j]);
                //cout<<pieces[i][j]<<endl;
            }
        for (int j=0;j<4;j++)
            cin>>tag[i][j];
        getline(cin,tmp);
        getline(cin,tmp);
    }
    bool findAns=false;
    findAns=dfs(0,0);
    /*
    for (int i=0;i<dimention;i++)
    {
        for (int j=0;j<dimention;j++)
            cout<<board[j][i]<<' ';
        cout<<endl;
    }
    */
    for (int i=0;i<dimention;i++)
    {
        for (int h=0;h<height;h++)
        {
            for (int j=0;j<dimention;j++)
            {
                for (int k=0;k<width;k++)
                    cout<<pieces[board[j][i]][h][k];
            }
            cout<<endl;
        }
    }

    return 0;
}
