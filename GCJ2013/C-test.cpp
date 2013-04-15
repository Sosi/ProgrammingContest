#include <iostream>
#include <vector>
using namespace std;

#define MAX 10000001LL
bool par(long long X)
{
    vector<int> m;
    while(X> 0)
    {
        m.push_back(X%10);
        X/=10;
    }
    for(int i=0;i<m.size()/2; i++)
    {
        if(m[i]!=m[m.size()-1-i]) return false;

    }
    return true;
}
int main()
{
    for(long long i = 1LL; i< MAX ; i++)
    {
        if(par(i) && par(i*i)) cout<<i*i<<endl;
    }
    return 0;
}
