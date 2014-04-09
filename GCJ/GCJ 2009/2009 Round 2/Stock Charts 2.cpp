#include <iostream>
#include <vector>
using namespace std; 

/*
Hungarian Algorithm 
匈牙利算法(Edmonds)
邻接表 (n^3) 邻接矩阵(mn) 
cx[] cy[]中保存二分图最大匹配的方案
（一）每个X节点都最多做一次增广路的起点；
（二）如果一个Y节点已经匹配了，那么增广路到这儿的时候唯一的路径是走到Y节点的匹配点
*/
#define  MAXN 505

int nx,ny,g[MAXN][MAXN],sy[MAXN],cx[MAXN],cy[MAXN];

int path(int u)
{
	for(int v=1;v<=ny;v++)
		if(g[u][v] && !sy[v]){ sy[v]=1;
	if(!cy[v] || path(cy[v])){cx[u]=v,cy[v]=u;return 1;}
	}
	return 0;
}

int Hungarian()
{
	int ret=0;
	memset(cx,0,sizeof(cx));memset(cy,0,sizeof(cy));
	for(int i=1;i<=nx;i++) if(!cx[i]){memset(sy,0,sizeof(sy));ret+=path(i);}
	return ret;
}
bool pick( vector< int > a, vector< int >b){
    bool flag=true;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]<=b[i]) flag=false;
    }
    return flag;
}
int main(){
    freopen("C-large-practice.in","r",stdin);
    freopen("C-large-practice.out","w",stdout);
    int T;
    cin>>T;
    for(int t=1;t<=T;t++){
        memset(g,0,sizeof(g));
        int n,k;
        cin>>n>>k;
        nx=n,ny=n;
        vector<vector<int > > C(n);
        vector<int>temp(k);
        for(int i=0;i<n;i++){
            for(int j=0;j<k;j++){
                cin>>temp[j];
            }
            C[i]=temp;
        }
        for(int i=0;i<C.size();i++){
            for(int j=0;j<C.size();j++)
            {
                if(pick(C[i],C[j]))g[i+1][j+1]=1;
            }
        }
        cout<<"Case #"<<t<<": "<<C.size()-Hungarian()<<endl;
       // for(int i=1;i<=C.size();i++)cout<<cx[i]<<" ";cout<<endl;
    }
    return 0;
}
