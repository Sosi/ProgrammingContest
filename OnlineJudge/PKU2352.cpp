/**
  A first glance , It's a two dimensional BIT. Actually, It's a one-dimensional BIT.
  Sort, and sequential insert and query.
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stdio.h>
#include <string.h>
using namespace std;
#define MAX 50000
int s[MAX];
int N = 50000; 
int level[MAX];
inline int lowbit(int  x)
{
    return x&(x^(x-1));
}
void change(int a, int delta)
{
    for(int x=a; x<=N; x+=lowbit(x))
        s[x]+=delta;
}
int sum(int a)
{
    int res=0;
    for(int x=a; x>0; x-=lowbit(x))
        res+=s[x];
    return res;
}
int main()
{
    //freopen("2352.txt","r",stdin);
    int m;
    scanf("%d",&m);
    memset(s,0,sizeof(s));
    memset(level, 0 ,sizeof(level));
    for(int i=0; i<m; i++)
    {
        int x,y; scanf("%d%d",&x,&y);
        x++;
        level[sum(x)]++;
        change(x, 1);
    }

    for(int i=0; i<m; i++) printf("%d\n",level[i]);
    return 0;
}
