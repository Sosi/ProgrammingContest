#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

set<vector<int>> PP;
int Analysis(vector<int> A,vector<int>B)
{
	vector<int> a;
	vector<int> b;
	vector<int> c;
	set<int> K;
	for(int i=0;i<A.size();i++)
		K.insert(A[i]);
	for(int j=0;j<B.size();j++)
		K.insert(B[j]);
	if(K.size()==A.size()+B.size())
		return 0;

	for(int i=0;i<A.size();i++)
	{
		for(int j=0;j<B.size();j++)
		{
			if(A[i]==B[j])
			{
				a.push_back(A[i]);
			}
		}
	}
	for(int i=0;i<A.size();i++)
	{
		bool flag=true;
		for(int j=0;j<a.size();j++)
		{
			if(A[i]==a[j])
			{
				flag=false;
				break;
			}
		}
		if(flag)
		{
			b.push_back(A[i]);
		}
	}
	for(int i=0;i<B.size();i++)
	{
		bool flag=true;
		for(int j=0;j<a.size();j++)
		{
			if(B[i]==a[j])
			{
				flag=false;
				break;
			}
		}
		if(flag)
		{
			c.push_back(B[i]);
		}
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	sort(c.begin(),c.end());
	PP.insert(a);
	PP.insert(b);
	PP.insert(c);
//	cout<<a.size()<<" "<<b.size()<<" "<<c.size()<<endl;
	return 0;
}
int main()
{
//	freopen("1.txt","r",stdin);

	int n;
	cin>>n;
	int k;
	vector<int> Mode;
	cin>>k;
	int temp;
	for(int i=0;i<k;i++)
	{
		cin>>temp;
		Mode.push_back(temp);
	}
	if(n==2)
	{
		cout<<1<<" "<<Mode[0]<<endl;
		cout<<Mode.size()-1<<" ";
		for(int i=1;i<Mode.size();i++)
			cout<<Mode[i]<<" ";
		cout<<endl;
		return 0;
	}

	while(cin>>k)
	{	
		vector<int> N;
		for(int i=0;i<k;i++)
		{
			cin>>temp;
			N.push_back(temp);
		}
		Analysis(Mode,N);
	}
	set< vector<int> >::iterator it;
//	cout<<"!!!!!!!!!"<<endl;

	for ( it=PP.begin() ; it != PP.end(); it++ )
	{
		cout<<(*it).size()<<" "; 
		for(int j=0;j<(*it).size();j++)
		{
			cout<<(*it)[j]<<" ";
			
		}
		cout<<endl;
	}

	return 0;
}