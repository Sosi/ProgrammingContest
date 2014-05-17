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
class PenguinPals
{
public:
    int findMaximumMatching(string colors)
    {
        int ret = 0;
        while(1)
        {
            string c;
            bool update = 0;
            for(int i=0; i<colors.size();)
            {
                if(i+1 < colors.size() &&  colors[i]== colors[i+1])
                {
                    ret++;
                    i+=2;
                    continue;
                }
                else
                {
                    c+= colors[i];
                    i++;
                }
            }
            cout<<ret<<endl;
            cout<< c<<endl;
            if(c.size() >=2 && c[0] == c[c.size()-1])
            {
                ret++;
                c= c.substr(1, c.size()-2);
            }
            if(c != colors ) update = true;
            colors = c;
            if(colors.size() ==0 || update == 0) break;
        }
        if(colors.size() >= 2) return ret + (colors.size()-2)/2;
        return ret;
    }


// BEGIN CUT HERE
public:
    void run_test(int Case)
    {
        if ((Case == -1) || (Case == 0)) test_case_0();
        if ((Case == -1) || (Case == 1)) test_case_1();
        if ((Case == -1) || (Case == 2)) test_case_2();
        if ((Case == -1) || (Case == 3)) test_case_3();
        if ((Case == -1) || (Case == 4)) test_case_4();
        if ((Case == -1) || (Case == 5)) test_case_5();
        if ((Case == -1) || (Case == 6)) test_case_6();
        if ((Case == -1) || (Case == 7)) test_case_7();
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
    void verify_case(int Case, const int &Expected, const int &Received)
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
        string Arg0 = "RRBRBRBB";
        int Arg1 = 3;
        verify_case(0, Arg1, findMaximumMatching(Arg0));
    }
    void test_case_1()
    {
        string Arg0 = "RRRR";
        int Arg1 = 2;
        verify_case(1, Arg1, findMaximumMatching(Arg0));
    }
    void test_case_2()
    {
        string Arg0 = "BBBBB";
        int Arg1 = 2;
        verify_case(2, Arg1, findMaximumMatching(Arg0));
    }
    void test_case_3()
    {
        string Arg0 = "RBRBRBRBR";
        int Arg1 = 4;
        verify_case(3, Arg1, findMaximumMatching(Arg0));
    }
    void test_case_4()
    {
        string Arg0 = "RRRBRBRBRBRB";
        int Arg1 = 5;
        verify_case(4, Arg1, findMaximumMatching(Arg0));
    }
    void test_case_5()
    {
        string Arg0 = "R";
        int Arg1 = 0;
        verify_case(5, Arg1, findMaximumMatching(Arg0));
    }
    void test_case_6()
    {
        string Arg0 = "RBRRBBRB";
        int Arg1 = 3;
        verify_case(6, Arg1, findMaximumMatching(Arg0));
    }
    void test_case_7()
    {
        string Arg0 = "RBRBRBRBRBRBRBRBRBRBRBRRBRBRBRBRBRBRBRB";
        int Arg1 = 19;
        verify_case(7, Arg1, findMaximumMatching(Arg0));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    PenguinPals ___test;
    ___test.run_test(-1);
}
// END CUT HERE
