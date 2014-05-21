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

int del[55];
int n;
using namespace std;
class TheLargestString
{
public:
    string find(string s, string t)
    {
        vector< pair<string, string> > Best(s.length() + 1, make_pair("", ""));

        for(int i = 0; i < s.length(); i++)
        {
            for(int j = i; j >= 0; j--)
            {
                string x = Best[j].first + s[i], y = Best[j].second + t[i];
                Best[j + 1] = max(Best[j + 1], make_pair(x, y));
            }
        }

        string best = "";

        for(int i = 0; i <= s.length(); i++)
        {
            best = max(best, Best[i].first + Best[i].second);
        }

        return best;
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
    void verify_case(int Case, const string &Expected, const string &Received)
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
        string Arg0 = "ab";
        string Arg1 = "zy";
        string Arg2 = "by";
        verify_case(0, Arg2, find(Arg0, Arg1));
    }
    void test_case_1()
    {
        string Arg0 = "abacaba";
        string Arg1 = "zzzaaaa";
        string Arg2 = "cbaaaa";
        verify_case(1, Arg2, find(Arg0, Arg1));
    }
    void test_case_2()
    {
        string Arg0 = "x";
        string Arg1 = "x";
        string Arg2 = "xx";
        verify_case(2, Arg2, find(Arg0, Arg1));
    }
    void test_case_3()
    {
        string Arg0 = "abbabbabbababaaaabbababab";
        string Arg1 = "bababbaabbbababbbbababaab";
        string Arg2 = "bbbbbbbbbbbbbbbbbbaaab";
        verify_case(3, Arg2, find(Arg0, Arg1));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    TheLargestString ___test;
    ___test.run_test(-1);
}
// END CUT HERE
