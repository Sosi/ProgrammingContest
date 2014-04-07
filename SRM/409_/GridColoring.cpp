#line 5 "GridColoring.cpp"
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


class GridColoring
{
        public:
        double pp(double x, double y, double rows, double cols)
        {
            double rx = 2*(x+1)*(cols-x)-1;
            double ry = 2*(y+1)*(rows-y)-1;
            return rx*ry/(rows*rows*cols*cols);
        }
        double area(int K, int rows, int cols)
        {
            double r=0;
            for(int i=0; i<cols; i++)
                for(int j=0; j<rows; j++)
                {
                    double p=pp(i,j,rows,cols);
                    double q = pow(1-p,K);
                    r+=1-q;
                }
             return r;
        }
        

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor


// Powered by FileEdit


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
