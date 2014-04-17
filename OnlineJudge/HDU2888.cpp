/**
  Given an Matrix[n,m] row = n, col = m;  find the position of the lelement of the minimum value between two given indices or find the value of the minimum value between two given indices.

Algorithm: 2D Sparse-Table  (dynamic programming)

Idea: d(row,col,i,j) is the minimum of  (row, col ) to (row+2^i-1, col+2^j-1)

d[row,col,i,j] = d[row,col,i,j-1], d[row,col,i-1,j] , d[row, col+2^(j-1), i,j-1] d[row+2^(i-1),col, i-1,j];



Init O(nmlognlogm) query O(1)
 */
#include <iostream>
#include <stdio.h>
using namespace std;
#define MAX 305
int A[MAX][MAX];   // 1-indexed
int d[MAX][MAX][9][9];
int n,m;


/*
   query the Maximum value of [Sx,Sy] to [Ex,Ey]
 */
void RMQ_init()
{
    for(int row = 1; row<=n; row++) for(int col = 1; col<=m; col++) d[row][col][0][0] = A[row][col];
    for(int i=0; (1<<i) <=n; i++) for(int j=0; (1<<j) <= m; j++)
    {
        if(i==0 && j==0) continue;
        for(int row=1; row+(1<<i)-1 <=n; row++) for(int col =1; col+(1<<j)-1<=m; col++)
        {
            if(i==0) d[row][col][i][j] = max(d[row][col][i][j-1], d[row][col+(1<<(j-1))][i][j-1]);
            else d[row][col][i][j] = max(d[row][col][i-1][j], d[row+(1<<(i-1))][col][i-1][j]);
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

int main()
{
    //freopen("2888.txt","r",stdin);
    while(cin>>n>>m)
    {
        for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) 
            scanf("%d", &A[i][j]);
        int Q; cin>>Q;
        RMQ_init();
        for(int i=0; i<Q; i++)
        {
            int r1,c1,r2,c2;
            scanf("%d%d%d%d", &r1,&c1,&r2,&c2);
            int ret = RMQ(r1,c1,r2,c2);
            int res= max(max(A[r1][c1], A[r1][c2]), max(A[r2][c1],A[r2][c2]));
            if(res == ret) printf("%d yes\n", ret);
            else printf("%d no\n", ret);

        }
    }
    return 0;
}
