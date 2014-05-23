/*
   Our chef has recently returned from the Lucky country. He observed that every restaurant in the Lucky country had a lucky number as its name. He believes that having a lucky number as a restaurant name can indeed turn out to be very lucky. 

   Our chef believes that it is possible to make a lucky number having N digits even luckier. Any number following the rules below is called Lucky lucky number - 

   1. The number contains only digits 4 and 7. 
   2. Count of digit 4 in the number should be divisible by 7. 
   3. Count of digit 7 in the number should be divisible by 4. 

   Help our chef to compute the count of digit 4 in the smallest Lucky lucky number having N digits.
   Input

   First line contains T, number of test cases. Each of the next T lines contains a number N, the number of digits in the Lucky lucky number to be formed. 

   1<=T<=1000 
   1<=N<=1000000000 (10^9)
   Output

   If it is not possible to form a Lucky lucky number having N digits, output -1. Otherwise, output the count of digit 4 in the smallest Lucky lucky number having N digits.
 */


#include<iostream>
#include<cstdio>

#define SI(x) scanf("%d",&x)
using namespace std;


int main()
{
    int t;
    SI(t);

    while(t-- >0)
    {
        int n;
        SI(n);
        bool ok = false;
        int nf = n/7;
        for(int f=nf;f>=0;f--)
        {
            int rem = n-(f*7);
            if(rem%4==0)
            {
                printf("%d\n",f*7);
                ok = true;
                break;
            }
        }

        if(!ok) printf("-1\n");
    }

    return 0;
}
