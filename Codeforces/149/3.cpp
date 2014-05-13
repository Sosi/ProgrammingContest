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

// nice solution to calculate the gird shortest path
int main()
{
    //freopen("3.txt","r",stdin);
    map<pair<int,int>, int> dis;
    set<pair<int,int> > C;
    pair<int,int> s,t;
    cin>>s.first>>s.second>>t.first>>t.second;
    int n; cin>>n;
    int r, a, b;
    for(int i =0 ;i<n; i++) 
    {
        cin>>r>>a>>b;
        for(int j=a;j<=b; j++) C.insert(make_pair(r,j));
    }
    dis[s] = 0;
    queue<pair<int,int> >Q;
    Q.push(s);
    while(!Q.empty())
    {
        pair<int,int> f = Q.front();
        Q.pop();
        for(int i=-1; i<=1; i++) for(int j=-1; j<=1; j++)
        {
            pair<int,int> temp = make_pair(f.first + i, f.second+j);
            if(C.count(temp) && dis.find(temp) == dis.end())
            {
                dis[temp] = dis[f]+1;
                Q.push(temp);
            }
        }
    }
    if(dis.find(t) == dis.end()) cout<<-1<<endl;
    else cout<<dis[t]<<endl;
    return 0;

}
