// BEGIN CUT HERE

// END CUT HERE
#line 5 "ExperimentalAnalyzer.cpp"

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
class ExperimentalAnalyzer
{
        public:
        vector <int> getPredictors(vector <string> data)
        {
                $CARETPOSITION$
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {
"0 10 20 20 0",
"1 20 30 17 98765",
"0 10 30 29 1234567",
"1 20 40 10 42"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 1,  3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getPredictors(Arg0)); }
	void test_case_1() { string Arr0[] = {
"1 220 212 247 764 928 956 946 66 640 983 125 994",
"0 816 835 98 81 783 267 946 584 309 757 876 670"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 1,  2,  3,  4,  5,  6,  8,  9,  10,  11,  12 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getPredictors(Arg0)); }
	void test_case_2() { string Arr0[] = {
"0 1944914038 1696137778 1525367830",
"0 1547932733 1185820653 1500052399",
"0 230149443 1358715189 501418065",
"0 1676118083 1499656529 2103271593",
"0 1441540020 1189300515 1544659186"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getPredictors(Arg0)); }
	void test_case_3() { string Arr0[] = {
"0 163869663 388719849 383049741",
"1 1982032201 1346175990 1500891700",
"0 436834674 559375803 994453722",
"0 652316051 372955428 361692727",
"1 1946362869 1204080206 2066121600",
"0 840867095 22073435 1166658385",
"1 1864235269 2041251772 1847305529",
"0 852306016 447986701 407997336",
"1 1183214776 728141214 1985649244",
"0 70064437 7110416 107908753",
"1 1383409284 1328770197 1942831571",
"1 1023334064 1596272317 1226876467",
"1 2068895243 1481323649 1955807390",
"0 758836687 541737411 312747384",
"1 1432983907 1475284843 1512945413",
"1 1512506825 1933755150 2041997368",
"1 2041700103 1859742986 1995865005",
"0 323696628 328891715 893352493",
"1 1623710967 1193592990 1871502957",
"0 9241593 127579695 36337622",
"1 1935123182 1332735215 1400991717",
"1 2130762600 1874898210 1234793873",
"0 411777048 142083649 61450530",
"1 1042383468 1979605937 1276643901",
"0 219279208 371281702 65383690",
"0 948808405 243728462 984221323",
"0 999393888 131231007 1186873391",
"1 1294115986 1618148416 1324126407",
"1 1710811842 2024808989 1696767048",
"1 1399327255 1317859960 1427366434",
"0 145887863 452552798 165691442",
"0 685701683 334764463 1001631935",
"1 1596433536 1911594193 1533322508",
"0 128647261 372955025 1051296077",
"0 946946329 548039713 83591687",
"1 1490995704 1541151932 2052868342",
"0 805037508 405134691 593191395",
"1 2048614262 1171142414 1309623012",
"1 1024870244 1791074791 1778846631",
"1 1403452711 2033486235 1555085078",
"0 900806815 269954427 806033528",
"1 1598931622 938905156 1474311731",
"1 1468418323 749319445 2060324871",
"0 407246582 393808982 163347811",
"0 52629967 643176802 619367349"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 1,  2,  3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getPredictors(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        ExperimentalAnalyzer ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
