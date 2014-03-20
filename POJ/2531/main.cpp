#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int c[20][20];
int n;
bool v[20];
int maxTraffic;
// remain[i]代表 i~n-1的节点能产生的极限最大traffic
int remain[30];
int num=0;

int calc(){
    int res = 0;
    for( int i=0; i<n; ++i ){
        for( int j=i+1; j<n; ++j ){
                if( v[i] ^ v[j] )  //v[i] != v[j]
                    res += c[i][j];
        }
    }
    return res;
}

int calcPartial( int idx, int partial ){
    int res = partial;
    for( int i=0; i<idx; ++i ){
        if( v[i] ^ v[idx] )
            res += c[i][idx];
    }
    return res;
}

int calcOpt( int idx, int partial ){
    int t = partial;
    int a,b;
    for( int i=idx + 1; i<n; ++i ){
        a=b=0;
        for( int j=0; j<=idx; ++j ){
            if( v[j] )
                a += c[i][j];
            else
                b += c[i][j];
        }
        t += max( a, b );
    }
    t += remain[idx+1];
    return min( remain[0], t );
}

void dfs( int idx, int partial ){
    if( idx == n ){
        maxTraffic = max( maxTraffic, partial );
        ++num;
        return;
    }
    v[idx] = true;
    int p = calcPartial( idx, partial );
    if( calcOpt( idx, p ) > maxTraffic )
        dfs( idx+1, p );
    v[idx] = false;
    p = calcPartial( idx, partial );
    if( calcOpt( idx, p ) > maxTraffic )
        dfs( idx + 1, p );
}

void calcRemain(){
    int cnt,p,q,sum = 0, asum = 0;
    priority_queue< int, vector<int>, greater<int> > Q;
    vector<int> v;
    v.reserve( 200 );

    remain[n] = remain[n-1] = 0;
    for( int i=n-2; i>-1; --i ){
        cnt = n - i;
        p = cnt >> 1;
        q = cnt - p;
        cnt = ( (p * (p-1) ) >> 1 ) + ( (q*(q-1)) >> 1 );
        for( int j=i+1; j<n; ++j ){
            Q.push( c[i][j] );
            sum += c[i][j];
        }
        remain[i] = sum;
        while(cnt--){
            v.push_back( Q.top() );
            remain[i] -= Q.top();
            Q.pop();
        }
        while( !v.empty() ){
            Q.push( v.back() );
            v.pop_back();
        }
    }
}

int main(){

    while( ~scanf( "%d", &n ) ){
        for( int i=0; i<n; ++i ){
            for( int j=0; j<n; ++j ){
                scanf( "%d", &c[i][j] );
            }
        }
        num = 0;
        maxTraffic = 0;
        calcRemain();
        v[0] = true;
        dfs( 1, 0 );
        printf( "%d\n", maxTraffic );
    }
    return 0;
}
