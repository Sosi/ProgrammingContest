#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<sstream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;
 
template<typename T> inline int sz(const T& c) { return (int)c.size(); }
 
struct MislabeledWeights
{
  int fewest(vector <int> w, int test)
  {
    int n = sz(w),ret=2147483647;
    for(int i=0;i<(1<<n);i++)
    {
      int sum=0,cnt=0;
      for(int j=0;j<n;j++)
        if(i&(1<<j))
          sum+=w[j],cnt++;
      if(sum-test>=-cnt&&sum-test<=cnt)
      {
        if(cnt<ret)
          ret=cnt;
      }
    }
    if(ret==2147483647) return -1;
    return ret;
  }
};
