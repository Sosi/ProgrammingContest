/**
Two dimensional BIT
*/

#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

#define MAX 1026
int s[MAX][MAX];
int lowbit(int x)
{
    return x&(x^(x-1));
}

int N;

void change(int a,int b,int delta)
{
    for(int x=a; x<=N; x+=lowbit(x))
        for(int y=b; y<=N; y+=lowbit(y))
            s[x][y]+=delta;
}
int sum(int a,int b)
{
    int res=0;
    for(int x=a; x>0; x-=lowbit(x))
        for(int y=b; y>0; y-=lowbit(y))
            res+=s[x][y];
    return res;
}
int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0)
        {
            cin>>N; N++;
            memset(s,0,sizeof(s));
        }
        else if(n==1)
        {
            int a,b,c;
            cin>>a>>b>>c; a++; b++;
            change(a,b,c);
        }
        else if(n==2)
        {
            int a,b,c,d;
            cin>>a>>b>>c>>d;
            a++;b++;c++;d++;
            cout<<sum(c,d) + sum(a-1,b-1) - sum(a-1,d) - sum(c,b-1)<<endl;
        }
        else break;;
    }
    return 0;
}
