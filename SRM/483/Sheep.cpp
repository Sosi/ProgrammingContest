// BEGIN CUT HERE

// END CUT HERE
#line 5 "Sheep.cpp"

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

class Sheep
{
        public:
        int minCapacity(int numSheep, int maxRuns, vector <string> part1, vector <string> part2, vector <string> part3, vector <string> part4);
       // {
              //  $CARETPOSITION$
      //  }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 6; int Arg1 = 2; string Arr2[] = { "26 7 10 30 5 4" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = { }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = { }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); string Arr5[] = { }; vector <string> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arg6 = 42; verify_case(0, Arg6, minCapacity(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { int Arg0 = 6; int Arg1 = 2; string Arr2[] = { "4 8 15 16 23 42" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = { }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = { }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); string Arr5[] = { }; vector <string> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arg6 = 54; verify_case(1, Arg6, minCapacity(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { int Arg0 = 15; int Arg1 = 4; string Arr2[] = { "666 42 7 13 400 511 600 200 202 111 313 94 280", " 72 42" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = { }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = { }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); string Arr5[] = { }; vector <string> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arg6 = 896; verify_case(2, Arg6, minCapacity(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_3() { int Arg0 = 7; int Arg1 = 6; string Arr2[] = { "200 2", "01 202 203" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = { " 204 " }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = { }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); string Arr5[] = { "205", " ", "206" }; vector <string> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arg6 = 401; verify_case(3, Arg6, minCapacity(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_4() { int Arg0 = 200; int Arg1 = 20; string Arr2[] = { "42 468 335 501 1170 1725 1479 1359 963 465 1706",
  " 146 1282 828 1962 492 996 1943 828 1437 392 605",
  " 1903 154 293 383 1422 717 1719 1896 1448 1727",
  " 772 1539 1870 1913 1668 300 1036 1895 704 1812",
  " 1323 334 1674 665 1142 1712 254 869 1548 1645",
  " 663 758 38 860 724 1742 1530 779 317 1036 191",
  " 1843 289 107 1041 943 1265 649 1447 1806 1891",
  " 730 371 1351 1007 1102 394 1549 1630 624 85 1955",
  " 757 1841 967 1377 1932 309 945 440 627 1324 1538",
  " 1539 119 83 930 542 834 1116 640 1659 705 1931",
  " 1978 307 1674 387 1022 746 925 1073 271 1830 778",
  " 1574 1098 513 1987 1291 1162 637 356 768 1656",
  " 1575 32 53 1351 1151 942 1725 1967 1431 1108 192",
  " 8 1338 1458 288 1754 384 946 910 210 1759 222",
  " 589 423 947 1507 1031 414 1169 901 592 763 1656",
  " 1411 360 1625 538 1549 484 1596 42 1603 351 292",
  " 837 1375 1021 597 22 1349 1200 1669 485 282 735",
  " 54 2000 419 1939 901 1789 128 468 1729 894 649",
  " 484 1808 422 311 618 814 1515" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = { }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = { }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); string Arr5[] = { }; vector <string> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arg6 = 9986; verify_case(4, Arg6, minCapacity(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        Sheep ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
string Str( vector <string> v )
{
	string res = "";
	for(int i=0;i< v.size();i++)
		res += v[i];
	return res;
}

const int maxn = 2010;

int n, K, a[maxn];

int Solve( int W )
{
	if (a[n - 1] > W)
		return 0;

	multiset <int> s;
	for(int i=0;i<n;i++)
		s.insert(a[i]);

	int num = 0;
	while (s.size())
	{
		if (num + s.size() <= K)
			return 1;
		num++;
		if (num > K)
			return 0;

		int rest = W;
		while (s.size())
		{
			set<int>::iterator it = s.upper_bound(rest);
			if (it == s.begin())
				break;
			it--;
			int w = *it;
			s.erase(it);
			rest -= w;
		}
	}
	return num <= K;
}

int Sheep::minCapacity(int _n, int _K, vector <string> part1, vector <string> part2, vector <string> part3, vector <string> part4)
{
	int start = clock();

	n = _n, K = _K;
	string s1 = Str(part1);
	string s2 = Str(part2);
	string s3 = Str(part3);
	string s4 = Str(part4);
	string s = s1 + s2 + s3 + s4;
	stringstream ss(s);
	for(int i=0;i<n;i++)
		assert(ss >> a[i]);
	sort(a, a + n);

	int mi = 1, ma = (int)4e6, ave;
	while (mi < ma)
		if (Solve(ave = (mi + ma) / 2))
			ma = ave;
		else
			mi = ave + 1;

	int res = mi;
	for (int i = mi - 1; i >= 1; i--)
	{
		if (clock() - start > 1.85 * CLOCKS_PER_SEC)
			break;
		if (Solve(i))
			res = i;
	}
	return res;
}