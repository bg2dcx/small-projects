#include <iostream>
#include <string.h>
#include <memory.h>
#include <stdlib.h>
using namespace std;

struct NODE
{
    NODE * next;
    NODE * prev;
    char info;
};

int cSize, cases,length;
NODE* first;
char cmd[500];

char ott[80];


int main()
{
    cin>>cSize;
    while (cSize>0)
    {
        first=NULL;
        cases++;
        length=0;
        cout<<"Simulation "<<cases<<endl;
        cin>>cmd;
        for (int i=0;i<strlen(cmd);i++)
        {
            if (cmd[i] != '!')
            {
                if (first == NULL)
                {
                    NODE *p;
                    p=(NODE*)malloc(sizeof(NODE));
                    p->info=cmd[i];
                    p->prev=NULL;
                    p->next=NULL;
                    length=1;
                    first=p;
                } else
                {
                    bool exist=false;
                    NODE* findN=NULL;
                    NODE* cur=first;
                    while (cur->next != NULL)
                    {
                        if (cur->info == cmd[i])
                        {
                            exist=true;
                            findN=cur;
                            break;
                        }
                        else
                            cur=cur->next;
                    }
                    if (cur->info == cmd[i])
                    {
                            exist=true;
                            findN=cur;
                    }
                    if (exist)
                    {
                        if (findN != first)
                        {
                            findN->prev->next=findN->next;
                            if (findN->next != NULL)
                            findN->next->prev=findN->prev;
                            findN->next=first;
                            findN->prev=NULL;
                            first->prev=findN;
                            first=findN;
                        }
                    } else
                    {
                        if (length<cSize)
                        {
                            length++;
                            NODE* p=(NODE*)malloc(sizeof(NODE));
                            p->info=cmd[i];
                            p->prev=NULL;
                            p->next=first;
                            first->prev=p;
                            first=p;
                        } else
                        {
                            NODE* p=(NODE*)malloc(sizeof(NODE));
                            p->info=cmd[i];
                            p->prev=NULL;
                            p->next=first;
                            first->prev=p;
                            first=p;
                            cur->prev->next=NULL;
                        }
                    }

                }
            } else
            {
                NODE * p=first;
                int ss=0;
                while (p != NULL)
                {

                    ott[ss]=p->info;
                    p=p->next;
                    ss++;
                }
                for (int tt=0;tt<ss;tt++)
                    cout<<ott[ss-tt-1];
                cout<<endl;
            }
        }
        cin>>cSize;
    }

    return 0;
}
