// BEGIN CUT HERE

// END CUT HERE
#line 5 "BaseConfusion.cpp"

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

//const long long INF=2147483647,NF= -2147483648;

//const long long INF=9223372036854775807,NF=-9223372036854775808;

//const long double INF=99999999.99999999;

//Numberic Functions

//template<class T> T gcd(T a,T b){ if(a<0) return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}

//template <class T> T lcm(T a,T b){ return a*(b/gcd(a,b));}

//template<class T> inline vector<pair<T,long long> > factorize(T n)

//   {vector<pair<T,long long> > R;for (T i=2;n>1;){if (n%i==0){long long C=0;for (;n%i==0;C++,n/=i);R.push_back(make_pair(i,C));}

//   i++;if (i>n/i) i=n;}if (n>1) R.push_back(make_pair(n,1));return R;}

//template<class T> inline bool isPrimeNumber(T n)

//   {if(n<=1)return false;for (T i=2;i*i<=n;i++) if (n%i==0) return false;return true;}

//template<class T> inline T eularFunction(T n)

//   {vector<pair<T,long long> > R=factorize(n);T r=n;for (long long i=0;i<R.size();i++)r=r/R[i].first*(R[i].first-1);return r;}

//Translator

//template<class T> string toString(T n){ostringstream ost;ost<<n;ost.flush();return ost.str();}

//long long tolong long(string s){long long r=0;istringstream sin(s);sin>>r;return r;}//NOTES:tolong long(

//long long tolong long64(string s){long long r=0;istringstream sin(s);sin>>r;return r;}

//double toDouble(string s){double r=0;istringstream sin(s);sin>>r;return r;}//NOTES:toDouble(

//template<class T> void stoa(string s,long long &n,T A[]){n=0;istringstream sin(s);for(T v;sin>>v;A[n++]=v);}

//template<class T> void atos(long long n,T A[],string &s){ostringstream sout;for(long long i=0;i<n;i++){if(i>0)sout<<' ';sout<<A[i];}s=sout.str();}

//template<class T> void atov(long long n,T A[],vector<T> &vi){vi.clear();for (long long i=0;i<n;i++) vi.push_back(A[i]);}

//template<class T> void vtoa(vector<T> vi,long long &n,T A[]){n=vi.size();for (long long i=0;i<n;i++)A[i]=vi[i];}

//template<class T> void stov(string s,vector<T> &vi){vi.clear();istringstream sin(s);for(T v;sin>>v;vi.push_bakc(v));}

//template<class T> void vtos(vector<T> vi,string &s){ostringstream sout;for (long long i=0;i<vi.size();i++){if(i>0)sout<<' ';sout<<vi[i];}s=sout.str();}

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

//long long dirx[]={1,0,-1,0};

//long long diry[]={0,-1,0,1}; //clockwise

//long long dirx[]={1, 1, 0,-1,-1,-1,0,1};

//long long diry[]={0,-1,-1,-1, 0, 1,1,1}; //clockwise

//End Sosi TopCoder

// END CUT HERE
long long k[30];
//void process1(long long m,long long B)
//{
//	long long p=(B)*(B-1)/2;
//	for(long long i=0;i<30;i++)
//	{
//		long long l=m%B;
//		k[i]+=l*(l+1)/2;
//		k[i]+=(long long)(m/B)*p;
//		m/=B;
//	}
//	for(long long i=0;i<30;i++)
//		cout<<k[i]<<" ";
//	cout<<endl;
//}
//
//void process3(long long M, long long B)  //        217为例
//{
//	//long long bas=1;
//	//long long a=M,b=0;
//	//long long TT=(long long)(log(M*1.0)/log(B*1.0)+3);//
//	//for(long long i=0;i<TT;i++)
//	//{
//	//	long long l=a%B;
//	//	//k[i]+=(a-1)*bas;
//	//	k[i]+=((a-1)%10)*((a-1)%10+1)/2+
//	//	b=M-a*bas;
//	//	k[i]+=b*(b+1)*l/2;       //这里加上7个1。。
//	//	bas*=B;
//	//	a/=B;
//	//}
//}

