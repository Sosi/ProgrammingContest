#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main()
{
	freopen("B-large-practice.in","r",stdin);
	freopen("B-large-practice.out","w",stdout);
	int T;
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		int M;
		cin>>M;
		int price[12];
		for(int i=0;i<12;i++)
			cin>>price[i];
		int x,y,res=-1;
		for(int i=0;i<12;i++)
		{
			if(price[i]<M)
			{
				int m=price[i];
				int tempj=-1;
				for(int j=i+1;j<12;j++)
				{
					if(price[j]>m) {m=price[j];tempj=j;}
				}
				if(M/price[i]*(m-price[i])>res){ res=M/price[i]*(m-price[i]);x=i;y=tempj;}
				if(M/price[i]*(m-price[i])==res){res=M/price[i]*(m-price[i]);if(price[i]<price[x]){ x= i;y=tempj;}}
			}
		}
		if(res==-1) cout<<"Case #"<<t<<": "<<"IMPOSSIBLE"<<endl;
		else
			cout<<"Case #"<<t<<": "<<x+1<<" "<<y+1<<" "<<res<<endl; 
	}
	return 0;
}