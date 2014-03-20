#include <iostream>
#include <stdio.h>
#include <math.h>

const double inf = 0xfffffff;
const double PI=3.1415926;


using namespace std;

double seg,l,n,c;

int main()
{
    scanf("%lf%lf%lf",&l,&n,&c);
    while (!(l<0))
    {
        if (n*c < 0.000001)
        {
            printf("0.000\n");
            scanf("%lf%lf%lf",&l,&n,&c);
            continue;
        }
        double seg=(1+n*c)*l;
        double mid,low,high,tmp;
        low=0;high=inf;
        while (high-low>0.0000001)
        {
            mid=(low+high)/2;
            double angle=asin(0.5*l/mid);
            tmp=2*angle*mid;
            if (tmp<seg)
                high=mid;
            else low=mid;
        }
        double ans=mid-sqrt(mid*mid-l*l/4);
        printf("%0.3lf\n",ans);
        scanf("%lf%lf%lf",&l,&n,&c);
    }
    return 0;
}
