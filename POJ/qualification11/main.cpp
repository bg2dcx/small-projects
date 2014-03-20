#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

char busMap[90][90];
char tmp[90];
int visited[90][90];
int column,row;
int numOfIslands;
int numOfBridges;
int numOfCars;
int numOfCases;
int incx[4]={1,0,-1,0};
int incy[4]={0,1,0,-1};

void insert_map(int rowNum)
{
    for (int i=0;i<column;i++)
        busMap[rowNum][i]=tmp[i];
    busMap[rowNum][column]='\0';
}

void dfs1(int x, int y, int flag)
{
    visited[x][y]=flag;
    for (int i=0;i<4;i++)
    {
        int ntx=x+incx[i];
        int nty=y+incy[i];
        if ( ntx>=0 && ntx<row && nty>=0 && nty<column &&
            (busMap[ntx][nty] == 'X' || busMap[ntx][nty]=='#') && visited[ntx][nty] == 0)
            dfs1(ntx,nty,flag);
    }
}

void dfs2(int x, int y, int flag, int direction)
{
    visited[x][y]=flag;
    int ntx,nty;
    if (busMap[x][y] == '#' || busMap[x][y] == 'X')
    {
        for (int i=0;i<4;i++)
        {
            ntx=x+incx[i];
            nty=y+incy[i];
            if ( ntx>=0 && ntx<row && nty>=0 && nty<column &&
                (busMap[ntx][nty] == 'X' || busMap[ntx][nty]=='#' || busMap[ntx][nty] == 'B') && visited[ntx][nty] == 0)
                dfs2(ntx,nty,flag,i);
        }
    } else
    {
        ntx=x+incx[direction];
        nty=y+incy[direction];
        dfs2(ntx,nty,flag,direction);
    }

}

int main()
{
    FILE *fp;
    fp=fopen("1.txt","r");
    tmp[0]='\0';
    numOfCases=0;
    while (fscanf(fp,"%[^\n]",tmp) != EOF)
    {
        fscanf(fp,"%*c");
        column=strlen(tmp);
        row=0;
        insert_map(0);
        row++;
        tmp[0]='\0';
        while (fscanf(fp,"%[^\n]",tmp) != EOF && tmp[0]!='\0')
        {
            fscanf(fp,"%*c");
            insert_map(row);
            row++;
            tmp[0]='\0';
        }
        fscanf(fp,"%*c");
        memset(visited,0,sizeof(visited));
        numOfIslands=0;
        for (int i=0;i<row;i++)
            for (int j=0;j<column;j++)
            if ( (busMap[i][j] == 'X' || busMap[i][j]=='#') && visited[i][j] == 0)
        {
            numOfIslands++;
            dfs1(i,j,numOfIslands);
        }
        numOfBridges=0;
        memset(visited,0,sizeof(visited));
        for (int i=0;i<row;i++)
            for (int j=0;j<column;j++)
              if (busMap[i][j] == 'X')
        {
            for (int k=0;k<4;k++)
            {
                int ntx=i+incx[k];
                int nty=j+incy[k];
                if ( ntx>=0 && ntx<row && nty>=0 && nty<column && busMap[ntx][nty] == 'B' && visited[ntx][nty]==0)
                {
                    numOfBridges++;
                    visited[ntx][nty]=numOfBridges;
                    while (busMap[ntx][nty] != 'X')
                    {
                        visited[ntx][nty]=numOfBridges;
                        ntx=ntx+incx[k];
                        nty=nty+incy[k];
                    }
                }
            }
        }
        memset(visited,0,sizeof(visited));
        numOfCars=0;
        for (int i=0;i<row;i++)
            for (int j=0;j<column;j++)
            if ( (busMap[i][j] == 'X' || busMap[i][j]=='#') && visited[i][j] == 0)
        {
            numOfCars++;
            dfs2(i,j,numOfCars,0);
        }
        numOfCases++;
        cout<<"Map "<<numOfCases<<endl;
        cout<<"islands: "<<numOfIslands<<endl;
        cout<<"bridges: "<<numOfBridges<<endl;
        cout<<"buses needed: "<<numOfCars<<endl;
        cout<<endl;
    }
    return 0;
}
