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
class FencingPenguinsEasy
{
public:

    // returns 1 if the three points are in counter-clockwise order
//         0 if the points are collinear
//        -1 if the order is clockwise
    int ccw(double x1, double y1, double x2, double y2, double x3, double y3)
    {
        x1 -= x3;
        y1 -= y3;
        x2 -= x3;
        y2 -= y3;
        double s = x1 * y2 - x2 * y1;
        if(s > 0) return 1;
        if(s < 0) return -1;
        return 0;
    }
// Returns a triangle's area given the coordinates of its vertices
    double triangleArea(double x1, double y1, double x2, double y2, double x3, double y3)
    {
        x1 -= x3;
        y1 -= y3;
        x2 -= x3;
        y2 -= y3;
        return (x1 * y2 - x2 * y1) / 2;
    }

    double calculateMinArea(int numPosts, int radius, vector <int> x, vector <int> y)
    {
        // Calculate the Cartesian position of each post:
        double px[numPosts], py[numPosts];
        for (int i=0; i<numPosts; i++)
        {
            const double PI = acos(-1);
            double a = i * 2 * PI / numPosts;
            px[i] = radius * cos(a);
            py[i] = radius * sin(a);
        }

        bool valid[numPosts][numPosts];
        for (int i=0; i<numPosts; i++)
        {
            for (int j=0; j<numPosts; j++)
            {
                // Is segment i -&gt; j valid ?
                // Triangle i -&gt; j -&gt; p must be ccw for each penguin p:
                valid[i][j] = true;
                for (int k=0; k<x.size(); k++)
                {
                    if ( ccw(px[i],py[i], px[j],py[j], x[k],y[k]) != 1)
                    {
                        valid[i][j] = false;
                    }
                }
            }
            valid[i][i] = false;
        }
        // minimum polygon that uses only valid segments:
        const double INF = 1e50;

        double dp[numPosts][numPosts];
        // the base case f(r,r) = 0.0.
        for (int r = 0; r < numPosts; r++)
        {
            dp[r][r] = 0.0;
        }
        for (int dif = 1; dif < numPosts; dif++)
        {
            for (int l = 0 ; l + dif < numPosts; l++)
            {
                int r = l + dif;
                dp[l][r] = INF;
                // Is there a valid nl?
                for (int nl = l+1; nl <= r; nl++)
                {
                    if (valid[l][nl])   // The segment is valid
                    {
                        double area = triangleArea(px[l],py[l], px[nl],py[nl], px[r],py[r]);
                        // area + f(nl, r). Note that f(nl, r) could be INF (an invalid case)
                        dp[l][r] = std::min(dp[l][r], area + dp[nl][r]);
                    }
                }
            }
        }

        double res = INF;
        // Pick the minimum and maximum indexes for the chosen posts.
        for (int l = 0; l < numPosts; l++)
        {
            for (int r = l+2; r < numPosts; r++)
            {
                // The closing segment r-&gt;l must be valid.
                if (valid[r][l])
                {
                    res = std::min(res, dp[l][r]);
                }
            }
        }
        return ( (res < INF) ? res : -1.0 );
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
    void verify_case(int Case, const double &Expected, const double &Received)
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
        int Arg0 = 3;
        int Arg1 = 5;
        int Arr2[] = {-1};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arr3[] = {0};
        vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
        double Arg4 = 32.47595264191645;
        verify_case(0, Arg4, calculateMinArea(Arg0, Arg1, Arg2, Arg3));
    }
    void test_case_1()
    {
        int Arg0 = 30;
        int Arg1 = 5;
        int Arr2[] = {6};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arr3[] = {0};
        vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
        double Arg4 = -1.0;
        verify_case(1, Arg4, calculateMinArea(Arg0, Arg1, Arg2, Arg3));
    }
    void test_case_2()
    {
        int Arg0 = 4;
        int Arg1 = 5;
        int Arr2[] = {2};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arr3[] = {1};
        vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
        double Arg4 = 25.0;
        verify_case(2, Arg4, calculateMinArea(Arg0, Arg1, Arg2, Arg3));
    }
    void test_case_3()
    {
        int Arg0 = 4;
        int Arg1 = 5;
        int Arr2[] = {2,-2};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arr3[] = {1,-1};
        vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
        double Arg4 = 50.0;
        verify_case(3, Arg4, calculateMinArea(Arg0, Arg1, Arg2, Arg3));
    }
    void test_case_4()
    {
        int Arg0 = 8;
        int Arg1 = 5;
        int Arr2[] = {8};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arr3[] = {8};
        vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
        double Arg4 = -1.0;
        verify_case(4, Arg4, calculateMinArea(Arg0, Arg1, Arg2, Arg3));
    }
    void test_case_5()
    {
        int Arg0 = 7;
        int Arg1 = 10;
        int Arr2[] = {9};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arr3[] = {1};
        vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
        double Arg4 = 29.436752637711805;
        verify_case(5, Arg4, calculateMinArea(Arg0, Arg1, Arg2, Arg3));
    }
    void test_case_6()
    {
        int Arg0 = 30;
        int Arg1 = 800;
        int Arr2[] = {8,2,100,120,52,67,19,-36};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arr3[] = {-19,12,88,-22,53,66,-140,99}
                     ;
        vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
        double Arg4 = 384778.74757953023;
        verify_case(6, Arg4, calculateMinArea(Arg0, Arg1, Arg2, Arg3));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    FencingPenguinsEasy ___test;
    ___test.run_test(-1);
}
// END CUT HERE
