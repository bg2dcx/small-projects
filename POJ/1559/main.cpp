#include <iostream>
#include <string>
using namespace std;
string equation;
char trailing[100];
int strlength;
int numOfOperands;
int numOfOperandsLeft;
int operands[22];
bool isNegative[22];
char operators[22];

void initialize()
{
    for (int i=0;i<22;i++)
    {
        operands[i]=0;
        isNegative[i]=false;
        operators[i]='N';
        numOfOperands=0;
        strlength=0;
    }
}

void delete_operand(int position)
{
    for (int i=position;i<numOfOperands;i++)
    {
        operands[i]=operands[i+1];
        isNegative[i]=isNegative[i+1];
    }
    numOfOperandsLeft--;
}

void delete_operator(int position)
{
    for (int i=position;i<numOfOperands-1;i++)
        operators[i]=operators[i+1];
}

int find_first_operator()
{
    int pos=1;
    if (operators[pos]=='*' || operators[pos]=='/') return pos;
    int tmp=2;
    while (tmp<numOfOperandsLeft)
    {
        if (operators[tmp]=='*' || operators[tmp]=='/') return tmp;
        tmp++;
    }
    return pos;
}

int main()
{
    while (getline(cin,equation))
    {
        initialize();
        strlength=equation.length();
        numOfOperands=1;
        int tmp=0;
        int tmpnum=0;
        while (equation[tmp] == ' ') tmp++;
        if (equation[tmp] == '-')
        {
            isNegative[1]=true;
            tmp++;
        }
        while (equation[tmp] == ' ') tmp++;
        tmpnum=equation[tmp]-'0';
        tmp++;
        while (equation[tmp] != '=')
        {
            if (equation[tmp]>='0' && equation[tmp]<='9' )
            {
                if (tmpnum==-1) tmpnum=0;
                tmpnum=tmpnum*10+equation[tmp]-'0';
                tmp++;
            } else
              if ( equation[tmp] == ' ')
              {
                  tmp++;
                  continue;
              } else
              if ( (equation[tmp]=='-' && tmpnum==-1) || (tmpnum==-1 && equation[tmp]=='+') )
              {
                  if (equation[tmp]=='-')
                  isNegative[numOfOperands]=true;
                  tmp++;
                  continue;
              } else
              {
                  operands[numOfOperands]=tmpnum;
                  tmpnum=-1;
                  operators[numOfOperands]=equation[tmp];
                  numOfOperands++;
                  tmp++;
              }
        }
        operands[numOfOperands]=tmpnum;
        for (int i=tmp;i<strlength;i++)
            trailing[i-tmp]=equation[i];
        trailing[strlength-tmp]=0;
        for (int i=1;i<=numOfOperands;i++)
        {
            if (isNegative[i]) cout<<'-';
            cout<<operands[i]<<' ';
            if (i != numOfOperands)
            cout<<operators[i]<<' ';
        }
        cout<<trailing;
        cout<<endl;
        numOfOperandsLeft=numOfOperands;
        for (int i=1;i<numOfOperands;i++)
        {
            int pos=find_first_operator();
            //cout<<pos<<operators[pos]<<endl;
            int op1=operands[pos];
            if (isNegative[pos]) op1=-op1;
            int op2=operands[pos+1];
            if (isNegative[pos+1]) op2=-op2;
            int newnum=0;
            switch (operators[pos])
            {
                case '+': newnum=op1+op2;
                          break;
                case '-': newnum=op1-op2;
                          break;
                case '*': newnum=op1*op2;
                          break;
                case '/': newnum=op1/op2;

            }
            operands[pos]=newnum;
            if (newnum<0)
            {
                isNegative[pos]=true;
                operands[pos]*=-1;
            } else isNegative[pos]=false;
            delete_operand(pos+1);
            delete_operator(pos);
            for (int i=1;i<=numOfOperandsLeft;i++)
            {
                if (isNegative[i]) cout<<'-';
                cout<<operands[i]<<' ';
                if (i != numOfOperandsLeft)
                cout<<operators[i]<<' ';
            }
            cout<<trailing;
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}
