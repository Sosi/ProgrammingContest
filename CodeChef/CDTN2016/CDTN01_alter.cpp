#include<bits/stdc++.h>
using namespace std;
typedef long long int uli;
const int mx=1e5+10;
int d[mx],pos[mx],cnt[mx];
int p[mx];
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            scanf("%d",p+i);
            p[i]--;
            d[i]=i;
            pos[i]=i;
            cnt[i]=0;
        }
        bool ok=true;
        int ans=0;
        for(int i=0; i<n && ok; i++)
        {
            if(i==pos[p[i]])continue;
            if(pos[p[i]]-i>2)
            {
                ok=false;
                break;
            }
            for(int j=pos[p[i]]-1; j>=i; j--)
            {
                swap(d[j],d[j+1]);
                pos[d[j]]=j;
                pos[d[j+1]]=j+1;
                cnt[d[j]]++;
                cnt[d[j+1]]++;
                ans++;
            }
        }
        if(ok)printf("%d\n",ans);
        else puts("Not Possible");
    }
    return 0;
}

