#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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
#include <ctime>
 
using namespace std;
 
class FreeGuitars {
public:
  int minimumCosts(int, vector <string>);
};
 
int FreeGuitars::minimumCosts(int N, vector <string> trainRoutes) {
  int n = N;
  int Graph[100][100]; memset( Graph, -1, sizeof Graph );
  
  for( int i = 0; i < trainRoutes.size(); ++i ) {
    istringstream in( trainRoutes[i] );
    int a, b, w; in >> a >> b >> w; --a, --b;
 
    Graph[a][b] = Graph[b][a] = w;
  }
  
  int dm[100]; memset( dm, -1, sizeof dm );
  bool done[100]; memset( done, false, sizeof done );
  
  *dm = 0;
  
  int sum = 0;
 
  for( int i = 0; i < n; ++i ) {
    int x = -1;
    
    for( int j = 0; j < n; ++j )
      if( dm[j] >= 0 && !done[j] && ( x < 0 || dm[j] < dm[x] ) ) x = j;
    if( x < 0 ) return -1;
    
    sum += dm[x];
    done[x] = true;
    
    for( int j = 0; j < n; ++j )
      if( !done[j] && Graph[x][j] >= 0 ) 
        if( dm[j] < 0 || Graph[x][j] < dm[j] ) dm[j] = Graph[x][j];
  }
  
  return sum;
}
