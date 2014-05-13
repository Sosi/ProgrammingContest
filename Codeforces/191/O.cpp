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
 

#define N  100000  
using namespace std;
int sieve[N + 1];  
int i;
int main()  
{ freopen("A.txt", "w",stdout); 
 for(int i = 2; i <= N; i++) sieve[i] = 1;  
 for(i = 2; i <= N / 2; i++) sieve[i * 2] = 0;   
 int p = 2;  
 while(p * p <= N)  
 {  
  p = p + 1;  
  while(sieve[p] == 0)  
   p++;  
  int t = p * p;  
  int s = 2 * p;  
  while(t <= N)  
  {  
   sieve[t] = 0;  
   t = t + s;  
  }  
 }  
 for(i = 2; i <= N; i++)  
  if(sieve[i] != 0) cout<<i<<",";    
}  
