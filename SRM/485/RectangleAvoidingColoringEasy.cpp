// BEGIN CUT HERE

// END CUT HERE
#line 5 "RectangleAvoidingColoringEasy.cpp"

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

vector<string> C;
int ans=0;
bool check(int x,int y)
{
	for(int i=0;i<x;i++)
	{
		for(int j=0;j<y;j++)
			if(C[i][j]==C[x][y]&&C[i][y]==C[x][y]&&C[x][j]==C[x][y])
				return false;
	}
	return true;
}
void dfs(int x ,int y)
{
	if(x==C.size())
	{
		ans++;
		return;
	}
	int x2=x,y2=y+1;
	if(y2==C[0].size())y2-=C[0].size(),x2++;

	if(C[x][y]=='?')
	{
		C[x][y]='W';if(check(x,y))dfs(x2,y2);
		C[x][y]='B';if(check(x,y))dfs(x2,y2);
		C[x][y]='?';
	}
	else if(check(x,y))dfs(x2,y2);
}
class RectangleAvoidingColoringEasy
{
        public:
        int count(vector <string> board)
        {
			C=board;
			ans=0;
			dfs(0,0);
			return ans;

		}
			////b=board;
			//int total=0;
			//for(int i=0;i<board.size();i++)
			//{
			//	for(int j=0;j<board[i].size();j++)
			//		if(board[i][j]=='?')
			//			total++;
			//}
			//total=(1<<total);
			//int n=board.size();
			//int dp[15][15];
			//memset(dp,0,sizeof(dp));
			//int l=0;
			//for(int i=1;i<n;i++)
			//{
			//	for(int j=1;j<n;j++)
			//	{
			//		for(int a=0;a<i;a++)
			//		{
			//			for(int b=0;b<j;b++)
			//			{
			//				l++;
			//				int W=0;int H=0;
			//				if(board[i][j]=='W')W++;
			//				if(board[i][j]=='B')H++;
			//				if(board[i][b]=='W')W++;
			//				if(board[i][b]=='B')H++;
			//				if(board[a][j]=='W')W++;
			//				if(board[a][j]=='B')H++;
			//				if(board[a][b]=='W')W++;
			//				if(board[a][b]=='B')H++;
			//				if(W!=0&&H!=0)
			//					dp[i][j]+= 0;
			//				if(W==0&&H==0)
			//					dp[i][j]+= 2;
			//				else
			//					dp[i][j]+= 1;
			//				//dp[i][j]=judge(a,b,i,j);
			//			}
			//		}
			//	}
			//}
			//int sum=0;
			//for(int i=0;i<n;i++)
			//{
			//	for(int j=0;j<n;j++)
			//		sum+=dp[i][j];
			//}
			//cout<<sum<<endl;
			//return l*total-sum;

   //     }

        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"??",
 "??"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 14; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { string Arr0[] = {"B?",
 "?B"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { string Arr0[] = {"WW",
 "WW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { string Arr0[] = {"??B??",
 "W???W",
 "??B??"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(3, Arg1, count(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        RectangleAvoidingColoringEasy ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
