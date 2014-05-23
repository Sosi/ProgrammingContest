#include <iostream>
using namespace std;
int count(int m)
{
    int ret=0;
    //cout<<"nima  "<<m<<endl;
    while(m)
    {
        //cout<<"b   "<<m<<endl;
        ret+= (m&1==1?1:0);
        m=(m>>1);
       // cout<<"c  "<<m<<endl;

    }
    return ret;
}
int shf(int m,int N)
{
    int K=(1<<N)-1;
    //cout<<"K "<<K<<endl;
    for(int i=0;i<N-m;i++)
    {
        K^=(1<<i);
    }
    return K;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N,a,b;
        cin>>N>>a>>b;
        int a1=count(a);
        int b1=count(b);
        //cout<<a1<<" "<<b1<<endl;
        int c=0;
        if(a1+b1<=N) c=a1+b1;
        else
        c= 2*N-a1-b1;
        cout<<shf(c,N)<<endl;
    }
    return 0;

}
