#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <bitset>
using namespace std;
typedef long long LL;
const int N = 2e5+5;
const LL mod = 1e6+3;
LL qpow(LL x,LL y)
{
    LL ret=1;
    while(y)
    {
        if(y&1)ret=ret*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return ret;
}
int main()
{
    LL n,k;
    scanf("%I64d%I64d",&n,&k);
    if(n<=62&&k>1ll<<n)
    {
        printf("1 1\n");
        return 0;
    }
    LL num=0;
    for(LL i=k-1; i; i>>=1)
    {
        num+=i/2;
    }
    LL b=1,a=qpow(2,n);
    for(LL i=1; i<=k-1; ++i)
    {
        LL tmp=(a-i+mod)%mod;
        b=b*tmp%mod;
        if(tmp==0)break;
    }
    LL inv=qpow(qpow(2,num),mod-2);
    a=qpow(a,k-1);
    a=a*inv%mod;
    b=b*inv%mod;
    b=(a-b+mod)%mod;
    printf("%I64d %I64d\n",b,a);
    return 0;
}
