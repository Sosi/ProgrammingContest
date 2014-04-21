
#include <iostream>
#include <vector>
//#include <assert.h>
using namespace std;

//if (b,c) = 1 , (a/b)%c=a*b^(phi(c)-1)%c

long long MOD = 1e9+7LL;
int main()
{
	//cal	(2,4, 6 ^(MOD-2))%MOD
	long long x = 500000004LL;
	long long y = 250000002LL;
	long long z = 166666668LL;
	//assert(x*2LL % MOD == 1);
	//assert(y*4LL % MOD == 1);
	//assert(z*6LL % MOD == 1);


	int T; 
	//cin>>T;
	long long N;
	int num = 1;
	//while(T--)
	for(N=1LL; N<=100; N++)
	{
		//cin>>N;
		long long n1 = N%MOD;
		long long n2 = n1*n1%MOD;
		long long n3 = n2*n1%MOD;
		long long n4 = n3*n1%MOD;
		long long Y = (n4*y%MOD + n3*x%MOD + n2*y%MOD)*3LL%MOD;
		//cout<<"Y "<<Y<<endl;
		cout<<"Case "<<num++<<": ";
		cout<<(((n2*x +n1*x)%MOD) * ((n4*y%MOD - n3*x%MOD - n2*y*5LL%MOD-n1*x%MOD)%MOD)%MOD + Y  +MOD)%MOD<<endl;

	}
#ifdef TEST
	for(int i=0; i<MOD-2; i++)
	{
		x*=2LL;
		x %= MOD;
		y*= 4LL;
		y%= MOD;
		z*= 6LL;
		z%= MOD;
	}
	cout<<x<<" "<<y<<" "<<z<<endl;
	Case 1: 1
    Case 1: 1

#endif
	return 0;
}