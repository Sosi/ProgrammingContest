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
class TheArray {
    public:
    int find(int n, int d, int first, int last) {
		if(d == 0) return first;
        int used = abs(first - last)/d;
		int gap = abs(first - last)%d;
		int left = n-2 - used;
		cout<<left<<endl;
		int ret = 0;
		while(left > 2 )
		{
			left -= 2;
			ret += d;
		}
		if(left == 1)
			return ret + d - gap+max(first, last);
		else if(left == 2) return ret +d+ max(first, last);
		else return max(first , last);

    }


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 5; int Arg2 = 2; int Arg3 = 4; int Arg4 = 7; verify_case(0, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 100; int Arg2 = 999; int Arg3 = 100; int Arg4 = 999; verify_case(1, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 1000000; int Arg1 = 0; int Arg2 = 474; int Arg3 = 474; int Arg4 = 474; verify_case(2, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 97; int Arg1 = 53; int Arg2 = -92; int Arg3 = 441; int Arg4 = 2717; verify_case(3, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 99; int Arg1 = 3; int Arg2 = -743; int Arg3 = -619; int Arg4 = -535; verify_case(4, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
TheArray ___test;
___test.run_test(-1);
}
// END CUT HERE
