// 这个问题太赞了！！
#include<cstdio>
#include<cstring>
#include<iostream>
#include<map>
using namespace std; 

int	n,k,data[400005];
map<int,int> mm; 
int	main()
{
    scanf("%d%d", &n ,&k );
    for (int i = 0; i<n; i++) scanf("%d", &data[i] );
    long long 	ans = 0; 
    int st = 0; 
    for (int j = 0; j<n; j++) 
    {	
        int num = ++mm[data[j]]; 
        if ( num < k ) continue; 
        while ( true ) 
        {
            ans += n-j; 
            mm[data[st]] --; 
            if ( data[st++] == data[j] ) break;
        }
    }
    cout<<ans<<endl;
    return 0;
}
