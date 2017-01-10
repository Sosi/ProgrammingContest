/*

*/

#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

#define MAX 1000005
int A[MAX];
int dmax[MAX];
int dmin[MAX];
int n,K;
void RMQ_init()
{
    for(int i=1; i<=n; i++) 
    {
        dmax[i] = A[i]; dmin[i] = A[i];
    }
    int k=0; while((1<<(k+1)) <= K) k++;
    for(int j=1; j <= k; j++)
    {
        for(int i=1; i+(1<<j)-1 <= n; i++)
        {
            dmin[i] = min(dmin[i], dmin[i+(1<<(j-1))]);
            dmax[i]= max(dmax[i], dmax[i+(1<<(j-1))]);
        }
    }
}

int RMQmin(int L, int R)
{
    int k =0; 
    while((1<<(k+1)) <= R-L+1) k++;
    return min(dmin[L], dmin[R-(1<<k)+1]);

}
int RMQmax(int L, int R)
{
    int k=0; 
    while((1<<(k+1)) <= R-L+1) k++;
    return max(dmax[L], dmax[R-(1<<k)+1]);
}
int main()
{
    //freopen("2823.txt","r",stdin);
    cin>>n>>K;
    memset(A, 0, sizeof(A));
    for(int i=1; i<=n; i++) scanf("%d", &A[i]);
    RMQ_init();
    for(int i=1; i<=n-K+1; i++) printf("%d ",RMQmin(i,i+K-1));
    cout<<endl;
    for(int i=1; i<=n-K+1; i++) printf("%d ",RMQmax(i,i+K-1));
    cout<<endl;
    return 0;
}
