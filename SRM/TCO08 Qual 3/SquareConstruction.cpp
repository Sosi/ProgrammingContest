// BEGIN CUT HERE

// END CUT HERE
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
//End Sosi TopCoder  
// END CUT HERE
class SquareConstruction
{
public:
	vector <string> construct(int N, int a, int b, int c, int d)
	{
		int currentx=0;
		int currenty=0;
		int Ans[15][15];
		for(int i=0;i<N;i++)
		{
			for(int  j=0;j<N;j++)
				Ans[i][j]=-1;
		}
		int num=1;
		while(Ans[currentx][currenty]==-1)
		{
			Ans[currentx][currenty]=num;
			currentx=(currentx+a)%N;
			currenty=(currenty+b)%N;
			if(Ans[currentx][currenty]!=-1)
			{
				currentx=(currentx+c)%N;
				currenty=(currenty+d)%N;
			}
			num++;
		}
		vector<string> S;
		for(int j=0;j<N;j++)
		{
			ostringstream sout;
			for(int i=0;i<N;i++)
			{
				if(i>0)sout<<' ';sout<<Ans[j][i];
			}
			string s=sout.str();
			cout<<s<<endl;
			S.push_back(s);
		}
		return S;
	}

	// BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; int Arg4 = 0; string Arr5[] = {"1 -1 -1 -1 -1", "-1 -1 -1 -1 -1", "-1 -1 -1 -1 -1", "-1 -1 -1 -1 -1", "-1 -1 -1 -1 -1" }; vector <string> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); verify_case(0, Arg5, construct(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 1; int Arg2 = 1; int Arg3 = 2; int Arg4 = 2; string Arr5[] = {"1 -1 -1 -1 -1", "-1 2 -1 -1 -1", "-1 -1 3 -1 -1", "-1 -1 -1 4 -1", "-1 -1 -1 -1 5" }; vector <string> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); verify_case(1, Arg5, construct(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 1; int Arg2 = 1; int Arg3 = 1; int Arg4 = 0; string Arr5[] = {"1 22 18 14 10", "6 2 23 19 15", "11 7 3 24 20", "16 12 8 4 25", "21 17 13 9 5" }; vector <string> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); verify_case(2, Arg5, construct(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 0; int Arg2 = 1; int Arg3 = 2; int Arg4 = 3; string Arr5[] = {"1 2 3 4 5", "17 18 19 20 16", "8 9 10 6 7", "24 25 21 22 23", "15 11 12 13 14" }; vector <string> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); verify_case(3, Arg5, construct(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 6; int Arg1 = 1; int Arg2 = 2; int Arg3 = 2; int Arg4 = 2; string Arr5[] = {"1 -1 15 -1 11 -1", "12 -1 2 -1 16 -1", "17 -1 7 -1 3 -1", "4 -1 18 -1 8 -1", "9 -1 5 -1 13 -1", "14 -1 10 -1 6 -1" }; vector <string> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); verify_case(4, Arg5, construct(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_5() { int Arg0 = 1; int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; int Arg4 = 0; string Arr5[] = {"1" }; vector <string> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); verify_case(5, Arg5, construct(Arg0, Arg1, Arg2, Arg3, Arg4)); }

	// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	SquareConstruction ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
