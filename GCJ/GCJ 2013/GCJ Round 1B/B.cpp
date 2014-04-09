#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int main()
{
    freopen("B.txt","r",stdin);
    //freopen("B-small-attempt0.in","r",stdin);
    //freopen("B-small-attempt0.out","w",stdout);
    int T; cin>>T;
    for(int t=1; t<=T; t++)
    {
        int N,X,Y;
        cin>>N>>X>>Y;
        X = abs(X);
        if(N >=15)
        {
            if(X%2 + Y%2 == 1 && X + Y <= 6) p = 1;
            
        }else if(N >= 6)
        {
            int Num = N - 6;
            if(Num > 4)
        }else if(N >=1)
        {
        }
    }
    return 0;
}
