#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
template<class T> T gcd(T a,T b){ if(a<0) return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template <class T> T lcm(T a,T b){ return a*(b/gcd(a,b));}
class AllButOneDivisor
{
public:
	int getMinimum(vector <int> divisors)
	{
		//sort(divisors.begin(),divisors.end());
		int total=-1;
		for(int j=0;j<divisors.size();j++)
		{
			int res=1;
			for(int i=0;i<divisors.size() ;i++)
			{
				if(i==j)continue;
				res=lcm(res,divisors[i]);
			}
			cout<<"res   "<<res<<endl;
			cout<<"p     "<<divisors[j]<<endl;
			if(res%divisors[j]!=0)
			{
				if(total==-1) total=res;
				else if(res<total) total=res;
			}

		}
		return total;
	}
};