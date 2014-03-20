#include <iostream>

using namespace std;
long long digit[5]={0,45,9000,1386450,188019000};
long long stdigit[6]={0,0,11,192,2893,38894};
long long bdigit[6]={0,0,9,189,2889,38889};
long long stnumber[6]={0,0,10,100,1000,10000};
long long t,n;

long long getdigit(long long number)
{
    long long l=0;
    while (number > 0){
        l++;
        number=number/10;
    }
    return l;
}

long long solve(long long number)
{
    long long sum=0;
    long long len=getdigit(number);
    long long tmp=1;
    for (long long i=1;i<len;i++)
        {
            sum+=digit[i];
            tmp=tmp*10;
        }
    if (tmp == 1) tmp=0;
    long long current=(number-tmp)*len+stdigit[len];
    if (current <10 ) sum+=(1+current)*number/2;
      else
        sum=sum+(stdigit[len]+current)*(number-tmp+1)/2;
    if (sum-current >= n) return -1;
    if (sum < n) return 1;
    long long order=n-sum+current;
    long long nlen=1;
    while ( (nlen<5) && (bdigit[nlen+1]<order) ) nlen++;
    if (nlen == 1)
    {
        cout<<order<<endl;
        return 0;
    }
    order=order-bdigit[nlen];
    long long norder=order/nlen;
    long long dorder=order%nlen;
    if (dorder == 0)
    {
        norder--;
        dorder=nlen;
    }
    tmp=stnumber[nlen]+norder;
    long long chushu= 1;
    for (int i=0;i<nlen-dorder;i++) chushu*=10;
    long long result=0;
    result=(tmp/chushu) % 10;
    cout<<result<<endl;
    return 0;

}

int main()
{
   cin>>t;
    long long st,ed,tmp;
    for (long long i=0;i<t;i++)
    {
        cin>>n;
        st=1;ed=99999;
        tmp=(st+ed)/2;
        while (true)
        {
            long long signal=solve(tmp);
            if (signal == 0) break;
            if (signal == 1) st=tmp+1;
            if (signal == -1) ed=tmp-1;
            tmp=(st+ed)/2;
        }

    }
    return 0;
}
/*
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

inline string  tostr(int x)
{
        string s;
        //int temp=0;
        while(x){
          s.push_back(x%10+'0');
          x/=10;
        }
        reverse(s.begin(),s.end());
        return s;
}

int main(  )
{
 //	freopen("i.txt","r",stdin);
   //	freopen("o.txt","w",stdout);
     long long pos,t;
     cin>>t;
     while(t--){
     cin>>pos;
     long long  top=2,len=1;
     string s="1",temp="1";
     while(len<pos){
       temp+=tostr(top);
       len+=temp.length();
       top++;
     }
     cout<<temp[temp.length()-(len-pos)-1]<<endl;
   }
	// system("pause");
	 return 0;
}

*/
