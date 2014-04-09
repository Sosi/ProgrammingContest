#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    long long N=243LL;
    
    cout<<(int)floor((log(N*1.0+0.000000001)/log(3*1.0)))<<endl;
    
    printf("%.8f",((log(243*1.0)/log(3*1.0))));cout<<endl;
    printf("%d",((log(243*1.0)/log(3*1.0))));cout<<endl;
    printf("%.8f",(int)((log(243*1.0)/log(3*1.0))));cout<<endl;
    printf("%d",(int)((log(243*1.0)/log(3*1.0))));cout<<endl;
    printf("%.8f",ceil((log(243*1.0)/log(3*1.0))));cout<<endl;
    printf("%.8f",floor((log(243*1.0)/log(3*1.0))));cout<<endl;
   // cout<<((log(243*1.0)/log(3*1.0)))<<endl;
    getchar();
    return 0;
}
