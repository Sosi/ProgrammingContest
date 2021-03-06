#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
#define MAXN 500001

/**

Union Find Set or Disjoint-set data structure.

Warning: 0- indexed
*/
struct
{
	int parent;       // parent is negative , it is root .Memorize the parent node of the current node.
	int rank;         // rank hegith of the tree
	bool flag;        // Wheather to be deleted.
}UFS[MAXN];

int N;

void UFS_init()
{
	for(int i=0;i<N;i++)             //0-indexed
	{
		UFS[i].parent=-1;
		UFS[i].rank=0;
		UFS[i].flag=0;
	}
}

int Root(int x)
{
	int i=x,temp;
	while(UFS[i].parent>=0) i=UFS[i].parent;
	while(i!=x)
	{
		temp=UFS[x].parent;
		UFS[x].parent=i;
		x=temp;
	}
	return i;
}

/*
Union1 find the node in the tree.(abs(parent)).
*/
void Union1(int a,int b)
{
	int x=Root(a), y=Root(b);
	if( x==y ) return;
	if(UFS[x].parent < UFS[y].parent)
		UFS[x].parent+=UFS[y].parent,UFS[y].parent=x;
	else
		UFS[y].parent+=UFS[x].parent,UFS[x].parent=y;

}
/*
Union2 find the height of the tree. (rank)
*/
void Union2(int a, int b)
{
	int x = Root(a), y = Root(b);
	if( x == y ) return ;
	if( UFS[x].rank > UFS[y].rank ) UFS[y].parent = x;
	else{
		UFS[x].parent = y;
		if( UFS[x].rank == UFS[y].rank ) UFS[y].rank++;
	}
}
/*
Delete the node of the x. (flag)  It became the virtual node!
*/
void Del1(int x)
{
	if(UFS[x].parent==-1)
		UFS[x].flag=true;
	else
	{
		if(UFS[x].parent>=0)
		{
			UFS[x].flag=true;
			int i=x;
			while(UFS[i].parent>=0)
				i=UFS[i].parent;
			UFS[i].parent+=1;
		}
		else
			UFS[x].parent+=1,UFS[x].flag=true;
	}
}

int main()
{
//    freopen("1.txt","r",stdin);
    int T; cin>>T;
    for(int cas = 1; cas<=T; cas++)
    {
        cin>>N;
        int B, Q; cin>>B>>Q;
        UFS_init();
        for(int i=0; i<B; i++)
        {
            int x,y; cin>>x>>y;
            x--; y--;
            Union1(x,y);
        }
        for(int i=0; i<Q; i++)
        {
            int x,y; cin>>x>>y;
            x--; y--;
            if(Root(x) == Root(y))
                cout<<"only bus"<<endl;
            else cout<<"bus and taxi"<<endl;
        }

    }
//	N=7;
//	UFS_init();
//	Union1(1,0);
//	Union1(1,2);
//	Union1(3,4);
//	Union1(1,4);
//	for(int i=0;i<N;i++)
//	{
//		if(UFS[i].flag==1)
//		{
//			cout<<"Index"<<i<<" be deleted"<<endl;
//			cout<<"Index  "<<i<<"  parent   "<<UFS[i].parent<<"   rank  "<<UFS[i].flag<<endl;
//		}
//		else
//			cout<<"Index  "<<i<<"  parent   "<<UFS[i].parent<<"   rank  "<<UFS[i].flag<<endl;
//
//	}
    return 0;
}

