#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <cmath>
using namespace std;

string ret = "";
void outputX(int num, int k1, int k2, int dir)
{
    if(dir > 0)
    {
        for(int i=1; i<=num; i++)
        {
                if (i!= k1 && i!=k2)
                {
                    ret += "N";
                }else
                {
                    ret += "S";
                }
        }
    }
    if(dir < 0)
    {
        for(int i=1; i<= num; i++)
        {
            if(i!= k1 && i!=k2)
            {
                ret += "S";
            }
            else
            {
                ret += "N";
            }
        }
    }
}
int main()
{
    //freopen("B.txt","r",stdin);
    //freopen("B-small-attempt0.in","r",stdin);
    //freopen("B-small-attempt0.out","w",stdout);
    int T; cin>>T;
    for(int t=1; t<=T; t++)
    {
        ret="";
        int X,Y; cin>>X>>Y;
        int A = abs(X), B = abs(Y);
        int n = ((int)sqrt(8.0*X+1) -1)/2;
        cout<<"n "<<n<<endl;
        if ( n*(n+1)/2 == A)
        {
            //output(n, -1, -1, X);

        }else
        {
            if(n*(n+1)/2 < A)
            {
                if( (n+2)*(n+1)/2 > A)
                {
                    n = n+1;
                }else
                {
                    cout<<"PPP"<<endl;
                }
            }
        }
        int SIG = n*(n+1)/2;
        if((SIG - A)%2== 0)
        {
            int k = (SIG - A)/2; // the kth change
            outputX(n,k,-1,X);
        }else
        {
            if((n+1)%2 == 1)
            {
                int k = (SIG+n-1-A)/2;
                outputX(n+1,k,-1,X);
            }else
            {
                int k = (SIG-A)/2;
                outputX(n+2,k,n+2,X);
                // change for n+2
            }
        }
        cout<<"Case #"<<t<<": "<<ret<<endl;
    }
    return 0;
}
