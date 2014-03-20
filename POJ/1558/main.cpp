#include <iostream>

using namespace std;
char c;
int row[8],column[8],diagonal1[15],diagonal2[15];
int board[8][8];
int ans[8][2];
int piece_type;

void initialize()
{
    for (int i=0;i<8;i++)
    {
        for (int j=0;j<8;j++)
        {
            board[i][j]=0;
            diagonal1[i+j]=0;
            diagonal2[7-i+j]=0;
        }
        row[i]=0;
        column[i]=0;
    }
}

bool not_horizon_block(int row, int stcol, int edcol)
{
    int inc=1;
    if (edcol<stcol) inc=-1;
    int current=stcol;
    while (current!=edcol)
    {
        if (board[row][current]==-piece_type) return false;
        current+=inc;
    }
    return true;
}

bool not_vertical_block(int col, int strow, int edrow)
{
    int inc=1;
    if (edrow<strow) inc=-1;
    int current=strow;
    while (current!=edrow)
    {
        if (board[current][col]==-piece_type) return false;
        current+=inc;
    }
    return true;
}

bool not_diagonal_block(int strow,int stcol, int edrow, int edcol)
{
    int rowinc=1;
    int colinc=1;
    if (edrow<strow) rowinc=-1;
    if (edcol<stcol) colinc=-1;
    int currentcol=stcol;
    int currentrow=strow;
    while (currentrow!=edrow)
    {
        if (board[currentrow][currentcol]==-piece_type) return false;
        currentrow+=rowinc;
        currentcol+=colinc;
    }
    return true;
}

int main()
{
    while (cin>>c)
    {
        initialize();
        for (int i=0;i<8;i++)
            for (int j=0;j<8;j++)
            {
                char tmp;
                if (i==0 && j==0) tmp=c;
                 else cin>>tmp;
                switch (tmp)
                 {
                    case 'O':row[i]++;
                             column[j]++;
                             diagonal1[i+j]++;
                             diagonal2[7-i+j]++;
                             board[i][j]=1;
                             break;
                    case 'X':row[i]++;
                             column[j]++;
                             diagonal1[i+j]++;
                             diagonal2[7-i+j]++;
                             board[i][j]=-1;
                             break;
                    case '.':board[i][j]=0;
                             break;
                 }
            }
        cin>>c;
        if (c=='X') piece_type=-1; else piece_type=1;
        int ans_num=0;
        bool find_ans=false;
        ////check each piece
        for (int i=0;i<8;i++)
            for (int j=0;j<8;j++)
                if (board[i][j]==piece_type)
        {
            ans_num=0;
            ////horizon
            if (j-row[i]>=0)
                if (board[i][j-row[i]]!=piece_type && not_horizon_block(i,j,j-row[i]))
            {
                ans[ans_num][0]=i;
                ans[ans_num][1]=j-row[i];
                ans_num++;
            }
            if (j+row[i]<8)
                if (board[i][j+row[i]]!=piece_type && not_horizon_block(i,j,j+row[i]))
            {
                ans[ans_num][0]=i;
                ans[ans_num][1]=j+row[i];
                ans_num++;
            }
            ////vertical
            if (i-column[j]>=0)
                if (board[i-column[j]][j]!=piece_type && not_vertical_block(j,i,i-column[j]))
            {
                ans[ans_num][0]=i-column[j];
                ans[ans_num][1]=j;
                ans_num++;
            }
            if (i+column[j]<8)
                if (board[i+column[j]][j]!=piece_type && not_vertical_block(j,i,i+column[j]))
            {
                ans[ans_num][0]=i+column[j];
                ans[ans_num][1]=j;
                ans_num++;
            }
            ////diagonal
            if ( (i-diagonal2[7-i+j]>=0) && (j-diagonal2[7-i+j]>=0) )
                if (board[i-diagonal2[7-i+j]][j-diagonal2[7-i+j]] != piece_type && not_diagonal_block(i,j,i-diagonal2[7-i+j],j-diagonal2[7-i+j]) )
            {
                ans[ans_num][0]=i-diagonal2[7-i+j];
                ans[ans_num][1]=j-diagonal2[7-i+j];
                ans_num++;
            }
            if ( (i+diagonal2[7-i+j]<8) && (j+diagonal2[7-i+j]<8) )
                if (board[i+diagonal2[7-i+j]][j+diagonal2[7-i+j]] != piece_type && not_diagonal_block(i,j,i+diagonal2[7-i+j],j+diagonal2[7-i+j]) )
            {
                ans[ans_num][0]=i+diagonal2[7-i+j];
                ans[ans_num][1]=j+diagonal2[7-i+j];
                ans_num++;
            }
            if ( (i-diagonal1[i+j]>=0) && (j+diagonal1[i+j]<8))
                if (board[i-diagonal1[i+j]][j+diagonal1[i+j]] != piece_type && not_diagonal_block(i,j,i-diagonal1[i+j],j+diagonal1[i+j]))
            {
                ans[ans_num][0]=i-diagonal1[i+j];
                ans[ans_num][1]=j+diagonal1[i+j];
                ans_num++;
            }
            if ( (i+diagonal1[i+j]<8) && (j-diagonal1[i+j]>=0))
                if (board[i+diagonal1[i+j]][j-diagonal1[i+j]] != piece_type && not_diagonal_block(i,j,i+diagonal1[i+j],j-diagonal1[i+j]))
            {
                ans[ans_num][0]=i+diagonal1[i+j];
                ans[ans_num][1]=j-diagonal1[i+j];
                ans_num++;
            }
            if (ans_num>0) find_ans=true; else continue;
            ////sort
            for (int ii=0;ii<ans_num;ii++)
            {
                int minans=ii;
                for (int jj=ii+1;jj<ans_num;jj++)
                    if ((ans[jj][0] < ans[minans][0]) || ( ans[jj][0]==ans[minans][0] && ans[jj][1]<ans[minans][1] ) )
                        minans=jj;
                int tmp[2];
                tmp[0]=ans[ii][0];
                tmp[1]=ans[ii][1];
                ans[ii][0]=ans[minans][0];
                ans[ii][1]=ans[minans][1];
                ans[minans][0]=tmp[0];
                ans[minans][1]=tmp[1];
            }
            ////output
            for (int ii=0;ii<ans_num;ii++)
            {
                char tmp;
                tmp=i+'A';
                cout<<tmp<<j+1<<'-';
                tmp=ans[ii][0]+'A';
                cout<<tmp<<ans[ii][1]+1<<endl;
            }
        }

        if (!find_ans) cout<<"No moves are possible"<<endl;
        cout<<endl;
    }
}
