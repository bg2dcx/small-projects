#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
ifstream fin("1.txt");



char str[100];

bool isEnd(char s[])
{
    if (strlen(s) == 3)
    {
        if (s[0]!='E')
            return false;
        if (s[1]!='N')
            return false;
        if (s[2]!='D')
            return false;
        return true;
    }
    return false;
}

int bestCount,bestLength,bestPosition,bestDist;

int main()
{
    fin>>str;
    while (!isEnd(str))
    {
        int len=strlen(str);
        bestCount=0;
        bestLength=0;
        bestPosition=0;
        bestDist=100;
        for (int st=0;st<len;st++)
            for (int dist=1;dist<len;dist++)
        {
            int cc=0;
            int current=st;
            while (current<len && str[current]=='.')
            {
                cc++;
                current+=dist;
            }
            int ll;
            if (current>=len)
                   ll=len-1;
                else ll=current;
            if (cc>bestCount ||
                (cc==bestCount && ll>bestLength) ||
                (cc==bestCount && ll==bestLength && st>bestPosition) ||
                (cc==bestCount && ll==bestLength && st==bestPosition && dist<bestDist)
               )
            {
                bestCount=cc;
                bestDist=dist;
                bestPosition=st;
                bestLength=ll;
            }
        }
        cout<<bestPosition<<' '<<bestDist<<endl;
        fin>>str;
    }
    return 0;
}
