#include <algorithm>
#include <complex>
#include <exception>
#include <list>
#include <stack>
#include <bitset>
#include <csetjmp>
#include <fstream>
#include <locale>
#include <stdexcept>
#include <cassert>
#include <csignal>
#include <functional>
#include <map>
#include <cctype>
#include <cstdarg>
#include <iomanip>
#include <memory>
#include <streambuf>
#include <cerrno>
#include <cstddef>
#include <ios>
#include <new>
#include <string>
#include <cfloat>
#include <cstdio>
#include <iosfwd>
#include <numeric>
#include <typeinfo>
#include <ciso646>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <utility>
#include <climits>
#include <cstring>
#include <istream>
#include <queue>
#include <valarray>
#include <clocale>
#include <ctime>
#include <iterator>
#include <set>
#include <vector>
#include <cmath>
#include <deque>
#include <limits>
#include <sstream>

using namespace std;
vector<string > r;

bool judge(int prex, int prey, int curx, int cury)
{
	//cout<<prex<<" "<<prey<<" "<<curx<<" "<<cury<<endl;
	int a =0; int b = 0;
	for(int i= prex; i< curx; i++)
	{
		for(int j= prey; j < cury; j++)
		{
			if(r[i][j] == 'W') a++;
			else if(r[i][j] == 'S') b++;
		}
	}
	if(a == 0 || b ==0)
		return false;
	return true;
}
class WolvesAndSheep {
public:
	int getmin(vector <string> field) {
		r = field;
		int n = field.size();
		int m = field[0].size();
		int ret = (n-1)*(m-1);
		n--; m--;
		for(int i=0; i< (1<<n); i++)
		{
			for(int j=0; j<(1<<m); j++)
			{
				if(i == 0x3)
					if(j == 0x3f6)
						cout<<"??"<<endl;
				int prex = 0; int prey = 0; //[)
				int curx = n; int cury = m;
				int num = 0; bool flag = 1;
				for(int x =n-1; x>=0; x--)
				{
					if( i& (1<<x))
					{
						//num++;
						curx = n-x;
						for(int y =m-1; y>=0; y--)
						{
							if(j & (1<<y))
							{
								//num++;
								cury = m-y;
								if(judge(prex, prey, curx, cury)) flag =0; 
								prey = cury;
							}

						}
						if(judge(prex, prey, curx, m+1)) flag =0; 
						prex = curx;
					}
				}
				for(int y =m-1; y>=0; y--)
				{
					if(j & (1<<y))
					{
						cury = m -y;
						if(judge(prex, prey, n+1, cury)) flag =0; 
						prey = cury;
					}

				}
				if(judge(prex, prey, n+1, m+1)) flag =0;
				for(int x =n-1; x>=0; x--)
					if( i& (1<<x)) num++;
				for(int y =m-1; y>=0; y--)
					if(j & (1<<y) ) num++;
				if(flag) 
					ret = min(ret, num);
				//cout<<ret<<endl;
			}
		}
		return ret;

	}


	// BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"W.WSS",
		"WW.S.",
		".SSS.",
		"SSS.S",
		".SS.S"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, getmin(Arg0)); }
	void test_case_1() { string Arr0[] = {".....",
		".....",
		"....."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, getmin(Arg0)); }
	void test_case_2() { string Arr0[] = {".SS",
		"...",
		"S..",
		"W.W"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, getmin(Arg0)); }
	void test_case_3() { string Arr0[] = {"WWWSWWSSWWW",
		"WWSWW.SSWWW",
		"WS.WSWWWWS."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(3, Arg1, getmin(Arg0)); }
	void test_case_4() { string Arr0[] = {".W.S.W.W",
		"W.W.S.W.",
		".S.S.W.W",
		"S.S.S.W.",
		".S.W.W.S",
		"S.S.W.W.",
		".W.W.W.S",
		"W.W.S.S."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(4, Arg1, getmin(Arg0)); }
	void test_case_5() { string Arr0[] = {"W.SSWWSSSW.SS",
		".SSSSW.SSWWWW",
		".WWWWS.WSSWWS",
		"SS.WSS..W.WWS",
		"WSSS.SSWS.W.S",
		"WSS.WS...WWWS",
		"S.WW.S.SWWWSW",
		"WSSSS.SSW...S",
		"S.WWSW.WWSWSW",
		".WSSS.WWSWWWS",
		"..SSSS.WWWSSS",
		"SSWSWWS.W.SSW",
		"S.WSWS..WSSS.",
		"WS....W..WSS."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 24; verify_case(5, Arg1, getmin(Arg0)); }
	void test_case_6() { string Arr0[] = {"WW..SS",
		"WW..SS",
		"......",
		"......",
		"SS..WW",
		"SS..WW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(6, Arg1, getmin(Arg0)); }

	// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	WolvesAndSheep ___test;
	___test.run_test(-1);
}
// END CUT HERE
