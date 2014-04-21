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

//freopen("","r",stdio);
//freopen("","w",stdout);

  
const int N=100005;  
const double eps=1e-7;  
int dx[]={-1,1};  
//int dy[]={0,0};  
struct point  
{  
	double x,y;  
	point(){}  
	point(double _x,double _y):x(_x),y(_y){}  
}g[N];
double Dis(point P,point Q)  
{  
	return sqrt((1.0*P.x-Q.x)*(1.0*P.x-Q.x)+(1.0*P.y-Q.y)*(1.0*P.y-Q.y));  
}  
double GetAll(point *g,point o,int n)  
{  
	double ret=0;  
	while(n--)ret+=Dis(g[n],o);  
	return ret;  
}  
double SimulatedAnnealing(point *g,int n)  
{  
	point o=g[0],p;
	o.y = 0;
	double t,tmp,ret=1e99;  
	int i,flag;  
	for(t=100;t>eps;t*=0.98)  
	{  
		flag=1;  
		while(flag)  
		{  
			flag=0;  
			for(i=0;i<2;++i)  
			{  
				p.x=o.x+dx[i]*t;  
				p.y=o.y;  
				if(ret>GetAll(g,p,n))  
				{  
					ret=GetAll(g,p,n);  
					o=p;  
					flag=1;  
				}  
			}  
		}  
	}
	//cout<<p.x<<endl;
	//cout<<o.x<<endl;
	return o.x;
	//return ret;  
}  
int main()  
{  
	//freopen("1.txt","r",stdin);
	int T; cin>>T;
	for(int t = 1; t<=T; t++)
	{
		int n; scanf("%d",&n);
		for(int i=0;i<n;++i)
			scanf("%lf%lf",&g[i].x,&g[i].y);  
		cout<<"Case "<<t<<": ";
		printf("%.9lf\n",SimulatedAnnealing(g,n));  
	}
	return 0;  
}  