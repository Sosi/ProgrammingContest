#include <iostream>
#include <stdio.h>
using namespace std;
#define MAX 255
int A[MAX][MAX];   // 1-indexed
int d[MAX][MAX][8][8];
int dmin[MAX][MAX][8][8];
int n,m;

void RMQ_init()
{
    for(int row = 1; row<=n; row++) for(int col = 1; col<=m; col++)
    {
        d[row][col][0][0] = A[row][col];
        dmin[row][col][0][0] = A[row][col];
    }
    for(int i=0; (1<<i) <=n; i++) for(int j=0; (1<<j) <= m; j++)
    {
        if(i==0 && j==0) continue;
        for(int row=1; row+(1<<i)-1 <=n; row++) for(int col =1; col+(1<<j)-1<=m; col++)
        {
            if(i==0) d[row][col][i][j] = max(d[row][col][i][j-1], d[row][col+(1<<(j-1))][i][j-1]);
            else d[row][col][i][j] = max(d[row][col][i-1][j], d[row+(1<<(i-1))][col][i-1][j]);
            if(i==0) dmin[row][col][i][j] = min(dmin[row][col][i][j-1] , dmin[row][col+(1<<(j-1))][i][j-1]);
            else dmin[row][col][i][j] = min(dmin[row][col][i-1][j], dmin[row+(1<<(i-1))][col][i-1][j]);
        }
    }
}

int RMQ(int Sx, int Sy, int Ex, int Ey)
{
    int kx=0,ky=0;
    while((1<<(kx+1))<= Ex-Sx+1) kx++; while((1<<(ky+1)) <= Ey-Sy+1) ky++;
    return max(max(d[Sx][Sy][kx][ky], d[Sx][Ey-(1<<ky)+1][kx][ky]), max(d[Ex-(1<<kx)+1][Sy][kx][ky],
                d[Ex-(1<<kx)+1][Ey-(1<<ky)+1][kx][ky]));
}

int RMQmin(int Sx, int Sy, int Ex, int Ey)
{
    int kx=0,ky=0;
    while((1<<(kx+1))<= Ex-Sx+1) kx++; while((1<<(ky+1)) <= Ey-Sy+1) ky++;
    return min(min(dmin[Sx][Sy][kx][ky], dmin[Sx][Ey-(1<<ky)+1][kx][ky]), min(dmin[Ex-(1<<kx)+1][Sy][kx][ky],
                dmin[Ex-(1<<kx)+1][Ey-(1<<ky)+1][kx][ky]));

}

int main()
{
    //freopen("2019.txt","r",stdin);
    cin>>n; m=n;
    int B; cin>>B; int Q; cin>>Q;
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) scanf("%d", &A[i][j]);
    RMQ_init();
    for(int i=0; i<Q; i++)
    {
        int a,b;
        scanf("%d%d", &a,&b);
        cout<<RMQ(a,b,a+B-1,b+B-1)-RMQmin(a,b,a+B-1,b+B-1)<<endl;
    }
}
