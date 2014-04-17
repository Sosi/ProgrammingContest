#include <stdio.h>
#define maxn 50001
int a[maxn],big[maxn],lit[maxn],n;
int main()
{
    int i,j, ans;
    while (scanf("%d",&n)!=EOF)
    {
        for (i=0; i<n; ++i) scanf("%d", &a[i]);
        ans=0;
        for (i=0; i<n; ++i)
        {
            lit[i]=i;
            for (j=i-1; j>=0&&a[j]<a[i]; j=big[j])lit[i]=a[lit[i]]<a[lit[j]]?lit[i]:lit[j];
            big[i]=j;
        }
        for (i=n-1; i>0; --i)
            if (i>ans)ans=ans>i-lit[i]?ans:(i-lit[i]);
        if(ans==0)ans=-1;
        printf("%d\n",ans);
    }
    return 0;
}
