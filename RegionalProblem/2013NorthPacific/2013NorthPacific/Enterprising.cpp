#ifdef SOSI
#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <queue>
using namespace std;
#define INF (1<<30)

int main()
{
	//cout << ">?" << endl;
	freopen("Escape_.in", "r", stdin);
	//freopen("Escape_.out", "w", stdout);
	int T; cin >> T; 
	//cout << "!!" << endl;
	for (int t = 1; t <= T; t++)
	{
		int k, w, h; cin >> k >> w >> h;
		map<char,int> mark;
		for (int i = 0; i < k; i++)
		{
			char m; int v;
			cin >> m >> v;
			mark[m] = v;
		}
		vector<string> M;
		for (int i = 0; i < h; i++)
		{
			string temp; cin >> temp; //temp;
			M.push_back(temp);
		}
		int startx = -1; int starty = -1;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (M[i][j] == 'E')
				{
					startx = i; starty = j;
				}
			}
		}
		vector<vector<int> > vis(h, vector<int>(w, 0));
		vector<vector<int> > value(h, vector<int>(w, INF));
		//for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) value[i][j] = INF;
		queue<pair<int, int>> Q;
		value[startx][starty] = 0;
		vis[startx][starty] = 1;
		Q.push(make_pair(startx, starty));
		int ret = INF;
		while (!Q.empty())
		{
			pair<int,int> tmp = Q.front();
			Q.pop();
			if (tmp.first == 0 || tmp.first == h - 1 || tmp.second == 0 || tmp.second == w - 1)
			{
				ret = min(ret, value[tmp.first][tmp.second]);
				continue;
			}
			for (int x = -1; x <= 1; x++)
			{
				for (int y = -1; y <= 1; y++)
				{
					if (x*y == 0 && !vis[tmp.first + x][tmp.second + y])
					{
						if (value[tmp.first + x][tmp.second + y] > value[tmp.first][tmp.second] + mark[M[tmp.first+x][tmp.second+y]])
						{
							value[tmp.first + x][tmp.second + y] = value[tmp.first][tmp.second] + mark[M[tmp.first+x][tmp.second+y]];
							Q.push(make_pair(tmp.first + x, tmp.second + y));
						}
					}
				}
			}
		}
		cout << ret << endl;
	}
	return 0;
}
#endif
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<bool> VB;
typedef vector<VB> VVB;

int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, -1, 0, 1 };

struct loc {
	int r, c, d;
	bool operator<(const loc &o) const {
		return d > o.d;
	}
};

int main() {
	int T;
	cin >> T;
	VI delay(26);
	for (int tc = 0; tc < T; tc++) {
		int k, w, h;
		cin >> k >> w >> h;
		char c;
		int d;
		for (int i = 0; i < k; i++) {
			cin >> c >> d;
			delay[c - 'A'] = d;
		}

		VVI dist(h, VI(w));
		loc start;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> c;
				dist[i][j] = delay[c - 'A'];
				if (c == 'E') {
					start.r = i;
					start.c = j;
					start.d = 0;
				}
			}
		}

		VVB visited(h, VB(w));

		priority_queue<loc> pq;
		pq.push(start);
		while (!pq.empty()) {
			loc cur = pq.top();
			pq.pop();
			if (visited[cur.r][cur.c]) continue;
			visited[cur.r][cur.c] = true;
			if (cur.r == 0 || cur.r == h - 1 || cur.c == 0 || cur.c == w - 1) {
				cout << cur.d << endl;
				break;
			}
			for (int i = 0; i < 4; i++) {
				loc next;
				next.r = cur.r + dr[i];
				next.c = cur.c + dc[i];
				next.d = cur.d + dist[next.r][next.c];
				if (!visited[next.r][next.c]) pq.push(next);
			}
		}
	}
}
