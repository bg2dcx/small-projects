#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

#define lint __int64
#define MAXN 100000
#define M 9901
struct Factor { lint base, exp; };
Factor f[MAXN]; lint fn;
lint p[MAXN], a[MAXN], pn;

void prime ()
{
    int i, j; pn = 0;
    memset(a,0,sizeof(a));
    for ( i = 2; i < MAXN; i++ )
    {
        if ( !a[i] ) p[pn++] = i;
        for ( j = 0; j < pn && i * p[j] < MAXN && (p[j] <= a[i] || a[i] == 0); j++ )
            a[i*p[j]] = p[j];
    }
}

void Factorization ( int num )
{
    fn = 0;
    for ( int i = 0; i < pn && p[i] <= num; i++ )
    {
        if ( num % p[i] ) continue;
        f[++fn].base = p[i];
        f[fn].exp = 0;
        while ( num % p[i] == 0 )
        {
            f[fn].exp++;
            num /= p[i];
        }
    }
    if ( num != 1 )
    {
        f[++fn].base = num;
        f[fn].exp = 1;
    }
}

int mod_exp ( int a, lint b )
{
    int ret = 1;
    a = a % M;
    while ( b >= 1 )
    {
        if ( b & 1 ) ret = ret * a % M;
        a = a * a % M;
        b >>= 1;
    }
    return ret;
}

int sum_exp ( int p, lint exp )
{
    if ( exp == 0 ) return 1;
    lint tmp1, tmp2, mid = exp / 2;
    if ( exp & 1 )
    {
        tmp1 = sum_exp (p, mid);
        tmp2 = mod_exp (p, mid + 1);
        return (tmp1+tmp2*tmp1) % M;
    }
    else
    {
        tmp1 = sum_exp (p, mid-1);
        tmp2 = mod_exp (p, mid);
        return (tmp1 + tmp2 + p*tmp2*tmp1) % M;
    }
}

int main()
{
    prime();
    int A, B, ret = 1;
    scanf("%d%d",&A,&B);
    if ( A == 0 ) {printf("0\n");return 0;}
    if ( B == 0 || A == 1 ) {printf("1\n"); return 0;}
    Factorization ( A );
    for ( int i = 1; i <= fn; i++ )
        ret = ret * sum_exp(f[i].base, f[i].exp*B) % M;
    printf("%d\n",ret);
}
