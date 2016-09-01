#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <bitset>
using namespace std;
typedef long long LL;
const int N = 2e5+5;
const LL mod = 1e9+7;
int to[N],n;
int vis[N];
LL qpow(LL x,LL y){
  LL ret=1;
  while(y){
    if(y&1)ret=ret*x%mod;
    y>>=1;
    x=x*x%mod;
  }
  return ret;
}
int main(){
  scanf("%d",&n);
    for(int i=1; i<=n; ++i)scanf("%d",&to[i]);
    LL z=n,ret=1;
  for(int i=1;i<=n;++i){
    if(vis[i])continue;
    int x=i;
    while(!vis[x]){
      vis[x]=i;
      x=to[x];
    }
    if(vis[x]!=i)continue;
    int t=x,cnt=0;
    do{
      ++cnt;
      t=to[t];
    }while(t!=x);
    z-=cnt;
    ret=1ll*ret*((qpow(2,cnt)-2+mod)%mod)%mod;
  }
  ret=ret*qpow(2,z)%mod;
  printf("%I64d\n",ret);
  return 0;
}
