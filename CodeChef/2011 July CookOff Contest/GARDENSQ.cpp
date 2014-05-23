#include <iostream>
#include <string.h>
using namespace std;

char G[55][55];

int main()
{
    int T;
    cin>>T;
    int N,M;
    while(T--)
    {
        cin>>N>>M;
        //cout<<N<<"  "<<M<<endl;

        memset(G,0,sizeof(G));
        for(int i=1; i<=N; i++)
        {
            for(int j=1; j<=M; j++)
            {
                cin>>G[i][j];
            }
        }
        //cout<<"a"<<endl;
        int num=0;
        for(int k=2; k<=min(N,M); k++)
        {
            for(int i=1; i<=N; i++)
            {
                for(int j=1; j<=M; j++)
                {
                    if(i+k-1>N || j+k-1>M) continue;
                    else
                    {
                        if( (G[i][j]==G[i+k-1][j]) && (G[i+k-1][j]==G[i+k-1][j+k-1]) && (G[i+k-1][j]== G[i][j+k-1])) num++;
                    }
                }
            }
        }
        cout<<num<<endl;
    }
    return 0;
}
