#include <iostream>

using namespace std;

int data[2][6];
long amount=-1;



int countIntersection(int firstCube, int secondCube){
    int point[3],l[3];

    for (int i=0;i<3;i++){
        // calculate x,y,z
        if (  (data[firstCube][i] <= data[secondCube][i]) && (data[firstCube][i]+data[firstCube][i+3] > data[secondCube][i]) )
        {
            point[i]=data[secondCube][i];
            l[i]=data[firstCube][i]+data[firstCube][i+3] - data[secondCube][i];
            if (l[i] > data[secondCube][i+3]) l[i]=data[secondCube][i+3];
        } else if (  (data[secondCube][i] <= data[firstCube][i]) && (data[secondCube][i]+data[secondCube][i+3] > data[firstCube][i]) )
        {
            point[i]=data[firstCube][i];
            l[i]=data[secondCube][i]+data[secondCube][i+3] - data[firstCube][i];
            if (l[i] > data[firstCube][i+3]) l[i]=data[firstCube][i+3];
        } else return 0;
    }
    for (int i=0;i<3;i++){
        data[firstCube][i]=point[i];
        data[firstCube][i+3]=l[i];
    }
    return l[0]*l[1]*l[2];
}

int main()
{
    int number;
    cin>>number;
    while (number != 0) {
        cin>>data[0][0];
        cin>>data[0][1];
        cin>>data[0][2];
        cin>>data[0][3];
        data[0][4]=data[0][5]=data[0][3];
        int i=1;
        for (;i<number;i++)
        {
            cin>>data[1][0];
            cin>>data[1][1];
            cin>>data[1][2];
            cin>>data[1][3];
            data[1][4]=data[1][5]=data[1][3];
            if (amount != 0)
                amount=countIntersection(0,1);
        }
        cout<<amount<<endl;
        amount=-1;
        cin>>number;
    }
    return 0;
}
