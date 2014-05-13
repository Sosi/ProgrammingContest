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
//const double EPS=1e-11;
//const double PI=acos(-1.0);
//const short INF=32767,NF= -32768;
//const int INF=2147483647,NF= -2147483648;
//const long long INF=9223372036854775807,NF=-9223372036854775808;
//const long double INF=99999999.99999999;

template<class T> string toString(T n){ostringstream ost;ost<<n;ost.flush();return ost.str();}
int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}//NOTES:toInt(
long long toInt64(string s){long long r=0;istringstream sin(s);sin>>r;return r;}
double toDouble(string s){double r=0;istringstream sin(s);sin>>r;return r;}//NOTES:toDouble(
template<class T> void stoa(string s,int &n,T A[]){n=0;istringstream sin(s);for(T v;sin>>v;A[n++]=v);}
template<class T> void atos(int n,T A[],string &s){ostringstream sout;for(int i=0;i<n;i++){if(i>0)sout<<' ';sout<<A[i];}s=sout.str();}
template<class T> void atov(int n,T A[],vector<T> &vi){vi.clear();for (int i=0;i<n;i++) vi.push_back(A[i]);}
template<class T> void vtoa(vector<T> vi,int &n,T A[]){n=vi.size();for (int i=0;i<n;i++)A[i]=vi[i];}
template<class T> void stov(string s,vector<T> &vi){vi.clear();istringstream sin(s);for(T v;sin>>v;vi.push_bakc(v));}
template<class T> void vtos(vector<T> vi,string &s){ostringstream sout;for (int i=0;i<vi.size();i++){if(i>0)sout<<' ';sout<<vi[i];}s=sout.str();}

struct Lpoint {double x,y;};
struct Ldir{double dx,dy;};
struct Lline{Lpoint p; Ldir dir;};

void format(Lline ln, double & A, double & B, double & C)
{

    A=ln.dir.dy;
    B=-ln.dir.dx;
    C=ln.p.y*ln.dir.dx-ln.p.x*ln.dir.dy;
}
double p2ldis(Lpoint a, Lline ln)
{
    double A,B,C;
    format(ln, A, B, C);
    return (fabs(A*a.x+ B*a.y + C)/ sqrt(A*A+B*B));
}


double p2pdis(Lpoint p1,Lpoint p2)
{
return(sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)));
}
/*
int main()
{
    //freopen("3.txt","r",stdin);
    double y1,y2,yw,xb,yb,r;
    cin>>y1>>y2>>yw>>xb>>yb>>r;
    double mid = (y1+y2)/2.0;
    Lpoint s; s.x = xb; s.y = yb;
    Lpoint t; t.x = 0; t.y = yw - r - mid + yw - r;
    Ldir d; d.dx = (t.x - s.x)/p2pdis(s,t);
    d.dy = (t.y - s.y)/p2pdis(s,t);
    Lline L; L.p = s; L.dir = d;
    double ret = (yw - r - s.y)*d.dy*d.dx + s.x;
    Lpoint temp; temp.x = 0; temp.y = yw-r -y1 + yw-r;
    if(p2ldis(temp,L ) <= r) cout<<-1.0<<endl;
    else printf("%.10f\n", ret);
    return 0;
}
*/
int main()
{
    double y1,y2,yw,xb,yb,r;
    scanf("%lf%lf%lf%lf%lf%lf",&y1,&y2,&yw,&xb,&yb,&r);
    yw-=r; y1+=r;
    double x=(yw-y1)*xb/(2*yw-yb-y1);
    if((y2-y1)*x/sqrt(x*x+(yw-y1)*(yw-y1))<=r) printf("-1\n");
    else printf("%.10lf\n",x);
    return 0;
}
