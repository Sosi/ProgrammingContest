#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*

for(k=1;k<=n;k++)
4         for(i=1;i<=n;i++)
5             for(j=1;j<=n;j++)
6                 if(dist[i][k]+dist[k][j]<dist[i][j])
7                     dist[i][j]=dist[i][k]+dist[k][j];
8 }
没有一个好的数学模型来表示，网格图上任意两点之间的最短距离！
有一些点是关心的距离点，有一些点只是一个路径！！
这个数据结构怎么搭建？！！
*/
int m[55][55];
int dist[55*55][55*55];
struct point
{
	int i;
	int j;
	char c;
};
point Start;
vector<point> P;
class SlimeXResidentSlime
{
public:
	int exterminate(vector <string> field)
	{
		for(int i=0;i<55*55;i++)
		{
			for(int j=0;j<55*55;j++)
				dist[i][j]=120;
		}
		for(int i=0;i<field.size();i++)
		{
			for(int j=0;j<field[0].size();j++)
			{
				if(field[i][j]=='.'||field[i][j]=='$'||(field[i][j]-'0'>=0&&field[i][j]-'0'<=9))
				{
					point p;
					p.i=i;p.j=j;p.c=field[i][j];
					if(field[i][j]=='$') Start=p;
				}
			}
		}
		for(int i=0;i<P.size();i++)
		{
			for(int j=0;j<P.size();j++)
			{
				if(abs(P[i].i-P[j].i)+abs(P[i].i -P[j].j ) ==1 ) dist[i][j]=1;
			}
		}
		int n=P.size();
		for(int k=0;k<=n;k++)
		{
			        for(int i=0;i<n;i++)
					{
			             for(int j=0;j<n;j++)
			                 if(dist[i][k]+dist[k][j]<dist[i][j])
			                    dist[i][j]=dist[i][k]+dist[k][j];
					}
		 }
		for(int i=0;i<P.size();i++)
		{
			for(int j=0;j<P.size();j++)
			{
				if()
			}
		}


		//for(int i=0;i<54;i++)
		//{
		//	for(int j=0;j<54;j++)
		//	{
		//		if(m[i][j]==1&& m[i][j+1]==1)
		//			dist[i][j]=1;
		//	}
		//}


	}
};