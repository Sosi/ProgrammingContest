/**
  using Priority_Queue to optimize the the Dijkstra algorithm

next : cluster according to the begin point of the edge.
head[u]: the first edge of begin with u;

Time Complexity O(ElogV)
 */

#include <iostream> 
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
#include <stdio.h>
using namespace std;

#define V   2000020
#define E   6000020
#define INF (1LL<<59)         

// v :the end point of an edge. w : the weight of the weight next:cluster according to the begin point of the edge
struct node
{
    int v,next;
    long long w;
    node(int vv=0, long long ww=0LL):v(vv),w(ww){}
    bool operator < (const node& r) const{return w> r.w;}
}pnt[E];

int e=0,N;

int head[V];
long long dis[V];
bool vis[V];
int src,sink;

long long Dijkstra()
{
    priority_queue<node> Q; 
    vis[src] = 1; dis[src] = 0LL; 
    Q.push(node(src,0LL)); 
    for (int u = src, i=1; i< N; i++)                 
    {
        for (int j = head[u]; j != -1; j = pnt[j].next)      // j is edge number.
        { 
            int v = pnt[j].v;
            if (vis[v] == 0 && dis[v] > dis[u] + pnt[j].w ) // u is the current vertex
            { 
                dis[v] = dis[u] + pnt[j].w;
                Q.push(node(v,dis[v]));
            } 
        } 
        while (!Q.empty() && vis[Q.top().v]) Q.pop(); 
        if (Q.empty()) break;
        vis[u = Q.top().v] = 1;
        if(u==sink) return dis[sink];
        Q.pop();
    }
    return 0LL;
} 

inline void addedge(int u, int v, int w){
    pnt[e].v = v; pnt[e].w = w; pnt[e].next= head[u]; head[u]=e++;
} 

int Dijkstra_init()
{
    memset(head, -1, sizeof(head));
    memset(vis, 0, sizeof(vis)); 
    int n; scanf("%d", &n);
    if(n==0) return 0;
    N = 2*n+2; 
    int a,b,c,d; scanf("%d%d%d%d", &a,&b,&c,&d);
    if(a==0) src = b; else src = n+1+b;
    if(c==0) sink = d; else sink = n+1+d;
    //cout<<"src "<<src<<endl;
    //cout<<"sink "<<sink<<endl;
    int temp; e=0;
    for(int i=0; i<n; i++)
    {
        scanf("%d", &temp);
        addedge(i,i+1,temp); addedge(i+1,i, temp);
    }
    for(int i=0; i<=n; i++)
    {
        scanf("%d", &temp);
        addedge(i, i+n+1, temp); addedge(i+n+1,i, temp);
    }
    for(int i=0; i<n; i++)
    {
        scanf("%d", &temp);
        addedge(n+1+i, n+2+i, temp); addedge(n+2+i,n+1+i, temp);
    }
    for (int i = 0; i < N; i++) dis[i] = INF;
    return 1;
} 

int main()
{
    //freopen("3377.txt","r",stdin);
    while(Dijkstra_init())
    {
        //Dijkstra();
        printf("%lld\n", Dijkstra());
    }
    return 0;
}


