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
const double EPS=1e-11;
const double PI=acos(-1.0);
template <class T>       T sqr(T x){return x*x;}
template<class T>     T gcd(T a,T b){ if(a<0) return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template <class T>     T lcm(T a,T b){ return a*(b/gcd(a,b));}
int countbit(int n)      { return (n==0)?0:(1+countbit(n&(n-1)));}
int lowbit(int n)        { return (n^(n-1))&n;}
class

	DirPattern
{
public:string matchFiles(vector <string> filenames)
	   {
		   string tar;
		   for(int j=0;j<filenames[0].size();j++)
		   {
			   bool flag=true;
			   char c=filenames[0][j];
			   for(int i=0;i<filenames.size();i++)
			   {
				   if(filenames[i][j]!=c)
				   {
					   flag=false;
					   break;
				   }
			   }
			   if(flag)
				   tar+=c;
			   else
				   tar+='?';
		   }
		   return tar;
	   }
};
