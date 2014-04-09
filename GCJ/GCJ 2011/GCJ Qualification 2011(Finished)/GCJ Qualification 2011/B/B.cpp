#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	int T;
	cin>>T;
	for(int Case=1;Case<=T;Case++)
	{
		vector<string> C;
		vector<string >D;
		string N;
		int c;
		int d;
		int n;
		cin>>c;
		string temp;
		for(int i=0;i<c;i++)
		{
			cin>>temp;
			C.push_back(temp);
		}
		cin>>d;
		for(int i=0;i<d;i++)
		{
			cin>>temp;
			D.push_back(temp);
		}
		cin>>n;
		cin>>N;
		vector<char> res;
		res.push_back(N[0]);
		for(int i=1;i<N.size();i++)
		{
			if(res.size()==0)
			{
				res.push_back(N[i]);
				continue;
			}
			bool flag=true;
			for(int j=0;j<C.size();j++)
			{
				if((res[res.size()-1]==C[j][0]&& N[i]==C[j][1])||(res[res.size()-1]==C[j][1]&& N[i]==C[j][0]))
				{
					res[res.size()-1]=C[j][2];
					flag=false;
					break;
				}
			}
			if(flag)
			{	
				for(int j=0;j<D.size();j++)
				{
					if(N[i]==D[j][1])
					{
						for(int k=0;k<res.size();k++)
						{	
							if(res[k]==D[j][0])
							{
								res.clear();
								flag=false;
							}

						}
					}
					if(N[i]==D[j][0])
					{
						for(int k=0;k<res.size();k++)
						{	
							if(res[k]==D[j][1])
							{
								res.clear();
								flag=false;
							}

						}
					}
					/*if((res[res.size()-1]==D[j][0]&& N[i]==D[j][1])||(res[res.size()-1]==D[j][1]&& N[i]==D[j][0]))
					{
					res.clear();
					flag=false;
					break;
					}*/
				}

			}
			if(flag)
				res.push_back(N[i]);
		}
		cout<<"Case #"<<Case<<": [";
		for(int i=0;i<res.size();i++)
		{
			cout<<res[i];
			if(i!=res.size()-1)
				cout<<", ";
		}
		cout<<"]"<<endl;
	}
	return 0;
}