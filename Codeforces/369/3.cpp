#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <vector>
#include <queue>
#include <deque>
#include <list>
using namespace std;
typedef long long ll;
#define INF 99999999999
ll dp[105][105][105];  //前i个树，第i个树染成j这种颜色，构成k段的最小花费
int c[105];  //最初树的颜色
int p[105][105];  //第i个树染成j颜色的花费
int main()
{
    int n,m,k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> p[i][j];
        }
    }
    memset(dp,1,sizeof(dp)); //花费初始化为很大值
    //处理第一课树
    if (c[0])  //如果第一棵树有颜色
    {
        dp[0][c[0]][1] = 0;
    }
    else
    {
        for (int i = 1; i <= m; i++) dp[0][i][1] = p[0][i];
    }

    for (int i = 1; i < n; i++)  //到第i个树
    {
        if (!c[i])  //如果这棵树可以被染色
        {
            for (int j = 1; j <= m; j++)  //第i个树染成j这种颜色
            {
                for (int k = 1; k <= i + 1; k++)  //分成了k段
                {
                    for(int h = 1; h <= m; h++)  //前面那个树是h这种颜色
                    {
                        if (j == h)  //如果当前这棵树和前面那棵树染的颜色相同
                        {
                            dp[i][j][k] = min(dp[i][j][k], dp[i - 1][h][k] + p[i][j]);
                        }
                        else  //不同，段数 + 1
                        {
                            dp[i][j][k] = min(dp[i][j][k],dp[i - 1][h][k - 1] + p[i][j]);
                        }
                    }
                }
            }
        }
        else
        {
            for (int k = 1; k <= i + 1; k++)  //分成了k段
            {
                for(int h = 1; h <= m; h++)  //前面那个树是h这种颜色
                {
                    if (c[i] == h)  //如果当前这棵树和前面那棵树染的颜色相同
                    {
                        dp[i][c[i]][k] = min(dp[i][c[i]][k], dp[i - 1][h][k]);
                    }
                    else  //不同，段数 + 1
                    {
                        dp[i][c[i]][k] = min(dp[i][c[i]][k],dp[i - 1][h][k - 1]);
                    }
                }
            }

        }
    }
    ll ans = INF;
    for (int i = 1; i <= m; i++)
    {
        ans = min(ans,dp[n - 1][i][k]);
    }
    if (ans == INF) ans = -1;
    cout << ans << endl;
    return 0;
}
