#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>

using namespace std;

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        int r, c;
        long long g;
        scanf("%d %d %lld", &r, &c, &g);
        if (c <= 1)
        {
            printf("%d\n", 1);
            printf("%lld\n", g);
            continue;
        }
        vector <long long> ret;
        long long mx = g;
        while (g > 0)
        {
            int low = c, high = 2000000;
            while (low < high)
            {
                int mid = (low + high + 1) >> 1;
                int by = (c < mid - c) ? c : (mid - c);
                long long res = 1;
                for (int i = 0; i < by; i++)
                {
                    res *= mid - i;
                    res /= i + 1;
                    if (res > g)
                    {
                        break;
                    }
                }
                if (res > g || res > mx) high = mid - 1;
                else low = mid;
            }
            int mid = low;
            int by = (c < mid - c) ? c : (mid - c);
            long long res = 1;
            for (int i = 0; i < by; i++)
            {
                res *= mid - i;
                res /= i + 1;
            }
            g -= res;
            mx = res;
            ret.push_back(res);
            c--;
        }
        int sz = ret.size();
        printf("%d\n", sz);
        for (int i = 0; i < sz - 1; i++) printf("%lld ", ret[i]);
        printf("%lld\n", ret[sz - 1]);
    }
    return 0;
}
