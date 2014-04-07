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
#define PI  3.1415926535897932384626

template<class T>     T gcd(T a,T b){ if(a<0) return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template <class T>     T lcm(T a,T b){ return a*(b/gcd(a,b));}

class 
	JohnnysCannon
{
public:
	double getDistance(int velocity, int distance, vector <int> angles)
	{
		vector<double> diff;
		vector<double> dis;
		for(int i=0;i<angles.size();i++)
		{
			dis.push_back(velocity*velocity*sin(2*angles[i]/180.0*PI)/10);
		}
		for(int i=0;i<angles.size();i++)
		{
			if(velocity*velocity*sin(2*angles[i]/180.0*PI)/10>=distance*1.0)
				diff.push_back(velocity*velocity*sin(2*angles[i]/180.0*PI)/10-distance);
			else
				diff.push_back(distance-velocity*velocity*sin(2*angles[i]/180.0*PI)/10);
		}
		sort(diff.begin(),diff.end());
		return diff[0];
	}
};
