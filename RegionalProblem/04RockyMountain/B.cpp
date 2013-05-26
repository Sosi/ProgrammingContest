#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <map>
using namespace std; 
int main()
{
    //freopen("B.in","r",stdin);
    string s;
    vector<string> v;
    int num = 0;
    while(cin>>s)
    {
        num++;
        v.push_back(s);
    }
    vector<string> S(v);
    sort(v.begin(), v.end());
    vector<string> ret(v.size());
    ret[0] = v[0].substr(0,1);
    for(int i=1; i<num; i++)
    {
        for(int j=0; j<min(v[i].size(),v[i-1].size());j++)
        {
            if(v[i-1][j] != v[i][j]) 
            {
                if(ret[i-1].size() < j+1)
                    ret[i-1] = v[i-1].substr(0,j+1);
                ret[i] = v[i].substr(0,j+1);
                break;
             }
        }
        if(ret[i].size() == 0)
        {
            ret[i-1] = v[i-1];
            ret[i] = v[i].substr(0, v[i-1].size() +1);
            //cout<<"!! "<<ret[i-1]<<" "<<ret[i]<<endl;
        }
    }
    map<string,string> m;
    for(int i=0; i< num; i++)
    {
        m[v[i]] = ret[i];
        //cout<<v[i]<<" "<<ret[i]<<endl;
    }
    for(int i=0; i<num; i++)
    {
        cout<<S[i]<<" "<<m[S[i]]<<endl;
    }
    return 0;
}
