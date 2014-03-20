#include <iostream>
#include <math.h>

using namespace std;
/*
int H,U,D,F,ans;
double d,u,f,h,days;

int main()
{
    cin>>H>>U>>D>>F;
    while (H != 0)
    {
        ans=0;
        h=H;
        u=U;
        d=D;
        f= ((double) F)/100*u;
        double tmp1=d-u-0.5*f;
        double tmp2=pow((u+0.5*f-d),2)+2*f*(d-h);
        double tmp3=tmp1+pow(tmp2,0.5);
        double successday=tmp3/(-f);
        if (successday>0)
        {
            ans=(int) successday;
            if (ans<successday)
                ans++;
        }
        tmp3=tmp1-pow(tmp2,0.5);
        successday=tmp3/(-f);
        if ( successday>0 && successday<ans)
        {
            ans= (int) successday;
            if (ans<successday)
                ans++;
        }
        if (ans>0)
        {
            cout<<"success on day "<<ans<<endl;
            cin>>H>>U>>D>>F;
            continue;
        }
        ans=0;
        successday=(u+f*0.5-d)*2/f;
        ans=(int) successday;
        if (ans< successday)
            ans++;
        double stopClimbingDay=u/f;
        if (stopClimbingDay<successday)
        {
            int stopDay= (int) stopClimbingDay;
            if (stopDay < stopClimbingDay)
                stopDay++;
            tmp1=(2*u-(stopDay-1)*f)*stopDay/2;
            successday=tmp1/d;
            ans=(int) successday;
            if (ans<successday)
                ans++;
        }
        if (successday-ans<0.00001 && successday-ans>-0.00001)
            ans++;
        cout<<"failure on day "<<ans<<endl;
        cin>>H>>U>>D>>F;

    }
    return 0;
}
*/

int H,U,D,F,days;
double height, inc, decrease;

int main()
{
    cin>>H>>U>>D>>F;
    while (H != 0)
    {
        height=0;
        days=0;
        inc=U;
        decrease=(double) F;
        decrease=decrease*inc/100;
        while (true)
        {
            days++;
            height+=inc;
            if (height>H)
            {
                cout<<"success on day "<<days<<endl;
                break;
            }
            inc-=decrease;
            if (inc<0)
                inc=0;
            height-=D;
            if (height<0)
            {
                cout<<"failure on day "<<days<<endl;
                break;
            }

        }
        cin>>H>>U>>D>>F;
    }
}
