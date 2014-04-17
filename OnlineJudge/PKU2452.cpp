#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

#define MAX 500005
int A[MAX];
int dmax[MAX][20];
int dmin[MAX][20];
int n;
void RMQ_init()
{
    for(int i=1; i<=n; i++) 
    {
        dmax[i][0] = i; dmin[i][0] =i;
    }
    for(int j=1; (1<<j) <=n; j++)
    {
        for(int i=1; i+(1<<j)-1 <= n; i++)
        {

            if(A[dmin[i][j-1]] < A[dmin[i+(1<<(j-1))][j-1]])
            {
                dmin[i][j] = dmin[i][j-1];
            }
            else
            {
                dmin[i][j] = dmin[i+(1<<(j-1))][j-1];
            }
            if(A[dmax[i][j-1]] < A[dmax[i+(1<<(j-1))][j-1]])
            {
                dmax[i][j] = dmax[i+(1<<(j-1))][j-1];
            }
            else
            {
                dmax[i][j] = dmax[i][j-1];
            }

        }
    }
}

int RMQmin(int L, int R)
{
    int k =0; 
    while((1<<(k+1)) <= R-L+1) k++;
    if(A[dmin[L][k]] <= A[dmin[R-(1<<k)+1][k]]) return dmin[L][k];
    return dmin[R-(1<<k)+1][k];

}
int RMQmax(int L, int R)
{
    int k=0; 
    while((1<<(k+1)) <= R-L+1) k++;
    if(A[dmax[L][k]] <= A[dmax[R-(1<<k)+1][k]]) return dmax[R-(1<<k)+1][k];
    return dmax[L][k];
}

int rec(int a, int b)
{
    if(b<=a) return b-a;
    int l = RMQmin(a,b);
    int r = RMQmax(a,b);
    if(l<r) return max(r-l, max(rec(a,l-1), rec(r+1,b)));
    else
    {
        return max( rec(r+1,l-1), max(rec(a, r), rec(l,b)) );
    }
}

int main()
{
    //freopen("2452.txt","r",stdin);
    while(cin>>n)
    {
        memset(A, 0, sizeof(A));
        for(int i=1; i<=n; i++) scanf("%d", &A[i]);
        RMQ_init();
        int ret = rec(1,n);
        if(ret == 0) cout<<-1<<endl;
        else cout<<ret<<endl;
    }
    return 0;

}
