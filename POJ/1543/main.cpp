#include <iostream>
#include <math.h>

using namespace std;
int cube[101];
int result_table[100][4];
int number=0;
int main()
{
    ////////Initiate////
    for (int i=0;i<101;i++)
        cube[i]=i*i*i;
    int cube_b_maximum,cube_c_maximum;
    int a,b,c,d,cube_d;
    double exponent3= 1.0/3;
    for (a=6;a<=100;a++)
    {
        cube_b_maximum=cube[a]/3;
        b=2;
        for (b;cube[b]<cube_b_maximum;b++)
        {
            cube_c_maximum=(cube[a]-cube[b])/2;
            c=b+1;
            for (c;cube[c]<cube_c_maximum;c++)
            {
                cube_d=cube[a]-cube[b]-cube[c];
                if (cube_d<=cube[c]) continue;
                double k=pow((double)cube_d,exponent3);
                d=(int)k;
                if ((d*d*d == cube_d) && d>1)
                {
                    result_table[number][0]=a;
                    result_table[number][1]=b;
                    result_table[number][2]=c;
                    result_table[number][3]=d;
                    number++;
                } else
                   if ( (d+1)*(d+1)*(d+1) == cube_d  )
                {
                    result_table[number][0]=a;
                    result_table[number][1]=b;
                    result_table[number][2]=c;
                    result_table[number][3]=d+1;
                    number++;
                }
            }
        }

    }
    int N,maxn;
    cin>>N;
    maxn=0;
    while ((result_table[maxn][0]<=N) && (maxn<number)) maxn++;

    for (int i=0;i<maxn;i++)
        cout<<"Cube = "<<result_table[i][0]<<", Triple = ("<<result_table[i][1]<<","<<result_table[i][2]<<","<<result_table[i][3]<<")"<<endl;
    return 0;
}
