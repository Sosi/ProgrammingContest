#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
    int S[1005];
    int N;
    while(cin>>N && N!=0)
    {
        fill(S,S+1005,0);
        char k;
        int count=0;
        for(int i=0;i<N;i++)
        {
            cin>>k;
            cin>>S[i];
            if(k=='P') S[i]--;else S[i]++;
            S[i]=abs(S[i]);
            if(S[i]>count) count+=S[i]-count;
            else count += (count-S[i])%2;
        }
        cout<<count<<endl;
       // cout<<*max_element(S,S+1005)<<endl;
    }

}
