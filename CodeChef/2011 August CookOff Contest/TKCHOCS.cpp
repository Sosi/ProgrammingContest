#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;

int M[505][505];
int DP[505][505];
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        memset(M,0,sizeof(M));
        memset(DP,0,sizeof(DP));
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=i;j++)
            {
                scanf("%d",&M[i][j]);
            }
        }
        /*
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                cout<<DP[i][j]<<" ";
            }
            cout<<endl;
        }
        */
        for(int k=1;k<N;k++)
        {
            //cout<<"Start"<<endl;
            for(int i=1;i<N-k+1;i++)   // 横向
            {
                DP[k][i]=M[k][i]+max(DP[k-1][i-1],max(DP[k-1][i],DP[k-1][i+1]));
                //cout<<"DP[k][i]  "<<DP[k][i]<<endl;
            }
            //cout<<"end heng"<<endl;
            for(int i=N;i>k;i--)
            {
                DP[i][N-k+1]=M[i][N-k+1]+max(DP[i][N-k+2],max(DP[i+1][N-k+2],DP[i-1][N-k+2]));
            }
            //cout<<"end shu"<<endl;
            //DP[k][N-k+1]=M[k][N-k+1]+max(max(DP[k-1][N-k],DP[k-1][N-k+1]),max(DP[k][N-k+2],max(DP[k+1][N-k+2],DP[k-1][N-k+2])));
        }
        // 以下分四种情况讨论

        // 1 两个点都没有走，则答案是 DP[N-1][1]+DP[N][2];
        // 2 其中有一个点走了，如果是上面，则 DP[N][2]+ 枚举对角线点+(可到达这个状态的两个点)
        //                      如果是下面，则DP[N-1][1]+ 没绝对角线点
        // 3 如果都走了，O(n^2)复杂度来枚举是那两个点走了这条路，注意是长的要减去短的对角线上的值！

        // 这只是一种特殊情况，更一般的情况是在任意两个点踏上对角线
        /*
         Both of them can not cross the diagonal ! So, they can only meet on the diagonal.
          We can as well try all possible cells at which both of them reach the diagonal ( refer setters solution ),
          or you can do a O(n) method going from bottom-top on the diagonal ( refer testers solution ). Complexity is O(n^2).
        */
        /*
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                cout<<DP[i][j]<<" ";
            }
            cout<<endl;
        }
        */
        int Dk[505];
        memset(Dk,0,sizeof(Dk));

        for(int i=1;i<=N;i++)
        {
            Dk[i]=M[N-i+1][i]+Dk[i-1];
            //cout<<Dk[i]<<" ";
        }

        int ans=0;
        for(int i=1;i<N;i++)
        {
            for(int j=1;j<N;j++)
            {
                ans=max(ans, max(DP[N-i][i-1],DP[N-i][i])+ max(DP[N-j+2][j+1],DP[N-j+1][j+1])  + Dk[max(i,j)]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
