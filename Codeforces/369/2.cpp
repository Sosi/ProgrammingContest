#include <bits/stdc++.h>
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

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("1.txt","r",stdin);

    int n; cin>>n;
    int A[505][505];
    int row = -1, col = -1;
    for(int i = 1; i<= n; i++)
    {
        for(int j = 1; j<=n; j++)
        {
            cin>>A[i][j];
            if(A[i][j] == 0)
                row = i, col = j;
        }
    }

//    cout<<"T "<<row<<" "<<col<<endl;
    vector<int> sumrow;
    vector<int> sumcol;
    for(int i = 1; i<=n; i++)
    {
        int sum = 0;
        if(i == row ) continue;
        for(int j = 0; j<= n; j++)
        {
            sum += A[i][j];
        }
        sumrow.push_back(sum);
    }

    for(int j = 1; j<=n; j++)
    {
        int sum = 0;
        if(j == col) continue;
        for(int i = 0; i<=n; i++)
        {
            sum += A[i][j];
        }
        sumcol.push_back(sum);
    }

    if(row != col)
    {
        int sum = 0;
        for(int i= 1; i<= n; i++)
            sum+= A[i][i];
        sumrow.push_back(sum);
    }

    if(row + col != n+1)
    {
        int sum = 0;
        for(int i = 1; i<=n; i++)
            sum += A[i][n+1 -i];
        sumcol.push_back(sum);
    }

    sort(sumrow.begin(), sumrow.end());
    sort(sumcol.begin(), sumcol.end());

//    for(int i = 0; i< sumrow.size(); i++) cout<<sumrow[i]<<" ";
//    cout<<endl;
//    cout<<"T"<<endl;
    int flag = -1;
    if(sumrow.size() > 0 &&sumcol.size() > 0 &&  sumrow[0] == sumrow[sumrow.size() -1] && sumcol[0] == sumcol[sumcol.size() - 1]  &&
       sumrow[0] == sumcol[0])
    {
        vector<int> p;
        {
            int p1 = 0, p2 = 0;
            for(int i= 1; i<=n; i++)
                p1 += A[row][i],
                p2 += A[i][col];
            p.push_back(p1);
            p.push_back(p2);
            if(row == col)
            {
                int sum = 0;
                for(int i= 1; i<= n; i++)
                    sum+= A[i][i];
                p.push_back(sum);
            }
            if(row + col == n+1)
            {
                int sum = 0;
                for(int i = 1; i<=n; i++)
                sum += A[i][n+1 -i];
                p.push_back(sum);
            }
        }
        sort(p.begin(), p.end());
        if(p[0] == p[p.size() - 1])
        {
            if(sumrow[0] - p[0] > 0)
                flag = sumrow[0] - p[0];
        }
    }
    if(n == 1) cout<<1<<endl;
    else cout<<flag<<endl;
    return 0;
}
