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
#include <cstring>
using namespace std;

template<class T> T gcd(T a,T b)
{
    if(a<0) return gcd(-a,b);
    if(b<0)return gcd(a,-b);
    return (b==0)?a:gcd(b,a%b);
}
template <class T> T lcm(T a,T b)
{
    return a*(b/gcd(a,b));
}
template<class T> inline vector<pair<T,int> > factorize(T n)
{
    vector<pair<T,int> > R;
    for (T i=2; n>1;)
    {
        if (n%i==0)
        {
            int C=0;
            for (; n%i==0; C++,n/=i);
            R.push_back(make_pair(i,C));
        }
        i++;
        if (i>n/i) i=n;
    }
    if (n>1) R.push_back(make_pair(n,1));
    return R;
}
template<class T> inline bool isPrimeNumber(T n)
{
    if(n<=1)return false;
    for (T i=2; i*i<=n; i++) if (n%i==0) return false;
    return true;
}
template<class T> inline T eularFunction(T n)
{
    vector<pair<T,int> > R=factorize(n);
    T r=n;
    for (int i=0; i<R.size(); i++)r=r/R[i].first*(R[i].first-1);
    return r;
}
template<class T> string toString(T n)
{
    ostringstream ost;
    ost<<n;
    ost.flush();
    return ost.str();
}
int toInt(string s)
{
    int r=0;
    istringstream sin(s);
    sin>>r;
    return r;
}

int i,j,k;
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
int dirx[]= {1, 1, 0,-1,-1,-1,0,1};
int diry[]= {0,-1,-1,-1, 0, 1,1,1}; //clockwise
long long com[45][45];
int main()
{
    ios_base::sync_with_stdio(0);
    freopen("1.txt","r",stdin);

    int kindnum[50];
    int kindprice[50];
    double ave[50];
//    long long com[45][45];
    for(int i=0; i<45; i++) for(int j=0; j<45; j++) com[i][j] = 0LL;
    for(int i=0; i<45; i++)
        com[0][i] = 1LL;
    for(int k=1; k<45; k++)
    {
        for(int i=1; i<=k; i++)
            com[i][k] = com[i-1][k-1]+ com[i][k-1];
    }
//    cout<<"2 3 "<<com[2][4]<<endl;


    int T; cin>>T;
    while(T--)
    {
        memset(kindprice, 0, sizeof(kindprice));
        memset(kindnum, 0, sizeof(kindnum));
        for(int i=0; i<50; i++ ) ave[i] = 0.0f;
        int N, M; cin>>N>>M;
        for(int i=0; i<N; i++)
        {
            int c, p; cin>>c>>p;
            kindnum[c]++;
            kindprice[c] += p;
        }
        int K = 0;
        for(int i=0; i<50; i++)
        {
            if(kindnum[i] == 0) continue;
            else{
                K++;
                ave[i] = kindprice[i] *1.0 * (1LL<<(kindnum[i] - 1)) / (1.0 * (1LL<<(kindnum[i])) - 1.0);
            }
        }
//        for(int i=0; i<50; i++)
//        {
//            if(kindnum[i]!=0 )
//            {
//                cout<<"Kind "<<i<<" "<<ave[i]<<endl;
//            }
//        }
//        cout<<endl;
        double x = 0.0f; double y = 0.0f;
        for(int i = M-1; i<=K-1; i++)
        {
            x+= com[i][K-1];
        }
        for(int i=M; i<=K; i++)
        {
            y += com[i][K];
        }
        double ret = 0;
        for(int i=0; i<50; i++)
        {
            if(kindnum[i]!=0) ret += ave[i];
        }
        printf("%.8f\n", ret*x/y);
//        cout<<ret* x/y<<endl;
//        cout<<x/y *
    }

    return 0;
}
