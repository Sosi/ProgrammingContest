#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int s=(int)ceil(log((n+5.0)/5.0)/log(2.0));
	//cout<<s<<endl;
	int m=n-(5*(1<<(s-1))-5);
	//cout<<m<<endl;
	s--;
	if(0<m && m<=1<<s) 	cout<<"Sheldon"<<endl;;
	if(m>(1<<s)&&m<=2*(1<<s)) cout<<"Leonard"<<endl;
	if(m>2*(1<<s)&& m<=3*(1<<s))cout<<"Penny"<<endl;
	if(m>3*(1<<s)&& m<=4*(1<<s)) cout<<"Rajesh"<<endl;
	if(m>4*(1<<s)&& m<=5*(1<<s)) cout<<"Howard"<<endl;

	return 0;
}