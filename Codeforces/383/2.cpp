#include<bits/stdc++.h>

using namespace std;

int main()
{
//    freopen("1.txt","r",stdin);

    int n;
    int x;
    cin>>n>>x;
    int cnt[100005];
    memset(cnt,0,sizeof(cnt));
    for(int i = 0; i<n; i++)
    {
        int p;
        cin>>p;
        cnt[p]++;
    }
    int ret = 0;
    if(x == 0)
    {
        for(int i = 0; i< 100005; i++)
        {
            ret += cnt[i]*(cnt[i]-1);
        }
    }
    else
    {
        for(int i = 0; i< 100005; i++)
        {
//            if(cnt[i] != 0)
            ret += cnt[x^i] * cnt[i];
        }
    }

    cout<<ret/2<<endl;
    return 0;
}
