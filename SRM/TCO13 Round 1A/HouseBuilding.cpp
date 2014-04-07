#line 5 "HouseBuilding.cpp"

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


 

class HouseBuilding
{
        public:
        int getMinimum(vector <string> area)
        {
            int MIN = 25000;
            for(int h = 0; h<= 9; h++)
            {
                int ret = 0;
                for(int i=0; i<area.size(); i++)
                {
                    for(int j=0; j<area[0].size(); j++)
                    {
                        if ( area[i][j] - '0' < h )  ret += h - area[i][j]+'0';
                        else if(area[i][j] - '0' > h) ret += area[i][j]- '0' - h -1;
                    }
                }
                MIN = min(ret, MIN);
            }
            return MIN;
        }
        

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
