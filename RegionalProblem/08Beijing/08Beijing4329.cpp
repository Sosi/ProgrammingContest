#include <iostream>
#include <stdio.h>
#include <string.h>
#include <assert.h>
using namespace std;

#define MAX 200005
int s[MAX];  // C[]
int N = MAX-1;     // the number
int K[30005];
inline int lowbit(int x)
{
    return x&(x^(x-1));
}
//1D
void change(int a,int delta)
{
    for(int x=a; x<=N; x+=lowbit(x))
        s[x]+=delta;
}
int sum(int a)
{
    int res=0;
    for(int x=a; x>0; x-=lowbit(x))
        res+=s[x];
    return res;
}
int main()
{
    //freopen("4329.txt","r",stdin);
    int t; cin>>t;
    for(int i=0; i<t; i++)
    {
        memset(K, 0, sizeof(K));
        memset(s, 0, sizeof(s));
        int num; scanf("%d", &num);
        for(int i=0; i<num; i++) scanf("%d", &K[i]);
        long long ret = 0;
        long long ret2 =0;
        int LA[30005],LB[30005],LC[30005],LD[30005];
        for(int i=0; i<num; i++)
        {
            LA[i]= sum(K[i]);
            LB[i]= sum(N) - LA[i];
            change(K[i],1);
        }
        memset(s, 0, sizeof(s));
        for(int i=num-1; i>=0; i--)
        {
            LC[i] = sum(K[i]);
            LD[i] = sum(N) - LC[i];
            change(K[i],1LL);
        }
        for(int i=0; i<num; i++)
        {
            ret += LA[i]*1LL * LD[i];
            ret += LB[i]*1LL * LC[i];
        }
        cout<<"ret "<<ret<<endl;

    }
    return 0;
}

