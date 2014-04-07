// BEGIN CUT HERE

// END CUT HERE
#line 5 "BoardPainting.cpp"
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
 
// BEGIN CUT HERE
//Begin Sosi TopCoder 
//const double EPS=1e-11;
//const double PI=acos(-1.0);
//const short INF=32767,NF= -32768;
//const int INF=2147483647,NF= -2147483648;
//const long long INF=9223372036854775807,NF=-9223372036854775808;
//const long double INF=99999999.99999999;
 
//Numberic Functions
//template<class T> T gcd(T a,T b){ if(a<0) return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
//template <class T> T lcm(T a,T b){ return a*(b/gcd(a,b));}
//template<class T> inline vector<pair<T,int> > factorize(T n)
//   {vector<pair<T,int> > R;for (T i=2;n>1;){if (n%i==0){int C=0;for (;n%i==0;C++,n/=i);R.push_back(make_pair(i,C));}
//   i++;if (i>n/i) i=n;}if (n>1) R.push_back(make_pair(n,1));return R;}
//template<class T> inline bool isPrimeNumber(T n)
//   {if(n<=1)return false;for (T i=2;i*i<=n;i++) if (n%i==0) return false;return true;}
//template<class T> inline T eularFunction(T n)
//   {vector<pair<T,int> > R=factorize(n);T r=n;for (int i=0;i<R.size();i++)r=r/R[i].first*(R[i].first-1);return r;}
 
//Translator
//template<class T> string toString(T n){ostringstream ost;ost<<n;ost.flush();return ost.str();}
//int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}//NOTES:toInt(
//long long toInt64(string s){long long r=0;istringstream sin(s);sin>>r;return r;}
//double toDouble(string s){double r=0;istringstream sin(s);sin>>r;return r;}//NOTES:toDouble(
//template<class T> void stoa(string s,int &n,T A[]){n=0;istringstream sin(s);for(T v;sin>>v;A[n++]=v);}
//template<class T> void atos(int n,T A[],string &s){ostringstream sout;for(int i=0;i<n;i++){if(i>0)sout<<' ';sout<<A[i];}s=sout.str();}
//template<class T> void atov(int n,T A[],vector<T> &vi){vi.clear();for (int i=0;i<n;i++) vi.push_back(A[i]);}
//template<class T> void vtoa(vector<T> vi,int &n,T A[]){n=vi.size();for (int i=0;i<n;i++)A[i]=vi[i];}
//template<class T> void stov(string s,vector<T> &vi){vi.clear();istringstream sin(s);for(T v;sin>>v;vi.push_bakc(v));}
//template<class T> void vtos(vector<T> vi,string &s){ostringstream sout;for (int i=0;i<vi.size();i++){if(i>0)sout<<' ';sout<<vi[i];}s=sout.str();}
 
//Fraction
//template<class T> struct Fraction{T a,b;Fraction(T a=0,T b=1);string toString();};
//template<class T> Fraction<T>::Fraction(T a,T b){T d=gcd(a,b);a/=d;b/=d;if (b<0) a=-a,b=-b;this->a=a;this->b=b;}
//template<class T> string Fraction<T>::toString(){ostringstream sout;sout<<a<<"/"<<b;return sout.str();}
//template<class T> Fraction<T> operator+(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.b+q.a*p.b,p.b*q.b);}
//template<class T> Fraction<T> operator-(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.b-q.a*p.b,p.b*q.b);}
//template<class T> Fraction<T> operator*(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.a,p.b*q.b);}
//template<class T> Fraction<T> operator/(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.b,p.b*q.a);}
 
//STL
//bool comp(T A,T B){return A<B?1:0; }
//do{ } while(next_permutation(T.begin(), T.end()));
//int dirx[]={1,0,-1,0};
//int diry[]={0,-1,0,1}; //clockwise
//int dirx[]={1, 1, 0,-1,-1,-1,0,1};
//int diry[]={0,-1,-1,-1, 0, 1,1,1}; //clockwise
//End Sosi TopCoder
// END CUT HERE

int i,j,k;
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

struct ISAP{

#define V 2505
#define E 500005
#define INF 0x3F3F3F3F  // 1061109567

    int n, S,T,e;
    struct edge{
        int x, y, c;
        edge *next, *op;
    }g[E],*fa[V],*ls[V],*cur[V];
    int d[V],num[V];
    int ret;

