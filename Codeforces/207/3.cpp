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
template<class T> inline vector<pair<T,int> > factorize(T n)
{
    vector<pair<T,int> > R;
    for (T i=2; n>1;)
    {
        if (n%i==0)
        {
            int C=0;
            for (; n%i==0; C++,n/=i);
            R.push_back(make_pair(i,C));
        }
        i++;
        if (i>n/i) i=n;
    }
    if (n>1) R.push_back(make_pair(n,1));
    return R;
}
template<class T> inline bool isPrimeNumber(T n)
{
    if(n<=1)return false;
    for (T i=2; i*i<=n; i++) if (n%i==0) return false;
    return true;
}
template<class T> inline T eularFunction(T n)
{
    vector<pair<T,int> > R=factorize(n);
    T r=n;
    for (int i=0; i<R.size(); i++)r=r/R[i].first*(R[i].first-1);
    return r;
}
template<class T> string toString(T n)
{
    ostringstream ost;
    ost<<n;
    ost.flush();
    return ost.str();
}
int toInt(string s)
{
    int r=0;
    istringstream sin(s);
    sin>>r;
    return r;
}

int i,j,k;
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
int dirx[]= {1, 1, 0,-1,-1,-1,0,1};
int diry[]= {0,-1,-1,-1, 0, 1,1,1}; //clockwise

#define LL(a)   a<<1
#define RR(a)   a<<1|1

const int MaxL = 300005;
struct Seg_tree
{
    int left, right;
    int winner;
    int lazy;
} tt[MaxL<<2];


void PushDown(int idx)
{
    // just update for the first depth subtree
    // if a node has a lazy taq, the subtree need to be updated, and the whole interval is dirty
    if(tt[idx].lazy!=-1)
    {
        tt[LL(idx)].lazy = tt[RR(idx)].lazy = tt[idx].lazy;
        if(tt[LL(idx)].winner == 0) tt[LL(idx)].winner = tt[idx].winner;
        if(tt[RR(idx)].winner == 0) tt[RR(idx)].winner = tt[idx].winner;
//        tt[LL(idx)].asum = tt[LL(idx)].lsum = tt[LL(idx)].rsum = tt[idx].lazy ? 0: len-(len>>1);
//        tt[RR(idx)].asum = tt[RR(idx)].lsum = tt[RR(idx)].rsum = tt[idx].lazy ? 0: len>>1;
        tt[idx].lazy = -1;
    }
}

//void PushUp(int idx, int len)
//{
////    tt[idx].lsum = tt[LL(idx)].lsum;
////    tt[idx].rsum = tt[RR(idx)].rsum;
//    // If cover the whole interval, update
////    if(tt[idx].lsum == len - (len >>1))  tt[idx].lsum += tt[RR(idx)].lsum;
////    if(tt[idx].rsum == len>>1) tt[idx].rsum += tt[LL(idx)].rsum;
////    tt[idx].asum = max(tt[LL(idx)].rsum + tt[RR(idx)].lsum, max(tt[LL(idx)].asum , tt[RR(idx)].asum));
//}

void build(int l,int r,int idx)
{
    tt[idx].left = l, tt[idx].right = r;
    tt[idx].winner = 0;
    tt[idx].lazy = -1;  // unused
    if (l == r) return ;
    int m = (l + r) >> 1;
    build(l,m, LL(idx));
    build(m+1, r, RR(idx));
}

// val 1 for check in / val 0 for check out
void update(int l, int r, int val, int idx)
{
//    cout<<l<<" "<<r<<" winner "<<val<<endl;
//    cout<<l<<" "<<r<<" winner "<<val<<endl;
    if(l == tt[idx].left && r == tt[idx].right)
    {
//        tt[idx].asum = tt[idx].rsum = tt[idx].lsum = val? 0: r-l+1;
        if(tt[idx].winner == 0)
        {
            tt[idx].winner = val;
            tt[idx].lazy = 1;
        }
        return ;
    }
    PushDown(idx);
    int mid = (tt[idx].left + tt[idx].right)>>1;
    if(r <= mid) update(l,r,val, LL(idx));
    else if(l> mid) update(l,r,val, RR(idx));
    else
    {
        update(l, mid, val, LL(idx));
        update(mid+1, r, val, RR(idx));
    }
//    PushUp(idx, tt[idx].right-tt[idx].left+1);
}

////there must have a valid interval
//int query(int idx, int len)
//{
//    if(tt[idx].left == tt[idx].right ) return tt[idx].left;
//    PushDown(idx, tt[idx].right-tt[idx].left+1);
//    int mid = (tt[idx].left + tt[idx].right)>>1;
//    if(tt[LL(idx)].asum >= len) return query(LL(idx),len);
//    else if(tt[LL(idx)].rsum + tt[RR(idx)].lsum >=len) return mid - tt[LL(idx)].rsum+1;
//    else return query(RR(idx), len);
//}

int query(int p,  int idx)
{
    if(tt[idx].left == tt[idx].right)
    {
//        tt[idx].num = val;
        return tt[idx].winner;
    }
    PushDown(idx);
    int mid = (tt[idx].left+ tt[idx].right)>>1;
    if(p <= mid)
        query(p, LL(idx));
    else
        query(p, RR(idx));
//    PushUp(idx);
}
////there must have a valid interval
//int query2( int idx, int len)
//{
//    if(tt[idx].left == tt[idx].right ) return tt[idx].left;
//    PushDown(idx, tt[idx].right-tt[idx].left+1);
//    // another way to implement (more quick??)
//    if(tt[idx].lsum >= len) return tt[idx].left;
//    else
//    {
//        int mid = (tt[idx].left + tt[idx].right)>>1;
//        if(tt[LL(idx)].asum >= len) return query(LL(idx),len);
//        else if(tt[LL(idx)].rsum + tt[RR(idx)].lsum >=len) return mid - tt[LL(idx)].rsum+1;
//        else return query(RR(idx), len);
//    }
//}


int main()
{
    ios_base::sync_with_stdio(0);
//    freopen("1.txt","r",stdin);
    int n,m;
    cin>>n>>m;
    build(1, n, 1);
    int a,b,w;
    for(int i=1; i<=m; i++)
    {
        cin>>a>>b>>w;
        if(a == w) update(a+1,b,w,1);
        else if(b == w) update(a,b-1,w,1);
        else
        {
            update(a,w-1,w,1);
            update(w+1,b,w,1);
        }
    }
    for(int i=1; i<=n; i++)
        cout<<query(i, 1)<<" ";
    cout<<endl;

    return 0;
}
