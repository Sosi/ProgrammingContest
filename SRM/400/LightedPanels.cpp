// BEGIN CUT HERE

// END CUT HERE
#line 5 "LightedPanels.cpp"
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
int i,j,k;
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

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
int row, col;
int pi, pj;
char reverse(char x)
{
    if(x == '*') return '.';
    return '*';
}

void output(vector<string> b)
{
    for(int i=0; i<row; i++)
    {
        cout<<b[i]<<endl;
    }
    cout<<endl;
}
vector<string > change(int a, int b, vector<string> board)
{
    for(int x = 0; x< row; x++)
    {
        int y = 0;
        if( b & (1<<(row - x - 1)))
        {
            for(int i=-1; i<=1; i++)
            {
                for(int j=-1; j<=1; j++)
                {
                    if(x+i>= 0 && x+i < row && y+j >= 0 && y+j <col)
                        board[x+i][y+j] = reverse(board[x+i][y+j]);
                }
            }
        }
    }
    for(int y = 1; y< col; y++)
    {
        int x = 0;
        if( a & (1<<(col - y - 1)))
        {
            for(int i=-1; i<=1; i++)
            {
                for(int j=-1; j<=1; j++)
                {
                    if(x+i>= 0 && x+i < row && y+j >= 0 && y+j <col)
                        board[x+i][y+j] = reverse(board[x+i][y+j]);
                }
            }
        }
    }
    return board;
}
bool process(vector<string> board, int & step)
{
//    cout<<pi<<" "<<pj<<endl;
    // x = 1, y = 1;
    for(int x = 1; x< row; x++)
    {
        for(int y = 1; y< col; y++)
        {
            if(y == col-1 && board[x-1][y-1] != board[x-1][y]) return false;
            if(board[x-1][y-1] == '*') continue;
            step ++;
            if(pi ==4 && pj == 4)
            {
                cout<<"!"<<endl;
                output(board);
            }
            // change!
            for(int i=-1; i<=1; i++)
            {
                for(int j=-1; j<=1; j++)
                {
                    if(x+i>= 0 && x+i < row && y+j >= 0 && y+j <col)
                        board[x+i][y+j] = reverse(board[x+i][y+j]);
                }
            }
            if(pi ==4 && pj == 4)
            {
                cout<<"?"<<endl;
                output(board);
            }
        }
    }
    bool flag = 1;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            if(board[i][j] != '*') flag = 0;
        }
    }
    if(flag) return true;
    return false;
}

class LightedPanels
{
public:

    int minTouch(vector <string> board)
    {
        row = board.size();
        col = board[0].size();
        int ret = 100;
        for(int i=0; i< (1<<col); i++)
        {
            for(int j=0; j< (1<<(row)); j++)
            {
                pi = i; pj = j;
                if((i>>(col-1)) != (j>>(row-1)) ) continue;
                vector<string> b = change(i,j, board);
                int step = 0;
                // process init i and j
                for(int x = 0; x< col; x++) if( i&(1<<x)) step++;
                for(int y = 0; y< row-1; y++) if(j&(1<<y)) step++;
                if(process(b, step))
                {
                    if(i==4 && j== 4)
                    {
                        cout<<"step "<<step<<endl;
                        output(b);
                    }
                    ret = min(step, ret);
                }
            }
        }
        if(ret == 100) return -1;
        return ret;
    }

// BEGIN CUT HERE
public:
    void run_test(int Case)
    {
        if ((Case == -1) || (Case == 0)) test_case_0();
        if ((Case == -1) || (Case == 1)) test_case_1();
        if ((Case == -1) || (Case == 2)) test_case_2();
        if ((Case == -1) || (Case == 3)) test_case_3();
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
    void verify_case(int Case, const int &Expected, const int &Received)
    {
        cerr << "Test Case #" << Case << "...";
        if (Expected == Received) cerr << "PASSED" << endl;
        else
        {
            cerr << "FAILED" << endl;
            cerr << "\tExpected: \"" << Expected << '\"' << endl;
            cerr << "\tReceived: \"" << Received << '\"' << endl;
        }
    }
    void test_case_0()
    {
        string Arr0[] = {"*****",
                         "*...*",
                         "*...*",
                         "*...*",
                         "*****"
                        };
        vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = 1;
        verify_case(0, Arg1, minTouch(Arg0));
    }
    void test_case_1()
    {
        string Arr0[] = {".*"};
        vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = -1;
        verify_case(1, Arg1, minTouch(Arg0));
    }
    void test_case_2()
    {
        string Arr0[] = {"**.",
                         "**.",
                         "..."
                        };
        vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = 2;
        verify_case(2, Arg1, minTouch(Arg0));
    }
    void test_case_3()
    {
        string Arr0[] = {"*...",
                         "**..",
                         "..**",
                         "...*"
                        };
        vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = 10;
        verify_case(3, Arg1, minTouch(Arg0));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    LightedPanels ___test;
    ___test.run_test(-1);
}
// END CUT HERE
