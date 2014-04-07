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
#include <string>
#include <cstring>
using namespace std;
#define PI  3.141592653589   7932384626

template<class T>     T gcd(T a,T b){ if(a<0) return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template <class T>     T lcm(T a,T b){ return a*(b/gcd(a,b));}

class 
	GameOfEight
{
public:
	set<string> M;
	vector<string> Q;
	int fewestMoves(vector<string>board)
	{
		string s="";
		for(int i=0;i<3;i++)s+=board[i];
		M.clear();
		M.insert(s);
		Q.clear();
		Q.push_back(s);
		for(int d=0,cl=0;cl<Q.size();d++)
		{
			cout<<d<<cl<<Q.size()<<endl;
			int size=Q.size();
			for(;cl<size;cl++)
			{
				s=Q[cl];
				if(s=="12345678.")return d;
				for(int i=0;i<9;i++)if(s[i]=='.')
					for(int j=0;j<9;j++)if(i!=j&&(abs(i/3-j/3)+abs(i%3-j%3)==1))
					{
						swap(s[i],s[j]);
						if(M.find(s)==M.end())
						{
							M.insert(s);
							Q.push_back(s);
						}
						swap(s[i],s[j]);
					}
			}
			
		}
		return -1;
	}
};
