/** 
TLE when using the queue SPFA Algorithm

shortest Path Faster Algorithm

  using queue to realize Bellmaford algorithm.Can be used when there are negative edge weights.
Theory: Only those in the pre-relax step can change the value of the current.

used for Directed Graph
Time complexity O(kE) K<=2
 */

#include <queue>
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
#define MAXN 30010      // vertex
#define MAXM 150010      // edge
#define INF 0x3F3F3F3F

struct node
{
    int v, w, next;
}pnt[MAXM];

int head[MAXN];
int  dis[MAXN];
bool vis[MAXN];
int  cnt[MAXN];       // the number of the operation of push to Quque. negatvie cycle.
int num = 0;          // the index of the edge
int N ;               // the number of the vertex.
int M ;               // the number of edges
int src, sink;
void addedge(int  u, int v, int w)
{
    pnt[num].v = v; pnt[num].w= w;
    pnt[num].next = head[u]; head[u] = num++;
}

int SPFA()
{
    for(int i=0; i<=N; i++)
    {
        vis[i]=0; dis[i] = INF; cnt[i] = 0;
    }

    int Q[MAXM], top=1;
    Q[0] = src; vis[src] = 1;
    dis[src] = 0;
    while(top)
    {
        int u = Q[--top]; vis[u] = 0;
        for(int i = head[u]; i!=-1; i=pnt[i].next)
        {
            int v = pnt[i].v;
            if(dis[v]> dis[u] + pnt[i].w )
            {
                dis[v]= dis[u] +pnt[i].w;
                if(!vis[v])
                {
                    Q[top++] = v; vis[v]= 1;
                }
            }

        }
    }



    return dis[sink];
}

int main()
{
    //freopen("3159.txt", "r", stdin);
    while(scanf("%d%d", &N , &M)!= EOF)
    {
        num = 0;
        memset(head, -1, sizeof(head)); 
        for(int i=0; i<M; i++)
        {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            addedge(a, b,c);
        }
        //cout<<num<<endl;
        src = 1; sink = N;
        //cout<<"src "<<src<<" sink "<<N<<endl;
        printf("%d\n", SPFA());
    }
    return 0;
}
