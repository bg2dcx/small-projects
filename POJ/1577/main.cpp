#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

char str[27][27];
int num[27];
int numOfLines;
struct NODE
{
    char cc;
    int childNum;
    int addedTime;
    NODE *leftC;
    NODE *rightC;
};

void insert_node(char name, int addedTime, NODE *root)
{
    if (root->cc > name)
    {
        if (root->leftC == NULL)
        {
            NODE *p;
            p=(NODE *)malloc(sizeof(NODE));
            p->cc=name;
            p->leftC=NULL;
            p->rightC=NULL;
            root->leftC=p;
        } else
          insert_node(name, addedTime, root->leftC);
    } else
    {
         if (root->rightC == NULL)
        {
            NODE *p;
            p=(NODE *)malloc(sizeof(NODE));
            p->cc=name;
            p->leftC=NULL;
            p->rightC=NULL;
            root->rightC=p;
        } else
          insert_node(name, addedTime, root->rightC);
    }
}
void print_pre(NODE *root)
{
    cout<<root->cc;
    if (root->leftC != NULL)
        print_pre(root->leftC);
    if (root->rightC != NULL)
        print_pre(root->rightC);
}
int main()
{
    char cIndication='*';
    while (cIndication != '$')
    {
        numOfLines=0;
        cin>>str[numOfLines];
        while (!(str[numOfLines][0]=='*' || str[numOfLines][0]=='$'))
        {
            numOfLines++;
            cin>>str[numOfLines];
        }
        cIndication=str[numOfLines][0];
        NODE *p;
        p=(NODE *)malloc(sizeof(NODE));
        p->cc=str[numOfLines-1][0];
        p->childNum=0;
        p->addedTime=numOfLines-1;
        p->leftC=NULL;
        p->rightC=NULL;
        for (int i=numOfLines-2;i>=0;i--)
        {
            for (int j=0;j<strlen(str[i]);j++)
                insert_node(str[i][j],i,p);
        }
        print_pre(p);
        cout<<endl;
    }
    return 0;
}
