#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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
#include <ctime>
#include <cctype>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

#define SIZE(a)     ((int)(a).size())
#define SORT(a)     sort(a.begin(),a.end())
#define REVERSE(a)  reverse(a.begin(),a.end())
#define LENGTH(a)   ((int)a.length())
#define MAP(a,b)   make_pair(a,b)
#define TWO(a)     (1<<(a))
#define TWOL(a)     (((int64)(1))<<(a))
#define CONTAIN(S,X)  ((S&TWO(X))>0)
#define CONTAINL(S,X)  ((S&TWOL(X))>0)

typedef long long int64;
typedef unsigned long long uint64;
typedef pair<int,int> ipair;
const double EPS=1e-11;
const double PI=acos(-1.0);
template<class T>        void checkmin(T &a,T b) { if(b<a) a=b;}
template< class T>        void checkmax(T &a,T b) { if(b>a)a=b; }
template <class T>       T sqr(T x){return x*x;}
template<class T>     T gcd(T a,T b){ if(a<0) return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template <class T>     T lcm(T a,T b){ return a*(b/gcd(a,b));}
int countbit(int n)      { return (n==0)?0:(1+countbit(n&(n-1)));}
int lowbit(int n)        { return (n^(n-1))&n;}
int64  toInt64(string a) { istringstream  sin(a); int64 t; sin>>t;  return t;}
int64  toInt  (string a) { istringstream  sin(a); int   t; sin>>t;  return t;}
string toString(int64 a) { ostringstream  sout;   sout<<a; return sout.str();}
string toString (int a)  { ostringstream  sout;   sout<<a; return sout.str();}




string rotate (string s)
{
	vector<string> b(7,"       ");
	for(int i=0;i<=6;i++)
	{
		for(int j=0;j<=6;j++)
		{
			b[i][j]=s[j*7+6-i];
		}
	}
	string c(""); 
	for(int i=0;i<=6;i++)
	{
		for(int j=0;j<=6;j++)
		{
			c+=b[i][j];
		}
	}
	return c;
}
string reflect(string s)
{
	vector<string> b(7,"       ");
	for(int i=0;i<=6;i++)
	{
		for(int j=0;j<=6;j++)
		{
			b[i][j]=s[i*7+6-j];
		}
	}
	string c(""); 
	for(int i=0;i<=6;i++)
	{
		for(int j=0;j<=6;j++)
		{
			c+=b[i][j];
		}
	}
	return c;
}
bool match(string a,string b)
{
	for(int i=0;i<a.size();i++)
	{
		if(a[i]==b[i])
			return false;
	}
	return true;
}
bool rematch(string a,string b)
{
	string c=b;
	if(match(a,c)||match(a,reflect(c)))
		return true;
	c=rotate(c);
	if(match(a,c)||match(a,reflect(c)))
		return true;
	c=rotate(c);
	if(match(a,c)||match(a,reflect(c)))
		return true;
	c=rotate(c);
	if(match(a,c)||match(a,reflect(c)))
		return true;
	return false;
}



class  CrimeLab
{
public:
	int matchFragment(string targetFragment, vector <string> candidateFragments)
	{
		int number=0;
		int pp=0;
		for(int i=0;i<candidateFragments.size();i++)
		{
			if(rematch(targetFragment,candidateFragments[i]))
			{
				number++;
				pp=i;
			}

		}

		if(number==0)
			return -1;
		if(number>1)
			return -2;
		return pp;
	}


};
