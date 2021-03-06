// Standard Solution
#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int g[505][505], dsum[505];

int main()
{
    int kases, i, j;

    for(scanf("%d",&kases);kases--;)
    {
        // read input ( 1-based indices, (1,1) at bottom-left )
        scanf("%d",&n);
        for(i=n;i>0;i--)
        {
            for(j=1;j<=n-i+1;j++) scanf("%d",&g[i][j]);
            g[i][j]=g[i][j+1]=0;
        }
        for(j=1;j<=n+2;j++) g[0][j] = 0;

        // diagonal prefix-sum
        int D = (n+1)/2;
        for(int i=1;i<=D;i++) dsum[i] = dsum[i-1] + g[i][i];

        // Po
        for(int i=n-1;i>1;i--) for(int j=1;j<=min(i-1,n-i+1);j++)
            g[i][j] += max( g[i+1][j-1], max( g[i+1][j], g[i+1][j+1] ) );

        // Mantis
        for(int j=n-1;j>1;j--) for(int i=1;i<=min(j-1,n-j+1);i++)
            g[i][j] += max( g[i+1][j+1], max( g[i][j+1], g[i-1][j+1] ) );

        // Try all possible diagonal meetups
        int ans = 0;
        for(int p=1;p<=D;p++) for(int m=1;m<=D;m++)
            ans = max( ans , max(g[p+1][p-1],g[p+1][p]) + max(g[m][m+1],g[m-1][m+1]) + dsum[max(p,m)] );

        printf("%d\n",ans);
    }

    return 0;
}
