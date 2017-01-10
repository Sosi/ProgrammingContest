#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
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
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;


int i,j,k;
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
int main()
{
    string S;
    cin>>S;
    vector<int> H;
    vector<int> M;
    REP(i,S.size())
    {
        if(i+5 <=S.size() && S.substr(i,5) == "metal") M.push_back(i);
        else if(i+5 <= S.size() && S.substr(i,5) == "heavy") H.push_back(i);
    }
    long long ret = 0LL;
    j=0;
    if(M.size() != 0)
    {
        for(i=0; i<H.size();)
        {
            if(H[i] < M[j])
            {
                ret += (long long)(M.size()-j);
                i++;
            }
            else j++;
        }
    }
    cout<<ret<<endl;
    return 0;
}
