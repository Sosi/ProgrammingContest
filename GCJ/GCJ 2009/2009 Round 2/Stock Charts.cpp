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

//Begin Sosi TopCoder   
//const double EPS=1e-11;  
//const double PI=acos(-1.0);  
//const short INF=32767,NF= -32768;  
//const int INF=2147483647,NF= -2147483648;  
//const long long INF=9223372036854775807,NF=-9223372036854775808;  
//const long double INF=99999999.99999999;  

//Numberic Functions  

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
//End Sosi TopCoder  

//freopen("","r",stdio);
//freopen("","w",stdout);
bool cmp(vector<int> A,vector<int> B){  
    for(int i=0;i<A.size();i++)if(i==0&&A[i]!=B[i])return A[i]<B[i];else if(i!=0&& A[i]!=B[i]) return A[i]>B[i];
}

bool ccmp(vector<int> A,vector<int> B){
    bool flag=true;
    for(int i=0;i<A.size();i++)if(A[i]>=B[i])flag= false;
    return flag;
}
int main()
{
    freopen("C-small-practice.in","r",stdin);
    freopen("C-small-practice.out","w",stdout); 
    int T;
    cin>>T;
    for(int t=1;t<=T;t++){
        int n ,k;
        cin>>n>>k;
        vector< vector<int> >C;
        vector<int> temp(k);
        for(int i=0;i<n;i++){
            for(int j=0;j<k;j++)
            cin>>temp[j];
            C.push_back(temp);
        }    
        stable_sort(C.begin(),C.end(),cmp);
        vector<int> dp(n,-1);
        for(int i=0;i<n;i++){
            if(dp[i]==-1){
                dp[i]=1;
                int cur=i;
                for(int j=i+1;j<n;j++){
                    if(dp[j]==-1 && ccmp(C[cur],C[j]))
                    {
                        cur=j;
                        dp[cur]=0;
                    }
                }
            }
        }
        int res=0;
        for(int i=0;i<n;i++){if(dp[i]==1)res++;}
    //    cout<<endl;
        cout<<"Case #"<<t<<": "<<res<<endl;
    }
    /*
    定义多维数据的偏序关系，使得能够沿着最大链的方向进行遍历是一个非常艰难的任务
    可以说基本不太可能。二维关系 的话，还是可以的！
    
    二维 严格对角上升序列(严格对角移动) 需要 x轴递增 y轴递减(x轴为主方向)或者y轴递增 x轴递减(y轴为主方向)
    当只允许x轴横向移动和对角移动而不允许y轴竖直移动的时候，我们需要y轴递增 x轴递增 y轴为主方向
    当只允许y轴竖直移动和对角移动而不允许x轴横向移动的时候，我们需要x轴递增 y轴递增 x轴为主方向
    当既允许x轴 横向移动 y轴横向移动和对角移动的时候，我们x轴递增y轴递增 xy轴谁是主方向都可以！
     
    
    3维及3维以上的想不出合适的偏序排列方法，使得其可以用贪心的方法来求解的。这个问题就是这样子， 
    使用的方法就是把这样一个问题，转化为二分图匹配问题 
    
    
     
    */
    return 0;
} 