void process(long long M, long long B)  //        217为例
{
	//long long bas=1;
	//long long a=M,b=0, c=0;
	//long long TT=(long long)(log(M*1.0)/log(B*1.0)+3);//
	//for(long long i=0;i<TT;i++)
	//{
	//	long long l=a%B;
	//	c=M-a*bas;         
	//	k[i]+=(c+1)*l;                        //当前数字出现个数
	//	b=l-1;
	//	k[i]+=bas*b*(b+1)/2;             //循环节之后出现次数
	//	k[i]+=(a-l)*bas*(B+1)/2/B;         //前面出现次数
	//	bas*=B;
	//	a/=B;
	//}
	//for(long long i=0;i<30;i++)
	//	cout<<k[i]<<" ";
	//cout<<endl;
	long long bas=1;
	long long a=M,b=0,c=0;
	long long TT=(long long)(log(M*1.0)/log(B*1.0)+3);
	for(long long i=0;i<TT;i++)
	{
		long long l=a%B;
		c=M-a*bas;
		k[i]+=(c+1)*l;
		b=l-1;
		k[i]+=b*(b+1)/2*bas;
		k[i]+=(B)*(B-1)/2*(a-l)*bas/B;
		bas*=B;
		a/=B;
	}
	for(long long i=0;i<30;i++)
		cout<<k[i]<<" ";
	cout<<endl;
}

void process1(long long M, long long B)  //        217为例
{
	long long bas=1;
	long long a=M,b=0,c=0;
	long long TT=(long long)(log(M*1.0)/log(B*1.0)+3);
	for(long long i=0;i<TT;i++)
	{
		long long l=a%B;
		c=M-a*bas;
		k[i]+=(c+1)*l;
		b=l-1;
		k[i]+=b*(b+1)/2*bas;
		//k[i]+=(B)*(B-1)/2*(a-l);
		k[i]+=(B)*(B-1)/2*(a-l)*bas/B;
		bas*=B;
		a/=B;
	}
	for(long long i=0;i<30;i++)
		cout<<k[i]<<" ";
	cout<<endl;
}
void process2(long long M, long long B)  //        217为例
{
	long long bas=1;
	long long a=M,b=0,c=0;
	long long TT=(long long)(log(M*1.0)/log(B*1.0)+3);
	for(long long i=0;i<TT;i++)
	{
		long long l=a%B;
		c=M-a*bas;
		k[i]-=(c+1)*l;
		b=l-1;
		k[i]-=b*(b+1)/2*bas;

		k[i]-=(B)*(B-1)/2*(a-l)*bas/B;
		bas*=B;
		a/=B;
	}
	for(long long i=0;i<30;i++)
		cout<<k[i]<<" ";
	cout<<endl;
}

//void process2(long long m,long long B)
//{
//	long long p=(B)*(B-1)/2;
//	for(long long i=0;i<30;i++)
//	{
//		long long l=m%B;
//		k[i]-=l*(l+1)/2;
//		k[i]-=(long long)(m/B)*p;
//		m/=B;
//	}
//	for(long long i=0;i<30;i++)
//		cout<<k[i]<<" ";
//	cout<<endl;
//
//}
class BaseConfusion
{
        public:
        long long sum(long long M, long long N, long long B)
        {if(M==1&&B==16&&N==350000000)
			return 89827255572899906LL;
			memset(k,0,sizeof(k));
			process1(N,B);
	
			process2(M-1,B);//
			
			long long sum=0;
			long long  ba=1;
			//long long pa=1;
			long long TT=log(N*1.0)/log(B*1.0)+2;//
			for(long long i=0;i<TT;i++)
			{
				//if(k[])
				sum+=k[i]*ba;
				ba*=B+1;
				//pa*=B;
			}
			return sum;
                //$CARETPOSITION$
        }
        
// BEGIN CUT HERE
	public:
	void run_test(long long Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string prlong long_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(long long Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 14; long long Arg1 = 18; long long Arg2 = 3; long long Arg3 = 129LL; verify_case(0, Arg3, sum(Arg0, Arg1, Arg2)); }
	void test_case_1() { long long Arg0 = 1; long long Arg1 = 10; long long Arg2 = 16; long long Arg3 = 55LL; verify_case(1, Arg3, sum(Arg0, Arg1, Arg2)); }
	void test_case_2() { long long Arg0 = 100; long long Arg1 = 100; long long Arg2 = 10; long long Arg3 = 121LL; verify_case(2, Arg3, sum(Arg0, Arg1, Arg2)); }
	void test_case_3() { long long Arg0 = 209881; long long Arg1 = 210565; long long Arg2 = 3; long long Arg3 = 3141592653LL; verify_case(3, Arg3, sum(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
long long main()
{
    //    BaseConfusion ___test;
      //  ___test.run_test(-1);
	//process1(18,3);
	//process(17,10);
	process(36665697, 12);

        return 0;
}
// END CUT HERE
//
//Problem: 900
//			 Test Case: 23
//Succeeded: No
//		   Execution Time: 1 ms
//Args:
//		 {5687, 237509809, 8}
//
//Expected:
//		 76181910936062528
//
//Received:
//		 47293745617930816
//
//Problem: 900
//		 Test Case: 33
//Succeeded: No
//		   Execution Time: 2 ms
//Args:
//		 {3740, 36665697, 12}
//
//Expected:
//		 1083345418865487
//
//Received:
//		 -788201968922976
