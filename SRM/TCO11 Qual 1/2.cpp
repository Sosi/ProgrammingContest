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
#include <cstring> 

using namespace std; 
class FoxListeningToMusic { 
public: vector <double> getProbabilities(vector <int> length, int T); 
}; 

double arr[85000]; 

vector <double> FoxListeningToMusic::getProbabilities(vector <int> length, int T) 
{ 
	vector<double> out(length.size(),0.0); 
	memset(arr, 0, sizeof(arr)); 
	arr[0] = 1.0; 
	const int N = length.size(); 
	const double denom = 1.0 / length.size(); 
	for(int i=0;i<=T;++i) 
	{ 
		const double P = arr[i] * denom; 
		for(int j=0;j<N;++j) 
		{ 
			int at = i+length[j]; 
			if(at > T){out[j] += P;} 
			else{arr[at] += P;} 
		} 
	} 
	return out; 
}

int main()
{
	int a[4]={2,4,6,9};
	vector<int> p(a,a+4);
	int dp[800];
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	for(int i=0;i<50;i++)
	{
		for(int j=0;j<p.size();j++)
			dp[i+p[j]]+=dp[i];
	}
	return 0;
}