    void init(int _n, int _S, int _T)
    {
        n = _n;
        S= _S;
        T = _T;
        e = 0;
        REP(i,n) ls[i]= NULL;
    }
    void addedge(int x, int y, int c){
        g[e].x= x; g[e].y = y; g[e].c = c; g[e].op = &g[e+1]; g[e].next = ls[x]; ls[x]= &g[e++];
        g[e].x = y; g[e].y = x; g[e].c = 0; g[e].op = &g[e-1]; g[e].next = ls[y]; ls[y]=&g[e++];
    }

    void relabel(int x){
        cur[x] = ls[x];
        d[x]= n+5;
        for(edge *t = ls[x];t; t=t->next) 
            if(t->c && d[t->y]+1 < d[x]) d[x]= d[t->y]+1;
    }

    void aug(){
        int nf = INF;
        for(int i= T; i!=S; i=fa[i]->x)
            if(fa[i]->c<nf) nf = fa[i]->c;
        ret += nf;
        for(int i =T; i!=S; i=fa[i]->x)
        {
            fa[i]->c -= nf;
            fa[i]->op->c += nf;
        }
    }
    int sap(){
        REP(i,n){
            d[i]=0;
            num[i]=0;
            cur[i]= ls[i];
        }
        num[0]=n;
        int i = S;
        ret =0;
        while(d[S]<n){
            edge *&t = cur[i];
            for(;t; t=t->next)
                if(d[i]==d[t->y]+1 && t->c) break;
            if(t){
                fa[t->y]=t;
                i=t->y;
                if(i==T) aug(),i=S;
            }else{
                if(!(--num[d[i]])) return ret;
                relabel(i);
                ++num[d[i]];
                if(i!=S) i=fa[i]->x;
            }
        }
        return ret;
    }
#undef E
#undef V
#undef INF
}sap;

int id[55][55];

int src, sink;

class BoardPainting
{
        public:
        int minimalSteps(vector <string> target)
        {
            int m = target.size(); int n = target[0].size();
            int num = 1;
            REP(i,m) REP(j,n) if(target[i][j]=='#') id[i][j]=num++;else id[i][j]=-1;
            src = 0; sink = num;
            sap.init(num+1,src,sink);
            REP(i,m) REP(j,n) {
                if(target[i][j] != '#') continue;
                if(i+1 < m && target[i+1][j]=='#') sap.addedge(id[i][j], id[i+1][j],1);
                else sap.addedge(id[i][j],sink, 1);
                if(j+1<n && target[i][j+1] == '#') sap.addedge(id[i][j+1], id[i][j], 1);
                else sap.addedge(src, id[i][j],  1);
            }
            return sap.sap();
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"#####"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, minimalSteps(Arg0)); }
	void test_case_1() { string Arr0[] = {"#####",
 ".....",
 "#####",
 ".....",
 "#####"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, minimalSteps(Arg0)); }
	void test_case_2() { string Arr0[] = {"..#..",
 "..#..",
 "#####",
 "..#..",
 "..#.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, minimalSteps(Arg0)); }
	void test_case_3() { string Arr0[] = {"#####",
 "..#..",
 "#####",
 "..#..",
 "#####"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(3, Arg1, minimalSteps(Arg0)); }
	void test_case_4() { string Arr0[] = {".#.#.",
 "#####",
 ".#.#.",
 "#####",
 ".#.#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(4, Arg1, minimalSteps(Arg0)); }
	void test_case_5() { string Arr0[] = {".##.####.####.#########.##..",
 "##.#.####################.##",
 ".##.###.##.###.###.###.###..",
 "#..###..#########..###.##.##",
 "####..#######.#.#####.######",
 "##.######.#..#.#############",
 "##.######.###########.######",
 "#######.#######.#..###.#.###",
 "#####..#######.#####.#.###.#",
 "#..#################.#.####.",
 "##.######..#.#####.######.##",
 "..#.#############.#.##....#.",
 "....##..##..#.#####.#.###.##",
 "##.#########...#..#.#.######",
 "##.#..###########..#..####.#",
 "#.####.###.########.########",
 "#####.#########.##.##.######",
 ".##.####..###.###...######.#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 88; verify_case(5, Arg1, minimalSteps(Arg0)); }
	void test_case_6() { string Arr0[] = {"...................."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(6, Arg1, minimalSteps(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
        BoardPainting ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
