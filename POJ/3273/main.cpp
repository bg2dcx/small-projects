#include<stdio.h>
int m,n,a[100001];
int check(int sub)
{
	int sum=0,k=0,i;
	for(i=0;i<n;i++)
	{
	    sum+=a[i];
		if(sum>sub)
		{
			k++;
			sum=a[i];
		}
	}
	if(sum!=0) k++;
	return k;
}
int solve(int a,int b)
{
	int left=a,right=b,res=0,mid;
	while(left<=right)
	{
		mid=left+(right-left)/2;
		if(check(mid)<=m)
		{
			res=mid;
			right=mid-1;
		}
		else left=mid+1;
	}

	return res;
}
int main()
{
	 int sum=0,max=0,i,ans;
	 scanf("%d%d",&n,&m);
	 for(i=0;i<n;i++)
	 {
 		scanf("%d",&a[i]);
 		sum+=a[i];
 		if(max<a[i]) max=a[i];
 	}
 	ans=solve(max,sum);
 	printf("%d\n",ans);

}
