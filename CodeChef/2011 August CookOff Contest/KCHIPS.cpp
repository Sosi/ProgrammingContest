#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define MX 100005
#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define F first
#define S second
#define SZ(v) ((int)((v).size()))
#define SI ({int x;scanf("%d",&x);x;})

int B[MX], V[MX], sz[MX], ans[MX];
pair<int,int> srtv[MX];
pair<int,pair<int,int> > Q[MX];
vector<int> ind[MX];
int tot, N, K, R;

void update(int x,int v){ for(;x<=N;x+=x&-x) B[x]+=v; }
int query(int x){ int r=0; for(;x;x-=x&-x) r+=B[x]; return r; }

int main()
{
    N = SI; K = SI + 1;

    for(int i=0;i<N;i++) srtv[i] = MP(SI,i+1);        //first ��ׯ��  second ����
    //normalize
    sort(srtv,srtv+N);

    for(int i=0,k=0;i<N;i++)
    {
        if(i>0 && srtv[i].F!=srtv[i-1].F) k++;
        V[srtv[i].S] = k;
    }
    R = SI;
    for(int i=0;i<R;i++)
    {
        int x = SI + 1, y = SI + 1;
        Q[i] = MP(y,MP(x,i));
    }

    sort(Q,Q+R);
    tot = 0;
    for(int i=1,j=0;i<=N;i++)
    {
        int v = V[i], s = sz[v];
        if(s>=K) update(ind[v][s-K],-1);
        ind[v].PB(i);
        s = ++sz[v];
        if(s==K) tot++;
        if(s>=K) update(ind[v][s-K],+1);

        while(j<R && Q[j].F==i)
        {
            ans[Q[j].S.S] = tot - query(Q[j].S.F-1);
            j++;
        }
    }

    for(int i=0;i<R;i++) printf("%d\n",ans[i]);

    return 0;
}
