#include<bits/stdc++.h>
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
int dirx[]= {1,  0, -1, 0 };
int diry[]= {0, -1, 0, 1}; //clockwise

int H[55][55];
int R,C;

bool possible(int x, int y , int h)
{
    bool vis[55][55];
    memset(vis, 0, sizeof(vis));
    vis[x][y] = 1;
    queue<pair<int,int> >Q;
    Q.push({x,y});
    while(!Q.empty())
    {
        pair<int,int> a = Q.front();
        Q.pop();
        if(a.first == 0 || a.first == R+1 ||
           a.second == 0 || a.second == C+1)
           return false;
        for(int i = 0; i< 4; i++)
        {
            pair<int,int> b;
            b.first  = a.first + dirx[i];
            b.second = a.second + diry[i];
            if(!vis[b.first][b.second] && H[b.first][b.second] < h)
            {
                vis[b.first][b.second] = 1;
                Q.push(b);
            }
        }
    }
    return true;
}

int determine(int x,int y)
{
    int low = H[x][y];
    int high = 1000;

    while( low < high)
    {
        int mid = low + (high - low)/2;
//        cout<<low<<" "<<mid<<" "<<high<<endl;
        if(possible(x,y,mid))
        {
            low = mid;
        }else
            high = mid-1;
        if(high - low == 1)
        {
            if(possible(x,y,high))
                return high;
            return low;
        }
    }
    return low;
}

int main()
{
    ios_base::sync_with_stdio(0);
//    freopen("2.txt","r",stdin);
//    freopen("B-small-attempt0.in","r",stdin);
//    freopen("B-small-attempt0.out","w",stdout);
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int T;
    cin>>T;
    for(int cas = 1; cas<= T; cas++)
    {

        cin>>R>>C;
        memset(H,0,sizeof(H));
        for(int i = 1; i<=R; i++)
        {
            for(int j = 1; j<=C; j++)
            {
                cin>>H[i][j];
            }
        }
//        for(int i= 1;i<= R; i++)
//        {
//            for(int j = 1; j<=C; j++)
//                cout<<H[i][j]<<" ";
//            cout<<endl;
//        }
//        cout<<"poss "<<possible(2,2,2)<<endl;
        int ret = 0;
        for(int i = 1; i<=R; i++)
        {
            for(int j = 1; j<=C; j++)
            {
//                cout<<" pos "<<i<<" "<<j<<endl;
                ret += determine(i,j) - H[i][j];
            }
        }
        cout<<"Case #"<<cas<<": "<<ret<<endl;
    }
    return 0;
}
