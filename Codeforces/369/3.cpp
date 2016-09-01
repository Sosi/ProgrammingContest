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
ll dp[105][105][105];  //ǰi��������i����Ⱦ��j������ɫ������k�ε���С����
int c[105];  //���������ɫ
int p[105][105];  //��i����Ⱦ��j��ɫ�Ļ���
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
    memset(dp,1,sizeof(dp)); //���ѳ�ʼ��Ϊ�ܴ�ֵ
    //�����һ����
    if (c[0])  //�����һ��������ɫ
    {
        dp[0][c[0]][1] = 0;
    }
    else
    {
        for (int i = 1; i <= m; i++) dp[0][i][1] = p[0][i];
    }

    for (int i = 1; i < n; i++)  //����i����
    {
        if (!c[i])  //�����������Ա�Ⱦɫ
        {
            for (int j = 1; j <= m; j++)  //��i����Ⱦ��j������ɫ
            {
                for (int k = 1; k <= i + 1; k++)  //�ֳ���k��
                {
                    for(int h = 1; h <= m; h++)  //ǰ���Ǹ�����h������ɫ
                    {
                        if (j == h)  //�����ǰ�������ǰ���ǿ���Ⱦ����ɫ��ͬ
                        {
                            dp[i][j][k] = min(dp[i][j][k], dp[i - 1][h][k] + p[i][j]);
                        }
                        else  //��ͬ������ + 1
                        {
                            dp[i][j][k] = min(dp[i][j][k],dp[i - 1][h][k - 1] + p[i][j]);
                        }
                    }
                }
            }
        }
        else
        {
            for (int k = 1; k <= i + 1; k++)  //�ֳ���k��
            {
                for(int h = 1; h <= m; h++)  //ǰ���Ǹ�����h������ɫ
                {
                    if (c[i] == h)  //�����ǰ�������ǰ���ǿ���Ⱦ����ɫ��ͬ
                    {
                        dp[i][c[i]][k] = min(dp[i][c[i]][k], dp[i - 1][h][k]);
                    }
                    else  //��ͬ������ + 1
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
