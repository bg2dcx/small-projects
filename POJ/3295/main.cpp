#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int originalStr[101];
int workStr[101];
bool truthValue[6];
char inputStr[120];
int length;
int truth;
//FILE *fp;



void create_original()
{
    for (int i=1;i<=length;i++)
    {
        char tmp=inputStr[i-1];
        if (tmp>='p' && tmp<= 't')
        {
            originalStr[i]=tmp-'p'+1;
        } else
          switch (tmp)
          {
              case 'N':originalStr[i]=14;
                        break;
              case 'K':originalStr[i]=10;
                        break;
              case 'A':originalStr[i]=11;
                        break;
              case 'C':originalStr[i]=12;
                        break;
              case 'E':originalStr[i]=13;
                        break;
          }
    }
}

bool solve()
{
    int rest=length;
    while (rest>1)
    {
        int current=1;
        while (current<length)
        {
            if (workStr[current]>13)
            {
                int next=current+1;
                while (next<length && workStr[next]==-1) next++;
                if (workStr[next]>0 && workStr[next]<8)
                {
                    if (workStr[next]==6)
                    {
                        workStr[current]=7;
                        workStr[next]=-1;
                    } else
                       if (workStr[next]==7)
                       {
                           workStr[current]=6;
                           workStr[next]=-1;
                       } else
                         {
                             if (truthValue[workStr[next]])
                             {
                                 workStr[current]=7;
                                 workStr[next]=-1;
                             } else
                             {
                                 workStr[current]=6;
                                 workStr[next]=-1;
                             }
                         }
                    rest=rest-1;
                    break;
                }
            }
            else if (workStr[current]>9 && workStr[current]<14)
            {
                int next1=current+1;
                while (next1<length && workStr[next1]==-1) next1++;
                int next2=next1+1;
                while (next2<length && workStr[next2]==-1) next2++;
                if (next1<= length && next2<= length)
                    if (workStr[next1]>0 && workStr[next1]<8 && workStr[next2]>0 && workStr[next2]<8)
                {
                    bool value1=true;
                    bool value2=true;
                    bool res=true;
                    if (workStr[next1]==6)
                        value1=true;
                     else if (workStr[next1]==7)
                        value1=false;
                     else
                        value1=truthValue[workStr[next1]];
                    if (workStr[next2]==6)
                        value2=true;
                     else if (workStr[next2]==7)
                        value2=false;
                     else
                        value2=truthValue[workStr[next2]];
                    switch (workStr[current])
                    {
                             case 10:res=value1&&value2;
                                    break;
                             case 11:res=value1||value2;
                                    break;
                             case 13:res=value1==value2;
                                    break;
                             case 12:if (!value1 || (value1&&value2))
                                        res=true;
                                     else
                                        res=false;
                                     break;
                    }
                    if (res)
                    {
                        workStr[current]=6;
                    } else
                        workStr[current]=7;
                    workStr[next1]=-1;
                    workStr[next2]=-1;
                    rest=rest-2;
                    break;
                }
            }
            current++;
        }
    }
    for (int i=1;i<=length;i++)
        if (workStr[i]!=-1)
        {
            if (workStr[i]==6)
               return true;
            if (workStr[i]==7)
                return false;
            if (workStr[i]>0 && workStr[i]<6)
                return truthValue[workStr[i]];
        }


}

int main()
{
//    fp=fopen("sample.txt","r");
    while (true)
    {
        scanf("%s",inputStr);
        length=strlen(inputStr);
        if (length==1 && inputStr[0]=='0')
            return 0;
        create_original();
        bool tautology=true;
        for (truth=0;truth<=31;truth++)
        {
            for (int i=1;i<=5;i++)
                truthValue[i]= (truth>>(i-1)) & 1;
            for (int i=1;i<=length;i++)
                workStr[i]=originalStr[i];
            if (!solve())
            {
                tautology=false;
                break;
            }
        }
        if (tautology)
            cout<<"tautology"<<endl;
        else cout<<"not"<<endl;
    }
    return 0;
}
