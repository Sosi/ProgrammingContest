#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;
int vis[1001];
int d[1001];
int M[1001];
int din[1001];
struct KK
{
	int a;
	int b;
	int c;
};
bool cmp(KK A,KK B)
{
	return A.a<B.a;
}
int main()
{
	//freopen("C.txt","r",stdin);
	vector<KK> C;
	int n,p;
	cin>>n>>p;
	for(int i=0;i<1001;i++){ M[i]=0;d[i]=0;din[i]=0;}
	for(int i=0;i<p;i++)
	{
		int a,b,dia;
		cin>>a>>b>>dia;
		M[a]=b;
		d[a]=dia;
		din[b]=1;
	}
	for(int i=0;i<=n;i++) vis[i]=-1;

	for(int i=1;i<=n;i++)
	{
		if(vis[i]==-1 && din[i]==0 && M[i]!=0)
		{
			//cout<<"P  "<<i<<endl;
			vis[i]=0;
			int st=i;
			int des=M[i];
			int dd=d[i];
			while(M[des] !=0 && vis[des] == -1)
			{
				//cout<<st<<"  to  "<<des<<endl;
				dd=min(dd,d[des]);
				st=des;
				vis[des]=0;
				des=M[des];
			}
			vis[des]=0;
			if(M[des]==0){KK ls;ls.a=i;ls.b=des;ls.c=dd;C.push_back(ls);}
		}
	}
	//for(int i=1;i<=n;i++){if(vis[i]==-1 && M[i]==0 && din[i]==0) { KK ls; ls.a=i;ls.b=0;ls.c=0;C.push_back(ls);}}

	sort(C.begin(),C.end(),cmp);
	cout<<C.size()<<endl;
	for(int i=0;i<C.size();i++)
	{
		cout<<C[i].a<<" "<<C[i].b<<" "<<C[i].c<<endl;
	}
	return 0;
}