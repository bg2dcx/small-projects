#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;
double doorway_ends[20][4];
double doorway_x[20];
double min_dist_to_end[20][4];
double input_y[4];
int number_of_walls;

double dist(double x1,double y1,double x2, double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

double calc_intersec(double stx, double sty, double edx, double edy, double intersecx)
{
    double k=(edy-sty)/(edx-stx);
    return sty+(intersecx-stx)*k;
}

bool block(int stWall,double stEndY,int edWall, double edEndy)
{
    for (int i=stWall+1;i<edWall;i++)
    {
        double intersection=calc_intersec(doorway_x[stWall],stEndY,doorway_x[edWall],edEndy,doorway_x[i]);
        if ( !( ((intersection>=doorway_ends[i][0]) && (intersection<=doorway_ends[i][1])) ||
                 ((intersection>=doorway_ends[i][2]) && (intersection<=doorway_ends[i][3])) ) )
            return true;
    }
    return false;
}

int main()
{
    cin>>number_of_walls;
    ////read walls////
    while (number_of_walls != -1)
    {
        for (int i=1;i<=number_of_walls;i++)
        {
            cin>>doorway_x[i];
            for (int j=0;j<4;j++)
                cin>>input_y[j];
            for (int ii=0;ii<3;ii++)
            {
                int tmpmin=ii;
                for (int jj=ii+1;jj<4;jj++)
                    if (input_y[jj]<input_y[tmpmin]) tmpmin=jj;
                if (tmpmin != ii)
                {
                    double tmpdouble=input_y[ii];
                    input_y[ii]=input_y[tmpmin];
                    input_y[tmpmin]=tmpdouble;
                }
            }
            for (int j=0;j<4;j++)
               doorway_ends[i][j]=input_y[j];
        }
        doorway_x[0]=0;
        doorway_x[number_of_walls+1]=10;
        ////Special cases: no internal wall or no blocking wall////
        if ( !block(0,5,number_of_walls+1,5) )
        {
            cout<<"10.00"<<endl;
            cin>>number_of_walls;
            continue;
        }
        ////find the shortest path to each end of the first doorway////
        for (int i=0;i<4;i++)
            min_dist_to_end[1][i]=dist(0,5,doorway_x[1],doorway_ends[1][i]);
        ////find the shortest path to each end of all doorways 2 to totalnumber////
        for (int i=2;i<=number_of_walls;i++)
        {
            for (int j=0;j<4;j++)
            {
                double mindist=500;
                if (!block(0,5,i,doorway_ends[i][j]))
                {
                    min_dist_to_end[i][j]=dist(0,5,doorway_x[i],doorway_ends[i][j]);
                    continue;
                }
                for (int k=1;k<i;k++)
                {
                    for (int k_end=0;k_end<4;k_end++)
                    {
                        if ( !block(k,doorway_ends[k][k_end],i,doorway_ends[i][j]) )
                        {
                           double  tmp=dist(doorway_x[k],doorway_ends[k][k_end],doorway_x[i],doorway_ends[i][j])+min_dist_to_end[k][k_end];
                           if (tmp<mindist) mindist=tmp;
                        }
                    }
                }
                min_dist_to_end[i][j]=mindist;
            }
        }
        ////find the shortest path to the exit////
        double mindist=500;
        for (int k=1;k<=number_of_walls;k++)
        {
            for (int k_end=0;k_end<4;k_end++)
            {
                if ( !block(k,doorway_ends[k][k_end],number_of_walls+1,5) )
                {
                    double tmp=dist(doorway_x[k],doorway_ends[k][k_end],10,5)+min_dist_to_end[k][k_end];
                    if (tmp<mindist) mindist=tmp;
                }
            }
        }
        cout<<setprecision(2)<<fixed<<mindist<<endl;
        cin>>number_of_walls;
    }
    return 0;
}
