#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#define MOD 1000000007
#define N 2005
#define mp make_pair
#define X first
#define Y second
using namespace std;
typedef int ll;
ll i,j,n,h,x,y,cur_h,k,m,p,fx,fy;
ll a[505][505], dp[505][505], d[505][505];
ll dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
vector<pair<ll,ll> > g[250505];
vector<pair<ll, pair<ll,ll> > > lst, bfs;
ll Abs(ll x)
{
	return x>0?x:-x;
}
ll find_dist(ll x1, ll y1, ll x2, ll y2)
{
	return Abs(x1-x2) + Abs(y1-y2);
}
bool in_range(ll x, ll y)
{
	return (x >= 0 && x < y);
}
int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >> n >> m >> p;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			dp[i][j] = (ll)1e+9;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
		{
			scanf("%d", &a[i][j]);
			g[a[i][j]].push_back(mp(i,j));
			if (a[i][j] == 1)
			   dp[i][j] = i+j;
			if (a[i][j] == p)
			   fx = i, fy = j;
		}
	for (i = 2; i <= p; i++)
	{
		ll cur_size = g[i].size();
		ll last_size = g[i-1].size();
		if (cur_size * last_size <= n * m)
		{
			for (j = 0; j < cur_size; j++)
			{
				ll cur_x = g[i][j].X;
				ll cur_y = g[i][j].Y;
				for (k = 0; k < last_size; k++)
				{
					ll last_x = g[i-1][k].X;
					ll last_y = g[i-1][k].Y;
					dp[cur_x][cur_y] = min(dp[cur_x][cur_y], dp[last_x][last_y] + find_dist(cur_x,cur_y,last_x,last_y));
				}
			}
		} else
		{
			for (k = 0; k < n; k++)
				for (j = 0; j < m; j++)
					d[k][j] = -1;
			bfs.clear();
			lst.clear();
			for (j = 0; j < last_size; j++)
			{
				ll last_x = g[i-1][j].X;
				ll last_y = g[i-1][j].Y;
				lst.push_back(mp(dp[last_x][last_y], mp(last_x, last_y)));
			}
			sort(lst.begin(), lst.end());
			ll pointer = 1;
			j = 0;
			bfs.push_back(lst[0]);
			d[lst[0].Y.X][lst[0].Y.Y] = lst[0].X;
			while (j < bfs.size())
			{
				ll x = bfs[j].Y.X;
				ll y = bfs[j].Y.Y;
				ll val = bfs[j].X;
				j++;
				while (pointer < lst.size() && lst[pointer].X <= val)
					  bfs.push_back(lst[pointer++]);
				for (k = 0; k < 4; k++)
					if (in_range(x+dir[k][0], n) && in_range(y+dir[k][1], m) && d[x+dir[k][0]][y+dir[k][1]] == -1)
					{
						d[x+dir[k][0]][y+dir[k][1]] = val+1;
						bfs.push_back(mp(val+1, mp(x+dir[k][0], y+dir[k][1])));
					}
			}
			for (j = 0; j < cur_size; j++)
			{
				ll cur_x = g[i][j].X;
				ll cur_y = g[i][j].Y;
				dp[cur_x][cur_y] = d[cur_x][cur_y];
			}
		}
	}
	cout << dp[fx][fy] << endl;
	return 0;
}
