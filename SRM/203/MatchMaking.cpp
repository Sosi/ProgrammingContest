// BEGIN CUT HERE

// END CUT HERE
#line 5 "MatchMaking.cpp"

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
int count(string A, string B)
{
    int ret=0;
    for(int i=0; i<A.size(); i++) 
    {
        if(A[i]==B[i]) ret++;
    }
    return ret;
}
class MatchMaking
{
        public:
        string makeMatch(vector <string> namesWomen, vector <string> answersWomen, vector <string> namesMen, vector <string> answersMen, string queryWoman)
        {
            cout<<"2~~"<<endl;
            vector< pair<string, string> > W;
            vector< pair<string, string> > M;
            for(int i=0; i<namesWomen.size(); i++)
            {
                W.push_back(make_pair(namesWomen[i],answersWomen[i]));
                M.push_back(make_pair(namesMen[i],  answersMen[i]));
            }
            sort(W.begin(),W.end());
            sort(M.begin(),M.end());
            vector<bool> vis(W.size(),0);
            cout<<"1~~~  "<<endl;
            for(int i=0; i<W.size(); i++)
            {
                if(W[i].first == queryWoman)
                {
                    string name;
                    int common=-1;
                    for(int j=0; j<M.size(); j++)
                    {
                        if(!vis[j] && count(W[i].second, M[j].second)>common)
                        {
                            common= count(W[i].second, M[j].second);
                            name = M[j].first;
                        }
                    }
                    cout<<common<<endl;
                    return name;
                }
                else
                {
                    int name = 0;
                    int common=-1;
                    for(int j=0; j<M.size(); j++)
                    {
                        if(!vis[j] && count(W[i].second, M[j].second)> common)
                        {
                            common= count(W[i].second, M[j].second);
                            name = j;
                        }
                    }
                    cout<<M[name].first<<endl;
                    vis[name] = 1;
                }
            }
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"Constance", "Bertha", "Alice"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"aaba", "baab", "aaaa"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"Chip", "Biff", "Abe"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"bbaa", "baaa", "aaab"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "Bertha"; string Arg5 = "Biff"; verify_case(0, Arg5, makeMatch(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { string Arr0[] = {"Constance", "Bertha", "Alice"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"aaba", "baab", "aaaa"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"Chip", "Biff", "Abe"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"bbaa", "baaa", "aaab"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "Constance"; string Arg5 = "Chip"; verify_case(1, Arg5, makeMatch(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { string Arr0[] = {"Constance", "Alice", "Bertha", "Delilah", "Emily"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"baabaa", "ababab", "aaabbb", "bababa", "baabba"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"Ed", "Duff", "Chip", "Abe", "Biff"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"aabaab", "babbab", "bbbaaa", "abbbba", "abaaba"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "Constance"; string Arg5 = "Duff"; verify_case(2, Arg5, makeMatch(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { string Arr0[] = {"Constance", "Alice", "Bertha", "Delilah", "Emily"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"baabaa", "ababab", "aaabbb", "bababa", "baabba"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"Ed", "Duff", "Chip", "Abe", "Biff"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"aabaab", "babbab", "bbbaaa", "abbbba", "abaaba"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "Delilah"; string Arg5 = "Chip"; verify_case(3, Arg5, makeMatch(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { string Arr0[] = {"Constance", "Alice", "Bertha", "Delilah", "Emily"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"baabaa", "ababab", "aaabbb", "bababa", "baabba"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"Ed", "Duff", "Chip", "Abe", "Biff"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"aabaab", "babbab", "bbbaaa", "abbbba", "abaaba"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "Emily"; string Arg5 = "Ed"; verify_case(4, Arg5, makeMatch(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_5() { string Arr0[] = {"anne", "Zoe"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"a", "a"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"bob", "chuck"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"a", "a"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "Zoe"; string Arg5 = "bob"; verify_case(5, Arg5, makeMatch(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_6() { string Arr0[] = {"F", "M", "S", "h", "q", "g", "r", "N", "U", "x", "H", "P",
 "o", "E", "R", "z", "L", "m", "e", "u", "K", "A", "w", "Q",
 "O", "v", "j", "a", "t", "p", "C", "G", "k", "c", "V", "B",
 "D", "s", "n", "i", "f", "T", "I", "l", "d", "J", "y", "b"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"abaabbbb", "bbaabbbb", "aaabaaab", "aabbaaaa", "baabbaab",
 "aaababba", "bbabbbbb", "bbbabbba", "aaabbbba", "aabbbaaa",
 "abbabaaa", "babbabbb", "aaaaabba", "aaaabbaa", "abbbabaa",
 "babababa", "abbaaaaa", "bbababba", "baaaaaba", "baaaaabb",
 "bbbbabba", "ababbaaa", "abbbabab", "baabbbaa", "bbbaabbb",
 "aababbab", "ababbabb", "abbaabba", "baabbabb", "aaabaaab",
 "aabbbaba", "aabaaabb", "abababba", "aabbaaaa", "aabbabaa",
 "bababaaa", "aabaaaab", "bbbbaabb", "baaababb", "abaabbab",
 "aabbbaaa", "baabbaba", "bbabbbaa", "aabbbbaa", "abbbaaab",
 "abababbb", "ababaaba", "bababaaa"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"f", "C", "v", "g", "Q", "z", "n", "c", "B", "o", "M", "F",
 "u", "x", "I", "T", "K", "L", "E", "U", "w", "A", "d", "t",
 "e", "R", "D", "s", "p", "q", "m", "r", "H", "j", "J", "V",
 "l", "a", "k", "h", "G", "y", "i", "P", "O", "N", "b", "S"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"bbbaabab", "bbabaabb", "ababbbbb", "bbbababb", "baababaa",
 "bbaaabab", "abbabbaa", "bbbabbbb", "aabbabab", "abbababa",
 "aababbbb", "bababaab", "aaababbb", "baabbaba", "abaaaaab",
 "bbaababa", "babaabab", "abbabbba", "ababbbab", "baabbbab",
 "babbaaab", "abbbbaba", "bbabbbba", "baaabaab", "ababbabb",
 "abbbaabb", "bbbbaabb", "bbbaaabb", "baabbaba", "bbabaaab",
 "aabbbaab", "abbbbabb", "bbaaaaba", "bbbababa", "abbaabba",
 "bababbbb", "aabaaabb", "babbabab", "baaaabaa", "ababbaba",
 "aaabaabb", "bbaaabaa", "baaaaabb", "bbaabaab", "bbababab",
 "aabaaaab", "aaaaabab", "aabbaaba"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "U"; string Arg5 = "x"; verify_case(6, Arg5, makeMatch(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_7() { string Arr0[] = {"q", "M", "w", "y", "p", "N", "s", "r", "a", "H", "o", "n",
 "F", "m", "l", "b", "D", "j", "C", "u", "f", "I", "g", "L",
 "i", "x", "A", "G", "O", "k", "h", "d", "c", "E", "B", "v",
 "J", "z", "K", "e", "t"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"aabbaaabb", "baabababb", "bbaababba", "bbbaaaaaa", "abaaaabaa",
 "bababbbab", "abbaabbaa", "aabababbb", "bababaaaa", "abbababaa",
 "aabbbbbba", "bbabbabab", "babaabbba", "babbabbbb", "baaabbbbb",
 "baaabaaaa", "aaabbaaab", "abbaabbbb", "abbabbbab", "bbaaaabba",
 "babbaaabb", "aabbabbab", "baaababba", "ababaabab", "bbbaabbab",
 "aaaabbabb", "babaaaaaa", "abbbbaaab", "aabaaabba", "bbbaaaaba",
 "bbbbbbaab", "aabbaaabb", "aabaabbab", "aababaaba", "bbabbbbab",
 "abbabaaab", "babaaabbb", "bababbaaa", "aabbaabaa", "baaabbabb",
 "bbbbbbbbb"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"m", "k", "n", "q", "L", "E", "M", "l", "w", "x", "g", "e",
 "i", "z", "F", "r", "a", "h", "f", "D", "J", "K", "j", "v",
 "A", "t", "N", "y", "s", "c", "o", "p", "d", "b", "B", "G",
 "O", "I", "u", "C", "H"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"bbaaabbba", "bbaaaaaab", "abaaababb", "baaaabbbb", "abbbababa",
 "baaaaaaaa", "aabbbbbab", "aaaaabbba", "baabababb", "babaaabab",
 "baaababaa", "bbbbaabba", "bbaabbabb", "bbaaababb", "abbabbaba",
 "aababaaab", "abbbbbbaa", "aabbaabaa", "bbbaabbba", "abbabbaba",
 "aaabbbaaa", "bbaabaaaa", "aabababbb", "abbbbabab", "baaabbbba",
 "bababbbba", "aababbaab", "bbaabbaab", "bbbaaabbb", "babbbbabb",
 "ababababb", "babaaabab", "bbaaaaaba", "aaaaabaaa", "abbaaabbb",
 "bbbbababb", "baabababb", "bbaabaaaa", "aaababbbb", "abbbbbbba",
 "bbaabbaaa"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "o"; string Arg5 = "C"; verify_case(7, Arg5, makeMatch(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        MatchMaking ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
