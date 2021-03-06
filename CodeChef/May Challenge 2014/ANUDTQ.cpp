#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
inline LL getnum()
{
    LL ans=0,fh=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')fh*=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')ans=ans*10+ch-'0',ch=getchar();
    return fh*ans;
}
int n;
struct point
{
    int haed,f,ds,de;
    LL val;
} p[210000];
struct edge
{
    int next,to;
} g[610000];
int gnum;
inline void addedge(int from,int to)
{
    g[++gnum].to=to;
    g[gnum].next=p[from].haed;
    p[from].haed=gnum;
    g[++gnum].to=from;
    g[gnum].next=p[to].haed;
    p[to].haed=gnum;
}
struct node
{
    int s[2],f,ws;
    LL sum,size,num,iadd;
} t[810000];
int tnum,root;
void output()
{
    cerr<<"========real tree========"<<endl;
    for(int i=1; i<=n; i++)
        cerr<<i<<" f="<<p[i].f<<" ds="<<p[i].ds<<" de="<<p[i].de<<" val="<<p[i].val<<endl;
    cerr<<"========splay tree======="<<endl;
    cerr<<root<<endl;
    for(int i=1; i<=tnum; i++)
        cerr<<i<<" f="<<t[i].f<<" ls="<<t[i].s[0]<<" rs="<<t[i].s[1]<<" ws="<<t[i].ws<<" sum="
            <<t[i].sum<<" num="<<t[i].num<<" size="<<t[i].size<<" iadd="<<t[i].iadd<<endl;
    cerr<<"========================="<<endl;
}
inline void setson(int f,int s,int ws)
{
    t[t[s].f=f].s[t[s].ws=ws]=s;
}
inline void maintain(int po)
{
    t[po].size=1;
    t[po].sum=t[po].num;
    if(t[po].s[0])t[po].sum+=t[t[po].s[0]].sum,t[po].size+=t[t[po].s[0]].size;
    if(t[po].s[1])t[po].sum+=t[t[po].s[1]].sum,t[po].size+=t[t[po].s[1]].size;
}
inline void pushdown(int po)
{
    if(po&&t[po].iadd)
    {
        if(t[po].s[0])
        {
            t[t[po].s[0]].sum+=t[t[po].s[0]].size*t[po].iadd;
            t[t[po].s[0]].num+=t[po].iadd;
            t[t[po].s[0]].iadd+=t[po].iadd;
        }
        if(t[po].s[1])
        {
            t[t[po].s[1]].sum+=t[t[po].s[1]].size*t[po].iadd;
            t[t[po].s[1]].num+=t[po].iadd;
            t[t[po].s[1]].iadd+=t[po].iadd;
        }
        t[po].iadd=0;
    }
}
inline void rotate(int po,int ws)
{
    int son=t[po].s[ws];
    if(po==root)t[root=son].f=0;
    else setson(t[po].f,son,t[po].ws);
    setson(po,t[son].s[!ws],ws);
    setson(son,po,!ws);
    maintain(po);
    maintain(son);
}
inline void splay(int po,int father)
{
    while(t[po].f!=father)
    {
        int fa=t[po].f,gf=t[fa].f;
        pushdown(gf);
        pushdown(fa);
        pushdown(po);
        if(gf==father)
        {
            rotate(fa,t[po].ws);
            break ;
        }
        if(t[po].ws==t[fa].ws)rotate(gf,t[fa].ws);
        rotate(fa,t[po].ws);
    }
    pushdown(po);
}
void dfs(int po)
{
    p[po].ds=++tnum;
    t[tnum].num=p[po].val;
    for(int i=p[po].haed; i; i=g[i].next)
        if(g[i].to!=p[po].f)
            p[g[i].to].f=po,dfs(g[i].to);
    p[po].de=++tnum;
    t[tnum].num=p[po].val;
}
int buildtree(int l,int r)
{
    int mid=(l+r)/2;
    if(l<mid)setson(mid,buildtree(l,mid-1),0);
    if(mid<r)setson(mid,buildtree(mid+1,r),1);
    maintain(mid);
    return mid;
}
inline LL getsum(int po)
{
    splay(p[po].ds,0);
    splay(p[po].de,p[po].ds);
    return t[t[p[po].de].s[0]].sum/2+t[p[po].ds].num;
}
int main(int argc, char *argv[])
{
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    n=getnum();
    for(int i=1; i<=n; i++)p[i].val=getnum();
    for(int i=1; i<n; i++)addedge(getnum()+1,getnum()+1);
    dfs(1);
    root=buildtree(1,tnum);
    int m=getnum();
    LL lastans=0;
    while(m--)
    {
        int choice=getnum();
        if(choice==1)
        {
            p[++n].f=getnum()+lastans+1;
            p[n].val=getnum();
            addedge(p[n].f,n);
            splay(p[p[n].f].ds,0);
            int succ=t[p[p[n].f].ds].s[1];
            while(t[succ].s[0])succ=t[succ].s[0];
            splay(succ,p[p[n].f].ds);
            t[p[n].ds=++tnum].num=p[n].val;
            t[p[n].de=++tnum].num=p[n].val;
            setson(p[n].ds,p[n].de,1);
            maintain(p[n].de);
            maintain(p[n].ds);
            setson(succ,p[n].ds,0);
            maintain(succ);
            maintain(p[p[n].f].ds);
        }
        if(choice==2)
        {
            int key=getnum()+lastans+1,value=getnum();
            splay(p[key].ds,0);
            splay(p[key].de,p[key].ds);
            t[t[p[key].de].s[0]].iadd+=value;
            t[t[p[key].de].s[0]].num+=value;
            t[t[p[key].de].s[0]].sum+=value*t[t[p[key].de].s[0]].size;
            t[p[key].de].num+=value;
            t[p[key].ds].num+=value;
            maintain(p[key].de);
            maintain(p[key].ds);
        }
        if(choice==3)
        {
            int key=getnum()+lastans+1;
            splay(p[key].ds,0);
            int pred=t[p[key].ds].s[0];
            while(t[pred].s[1])pred=t[pred].s[1];
            splay(p[key].de,0);
            int succ=t[p[key].de].s[1];
            while(t[succ].s[0])succ=t[succ].s[0];
            splay(pred,0);
            splay(succ,pred);
            t[succ].s[0]=0;
            maintain(succ);
            maintain(pred);
        }
        if(choice==4)printf("%lld\n",lastans=getsum(getnum()+lastans+1));
    }
    return 0;
}
