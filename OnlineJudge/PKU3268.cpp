/**
Using Dijkstra algorithm, and reverse the edge do another Dijkstra algorithm.
*/
#include <iostream> 
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
#include <stdio.h>
using namespace std;

#define V   1005
#define E   100005
#define INF 329999         

// v :the end point of an edge. w : the weight of the weight next:cluster according to the begin point of the edge
struct node
{
    int v, w,next;
    node(int vv=0, int ww=0):v(vv),w(ww){}
    bool operator < (const node& r) const{return w> r.w;}
}pnt[E],pnt1[E];

int e=0,N,M,s;

int head[V];
int dis[V];
bool vis[V];
int src, sink;

void Dijkstra()
{ 
    priority_queue<node> Q; 
    vis[src] = 1; dis[src] = 0; 
    Q.push(node(src, 0)); 
    for (int u = src, i=1; i< N; i++)                 
    { 
        for (int j = head[u]; j != -1; j = pnt[j].next)    // j is edge number.
        { 
            int v = pnt[j].v;                          
            if (vis[v] == 0 && dis[v] > dis[u] + pnt[j].w )// pre is the current vertex
            { 
                dis[v] = dis[u] + pnt[j].w; 
                Q.push(node(v, dis[v]));
            } 
        } 
        while (!Q.empty() && vis[Q.top().v]) Q.pop(); 
        if (Q.empty()) break;
        vis[u = Q.top().v] = 1; Q.pop();
    }
} 
int head1[V];
inline void addedge1(int u, int v, int w)
{
    pnt1[s].v =v; pnt1[s].w = w; pnt1[s].next = head1[u]; head1[u]=s++;
}
inline void addedge(int u, int v, int w){ 
    pnt[e].v = v; pnt[e].w = w; pnt[e].next= head[u]; head[u]=e++;
} 

void Dijkstra_init()
{ 
    e = 0; s =0;
    memset(head, -1, sizeof(head)); 
    memset(head1, -1, sizeof(head));
    memset(vis, 0, sizeof(vis));
    scanf("%d%d", &N , &M);
    for (int i = 0; i <=N; i++) dis[i] = INF; 
    scanf("%d", &src);
    //cout<<src<<endl;
    for(int i=0; i<M; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        addedge(a, b, c);
        addedge1(b,a, c);
    }


} 

int main()
{
    //freopen("3268.txt","r",stdin);

    Dijkstra_init();
    Dijkstra();
    int dis1[V];
    for(int i=0; i<=N; i++) dis1[i] = dis[i];
    //for(int i=1; i<=N; i++) cout<<dis[i]<<" "; cout<<endl;
    memset(vis, 0 ,sizeof(vis));
    for(int i=0; i<=N; i++) { dis[i]= INF; head[i] = head1[i];}
    for(int i=0; i<M; i++)
    {
        pnt[i]=pnt1[i];

    }
    Dijkstra();
    //for(int i=1; i<=N; i++) cout<<dis[i]<<" "; cout<<endl;
    int ret = 0;
    for(int i=1; i<=N; i++) ret = max(ret, dis1[i]+dis[i]);
    cout<<ret<<endl;
    return 0;
}


