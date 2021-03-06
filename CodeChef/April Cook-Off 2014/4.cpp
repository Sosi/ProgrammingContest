#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <iostream>
#include <ctime>
#include <cassert>
#include <sstream>

using namespace std;

#define INF 0x3f3f3f3f
#define ll long long
#define SZ(x) (int)((x).size())
#define MAXN 300

int n;
map<string,int> mymap;
vector<int> filhos[MAXN];
int mano[MAXN][MAXN];
int adj[MAXN][MAXN];

int main()
{
    int m,t = 1;
    cin.sync_with_stdio(false);
    cin>>n>>m;
    memset(adj,INF,sizeof(adj));
    while (m--)
    {
        string A,is,F,of,B;
        cin>>A>>is>>F>>of>>B;
        int u,v;
        if (!mymap[A]) mymap[A] = t++;
        if (!mymap[B]) mymap[B] = t++;
        u = mymap[A];
        v = mymap[B];
        if (F == "father") filhos[u].push_back(v), adj[u][v] = adj[v][u] = 1;
        if (F == "mother") filhos[u].push_back(v), adj[u][v] = adj[v][u] = 1;
        if (F == "sister" || F == "brother") mano[u][v] = mano[v][u] = adj[u][v] = adj[v][u] = 1;
        if (F == "son") filhos[v].push_back(u), adj[u][v] = adj[v][u] = 1;
        if (F == "daughter") filhos[v].push_back(u), adj[u][v] = adj[v][u] = 1;
    }



    while (true)
    {
        bool changed = false;
        for (int i=1; i<t; i++)
        {
            for (int j=0; j<int(filhos[i].size()); j++)
            {
                int v = filhos[i][j];
                for (int k=1; k<t; k++)
                    if (mano[v][k] && adj[i][k] > 1)
                    {
                        adj[i][k] = adj[k][i] = 1;
                        filhos[i].push_back(k);
                        changed = true;
                    }
            }

            for (int j=0; j<int(filhos[i].size()); j++)
                for (int k=j+1; k<int(filhos[i].size()); k++)
                {
                    int u = filhos[i][j], v = filhos[i][k];
                    if (adj[u][v] > 1)
                    {
                        adj[u][v] = adj[v][u] = 1;
                        mano[u][v] = mano[v][u] = 1;
                        changed = true;
                    }
                }

            for (int j=1; j<t; j++)
                if (mano[i][j])
                {
                    for (int k=1; k<t; k++)
                        if (mano[j][k] && !mano[i][k] && k != i)
                        {
                            mano[i][k] = mano[k][i] = 1;
                            adj[i][k] = adj[k][i] = 1;
                            changed = true;
                        }
                }
        }
        if (!changed) break;
    }

    for (int k=1; k<t; k++)
        for (int i=1; i<t; i++)
            for (int j=1; j<t; j++)
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

    int Q;
    cin>>Q;
    while (Q--)
    {
        string x,y;
        cin>>x>>y;
        int ans = adj[mymap[x]][mymap[y]];
        if (ans == INF) ans = -1;
        printf("%d\n",ans);
    }

    return 0;
}

