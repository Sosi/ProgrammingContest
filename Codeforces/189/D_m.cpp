#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;

int N, a[1000006], f[1000006], top, stack[1000006];

int main()
{
	cin>>N ;
	for (int i = 1; i <= N; ++ i) cin>>a[i];
	int ans = 0;
	top = 0;
	for (int i = N; i; -- i)
	{
		f[i] = 0;
		while (top && a[i] > a[stack[top]])
		{
			int j = stack[top];
            f[i] = max(f[i]+1, f[j]);
			top --;
		}
		stack[++ top] = i;
		ans = max(ans, f[i]);
	}
	cout << ans << endl;

	return 0;
}
