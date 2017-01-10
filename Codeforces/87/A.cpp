#include <iostream>
using namespace std;
int main()
{
	int m=-1;
	int n=0;
	cin>>n;
	int cap=0;
	for(int i=0;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		if(cap-a+b>m)
		{
			m=cap-a+b;
		}
		cap=cap-a+b;
	}
	cout<<m<<endl;
	return 0;
}