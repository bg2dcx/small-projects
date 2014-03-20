#include <iostream>
#include <string>

using namespace std;
string protein[20]={"Phe","Ser","Tyr","Cys","Trp","Leu","Pro","His","Arg","Ile","Thr","Asn","Met","Lys","Val","Ala","Asp","Glu","Gly","Gln"};
int combination[500];
int DNA[300];
int cDNA[300];
int pout[100];
string inputs;

void print_error(){
    cout<<"*** No translatable DNA found ***"<<endl;
}

void print_success(int l){
    cout<<protein[pout[0]];
    for  (int i=1;i<l;i++)
    {
        cout<<'-'<<protein[pout[i]];
    }
    cout<<endl;
}


int main()
{
   for (int i;i<500;i++) combination[i]=-1;
    ////////////////Initialization////////////////
    combination[0]=0;    combination[10]=1;    combination[30]=2;   combination[20]=3;
    combination[1]=0;    combination[11]=1;    combination[31]=2;   combination[21]=3;
    combination[3]=5;    combination[13]=1;
    combination[2]=5;    combination[12]=1;                         combination[22]=4;

    combination[100]=5;    combination[111]=6;  combination[130]=7; combination[120]=8;
    combination[101]=5;    combination[111]=6;  combination[131]=7; combination[121]=8;
    combination[103]=5;    combination[113]=6;  combination[133]=19; combination[123]=8;
    combination[102]=5;    combination[112]=6;  combination[132]=19; combination[122]=8;

    combination[300]=9;    combination[310]=10;  combination[330]=11; combination[320]=1;
    combination[301]=9;    combination[311]=10;  combination[331]=11; combination[321]=1;
    combination[303]=9;    combination[313]=10;  combination[333]=13; combination[323]=8;
    combination[302]=12;    combination[312]=10;  combination[332]=13; combination[322]=8;

    combination[200]=14;    combination[210]=15;  combination[230]=16; combination[220]=18;
    combination[201]=14;    combination[211]=15;  combination[231]=16; combination[221]=18;
    combination[203]=14;    combination[213]=15;  combination[233]=17; combination[223]=18;
    combination[202]=14;    combination[212]=15;  combination[232]=17; combination[222]=18;

    getline(cin,inputs);
    while (inputs.length() != 1)
    {

        int length=inputs.length();
        for (int i=0;i<length;i++)
           switch (inputs[i]){
           case 'T': DNA[i]=0;
                    break;
           case 'C': DNA[i]=1;
                    break;
           case 'A': DNA[i]=3;
                    break;
           case 'G': DNA[i]=2;
                    break;
        }
        /////////SV/////
        int tmp;
        int st=-1;int ed=-1;
        bool success=true;
        int number=0;
        for (int i=0;i<length;i++)
        {
            if (DNA[i]*100+DNA[i+1]*10+DNA[i+2] == 302)
                {
                    st=i+3;
                    break;
                }
        }
        for (int i=st;i<length;i=i+3)
        {
            if ( (DNA[i]*100+DNA[i+1]*10+DNA[i+2] == 33) || (DNA[i]*100+DNA[i+1]*10+DNA[i+2] == 32) || (DNA[i]*100+DNA[i+1]*10+DNA[i+2] == 23))
                {
                    ed=i-3;
                    break;
                }
        }
        if ( (st>0) && (ed>=st))
        {
            for (int i=st;i<=ed;i=i+3)
            {
                tmp=DNA[i]*100+DNA[i+1]*10+DNA[i+2];
                if (combination[tmp] == -1) success=false;
                pout[number]=combination[tmp];
                number++;
            }
            if (success){
                print_success(number);
                getline(cin,inputs);
                continue;
            }
        }
        ///////SV'///////
        for (int i=0;i<length;i++)
                cDNA[length-i-1]=DNA[i];
         for (int i=0;i<length;i++)
                DNA[i]=cDNA[i];
        success=true;
        number=0;
        st=ed=-1;
        for (int i=0;i<length;i++)
        {
            if (DNA[i]*100+DNA[i+1]*10+DNA[i+2] == 302)
                {
                    st=i+3;
                    break;
                }
        }
        for (int i=st;i<length;i=i+3)
        {
            if ( (DNA[i]*100+DNA[i+1]*10+DNA[i+2] == 33) || (DNA[i]*100+DNA[i+1]*10+DNA[i+2] == 32) || (DNA[i]*100+DNA[i+1]*10+DNA[i+2] == 23))
                {
                    ed=i-3;
                    break;
                }
        }
        if ( (st>0) && (ed>=st))
        {
            for (int i=st;i<=ed;i=i+3)
            {
                tmp=DNA[i]*100+DNA[i+1]*10+DNA[i+2];
                if (combination[tmp] == -1) success=false;
                pout[number]=combination[tmp];
                number++;
            }
            if (success){
                print_success(number);
                getline(cin,inputs);
                continue;
            }
        }

        /////////////S'/////////////
        success=true;
        number=0;
        st=ed=-1;
        for (int i=0;i<length;i++) DNA[i]=3-DNA[i];
        for (int i=0;i<length;i++)
        {
            if (DNA[i]*100+DNA[i+1]*10+DNA[i+2] == 302)
                {
                    st=i+3;
                    break;
                }
        }
        for (int i=st;i<length;i=i+3)
        {
            if ( (DNA[i]*100+DNA[i+1]*10+DNA[i+2] == 33) || (DNA[i]*100+DNA[i+1]*10+DNA[i+2] == 32) || (DNA[i]*100+DNA[i+1]*10+DNA[i+2] == 23))
                {
                    ed=i-3;
                    break;
                }
        }
        if ( (st>0) && (ed>=st))
        {
            for (int i=st;i<=ed;i=i+3)
            {
                tmp=DNA[i]*100+DNA[i+1]*10+DNA[i+2];
                if (combination[tmp] == -1) success=false;
                pout[number]=combination[tmp];
                number++;
            }
            if (success){
                print_success(number);
                getline(cin,inputs);
                continue;
            }
        }
        ////////S///////
        success=true;
        number=0;
        st=ed=-1;
        for (int i=0;i<length;i++)
                cDNA[length-i-1]=DNA[i];
         for (int i=0;i<length;i++)
                DNA[i]=cDNA[i];
        for (int i=0;i<length;i++)
        for (int i=0;i<length;i++)
        {
            if (DNA[i]*100+DNA[i+1]*10+DNA[i+2] == 302)
                {
                    st=i+3;
                    break;
                }
        }
        for (int i=st;i<length;i=i+3)
        {
            if ( (DNA[i]*100+DNA[i+1]*10+DNA[i+2] == 33) || (DNA[i]*100+DNA[i+1]*10+DNA[i+2] == 32) || (DNA[i]*100+DNA[i+1]*10+DNA[i+2] == 23))
                {
                    ed=i-3;
                    break;
                }
        }
        if ( (st>0) && (ed>=st))
        {
            for (int i=st;i<=ed;i=i+3)
            {
                tmp=DNA[i]*100+DNA[i+1]*10+DNA[i+2];
                if (combination[tmp] == -1) success=false;
                pout[number]=combination[tmp];
                number++;
            }
            if (success){
                print_success(number);
                getline(cin,inputs);
                continue;
            }
        }
        ///////////////
        print_error();
        getline(cin,inputs);
    }
    return 0;
}
