#include<bits/stdc++.h>
using namespace std;
const int nax = 505;
int n;
char grid[nax][nax]; // input
int cc[nax][nax]; // id of CC in which this cell is
int cc_size[nax*nax]; // size of CC
int when_added[nax*nax];

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const char EMPTY = '.';

bool inside(int x, int y) {
	return 0 <= min(x, y) && max(x, y) < n;
}

void dfs(int x, int y, int which_cc) {
	cc[x][y] = which_cc;
	++cc_size[which_cc];
	for(int i = 0; i < 4; ++i) { // iterate of 4 adjacent cells
		int x2 = x + dx[i];
		int y2 = y + dy[i];
		if(inside(x2, y2) && grid[x2][y2] == EMPTY && cc[x2][y2] == 0)
			dfs(x2, y2, which_cc);
	}
}

void add(int x, int y, int & answer, int current_time) {
	if(inside(x, y) && grid[x][y] == EMPTY) {
		int id = cc[x][y];
		if(when_added[id] != current_time) {
			when_added[id] = current_time;
			answer += cc_size[id];
		}
	}
}

int main() {
	int k;
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; ++i)
		scanf("%s", grid[i]);

	// run DFS many times to find CC's (connected components)
	int how_many_cc = 0;
	for(int x = 0; x < n; ++x)
		for(int y = 0; y < n; ++y)
			if(grid[x][y] == EMPTY && cc[x][y] == 0)
				dfs(x, y, ++how_many_cc);

	int cur_time = 1;
	int best_answer = 0;

	for(int y_low = 0; y_low + k <= n; ++y_low) {
		// first we put a square with corner in (0, y_low)
		for(int x = 0; x < k; ++x)
			for(int y = y_low; y < y_low + k; ++y)
				--cc_size[cc[x][y]]; // subtract cells inside a square

		for(int x_low = 0; x_low  + k <= n; ++x_low) {
			int answer = k * k; // all cells inside a square
			// consider one row: below, above, left, right
			for(int x = x_low; x < x_low + k; ++x) {
				add(x, y_low - 1, answer, cur_time);
				add(x, y_low + k, answer, cur_time);
			}
			for(int y = y_low; y < y_low + k; ++y) {
				add(x_low - 1, y, answer, cur_time);
				add(x_low + k, y, answer, cur_time);
			}
			++cur_time;
			best_answer = max(best_answer, answer);

			if(x_low + k != n) {
				// move a square to increase x_low by 1
				for(int y = y_low; y < y_low + k; ++y) {
					++cc_size[cc[x_low][y]]; // remove cells with x = x_low
					--cc_size[cc[x_low+k][y]]; // insert cells with x = x_low+k
				}
			}
		}

		for(int x = n - k; x < n; ++x)
			for(int y = y_low; y < y_low + k; ++y)
				++cc_size[cc[x][y]]; // we don't need cells inside to be subtracted
	}
	printf("%d\n", best_answer);
	return 0;
}
