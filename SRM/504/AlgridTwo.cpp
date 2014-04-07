// BEGIN CUT HERE

// END CUT HERE
#line 5 "AlgridTwo.cpp"

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
class AlgridTwo
{
public:
	int makeProgram(vector <string> output)
	{
		vector<string> input=output;
		int W=output[0].size();
		int H=output.size();
		bool flag=false;
		bool s=true;
		for(int i=H-2;i>=0;i--)
		{
			for(int j=W-2;j>=0;j--)
			{
				flag=false;
				cout<<j<<" "<<flag<<endl;
				if(output[i][j]=='W' && output[i][j+1]=='W')
				{
					flag=true;cout<<i<<" "<<j<<" WW__"<<endl;
				}
				if(output[i][j]=='B' && output[i][j+1]=='W' && output[i+1][j]=='B'  && (input[i+1][j+1]=='B'||input[i+1][j+1]=='A'))
				{
					input[i+1][j]='A';
					input[i+1][j+1]='A';
					flag=true;
					cout<<i<<" "<<j<<" WWB_"<<endl;
					if(i==H-2&&j==W-2 && output[i+1][j+1]!='B') s=false;
				}
				if(output[i][j]=='W' && output[i][j+1]=='B' && output[i+1][j]=='W'  && ( input[i+1][j+1]=='W'||input[i+1][j+1]=='A'))
				{
					input[i+1][j]='A';
					input[i+1][j+1]='A';
					flag=true;
					cout<<i<<" "<<j<<" WBW_"<<endl;
					if(i==H-2 && j==W-2 && output[i+1][j+1]!='W') s=false;
				}
				if(output[i][j]=='B' && output[i][j+1]=='B')
				{
					swap(input[i+1][j],input[i+1][j+1]);
					flag=true;
					cout<<i<<" "<<j<<" BB__"<<endl;
				}
				if(!flag)
				{
					s=false;
					cout<<"ERROR"<<endl;
				}
				cout<<j<<" "<<flag<<endl;
			}
		}
		if(!s)
		{
			return 0;
		}
		int num=1;
		for(int i=0;i<input.size();i++)
		{
			for(int j=0;j<input[0].size();j++)
				if(input[i][j]=='A')
					num=(num<<1)%1000000007;
		}
		return num;
	}

	// BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"BB",
		"WB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, makeProgram(Arg0)); }
	void test_case_1() { string Arr0[] = {"BBWBBB",
		"WBWBBW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(1, Arg1, makeProgram(Arg0)); }
	void test_case_2() { string Arr0[] = {"BWBWBW",
		"WWWWWW",
		"WBBWBW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, makeProgram(Arg0)); }
	void test_case_3() { string Arr0[] = {"WWBWBWBWBWBWBWBW",
		"BWBWBWBWBWBWBWBB",
		"BWBWBWBWBWBWBWBW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 73741817; verify_case(3, Arg1, makeProgram(Arg0)); }

	// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	AlgridTwo ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE