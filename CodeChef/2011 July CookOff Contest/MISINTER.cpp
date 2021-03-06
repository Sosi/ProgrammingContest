#include <stdio.h>

const int maxN = 100000;
const int MOD = 1000000007;
int p[maxN+1];
int mark[maxN+1];

int main()
{
    int TST;
    scanf("%d",&TST);
    int tst;
    for(tst=0;tst<TST;tst++)
    {
        int n,i,j=0;
        scanf("%d",&n);
        for(i=2;i<=n;i+=2)
            p[++j]=i;
        for(i=1;i<=n;i+=2)
            p[++j]=i;
        for(i=1;i<=n;i++)
            mark[i]=0;
        int cnt=0;
        for(i=1;i<=n;i++) if(!mark[i])
        {
            cnt++;
            for(j=i;!mark[j];j=p[j])
                mark[j]=1;
        }
        int ans=1;
        while(cnt--)
            ans=(long long)(ans)*26%MOD;
        printf("%d\n",ans);
    }
    return 0;
}
