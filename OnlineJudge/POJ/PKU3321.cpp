/**
  linearize the tree using Depth first search, save the first and last time of travel of the specific node. The subtree's travel is just between them.

  BIT
 */
#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
using namespace std;

#define MAX 200002

int s[MAX];
bool apple[MAX];
int pre[MAX];  // first travel
int nxt[MAX];  // nxt travel
bool vis[MAX];
int N;
vector<vector<int> > E(MAX);
inline int lowbit(int x)
{
    return x&(x^(x-1));
}
void change(int a, int delta)
{
    for(int x=a; x<=N; x+=lowbit(x))
        s[x]+=delta;
}
int sum(int a)
{
    int res= 0;
    for(int x=a; x>0; x-=lowbit(x))
        res+= s[x];
    return res;
}
int mark = 1;
void dfs( int a)
{
    vis[a] = 1;
    pre[a] = mark++;
    for(int i=0; i<E[a].size(); i++)
    {
        if(!vis[E[a][i]])
            dfs(E[a][i]);
    }
    nxt[a] = mark++;
}
int main()
{
    //freopen("3321.txt","r",stdin);
    memset(pre, 0, sizeof(pre));
    memset(nxt, 0 ,sizeof(nxt));
    memset(vis, 0 ,sizeof(vis));

    scanf("%d", &N);
    for(int i=1; i<N; i++)
    {
        int a,b; scanf("%d%d", &a,&b);
        E[a].push_back(b); E[b].push_back(a);
    }
    dfs(1);

    N*=2;
    for(int i=1; i<=N/2; i++)
    {
        apple[i]=1;
        change(nxt[i],1);
    }
    int M; scanf("%d", &M);
    for(int i=1; i<=M; i++)
    {
        char c; int a;
        scanf("%s", &c); scanf("%d",&a);
        if(c =='Q')
        {
            cout<<sum(nxt[a]) - sum(pre[a] -1 )<<endl;
        }
        else
        {
            if(apple[a]) 
            {
                apple[a]=0;
                change(nxt[a],-1);
            }
            else
            {
                apple[a]=1;
                change(nxt[a], 1);
            }
        }
    }
    return 0;
}
