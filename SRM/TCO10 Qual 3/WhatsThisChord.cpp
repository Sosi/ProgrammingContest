// BEGIN CUT HERE

// END CUT HERE
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
// END CUT HERE
class WhatsThisChord
{
public:
	string classify(vector <int> chord)
	{
		string Ans;
		Ans.clear();
		string Tune[12]={"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
		string GS[]={"E", "A", "D", "G", "B", "E"};
		int G[6]={4,9,2,7,11,4};
		int Minor[3]={0,3,7};//C, D#, and G
		int Major[3]={0,4,7};    //C E G
		vector<int> MMinor(Minor,Minor+3);
		vector<int> MMajor(Major,Major+3);
		//set<int> S;
		vector<int> P;
		for(int i=0;i<chord.size();i++)
		{
			if(chord[i]!=-1)
			{
				bool flag=true;
				for(int j=0;j<P.size();j++)
				{
					if(P[j]==(G[i]+chord[i])%12)
					flag=false;
				}
				if(flag)
					P.push_back((G[i]+chord[i])%12);
				//S.insert((G[i]+chord[i])%12);
			}
		}
		sort(P.begin(),P.end());
		cout<<P.size()<<endl;
		if(P.size()!=3)
			return Ans;
		/*	set<int>::iterator it=S.begin();

		while(it!=S.end())
		{
		P.push_back(*it);
		it++;
		}*/
		for(int i=0;i<12;i++)
		{
			vector<int> temp=P;
			for(int j=0;j<3;j++)
				temp[j]=(temp[j]+i)%12;
				sort(temp.begin(),temp.end());
			if(temp==MMajor)
			{
				string s;
				s+=Tune[i]+" Major";
				return s;
			}
			if(temp==MMinor)
			{
				string s;
				s+=Tune[i]+" Minor";
				return s;
			}
		}
		return Ans;

		/*	set<int> SMinor;
		set<int> SMajor;
		for(int i=0;i<3;i++)
		{
		SMinor.insert(Minor[i]);
		SMajor.insert(Major[i]);
		}*/





	}

	// BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {-1, 3, 2, 0, 1, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "C Major"; verify_case(0, Arg1, classify(Arg0)); }
	void test_case_1() { int Arr0[] = {3,2,0,0,0,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "G Major"; verify_case(1, Arg1, classify(Arg0)); }
	void test_case_2() { int Arr0[] = {-1,0,2,2,1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "A Minor"; verify_case(2, Arg1, classify(Arg0)); }
	void test_case_3() { int Arr0[] = {-1,4,3,1,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "C# Major"; verify_case(3, Arg1, classify(Arg0)); }
	void test_case_4() { int Arr0[] = {8,10,10,9,8,8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "C Major"; verify_case(4, Arg1, classify(Arg0)); }
	void test_case_5() { int Arr0[] = {0,0,0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = ""; verify_case(5, Arg1, classify(Arg0)); }
	void test_case_6() { int Arr0[] = {-1,-1,4,-1,-1,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = ""; verify_case(6, Arg1, classify(Arg0)); }
	void test_case_7() { int Arr0[] = {-1, -1, 2, 0, 1, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "C Major"; verify_case(7, Arg1, classify(Arg0)); }

	// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	WhatsThisChord ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
