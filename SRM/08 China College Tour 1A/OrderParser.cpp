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
 
struct OrderParser
{
  vector <int> orderAmount(vector <string> items, vector <string> message)
  {
    vector<int> ret;
    ret.clear();
    int n = sz(message);
    int numitem = sz(items);
    for(int i=0;i<numitem;i++)
      ret.push_back(0);
    for(int i=0;i<n;i++)
    {
      istringstream in(message[i]);
      string str;
      int num=-1;
      while(in>>str)
      {
        int len=sz(str);
        bool flag=true;
        for(int i=0;i<len;i++)
          if(str[i]<'0'||str[i]>'9')
            flag=false;
        if(flag)
          sscanf(str.c_str(),"%d",&num);
        else
        {
          for(int j=0;j<numitem;j++)
            if(str==items[j])
            {
              if(num==-1)
                continue;
              else
              {
                ret[j]+=num;
                num=-1;
              }
            }
        }
      }
    }
    return ret;
  }
};
