#include <stdio.h>
#include <map>
#include <queue>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
#define MAX 1000005
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
map<pair<int,int>, int > L;
int main()
{
    //freopen("B.txt","r",stdin);
    //freopen("B-small-attempt0.in","r",stdin);
    //freopen("B-small-attempt0.out","w",stdout);
    queue<pair< pair<int,int>,int > > Q;
    Q.push(make_pair(make_pair(0,0),0));
    while(!Q.empty())
    {
        //cout<<"??"<<endl;
        pair< pair<int,int>,int > tmp = Q.front();
        Q.pop();
        int X = tmp.first.first;
        int Y = tmp.first.second;
        int d = tmp.second;
        if(X+d+1 > MAX || X-d-1 < -MAX || Y+d+1 > MAX || X-d-1 < -MAX) continue; 
        if(L.find(make_pair(X + d+1,Y))== L.end())
        {
            L[make_pair(X+d+1,Y)] = d+1;
            Q.push(make_pair(make_pair(X+d+1,Y),d+1));
        }
        if(L.find(make_pair(X-d-1,Y))== L.end())
        {
            L[make_pair(X-d-1,Y)] = d+1;
            Q.push(make_pair(make_pair(X-d-1,Y),d+1));
        }
        if(L.find(make_pair(X,Y+d+1))==L.end())
        {
            L[make_pair(X,Y+d+1)] = d+1;
            Q.push(make_pair(make_pair(X,Y+d+1),d+1));
        }
        if(L.find(make_pair(X,Y-d-1))==L.end())
        {
            L[make_pair(X,Y-d-1)] = d+1;
            Q.push(make_pair(make_pair(X,Y-d-1),d+1));
        }
        //cout<<"1"<<endl;
    }
    snuke(L,itr)
    {
        cout<<itr->second<<endl;
    }

    int T; cin>>T;
    for(int t=1; t<=T; t++)
    {
        string ret="";
        int X,Y; cin>>X>>Y;

        cout<<"Case #"<<t<<": "<<ret<<endl;
    }
    return 0;
}
