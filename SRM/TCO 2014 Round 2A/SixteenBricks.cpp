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
class SixteenBricks {
    public:
    int maximumSurface(vector <int> height) {
        int ret = 16;
        int n = height.size();
        sort(height.begin(), height.end());
        int h[6][6];
        memset(h, 0, sizeof(h));
        int a = 8; int b = 0;
        for(int i=1; i<=4; i++)
        {
            for(int j=1; j<=4; j++)
            {
                int k = -1;
                if(i%2 == 1 && j%2  == 1) k = a++;
                else if(i%2 ==1 && j%2 == 0) k= b++;
                else if(i%2 == 0 && j%2 ==1) k = b++;
                else k = a++;
                h[i][j] = height[k];
                cout<<h[i][j]<<" ";
            }
            cout<<endl;
        }
        for(int i=1; i<= 5; i++)
        {
            for(int j =1; j<=5; j++)
            {
                ret += abs(h[i][j] - h[i-1][j]) + abs(h[i][j] - h[i][j-1]);
            }
        }

        vector<int> s,bestv;
        int best = 0;
        for(int i=1; i<=9; i++) s.push_back(i);
        sort(s.begin(), s.end());
        memset(h,0,sizeof(h));
        do{
                int sum = 0;
                for(int i=1; i<=3; i++)
                {
                    for(int j=1; j<=3; j++)
                    {
                        h[i][j]  = s[(i-1)*3+j-1];
                    }
                }
                for(int i=1; i<=4; i++)
                {
                    for(int j=1; j<=4; j++)
                    {
                        sum += abs(h[i][j] - h[i-1][j]) + abs(h[i][j] - h[i][j-1]);
                    }
                }
                if(sum > best)
                {
                    bestv = s;
                    best = sum;
                }

        }while(next_permutation(s.begin(), s.end()));
        cout<<"Best ";
        for(int i=0; i<9; i++) cout<<bestv[i]<<" "; cout<<endl;
//        int x = height[n-1] + height[n-2]+ height[n-3] + height[n-4];
//        x *=2;
//        ret += x;
//        for(int i=12; i<16; i++)
//            ret += height[i]*4;
//        for(int i=4; i< 12; i++)
//            ret += height[i];
//        for(int i=4; i<8; i++)
//            ret += abs(height[i] - height[i+4]);
//        for(int i=0; i<4; i++)
//            ret -= height[i]*2;
//        for(int i=0; i<2; i++)
//            ret += abs(height[i] - height[i+2]);

        return ret;

    }


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 32; verify_case(0, Arg1, maximumSurface(Arg0)); }
	void test_case_1() { int Arr0[] = {1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 64; verify_case(1, Arg1, maximumSurface(Arg0)); }
	void test_case_2() { int Arr0[] = {77, 78, 58, 34, 30, 20, 8, 71, 37, 74, 21, 45, 39, 16, 4, 59}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1798; verify_case(2, Arg1, maximumSurface(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
SixteenBricks ___test;
___test.run_test(-1);
}
// END CUT HERE
