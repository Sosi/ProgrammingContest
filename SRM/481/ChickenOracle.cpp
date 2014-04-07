// BEGIN CUT HERE

// END CUT HERE
#line 5 "ChickenOracle.cpp"

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
bool check(int n, int x, int lieCount, int liarCount) 
{
	// Iterate through all the possible values of the intersection y:
	for (int y = 0; y <= lieCount && y <= liarCount; y++)
	{
		int a = lieCount - y;
		int b = liarCount - y;
		int c = n - a - b - y;

		// Do all the required conditions hold?
		if ( a+b==n-x && c+y==x && c>=0 )
		{
			return true;
		}
	}
	return false;
}
class ChickenOracle
{

        public:

        string theTruth(int n, int eggCount, int lieCount, int liarCount)
        {
             //   $CARETPOSITION$
			bool egg =     check(n,eggCount, lieCount, liarCount );
			// Then assuming that the chicken is the correct answer:
			bool chicken = check(n,n-eggCount, lieCount, liarCount );
			if(egg&&chicken) {
				return "Ambiguous";
			} else if (egg) {
				return "The egg";
			} else if (chicken) {
				return "The chicken";
			} else {
				return "The oracle is a lie";
			}
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 10; int Arg2 = 0; int Arg3 = 0; string Arg4 = "The egg"; verify_case(0, Arg4, theTruth(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 60; int Arg1 = 40; int Arg2 = 0; int Arg3 = 30; string Arg4 = "The oracle is a lie"; verify_case(1, Arg4, theTruth(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 60; int Arg1 = 20; int Arg2 = 5; int Arg3 = 25; string Arg4 = "The chicken"; verify_case(2, Arg4, theTruth(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 1000; int Arg1 = 500; int Arg2 = 250; int Arg3 = 250; string Arg4 = "Ambiguous"; verify_case(3, Arg4, theTruth(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        ChickenOracle ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
