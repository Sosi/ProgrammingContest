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
int dirx[8]={ 1 ,1,1, 0, 0,-1,-1,-1};
int diry[8]={ 1, -1,0,1,-1,0, 1,-1};
void judge(int (* Map)[55] ,int N,int K,bool & red,bool & blue)
{
	//bool tempred=false;
	//bool tempblue=false;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(Map[i][j]==1)
			{
				for(int a=0;a<8;a++)
				{
					//bool flag=false;
					//tempred=true;
					int b=0;
					for(;b<K;b++)
					{
						if((i+b*dirx[a]<N)&&(i+b*dirx[a]>=0)&&(j+b*diry[a]<N)&&(j+b*diry[a]>=0))
						{
							if(Map[i+b*dirx[a]][j+b*diry[a]]!=1)
							{
								//tempred=false;
								break;
							}
						}
						else
							break;

					}
					if(b==K)
						red=true;
				}
			}
			if(Map[i][j]==2)
			{
				for(int a=0;a<8;a++)
				{
					int b=0;
					for(;b<K;b++)
					{
						if((i+b*dirx[a]<N)&&(i+b*dirx[a]>=0)&&(j+b*diry[a]<N)&&(j+b*diry[a]>=0))
						{
							if(Map[i+b*dirx[a]][j+b*diry[a]]!=2)
							{
								//	tempblue=false;
								break;
							}
						}
						else
							break;

					}
					if(b==K)
						blue=true;
				}

			}
		}

	}
}
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int Case;
	cin>>Case;
	int n=Case;
	int Map[55][55];
	while(n--)
	{
		memset(Map,0,sizeof(Map));
		int N,K;
		cin>>N>>K;
		string s;
		for(size_t i=0;i<N;i++)
		{
			cin>>s;
			for(size_t j=0;j<s.size();j++)
			{
				if(s[j]=='.')
					Map[i][j]=0;
				if(s[j]=='R')
					Map[i][j]=1;//红的认为是1；
				if(s[j]=='B')
					Map[i][j]=2;
			}
		}

		for(size_t i=0;i<N;i++)
		{		
			string p;
			for(size_t j=0;j<N;j++)
			{
				if(Map[i][j]==1)
					p+="1";
				if(Map[i][j]==2)
					p+="2";
			}
			for(size_t j=0;j<N;j++)
			{
				Map[i][j]=0;
			}
			reverse(p.begin(),  p.end());
			for(size_t j=0;j<p.size();j++)
			{
				Map[i][j]=p[j]-'0';
			}
		}
	/*	for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
				cout<<Map[i][j];
			cout<<endl;
		}*/
		bool red=false;
		bool blue=false;
		judge(Map,N,K,red,blue);
		if(red&&blue)
			cout<<"Case #"<<Case-n<<": Both"<<endl;
		else
		{
			if(red)
				cout<<"Case #"<<Case-n<<": Red"<<endl;
			else
			{

				if(blue)
					cout<<"Case #"<<Case-n<<": Blue"<<endl;
				else
					cout<<"Case #"<<Case-n<<": Neither"<<endl;
			}

		}

	}
}
