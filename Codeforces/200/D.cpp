#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

#define LL(a)   a<<1
#define RR(a)   a<<1|1
const int MaxL = 500010;

int pre[MaxL];  // first travel
int nxt[MaxL];  // nxt travel
int fa[MaxL];
bool vis[MaxL];
int N;
vector<vector<int> > E(MaxL);

struct SegmentTree
{
    struct Seg_Tree
    {
        int left, right;
        int sum;
        int lazy;
    } tt[MaxL<<2];

    void PushUp(int idx)
    {
        tt[idx].sum = tt[LL(idx)].sum + tt[RR(idx)].sum;
    }

    void PushDown(int idx)
    {
        if(tt[idx].lazy)
        {
            tt[LL(idx)].lazy = tt[idx].lazy;
            tt[RR(idx)].lazy = tt[idx].lazy;
            int len =(tt[idx].right - tt[idx].left +1);
            tt[LL(idx)].sum  = (tt[idx].lazy-1) * (len - (len>>1));
            tt[RR(idx)].sum  = (tt[idx].lazy - 1) * (len >>1);
            tt[idx].lazy = 0;
        }
    }
    void build(int l,int r,int idx)
    {
        tt[idx].left = l;
        tt[idx].right = r;
        tt[idx].lazy = 0;
        if (l == r)
        {
            tt[idx].sum = 0;
            return ;
        }
        int mid = (l + r) >> 1;
        build(l,mid, LL(idx));
        build(mid+1, r, RR(idx));
        PushUp(idx);
    }

    // range update
    void update(int l,int r,int c, int idx)
    {
        if( l== tt[idx].left && r == tt[idx].right)
        {
            tt[idx].lazy = 1+c;
            tt[idx].sum  = c * (r - l + 1);
            return ;
        }
        PushDown(idx);
        int mid = (tt[idx].left + tt[idx].right) >> 1;
        if( mid >= r) update(l,r,c,LL(idx));
        else if(mid < l) update(l,r,c,RR(idx));
        else
        {
            update(l,mid,c, LL(idx));
            update(mid+1, r, c, RR(idx));
        }
        PushUp(idx);
    }

    // range query
    int query(int l,int r,int idx)
    {
        if(l == tt[idx].left && r == tt[idx].right)
        {
            return tt[idx].sum;
        }
        PushDown(idx);
        int mid =(tt[idx].left + tt[idx].right)>>1;
        if(mid >= r)
            return query(l,r,LL(idx));
        else if(mid < l)
            return query(l,r,RR(idx));
        else
            return query(l,mid,LL(idx)) + query(mid+1,r,RR(idx));
    }
} sg;

int mark = 0;
void dfs( int a)
{
    vis[a] = 1;
    pre[a] = ++mark;
    for(int i=0; i<E[a].size(); i++)
    {
        if(!vis[E[a][i]])
            dfs(E[a][i]);
    }
    nxt[a] = mark;
}

int main()
{
    scanf("%d", &N);
    memset(pre, 0, sizeof(pre));
    memset(nxt, 0 ,sizeof(nxt));
    memset(vis, 0 ,sizeof(vis));
    memset(fa,0, sizeof(fa));
    for(int i=1; i<N; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        E[a].push_back(b);
        E[b].push_back(a);
        if(a>b) swap(a,b);
        fa[b] = a;
    }
    mark = 0;
    fa[1] =1;
    dfs(1);
    sg.build(1, mark, 1);
    int Q;
    scanf("%d", &Q);
    for(int i=0; i<Q; i++)
    {
        int op, p;
        scanf("%d%d", &op, &p);
        if(op == 1)
        {
            // fill
            int sum = sg.query(pre[p],nxt[p],1);
            if(sum != nxt[p] - pre[p] +1)
                sg.update(pre[fa[p]], pre[fa[p]], 0,1);
            sg.update(pre[p], nxt[p], 1, 1);
        }
        else if(op == 2)
        {
            //empty
            sg.update(pre[p], pre[p], 0, 1);
        }
        else if(op == 3)
        {
            // query
            if( sg.query(pre[p],nxt[p],1) != nxt[p] -pre[p]+1)
                printf("0\n");
            else printf("1\n");
        }
    }
    return 0;
}
