// BEGIN CUT HERE

// END CUT HERE
#line 5 "WallGameDiv2.cpp"
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

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define MIN -25000
int dp[55][55];
class WallGameDiv2
{
    public:
        int play(vector <string> costs)
        {
            int i, j,k;
            int m = costs.size(); int n = costs[0].size(); 
            REP(i,m) REP(j,n) dp[i][j] = MIN;
            dp[0][0]=0;
            REP(i,n-1) 
            {
                if(costs[0][i+1] == 'x') dp[0][i+1] = MIN;
                else  if(dp[0][i] >= 0) dp[0][i+1] = max(dp[0][i]+costs[0][i+1]-'0', MIN);
                cout<<dp[0][i+1]<<" ";
            }
            cout<<"@@@@"<<endl;
            REP(i,m-1)
            {
                REP(j, n)
                {
                    int MAX = MIN;
                    REP(k,n)
                    {
                        int tmp = dp[i][k];
                        for(int p = min(k,j); p<= max(k,j); p++) if(costs[i+1][p] == 'x') tmp += MIN; else tmp += costs[i+1][p] - '0';
                        MAX = max(MAX, tmp);
                    }
                    if(MAX >=0) dp[i+1][j] = MAX; else dp[i+1][j]= MIN;
                    cout<<dp[i+1][j]<<" ";
                }
                cout<<endl;
            }
            int ret = MIN;
            REP(i,n) if(costs[m-1][i] != 'x')  ret = max(ret, dp[m-2][i] + costs[m-1][i] - '0' );
            return ret;
        }

        // BEGIN CUT HERE
    public:
        void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
    private:
        template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
        void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
        void test_case_0() { string Arr0[] = {"042"
            ,"391"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; verify_case(0, Arg1, play(Arg0)); }
        void test_case_1() { string Arr0[] = {"0xxxx"
            ,"1x111"
                ,"1x1x1"
                ,"11191"
                ,"xxxx1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; verify_case(1, Arg1, play(Arg0)); }
        void test_case_2() { string Arr0[] = {"0"
            ,"5"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(2, Arg1, play(Arg0)); }
        void test_case_3() { string Arr0[] = {"0698023477896606x2235481563x59345762591987823x663"
            ,"1x88x8338355814562x2096x7x68546x18x54xx1077xx5131"
                ,"64343565721335639575x18059738478x156x781476124780"
                ,"2139850139989209547489708x3466104x5x3979260330074"
                ,"15316x57171x182167994729710304x24339370252x2x8846"
                ,"459x479948xx26916349194540891252317x99x4329x34x91"
                ,"96x3631804253899x69460666282614302698504342364742"
                ,"4x41693527443x7987953128673046855x793298x8747219x"
                ,"7735427289436x56129435153x83x37703808694432026643"
                ,"340x973216747311x970578x9324423865921864682853036"
                ,"x1442314831447x860181542569525471281x762734425650"
                ,"x756258910x0529918564126476x481206117984425792x97"
                ,"467692076x43x91258xx3xx079x34x29xx916574022682343"
                ,"9307x08x451x2882604411x67995x333x045x0x5xx4644590"
                ,"4x9x088309856x342242x12x79x2935566358156323631235"
                ,"04596921625156134477422x2691011895x8564609x837773"
                ,"223x353086929x27222x48467846970564701987061975216"
                ,"x4x5887805x89746997xx1419x758406034689902x6152567"
                ,"20573059x699979871151x444449x5170122650576586x898"
                ,"683344308229681464514453186x51040742xx138x5170x93"
                ,"1219892x9407xx63107x24x4914598xx4x478x31485x69139"
                ,"856756530006196x8722179365838x9037411399x41126560"
                ,"73012x9290145x1764125785844477355xx827269976x4x56"
                ,"37x95684445661771730x80xx2x459547x780556228951360"
                ,"54532923632041379753304212490929413x377x204659874"
                ,"30801x8716360708478705081091961915925276739027360"
                ,"5x74x4x39091353819x10x433010250089676063173896656"
                ,"03x07174x648272618831383631629x020633861270224x38"
                ,"855475149124358107x635160129488205151x45274x18854"
                ,"091902044504xx868401923845074542x50x143161647934x"
                ,"71215871802698346x390x2570413992678429588x5866973"
                ,"87x4538137828472265480468315701832x24590429832627"
                ,"9479550007750x658x618193862x80317248236583631x846"
                ,"49802902x511965239855908151316389x972x253946284x6"
                ,"053078091010241324x8166428x1x93x83809001454563464"
                ,"2176345x693826342x093950x12x7290x1186505760xx978x"
                ,"x9244898104910492948x2500050208763770568x92514431"
                ,"6855xx7x145213846746325656963x0419064369747824511"
                ,"88x15690xxx31x20312255171137133511507008114887695"
                ,"x391503034x01776xx30264908792724712819642x291x750"
                ,"17x1921464904885298x58x58xx174x7x673958x9615x9230"
                ,"x9217049564455797269x484428813681307xx85205112873"
                ,"19360179004x70496337008802296x7758386170452xx359x"
                ,"5057547822326798x0x0569420173277288269x486x582463"
                ,"2287970x0x474635353111x85933x33443884726179587xx9"
                ,"0x697597684843071327073893661811597376x4767247755"
                ,"668920978869307x17435748153x4233659379063530x646x"
                ,"0019868300350499779516950730410231x9x18749463x537"
                ,"00508xx083203827x42144x147181308668x3192478607467"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3512; verify_case(3, Arg1, play(Arg0)); }

        // END CUT HERE

};
// BEGIN CUT HERE
int main()
{
    WallGameDiv2 ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
