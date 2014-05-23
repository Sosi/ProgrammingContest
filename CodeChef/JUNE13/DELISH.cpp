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

int i,k;
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define RREP(i,n) for((i)=(int)(n) -1; (i)>=0; (i)--)
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

#define MAX 10005
int D[MAX];
int N;
long long MINCON[MAX];
long long MAXCON[MAX];
long long Left[MAX];
long long Right[MAX];
int main()
{
    //freopen("DELISH.txt","r",stdin);
    int T; cin>>T;
    while(T--)
    {
        scanf("%d", &N);
        REP(i,N) scanf("%d", &D[i]);
        MINCON[0]  = D[0];
        REP(i,N-1) if(MINCON[i] < 0LL) MINCON[i+1] = MINCON[i] +D[i+1]; else MINCON[i+1] = D[i+1];
        MAXCON[N-1] = D[N-1];
        RREP(i,N-1) if(MAXCON[i+1] > 0LL) MAXCON[i] = MAXCON[i+1] + D[i]; else MAXCON[i] = D[i];
        //REP(i,N) cout<<MINCON[i]<<" "; cout<<endl;
        //REP(i,N) cout<<MAXCON[i]<<" "; cout<<endl;
        Left[0] = MINCON[0];
        REP(i,N-1) Left[i+1] = min(MINCON[i+1], Left[i]);
        //REP(i,N) cout<<Left[i]<<" "; cout<<endl;
        Right[N-1] = MAXCON[N-1];
        RREP(i,N-1) Right[i] = max(MAXCON[i],Right[i+1]);
        //REP(i,N) cout<<Right[i]<<" "; cout<<endl;
        long long ret = -(1LL << 34);
        REP(i,N-1)  ret = max(ret, abs(Right[i+1] - Left[i]));

        MAXCON[0] = D[0];
        REP(i,N-1) if(MAXCON[i] > 0LL) MAXCON[i+1] = MAXCON[i] + D[i+1]; else MAXCON[i+1] = D[i+1];
        MINCON[N-1] = D[N-1];
        RREP(i,N-1) if(MINCON[i+1] < 0LL) MINCON[i] = MINCON[i+1]+D[i]; else MINCON[i] = D[i];
        Left[0] = MAXCON[0];
        REP(i,N-1) Left[i+1] = max(MAXCON[i+1], Left[i]);
        Right[N-1] = MINCON[N-1];
        RREP(i,N-1) Right[i] = min(MINCON[i], Right[i+1]);
        REP(i,N-1) ret = max(ret, abs(Right[i+1]-Left[i]));
        printf("%lld\n", ret);
    }
    return 0;
}
