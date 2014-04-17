/**
just want to  die when I debugging 

if(b>d) {swap(a,c); swap(b,d)}   ==> if(a>c){swap(a,c); swap(b,d)}

for 3 hours!!!


    5555555555555               555555555

                 55555555555


                 55555
             5555     5555
        55555             555555

*/
#include <stdio.h>
#include <iostream>
using namespace std;

#define MAXN 10000070
#define min(a,b) (a<b?a:b)
#define INF (1<<59)

long long S[MAXN];
long long N[MAXN];
long long bet[MAXN];
long long dis[MAXN][2];
int main()
{
    //freopen("3377.txt","r",stdin);
    int M;
    while(scanf("%d", &M) && M!=0)
    {
        if(M==0) break;
        int a, b, c,d; 
        scanf("%d%d%d%d", &a, &b, &c, &d);
        if(b>d) {swap(a,c); swap(b,d);}
        for(int i=0; i<=M; i++) 
        {
            dis[i][0]=INF;
            dis[i][1]=INF;
        }
        for(int i=1; i<=M; i++)
            scanf("%lld", &N[i]);
        for(int i=0; i<=M; i++)
            scanf("%lld",&bet[i]);
        for(int i=1; i<=M; i++)
            scanf("%lld", &S[i]);
        dis[b][a] = 0; dis[b][1-a] = bet[b];
        long long temp=0LL;
        for(int i=b; i>0; i--)
        {
            temp+=N[i]+S[i];
            dis[b][1-a] = min(dis[b][1-a], temp+bet[i-1]);
        }
        //cout<<"L   "<<dis[b][1-a]<<endl;
        temp = 0LL;
        long long L = bet[d];
        for(int i=d+1; i<=M; i++)
        {
            temp += N[i]+S[i];
            L = min(L, temp + bet[i]);
        }
        //cout<<"R  "<<L<<endl;
        bet[d] =L;
        for(int i=b+1; i<=d; i++)
        {
            dis[i][0] = min( dis[i-1][0]+N[i], dis[i-1][1]+ S[i]+bet[i]);
            dis[i][1] = min( dis[i-1][1]+S[i], dis[i-1][0]+ N[i]+bet[i]);
        }
        //long long ret = min(dis[d][c], L+dis[d][1-c]);
        //cout<<ret<<endl;
        cout<<dis[d][c]<<endl;
    }
}
