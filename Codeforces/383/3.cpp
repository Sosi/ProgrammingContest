#include<bits/stdc++.h>

using namespace std;
template<class T> T gcd(T a,T b)
{
    if(a<0) return gcd(-a,b);
    if(b<0)return gcd(a,-b);
    return (b==0)?a:gcd(b,a%b);
}
template <class T> T lcm(T a,T b)
{
    return a*(b/gcd(a,b));
}
int main()
{
//    freopen("1.txt","r",stdin);

    int n; cin>>n;
    int num[105];
    for(int i = 1; i<=n; i++) cin>>num[i];
    int vis[105];
    memset(vis,0,sizeof(vis));
    int start = -1;
    int tag = 1;
    int ret = 1;
    for(int i = 1; i<=n; i++)
    {
        int cur = i;
        start = tag;
        if(vis[cur]!=0) continue;
        while(vis[cur] == 0)
        {
            vis[cur] = tag++;
            cur = num[cur];
        }
//        cout<<"cur "<<cur<<endl;
//        cout<<"tag "<<tag<<endl;
        if(vis[cur] >= start)
        {
            int circle = tag - vis[cur];
//            cout<<" - "<<circle<<endl;
            if(circle %2 == 0)
                ret = lcm(ret, circle/2);
            else ret = lcm(ret, circle);
        }else
        {
            cout<<-1<<endl;
            return 0;
        }
    }

    cout<<ret<<endl;


    return 0;
}
