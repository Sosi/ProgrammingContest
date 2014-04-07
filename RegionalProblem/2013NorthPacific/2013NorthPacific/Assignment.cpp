#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
int main()
{
	freopen("Assignments.in", "r", stdin);
	freopen("Assignments_.out", "w", stdout);
	int T; cin >> T;
	for (int i = 0; i < T; i++)
	{
		int N, D;
		cin >> N >> D;
		int num = 0;
		for (int j = 0; j < N; j++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			if (a*b >= c*D) num++;
		}
		cout << num << endl;
	}
	return 0;
}