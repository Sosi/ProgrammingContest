#line 5 "BrokenStrings.cpp"
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


class BrokenStrings
{
        public:
        int buyStrings(int n, vector <string> stringCosts)
        {
            int a=10001, b=100001;
            for(int i=0; i<stringCosts.size(); i++)
            {
                int temp;
                istringstream iin(stringCosts[i]);
                iin>>temp; a = min(a,temp);
                iin>>temp; b = min(b,temp);
            }
            if(b*6<=a) return b*n;
            else
            {
                if((n%6)*b < a) return n/6*a+(n%6)*b;
                else
                    return (int)ceil(n/6.0)*a;
            }
        }
        

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor


// Powered by FileEdit
