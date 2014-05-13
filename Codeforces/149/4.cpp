#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
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
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
//const double EPS=1e-11;
//const double PI=acos(-1.0);
//const short INF=32767,NF= -32768;
//const int INF=2147483647,NF= -2147483648;
//const long long INF=9223372036854775807,NF=-9223372036854775808;
//const long double INF=99999999.99999999;
 
template<class T> string toString(T n){ostringstream ost;ost<<n;ost.flush();return ost.str();}
int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}//NOTES:toInt(
long long toInt64(string s){long long r=0;istringstream sin(s);sin>>r;return r;}
double toDouble(string s){double r=0;istringstream sin(s);sin>>r;return r;}//NOTES:toDouble(
template<class T> void stoa(string s,int &n,T A[]){n=0;istringstream sin(s);for(T v;sin>>v;A[n++]=v);}
template<class T> void atos(int n,T A[],string &s){ostringstream sout;for(int i=0;i<n;i++){if(i>0)sout<<' ';sout<<A[i];}s=sout.str();}
template<class T> void atov(int n,T A[],vector<T> &vi){vi.clear();for (int i=0;i<n;i++) vi.push_back(A[i]);}
template<class T> void vtoa(vector<T> vi,int &n,T A[]){n=vi.size();for (int i=0;i<n;i++)A[i]=vi[i];}
template<class T> void stov(string s,vector<T> &vi){vi.clear();istringstream sin(s);for(T v;sin>>v;vi.push_bakc(v));}
template<class T> void vtos(vector<T> vi,string &s){ostringstream sout;for (int i=0;i<vi.size();i++){if(i>0)sout<<' ';sout<<vi[i];}s=sout.str();}

#define MAX 100005
int N, M,e;
struct node
{
    int v,  next;
}pnt[MAX];
int head[MAX];
int NUM[MAX];
bool ret[MAX];
int res[MAX];
void addedge(int  u, int v)
{
    pnt[e].v = v;
    pnt[e].next = head[u]; head[u] = e++;
}

void dfs(int u)
{
    //cout<<"__"<<u<<endl;
    ret[u]=1; res[u]++;
    for(int i=head[u]; i!=-1; i=pnt[i].next)
    {
        int j =pnt[i].v;
        res[j]++; if(NUM[j] == res[j]) dfs(j);
    }
}
int main()
{
    //freopen("4.txt","r",stdin);
    scanf("%d%d", &N, &M);
    int x, y,e=0;
    memset(ret, 0, sizeof(ret));
    memset(res, 0 ,sizeof(res));
    memset(head, -1 ,sizeof(head));
    for(int i=0; i<M; i++)
    {
        scanf("%d%d",&x,&y);
        addedge(x,y);
        addedge(y,x);
    }
    for(int i=1; i<=N; i++) scanf("%d", &NUM[i]);
    for(int i=1; i<=N; i++)
    {
        if(NUM[i]== res[i]) dfs(i);
    }
    int ans = 0;
    for(int i=1; i<=N; i++) if(ret[i]) ans++;
    //for(int i=1; i<=N; i++) cout<<res[i]<<" "; cout<<endl;
    cout<<ans<<endl;
    for(int i=1; i<=N; i++)
        if(ret[i]) printf("%d ", i);
    cout<<endl;

    return 0;
}
