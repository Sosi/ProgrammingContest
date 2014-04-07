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


class  CampLunches 
{ 
public: 
  int firstMatching(vector <string> menu1, vector <string> menu2) 
  { 
    int pp=lcm((int)menu1.size(),(int)menu2.size()); 
    for(int i=0;i<pp;i++) 
    { 
      menu1.push_back(menu1[i%menu1.size()]); 
    } 
    for(int i=0;i<pp;i++) 
    { 
      menu2.push_back(menu2[i%menu2.size()]); 
    } 
    for(int i=0;i<pp;i++) 
    { 
      if(menu1[i]==menu2[i]) 
      { 
        return i; 
      } 
    } 
    return -1; 
  } 
};
