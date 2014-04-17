/**
search the longest path , just jude whether there are a positve cycle.

*/

#include <queue>
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
#define V 3000      // vertex
#define E 1500      // edge
#define INF 1000000.0f

struct node
{
    int v, next;
    double R,C,w;
}pnt[E];

int head[V];
double  dis[V];
bool vis[V];
int  cnt[V];          // the num of the operation of push to Quque. negatvie cycle.
int e = 0;            // the index of the edge
int N ;               // the num of the vertex.
int M ;               // the num of edges
int src, sink;
double val;
void addedge(int  u, int v, double R, double C)
{
    pnt[e].v = v; pnt[e].w= 0;
    pnt[e].R = R; pnt[e].C = C;
    pnt[e].next = head[u]; head[u] = e++;
}
void SPFA_init()
{
    e=0;
    memset(head, -1,sizeof(head));
    memset(vis, 0 ,sizeof(vis));
    memset(cnt, 0 ,sizeof(cnt));
    for(int i=0; i<=N; i++) dis[i] = 0;
}
int SPFA()
{
    queue<int> Q;
    Q.push(src); vis[src] = 1; dis[src] = val; ++cnt[src]; 
    while(!Q.empty()) 
    {
        int u = Q.front(); Q.pop();  vis[u] = 0;
        for(int i=head[u]; i!=-1; i=pnt[i].next)
        {
            int v = pnt[i].v;
            pnt[i].w = (dis[u] - pnt[i].C)*pnt[i].R - dis[u];
            //cout<<u<<" to "<<v<<" "<<pnt[i].w<<endl;
            if( dis[v] < dis[u] + pnt[i].w  )
            {
                dis[v] = dis[u] + pnt[i].w;
                //cout<<u<<" to "<<v<<"  "<<pnt[i].w<<" "<<dis[v]<<endl;
                if(!vis[v]) { Q.push(v); vis[v] = 1;}
                if( ++cnt[v] > N) return -1; // negative cycle.
            }
        }
    }
    return 1;
    //if(dis[sink] == INF) return -2;          // can't from src to sink. 
    //return dis[sink];
}

int main()
{
    freopen("1860.txt","r",stdin);
    scanf("%d%d", &N , &M);

    scanf("%d", &src);
    //cout<<src<<endl;
    scanf("%lf", &val);
    //cout<<val<<endl;
    SPFA_init();
    for(int i=0; i<M; i++)
    {
        int a, b; double Rab, Cab, Rba,Cba;
        scanf("%d%d", &a, &b);
        scanf("%lf%lf", &Rab, &Cab);
        scanf("%lf%lf", &Rba, &Cba);
        addedge(a, b,Rab, Cab);
        addedge(b,a,Rba, Cba);
        //cout<<Rab<<" "<<Cab<<" "<<Rba<<" "<<Cba<<endl;
    }
    int ret = SPFA();
    if(ret == -1)  cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
