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
        int tag; // time tag
        int lazy;
    } tt[MaxL<<3];

    void PushUp(int idx)
    {
        tt[idx].tag = max( tt[idx].tag, max( tt[LL(idx)].tag, tt[RR(idx)].tag));
    }

    void PushDown(int idx)
    {
        if(tt[idx].lazy)
        {
            tt[LL(idx)].lazy = tt[idx].lazy;
            tt[RR(idx)].lazy = tt[idx].lazy;
            tt[LL(idx)].tag = max(tt[idx].tag, tt[LL(idx)].tag);
            tt[RR(idx)].tag = max(tt[idx].tag, tt[RR(idx)].tag);
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
            tt[idx].tag = 0;
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
            tt[idx].lazy = 1;
            tt[idx].tag  = c;
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
            return tt[idx].tag;
        }
        PushDown(idx);
        int mid =(tt[idx].left + tt[idx].right)>>1;
        if(mid >= r)
            return query(l,r,LL(idx));
        else if(mid < l)
            return query(l,r,RR(idx));
        else
            return max(query(l,mid,LL(idx)), query(mid+1,r,RR(idx)));
    }
} sg0;


struct SG
{
    struct Seg_Tree
    {
        int left, right;
        int tag; // time tag
        int lazy;
    } tt[MaxL<<3];

    void PushUp(int idx)
    {
//        tt[idx].tag = max( tt[idx].tag, max( tt[LL(idx)].tag, tt[RR(idx)].tag));
    }

    void PushDown(int idx)
    {
        if(tt[idx].lazy)
        {
            tt[LL(idx)].lazy = tt[idx].lazy;
            tt[RR(idx)].lazy = tt[idx].lazy;
            tt[LL(idx)].tag = max(tt[idx].tag, tt[LL(idx)].tag);
            tt[RR(idx)].tag = max(tt[idx].tag, tt[RR(idx)].tag);
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
            tt[idx].tag = 0;
//            cout<<"--- "<<l<<" "<<r<<" "<<tt[idx].tag<<endl;
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
            tt[idx].lazy = 1;
            tt[idx].tag  = c;
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
//            cout<<"=== "<<l<<" "<<r<<" "<<tt[idx].tag<<endl;
            return tt[idx].tag;
        }
        PushDown(idx);
        int mid =(tt[idx].left + tt[idx].right)>>1;
        if(mid >= r)
            return query(l,r,LL(idx));
        else if(mid < l)
            return query(l,r,RR(idx));
        else
            return max(query(l,mid,LL(idx)), query(mid+1,r,RR(idx)));
    }
} sg1;
// 建立 一棵0树和一棵1树,然后比较两者修改的时间戳最大的谁更大即可!

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
    nxt[a] = ++mark;
}

int main()
{
//    freopen("1.txt","r",stdin);
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
    sg0.build(1, 2*N, 1);
    sg1.build(1, 2*N, 1);

//    cout<<"?"<<endl;
//    for(int i=1; i<=N; i++)
//    {
//        cout<<i<<" ! "<<sg1.query(pre[i], nxt[i], 1)<<endl;
//    }
//    cout<<"! "<<endl;
//    for(int i=1; i<=N; i++)
//    {
//        cout<<i<<" ! "<<sg0.query(pre[i], nxt[i], 1)<<endl;
//    }


    int Q;
    scanf("%d", &Q);
    for(int i=1; i<=Q; i++)
    {
        int op, p;
        scanf("%d%d", &op, &p);
//        cout<<"op "<<op<<" "<<p<<endl;
        if(op == 1)
        {
            // fill
            // 1号 seg 是不应该pushup的!
            sg1.update(pre[p],nxt[p], i, 1);
//            cout<<"?"<<endl;
//            for(int i=1; i<=N; i++)
//            {
//                cout<<i<<" ! "<<sg1.query(pre[i], nxt[i], 1)<<endl;
//            }
//            cout<<"! "<<endl;
//            for(int i=1; i<=N; i++)
//            {
//                cout<<i<<" ! "<<sg0.query(pre[i], nxt[i], 1)<<endl;
//            }
        }
        else if(op == 2)
        {
            //empty
            sg0.update(pre[p], pre[p], i, 1);
            sg0.update(nxt[p], nxt[p], i, 1);
//            cout<<"! "<<endl;
//            for(int i=1; i<=N; i++)
//            {
//                cout<<i<<" ! "<<sg0.query(pre[i], nxt[i], 1)<<endl;
//            }
        }
        else if(op == 3)
        {
            // query
            int t1 = sg1.query(pre[p],nxt[p],1);
            int t0 = sg0.query(pre[p],nxt[p],1);
//            cout<<"Query "<<endl;
//            cout<< t1<<" "<<t0<<endl;
            // 注意初始时刻如果相同的话,应该是0
            if(t0 >= t1) printf("0\n");
            else printf("1\n");
        }
    }
    return 0;
}
