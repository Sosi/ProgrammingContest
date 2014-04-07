// BEGIN CUT HERE

// END CUT HERE
#line 5 "PointErasing.cpp"

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

// BEGIN CUT HERE
//Begin Sosi TopCoder
//const double EPS=1e-11;
//const double PI=acos(-1.0);
//const short INF=32767,NF= -32768;
//const int INF=2147483647,NF= -2147483648;
//const long long INF=9223372036854775807,NF=-9223372036854775808;
//const long double INF=99999999.99999999;
//Numberic Functions
//template<class T> T gcd(T a,T b){ if(a<0) return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
//template <class T> T lcm(T a,T b){ return a*(b/gcd(a,b));}
//template<class T> inline vector<pair<T,int> > factorize(T n)
//   {vector<pair<T,int> > R;for (T i=2;n>1;){if (n%i==0){int C=0;for (;n%i==0;C++,n/=i);R.push_back(make_pair(i,C));}
//   i++;if (i>n/i) i=n;}if (n>1) R.push_back(make_pair(n,1));return R;}
//template<class T> inline bool isPrimeNumber(T n)
//   {if(n<=1)return false;for (T i=2;i*i<=n;i++) if (n%i==0) return false;return true;}
//template<class T> inline T eularFunction(T n)
//   {vector<pair<T,int> > R=factorize(n);T r=n;for (int i=0;i<R.size();i++)r=r/R[i].first*(R[i].first-1);return r;}
//Translator
//template<class T> string toString(T n){ostringstream ost;ost<<n;ost.flush();return ost.str();}
//int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}//NOTES:toInt(
//long long toInt64(string s){long long r=0;istringstream sin(s);sin>>r;return r;}
//double toDouble(string s){double r=0;istringstream sin(s);sin>>r;return r;}//NOTES:toDouble(
//template<class T> void stoa(string s,int &n,T A[]){n=0;istringstream sin(s);for(T v;sin>>v;A[n++]=v);}
//template<class T> void atos(int n,T A[],string &s){ostringstream sout;for(int i=0;i<n;i++){if(i>0)sout<<' ';sout<<A[i];}s=sout.str();}
//template<class T> void atov(int n,T A[],vector<T> &vi){vi.clear();for (int i=0;i<n;i++) vi.push_back(A[i]);}
//template<class T> void vtoa(vector<T> vi,int &n,T A[]){n=vi.size();for (int i=0;i<n;i++)A[i]=vi[i];}
//template<class T> void stov(string s,vector<T> &vi){vi.clear();istringstream sin(s);for(T v;sin>>v;vi.push_bakc(v));}
//template<class T> void vtos(vector<T> vi,string &s){ostringstream sout;for (int i=0;i<vi.size();i++){if(i>0)sout<<' ';sout<<vi[i];}s=sout.str();}
//Fraction
//template<class T> struct Fraction{T a,b;Fraction(T a=0,T b=1);string toString();};
//template<class T> Fraction<T>::Fraction(T a,T b){T d=gcd(a,b);a/=d;b/=d;if (b<0) a=-a,b=-b;this->a=a;this->b=b;}
//template<class T> string Fraction<T>::toString(){ostringstream sout;sout<<a<<"/"<<b;return sout.str();}
//template<class T> Fraction<T> operator+(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.b+q.a*p.b,p.b*q.b);}
//template<class T> Fraction<T> operator-(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.b-q.a*p.b,p.b*q.b);}
//template<class T> Fraction<T> operator*(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.a,p.b*q.b);}
//template<class T> Fraction<T> operator/(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.b,p.b*q.a);}
//STL
//bool comp(T A,T B){return A<B?1:0; }
//do{ } while(next_permutation(T.begin(), T.end()));
//int dirx[]={1,0,-1,0};
//int diry[]={0,-1,0,1}; //clockwise
//int dirx[]={1, 1, 0,-1,-1,-1,0,1};
//int diry[]={0,-1,-1,-1, 0, 1,1,1}; //clockwise
//End Sosi TopCoder
// END CUT HERE
class PointErasing
{
public:
    vector <int> getOutcomes(vector <int> y)
    {
        int minY = *min_element(y.begin(),y.end());
        int maxY = *max_element(y.begin(),y.end());
        int constant = 0;
        int n  = y.size();
        for(vector<int>::iterator e=y.begin(); e!=y.end(); e++)
            if(*e == minY || *e== maxY) constant++;
        string s;
        for(int i=0; i<n; i++)
        {
            if(y[i]==minY || y[i]==maxY) break;
            else if(y[i] < y[0]) s+="-";
            else if(y[i] > y[0]) s+="+";
            else s+="0";
        }
        s+="+-";
        vector<int> left = solve(s);
        reverse(y.begin(),y.end());
        s ="";
        for(int i=0; i<n; i++)
        {
            if(y[i]==minY || y[i]==maxY) break;
            else if(y[i] < y[0]) s+="-";
            else if(y[i] > y[0]) s+="+";
            else s+="0";
        }
        s+="+-";
        vector<int> right = solve(s);
        set<int> ans;
        for(vector<int>::iterator e= left.begin(); e!=left.end(); e++)
        {
            for(vector<int>::iterator e2 = right.begin(); e2!=right.end(); e2++)
                ans.insert(constant + *e + *e2);
        }
        return vector<int>(ans.begin(),ans.end());
    }

