/**
 把问题的所有维度排序列举出来，然后根据维度来确定状态！
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
double dp[1005][1005];
int a[1005];
int b[1005];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int N,K;
        scanf("%d%d",&N,&K);
        //cin>>N>>K;
        memset(dp,0,sizeof(dp));
        //memset(S,0,sizefo(S));
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        //fill(a,a+1005,0);
        //fill(b,b+1005,0);
        for(int i=1;i<=N;i++) scanf("%d",a+i);//a[i];
        for(int i=1;i<=K;i++) scanf("%d",b+i);//cin>>b[i];
        sort(a+1,a+N+1);
        sort(b+1,b+K+1);
       // for(int i=1;i<=N;i++) cout<<a[i]<<" "; cout<<endl;
       // for(int i=1;i<=K;i++) cout<<b[i]<<" ";cout<<endl;
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=K;j++)
            {
                dp[i][j]=j*1.0/i*(a[i]*b[j]/100.0+ dp[i-1][j-1]) + (1.0- j*1.0/i)*dp[i-1][j];
            }
        }
        cout<<dp[N][K]<<endl;
    }
    return 0;
}
