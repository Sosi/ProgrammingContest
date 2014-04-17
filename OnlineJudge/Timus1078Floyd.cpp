
#include <queue>
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
#define V 505      // vertex
#define INF 0x3F3F3F3F
int N; 
int dis[V][V];
int path[V][V];

// normal distance.
void floyd()
{
    for(int k=1;k<=N;k++)
    {
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                if(dis[i][k]== -INF || dis[k][j] == -INF) continue;
                if(dis[i][k] + dis[k][j] > dis[i][j])
                {
                    dis[i][j] = dis[i][k] + dis[k][j];
                    path[i][j] = path[i][k];
                }

            }
        }
    }
}
void floyd_path(int i, int j)
{
    int k=path[i][j];
    while(k!=j)
    {
        printf(" %d", k );
        k= path[k][j];
    }
}

int main()
{
    //freopen("1078.txt","r",stdin);
    scanf("%d", &N);
    int a, b;
    vector<pair<int, int> > C;
    memset(dis, 0 ,sizeof(dis));
    for(int i=0; i<N; i++)
    {
        scanf("%d%d", &a, &b);
        C.push_back(make_pair(a,b));
        for(int i=0; i<C.size(); i++)
        {
            if(a<C[i].first && b> C[i].second)
            {
                dis[i+1][C.size()] = 1;
                path[i+1][C.size()] = C.size();
            }
            else if(a> C[i].first && b< C[i].second)
            {
                dis[C.size()][i+1]=1;
                path[C.size()][i+1] = i+1;
            }
        }
    }
    for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) if(dis[i][j]==0) dis[i][j]=-INF;
    floyd();
    int ret = 0;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            if(dis[i][j] > ret)
            {
                ret = dis[i][j];
                a = i; b = j;
            }
        }
    }
    if(ret == 0) 
    {
        cout<<1<<endl;
        cout<<1<<endl;
    }else
    {
        cout<<ret+1<<endl;
        cout<<a;
        floyd_path(a,b);
        cout<<" "<<b<<endl;
    }
    return 0;
}


