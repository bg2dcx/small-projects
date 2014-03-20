#include <iostream>

using namespace std;
int maze[41][41];
int dir_move[4][2]={{1,0},{0,-1},{-1,0},{0,1}};
int bfsqueue[1601][2];
int maze_step[41][41];
int width,height,number_of_cases;
int stx,sty,edx,edy;

void initialize()
{
    for (int i=0;i<1601;i++)
    {
        bfsqueue[i][0]=0;
        bfsqueue[i][1]=0;
    }
    for (int i=0;i<41;i++)
        for (int j=0;j<41;j++)
    {
        maze[i][j]=0;
        maze_step[i][j]=0;
    }
}
int main()
{
    cin>>number_of_cases;
    for (int case_number=0;case_number<number_of_cases;case_number++)
    {
        initialize();
        cin>>width>>height;
        for (int x=1;x<=height;x++)
            for (int y=1;y<=width;y++)
        {
            char tmp;
            cin>>tmp;
            if (tmp == '#') maze[x][y]=-1;
            if (tmp == '.') maze[x][y]=1;
            if (tmp == 'S')
            {
                maze[x][y]=1;
                stx=x;
                sty=y;
            }
            if (tmp == 'E')
            {
                maze[x][y]=1;
                edx=x;
                edy=y;
            }
        }
        int traverse_number=1;
        int currentx=stx;
        int currenty=sty;
        int nextx,nexty,nextdir,currentdir,stdir;
        for (int i=0;i<4;i++)
        {
            nextx=currentx+dir_move[i][0];
            nexty=currenty+dir_move[i][1];
            if (  (nextx>0) && (nextx<=height) && (nexty>0) && (nexty<=width) && (maze[nextx][nexty]==1) )
                currentdir=i;
        }
        stdir=currentdir;
        ////left traverse////
        while ( (currentx!=edx) || (currenty!=edy) )
        {
            int direction;
            direction=(currentdir-1+4)%4;
            for (int i=0;i<4;i++)
            {
                nextdir=(direction+i)%4;
                nextx=currentx+dir_move[nextdir][0];
                nexty=currenty+dir_move[nextdir][1];
                if (  (nextx>0) && (nextx<=height) && (nexty>0) && (nexty<=width) && (maze[nextx][nexty]==1) )
                {
                            currentdir=nextdir;
                            currentx=nextx;
                            currenty=nexty;
                            traverse_number++;
                            break;
                }
            }
        }
        int left_result,right_result,shortest_result;
        left_result=traverse_number;
        ////right traverse////
        traverse_number=1;
        currentx=stx;
        currenty=sty;
        currentdir=stdir;
        while ( (currentx!=edx) || (currenty!=edy) )
        {
            int direction;
            direction=(currentdir+1)%4;
            for (int i=0;i<4;i++)
            {
                nextdir=(direction+-i+4)%4;
                nextx=currentx+dir_move[nextdir][0];
                nexty=currenty+dir_move[nextdir][1];
                if (  (nextx>0) && (nextx<=height) && (nexty>0) && (nexty<=width) && (maze[nextx][nexty]==1) )
                {
                            currentdir=nextdir;
                            currentx=nextx;
                            currenty=nexty;
                            traverse_number++;
                            break;
                }
            }
        }
        right_result=traverse_number;
        int head=0;
        int tail=1;
        bfsqueue[head][0]=stx;
        bfsqueue[head][1]=sty;
        maze_step[stx][sty]=1;
        int currentstep;
        while (head<tail)
        {
            currentx=bfsqueue[head][0];
            currenty=bfsqueue[head][1];
            currentstep=maze_step[currentx][currenty];
            for (int i=0;i<4;i++)
            {
                nextx=currentx+dir_move[i][0];
                nexty=currenty+dir_move[i][1];
                if (  (nextx>0) && (nextx<=height) && (nexty>0) && (nexty<=width) && (maze[nextx][nexty]==1) &&
                    ((maze_step[nextx][nexty]==0) || (maze_step[nextx][nexty]>(currentstep+1)))  )
                {
                            bfsqueue[tail][0]=nextx;
                            bfsqueue[tail][1]=nexty;
                            maze_step[nextx][nexty]=currentstep+1;
                            tail++;
                }
            }
            head++;
        }
        shortest_result=maze_step[edx][edy];
        cout<<left_result<<" "<<right_result<<" "<<shortest_result<<endl;
    }
    return 0;
}
