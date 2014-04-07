#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
using namespace std;
#define PI  3.141592653589

template<class T>     T gcd(T a,T b){ if(a<0) return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template <class T>     T lcm(T a,T b){ return a*(b/gcd(a,b));}

class 
	GoodHours
{
public:int howMany(string beforeTime, string afterTime)
	   {
		   int a=(beforeTime[0]-'0')*10+(beforeTime[1]-'0');
		   int  b=(beforeTime[3]-'0')*10+(beforeTime[4]-'0');
		   int c=(afterTime[0]-'0')*10+(afterTime[1]-'0');
		   int d=(afterTime[3]-'0')*10+(afterTime[4]-'0');
		   cout<<a<<endl;
		   cout<<b<<endl;
		   cout<<c<<endl;
		   cout<<d<<endl;
		   int num=0;
		   if(a==c&&b<=d)
		   {
			   for(int j=b;j<=d;j++)
			   {
				   if(a%10*(a/10)==j%10*(j/10))

					   num++;
				   else

					   if(a/10==(a%10)*(j%10)*(j/10))
						   num++;
					   else

						   if((a/10)*(a%10)*(j/10)==j%10)
							   num++;
			   }

		   }
		   if(a<c)
		   {
			   for(int i=a;i<c;i++)
			   {
				   for(int j=0;j<=59;j++)
				   {
					   if(i%10*(i/10)==j%10*(j/10))
						   num++;
					   else
						   if(i/10==(i%10)*(j%10)*(j/10))
							   num++;
						   else
							   if((i/10)*(i%10)*(j/10)==j%10)
								   num++;
				   }
			   }
			   for(int j=0;j<b;j++)
			   {
				   if(a%10*(a/10)==j%10*(j/10))
					   num--;
				   else

					   if(a/10==(a%10)*(j%10)*(j/10))
						   num--;
					   else

					   if((a/10)*(a%10)*(j/10)==j%10)
						   num--;
			   }
			   for(int j=0;j<=d;j++)
			   {
				   if(c%10*(c/10)==j%10*(j/10))
					   num++;
				   else

					   if(c/10==(c%10)*(j%10)*(j/10))
						   num++;
					   else

						   if((c/10)*(c%10)*(j/10)==j%10)
							   num++;
			   }
		   }
		   if(a>c||(a==c&&b>d))
		   {
			   for(int i=a;i<=23;i++)
			   {
				   for(int j=0;j<=59;j++)
				   {
					   if(i%10*(i/10)==j%10*(j/10))
						   num++;
					   else

						   if(i/10==(i%10)*(j%10)*(j/10))
							   num++;
						   else

							   if((i/10)*(i%10)*(j/10)==j%10)
								   num++;
				   }
			   }
			   for(int j=0;j<b;j++)
			   {
				   if(a%10*(a/10)==j%10*(j/10))
					   num--;
				   else

					   if(a/10==(a%10)*(j%10)*(j/10))
						   num--;
					   else

						   if((a/10)*(a%10)*(j/10)==j%10)
							   num--;
			   }

			   //
			   /*for(int j=0;j<=59;j++)
			   {
				   if(c%10*(c/10)==j%10*(j/10))
					   num++;
				   else

					   if(c/10==(c%10)*(j%10)*(j/10))
						   num++;
					   else

						   if((c/10)*(c%10)*(j/10)==j%10)
							   num++;
			   }
			   */


			   for(int i=0;i<c;i++)
			   {
				   for(int j=0;j<=59;j++)
				   {
					   if(i%10*(i/10)==j%10*(j/10))
						   num++;
					   else

						   if(i/10==(i%10)*(j%10)*(j/10))
							   num++;
						   else

							   if((i/10)*(i%10)*(j/10)==j%10)
								   num++;
				   }
			   }

			   for(int j=0;j<=d;j++)
			   {
				   if(c%10*(c/10)==j%10*(j/10))
					   num++;
				   else

					   if(c/10==(c%10)*(j%10)*(j/10))
						   num++;
					   else

						   if((c/10)*(c%10)*(j/10)==j%10)
							   num++;
			   }
		   }


		   return num;

	   }





};
