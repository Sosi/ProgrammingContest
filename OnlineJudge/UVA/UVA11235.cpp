/**
RMQ 
*/

#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;


#define MAX 100009
int A[MAX];
int d[MAX][20];
int n;

void RMQ_init()
{
    for(int i=1; i<=n; i++) d[i][0] = A[i];
    for(int j=1; (1<<j) <= n; j++)
    {
        for(int i=1; i+(1<<j)-1 <=n; i++)
            d[i][j] = max(d[i][j-1], d[i+(1<<(j-1))][j-1]);
    }
}
int RMQ(int L, int R)
{
    int k=0; 
    while((1<<(k+1))<= R-L+1) k++;
    return max( d[L][k], d[R-(1<<k)+1][k]);
}

struct interval
{
    int left;
    int right;
    int length;
};
int main()
{
    //freopen("11235.txt","r",stdin);
    int num, q;
    while(cin>>num>>q && num!=0)
    {
        memset(A,0,sizeof(A));
        memset(d,0,sizeof(d));
        int Anum = 1;
        interval INT[MAX];
        int Belong[MAX];
        int S[MAX];
        for(int i=1; i<=num; i++)
        {
            scanf("%d", &S[i]);
            if(i==1)
            {
                INT[Anum].left = 1;
                INT[Anum].right = 1;
                INT[Anum].length = 1;
                A[Anum] = 1;
            }
            else
            {
                if(S[i] == S[i-1])
                {
                    INT[Anum].right++;
                    INT[Anum].length++;
                }
                else
                {
                    A[Anum] = INT[Anum].length;
                    Anum++;
                    INT[Anum].left = INT[Anum-1].right+1;
                    INT[Anum].right = INT[Anum].left;
                    INT[Anum].length = 1;
                }
            }
            Belong[i] = Anum;
        }
        n = Anum;
        RMQ_init();
        for(int i=0; i<q; i++)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            if(Belong[l] == Belong[r]) cout<<r-l+1<<endl;
            else
            {
                int ret = 0;
                ret = max(ret,  INT[Belong[l]].right - l+1);
                ret = max(ret, r - INT[Belong[r]].left+1);
                if(Belong[r] > Belong[l]+1 )
                {
                    ret = max(ret, RMQ(Belong[l]+1, Belong[r]-1));
                }
                cout<<ret<<endl;
            }
        }
    }
    return 0;
}
