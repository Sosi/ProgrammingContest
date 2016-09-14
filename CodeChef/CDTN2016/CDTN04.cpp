#include  <bits/stdc++.h>

using namespace std;

int N, K;
long long dp[66][66];

int main()
{
    scanf("%d%d", &N, &K);
    dp[0][0] = 1;
    for(int i = 0; i< N; i++)
    {
        for(int j = 0; j<  K; j++)
        {
            dp[i+1][0] += dp[i][j];
            dp[i+1][j+1] += dp[i][j];
        }

        dp[i+1][K] += dp[i][K] * 2;
    }

    long long nu = dp[N][K], de = 1LL << N;
    long long g = __gcd(nu, de);
    nu /= g;
    de /= g;
    printf("%lld/%lld\n", nu, de);

    return 0;
}
