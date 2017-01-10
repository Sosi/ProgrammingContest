
#include <queue>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
#define V 30010      // vertex
#define E 150010      // edge
#define INF 0x3F3F3F3F

struct node
{
    int v, w, next;
}pnt[E];

int head[V];
int  dis[V];
bool vis[V];
int  cnt[V];          // the num of the operation of push to Quque. negatvie cycle.
int e = 0;            // the index of the edge
int N ;               // the num of the vertex.
int M ;               // the num of edges
int src, sink;
int father[V];
int ru[V];
void addedge(int  u, int v, int w)
{
    pnt[e].v = v; pnt[e].w= w;
    pnt[e].next = head[u]; head[u] = e++;
}
void SPFA_init()
{
    e=0;
    memset(head, -1,sizeof(head));
    memset(vis, 0 ,sizeof(vis));
    memset(cnt, 0 ,sizeof(cnt));
    for(int i=0; i<=N; i++) dis[i] = -1;          // MODIFIED
    memset(father, -1, sizeof(father));
}
int SPFA()
{
    queue<int> Q;
    for(int i=1; i<=N; i++) 
    {
        src = i;
        if(ru[i] == 0)
        {
            Q.push(src); vis[src] = 1; dis[src] = 0; ++cnt[src];
        }
    }
    while(!Q.empty()) 
    {
        int u = Q.front(); Q.pop();  vis[u] = 0;
        for(int i=head[u]; i!=-1; i=pnt[i].next)
        {
            int v = pnt[i].v;
            if( dis[v] < dis[u] + pnt[i].w  )          // MODIFIED
            {
                dis[v] = dis[u] + pnt[i].w;
                father[v] = u;
                if(!vis[v]) { Q.push(v); vis[v] = 1;}
                if( ++cnt[v] > N) return -1;   // positive  cycle.
            }
        }
    }
    if(dis[sink] == -1 ) return -2;            // can't from src to sink. 
    return dis[sink];
}

int main()
{
    //freopen("1078.txt","r",stdin);
    scanf("%d", &N);
    int a, b;
    vector<pair<int, int> > C;
    memset(ru, 0 ,sizeof(ru));
    SPFA_init();
    for(int i=0; i<N; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        C.push_back(make_pair(a,b));
        for(int i=0; i<C.size(); i++)
        {
            if(a<C[i].first && b> C[i].second)
            {
                ru[C.size()]++;
                addedge(i+1,C.size() , 1);
            }
            else if(a> C[i].first && b< C[i].second)
            {
                ru[i+1]++;
                addedge(C.size(), i+1,1);
            }
        }
    }
    SPFA();
    //for(int i=1; i<=N; i++) cout<<father[i]<<" "; cout<<endl;
    int ret  =0; int idx = -1;
    for(int i=1; i<=N; i++)
    {
        if(dis[i]>ret)
        {
            ret = dis[i];
            idx = i;
        }
    }
    if(ret == 0)
    {
        cout<<1<<endl;
        cout<<1<<endl;
    }
    else
    {
        cout<<ret+1<<endl;
        vector<int> D;
        D.push_back(idx);
        while(father[idx] != -1)
        {
            D.push_back(father[idx]);
            idx = father[idx];
        }
        reverse(D.begin(), D.end());
        for(int i=0; i<D.size(); i++) cout<<D[i]<<" ";
        cout<<endl;
    }
    return 0;
}

