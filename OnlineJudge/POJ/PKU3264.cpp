/**
Easy RMQ
*/
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

#define MAX 50005
int A[MAX];
int dmax[MAX][20];
int dmin[MAX][20];
int n;
void RMQ_init()
{
    for(int i=1; i<=n; i++) 
    {
        dmax[i][0] = A[i]; dmin[i][0] = A[i];
    }
    for(int j=1; (1<<j) <=n; j++)
    {
        for(int i=1; i+(1<<j)-1 <= n; i++)
        {
            dmin[i][j] = min(dmin[i][j-1], dmin[i+(1<<(j-1))][j-1]);
            dmax[i][j] = max(dmax[i][j-1], dmax[i+(1<<(j-1))][j-1]);
        }
    }
}

int RMQmin(int L, int R)
{
    int k =0; 
    while((1<<(k+1)) <= R-L+1) k++;
    return min(dmin[L][k], dmin[R-(1<<k)+1][k]);

}
int RMQmax(int L, int R)
{
    int k=0; 
    while((1<<(k+1)) <= R-L+1) k++;
    return max(dmax[R-(1<<k)+1][k],dmax[L][k]);
}


int main()
{
    //freopen("3264.txt","r",stdin);
    int Q;
    cin>>n>>Q;
    memset(A, 0, sizeof(A));
    for(int i=1; i<=n; i++) scanf("%d", &A[i]);
    RMQ_init();
    for(int i=0; i<Q; i++)
    {
        int L,R;
        scanf("%d%d",&L,&R);
        printf("%d\n", RMQmax(L,R) - RMQmin(L,R));
    }
    return 0;
}
