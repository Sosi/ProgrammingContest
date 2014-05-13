#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
#define MAX 500009
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

vector<int> G[MAX];
int L[MAX];
int R[MAX];
int cnt=0;
int data[MAX<<3][2];// 0 fill 1 empty
void dfs(int x,int fa)
{
	L[x]=++cnt;
	for(int i=0;i<G[x].size();i++)
	{
		int v=G[x][i];
		if(v!=fa)
			dfs(v,x);
	}
	R[x]=++cnt;
}

void PushDown(int rt)
{
		data[rt<<1][0] = max(data[rt<<1][0],data[rt][0]);
		data[rt<<1|1][0] = max(data[rt<<1|1][0],data[rt][0]);
}
void PushUp(int rt)
{
	int t=max(data[rt<<1][1],data[rt<<1|1][1]);
	data[rt][1]=max(t,data[rt][1]);
}
void Update(int a,int b,int op,int time,int l,int r,int rt)
{

	if(b<l||a>r) return;
//	printf("a %d b %d op %d time %d l %d r %d rt %d\n",a,b,op,time,l,r,rt);
	if(a<=l&&r<=b)
	{
		data[rt][op]=time;
		return;
	}
	PushDown(rt);
	int m = (l+r)>>1;
	Update(a,b,op,time,lson);
	Update(a,b,op,time,rson);
	PushUp(rt);
}
int Query(int a,int b,int op,int l,int r,int rt)
{

	if(a>r||b<l)
		return -1;
	if(a<=l&&r<=b)
		return 	data[rt][op];

	PushDown(rt);

	int m = (l+r)>>1;
	int ans = 0;
	ans=max(ans,Query(a,b,op,lson));
	ans=max(ans,Query(a,b,op,rson));
	PushUp(rt);
//	printf("v1 %d v2 %d\n", v1, v2);
	return ans;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		int f,t;
		scanf("%d%d",&f,&t);
		G[f].push_back(t);
		G[t].push_back(f);
	}
	dfs(1,0);
	memset(data,0,sizeof(data));
	int m;
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int t,v;
		scanf("%d%d",&t,&v);
		switch(t)
		{
			case 1:
				Update(L[v],R[v],0,i,L[1],R[1],1);
				break;
			case 2:
				Update(L[v],L[v],1,i,L[1],R[1],1);
				break;
			case 3:
				int v1=Query(L[v],L[v],0,L[1],R[1],1);
				int v2=Query(L[v],R[v],1,L[1],R[1],1);
				if(v1>v2)
					puts("1");
				else
					puts("0");
				break;
		}
	}
	return 0;
}
