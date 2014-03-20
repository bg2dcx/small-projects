#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

char player1[80],player2[80];

int whoWins(char cc1, char cc2)
{
    if (cc2 == cc1)
        return 0;
    switch (cc1)
    {
        case 'R': if (cc2 == 'S')
                    return 1;
                  if (cc2 == 'P')
                    return 2;
                  break;
        case 'P': if (cc2 == 'R')
                     return 1;
                  if (cc2 == 'S')
                     return 2;
                  break;
        case 'S':  if (cc2 == 'P')
                       return 1;
                   if (cc2 == 'R')
                        return 2;
    }
    return 0;
}

int main()
{
    while (scanf("%s",player1)!= EOF)
    {
        scanf("%s",player2);
        int sum1=0,sum2=0;
        int len=strlen(player1);
        if (len == 1 && player1[0]=='E')
            return 0;
        for (int i=0;i<len;i++)
        {
            int tmp=whoWins(player1[i],player2[i]);
            if (tmp ==1)
                sum1++;
            else if (tmp == 2)
                sum2++;
        }
        cout<<"P1: "<<sum1<<endl;
        cout<<"P2: "<<sum2<<endl;
    }
    return 0;
}
