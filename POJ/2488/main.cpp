#include <iostream>

using namespace std;
int number_of_cases;
int x_length,y_length;
int move_x[8]={-2,-2,-1,-1,1,1,2,2};
int move_y[8]={-1,1,-2,2,-2,2,-1,1};
int chessboard[15][15];
int move_order[27][2];
int square_number;

void initialize_board()
{
    for (int i=0;i<15;i++)
        for (int j=0;j<15;j++)
            chessboard[i][j]=-1;
    for (int i=0;i<27;i++)
    {
        move_order[i][0]=-1;
        move_order[i][1]=-1;
    }
}
void print_result(int square_number,int case_number)
{
    cout<<"Scenario #"<<case_number<<':'<<endl;
    for (int i=1;i<=square_number;i++)
    {
        char tmp='A'+move_order[i][0]-1;
        cout<<tmp<<move_order[i][1];
    }
    cout<<endl;
    cout<<endl;
}
bool search_board(int step, int currentx, int currenty)
{
    bool find_result=false;
    if (step == square_number) return true;
    for (int direction=0;direction<8;direction++)
        if ( (currentx+move_x[direction]>0) && (currentx+move_x[direction]<=x_length) && (currenty+move_y[direction]>0)
            && (currenty+move_y[direction]<=y_length) )
        {
            int next_x=currentx+move_x[direction];
            int next_y=currenty+move_y[direction];
            if (chessboard[next_x][next_y]==-1)
            {
                chessboard[next_x][next_y]=step+1;
                move_order[step+1][0]=next_x;
                move_order[step+1][1]=next_y;
                find_result=search_board(step+1,next_x,next_y);
                if (!find_result)
                {
                    chessboard[next_x][next_y]=-1;
                    move_order[step+1][0]=-1;
                    move_order[step+1][1]=-1;
                }
                  else return true;
            }
        }
    return false;
}
int main()
{
    cin>>number_of_cases;
    for (int case_number=1;case_number<=number_of_cases;case_number++)
    {
        cin>>y_length>>x_length;
        square_number=y_length*x_length;
        initialize_board();
        bool find_result=false;
        for (int x=1;x<=(x_length/2+1);x++)
        {
            for (int y=1;y<=(y_length/2+1);y++)
            {
                chessboard[x][y]=1;
                move_order[1][0]=x;
                move_order[1][1]=y;
                find_result=search_board(1,x,y);
                if (find_result) break;
            }
            if (find_result) break;
        }
        if (find_result) print_result(square_number,case_number);
         else
         {
             cout<<"Scenario #"<<case_number<<':'<<endl;
             cout<<"impossible"<<endl;
             cout<<endl;
         }
    }
    return 0;
}
