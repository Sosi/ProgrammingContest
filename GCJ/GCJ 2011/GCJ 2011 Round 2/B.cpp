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
vector<vector<int > > M;

vector<vector<long long > > Sum;
vector<vector<long long > > Sump1;
vector<vector<long long > > Sump2;
void init(){
    int m=M.size();int n=M[0].size();
    vector<long long> temp(n,0);
  //  Sum.push_back(temp);
   // Sump1.push_back(temp);
   // Sump2.push_back(temp);
    for(int i=0;i<m;i++){
        vector<long long> s(n+1);
        vector<long long> t1(n+1);
        vector<long long> t2(n+1);
        for(int j=1;j<=n;j++){
            s[j]+=j>0?s[j-1]:0+M[i][j];
            t1[j]+=j>0?t[j-1]:0+M[i][j]*(j);
            t2[j]+=j>0?t[j-1]:0+M[i][j]*(i);
        }
        Sum.push_back(s);
        Sump1.push_back(t1);
        Sump2.push_back(t2);
    }
    for(int j=0;j<n;j++){
        for(int i=1;i<m;i++){
            Sum[i][j]+=Sum[i-1][j];
            Sump1[i][j]+=Sump1[i-1][j];
            Sump2[i][j]+=Sump2[i-1][j];
        }
    }
}
bool Pos(int a,int b,int c,int d,int K){
    //cout<<" "<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<K<<endl;
    double CenterX;double CenterY;
    CenterX=(a+c)*1.0/2;
    CenterY=(b+d)*1.0/2;
    
    for(int i=a;i<=c;i++){
        for(int j=b;j<=d;j++)
        {
            if(i==a&&j==b || i==a&&j==d || i==c&&j==b || i==c&&j==d)continue;
            X+=M[i][j]*1.0*(i-CenterX);
            Y+=M[i][j]*1.0*(j-CenterY);
        }
    }
   // cout<<"X "<<X<<endl;
   // cout<<"Y  "<<Y<<endl;
    if(X==0 && Y==0) return true;else return false;
    
}
int main(){
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int T;
    cin>>T;
    for(int t=1;t<=T;t++){
        M.clear();
        int R,C,D;
        cin>>R>>C>>D;
        //vector< vector<int > > M;
        string s;
        vector<int> Row(C);
        for(int i=0;i<R;i++){
            cin>>s;
            for(int j=0;j<C;j++){
                Row[j]=s[j]-'0';
            }
            M.push_back(Row);
        }
        int ret=0;
        bool flag=true;
        
        for(int K=min(R,C);K>=3;K--){ // cout<<"  K "<<K<<endl; 
        if(flag)
            for(int i=0;i<=R-K;i++){
                for(int j=0;j<=C-K;j++)
                {
                   // cout<<"i  "<<i<<"  j "<<j<<endl;
                   if(flag)
                    if(Pos(i,j,i+K-1,j+K-1,K)){
                        flag=false;
                        ret=K;
                        //goto Lp;
                    }
                }
            }
        }
    if(ret==0)
    cout<<"Case #"<<t<<": IMPOSSIBLE"<<endl;
    else
    cout<<"Case #"<<t<<": "<<ret<<endl;
    }
    return 0;
} 