    vector<int>  solve(string s)
    {
        cout<<s<<endl;
        int n= s.size();
        vector<int> cnt0(n+1, 0);
        cout<<"cnt0 ";
        for( int i=0; i<n; i++)
            cnt0[i+1] = (s[i]=='0')+ cnt0[i];
        // cnt0[] 保存的是从最左边到目前有多少个0点

        vector< vector<bool> > dp(n+1 , vector<bool> (n+1, false));
        dp[0][0] =1;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<=n; j++)
            {
                if(dp[i][j])
                {
                    dp[i+1][j]=true;
                    for(int l=i; l<n; l++)
                    {
                        for(int r=l+1; r<=n; r++)
                        {
                            if(s[l]=='+' && s[r]=='-' || s[r]=='+'&& s[l]=='-')
                                dp[r][j+(cnt0[r]-cnt0[l])]= true;
                        }
                    }
                }
            }
        }

        vector<int> ans;
        for(int i=0; i<=n; i++)
        {
            if(dp[n][i])
                ans.push_back(cnt0.back()-i);
        }
        return ans;
    }

// BEGIN CUT HERE
public:
    void run_test(int Case)
    {
        if ((Case == -1) || (Case == 0)) test_case_0();
        if ((Case == -1) || (Case == 1)) test_case_1();
        if ((Case == -1) || (Case == 2)) test_case_2();
        if ((Case == -1) || (Case == 3)) test_case_3();
        if ((Case == -1) || (Case == 4)) test_case_4();
        if ((Case == -1) || (Case == 5)) test_case_5();
        if ((Case == -1) || (Case == 6)) test_case_6();
        if ((Case == -1) || (Case == 7)) test_case_7();
    }
private:
    template <typename T> string print_array(const vector<T> &V)
    {
        ostringstream os;
        os << "{ ";
        for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\",";
        os << " }";
        return os.str();
    }
    void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received)
    {
        cerr << "Test Case #" << Case << "...";
        if (Expected == Received) cerr << "PASSED" << endl;
        else
        {
            cerr << "FAILED" << endl;
            cerr << "\tExpected: " << print_array(Expected) << endl;
            cerr << "\tReceived: " << print_array(Received) << endl;
        }
    }
    void test_case_0()
    {
        int Arr0[] = { 1, 2, 1, 1, 0, 4, 3 };
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {4, 6 };
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        verify_case(0, Arg1, getOutcomes(Arg0));
    }
    void test_case_1()
    {
        int Arr0[] = { 0, 0, 4, 4, 8, 8, 4, 4 };
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {6 };
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        verify_case(1, Arg1, getOutcomes(Arg0));
    }
    void test_case_2()
    {
        int Arr0[] = { 522 };
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {1 };
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        verify_case(2, Arg1, getOutcomes(Arg0));
    }
    void test_case_3()
    {
        int Arr0[] = { 19, 19, 19, 19, 19, 19 };
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {6 };
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        verify_case(3, Arg1, getOutcomes(Arg0));
    }
    void test_case_4()
    {
        int Arr0[] = { 0, 1, 2, 3, 4 };
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {2 };
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        verify_case(4, Arg1, getOutcomes(Arg0));
    }
    void test_case_5()
    {
        int Arr0[] = { 7, 8, 8, 7, 6, 7, 9, 3, 5, 0 };
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {3, 4, 5 };
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        verify_case(5, Arg1, getOutcomes(Arg0));
    }
    void test_case_6()
    {
        int Arr0[] = { 3, 2, 3, 3, 4, 3, 4, 3, 3, 1, 5, 3 };
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {4, 5, 6, 7, 9 };
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        verify_case(6, Arg1, getOutcomes(Arg0));
    }
    void test_case_7()
    {
        int Arr0[] = { 5, 5, 4, 4, 5, 8, 5, 5, 5, 5, 5, 9, 2, 0, 9, 4, 5, 5, 3, 4, 4, 4, 4, 7, 4 };
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {6, 7, 8, 10, 11, 12, 13, 15, 16, 17 };
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        verify_case(7, Arg1, getOutcomes(Arg0));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    PointErasing ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
