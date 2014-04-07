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
#include <cctype>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;
const double EPS=1e-11;
const double PI=acos(-1.0);
template <class T>       T sqr(T x){return x*x;}
template<class T>     T gcd(T a,T b){ if(a<0) return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template <class T>     T lcm(T a,T b){ return a*(b/gcd(a,b));}
int countbit(int n)      { return (n==0)?0:(1+countbit(n&(n-1)));}
int lowbit(int n)        { return (n^(n-1))&n;}
class


	KingMovement
{
public:string finalPosition(string startPosition, string stonePosition, vector <string> moves)
	   {
		   // int map[9][9]={0};
		   int iking=9-(startPosition[1]-'0');
		   int jking=startPosition[0]-'A'+1;
		   int istone=9-(stonePosition[1]-'0');
		   int jstone=stonePosition[0]-'A'+1;
		   // map[9-(startPosition[1]-'0')][startPosition[0]-'A'+1]=1;
		   //map[9-(stonePosition[1]-'0')][stontPosition[0]-'A'+1]=1;
		   for(int num=0;num<moves.size();num++)
		   {
			   if(moves[num]=="L")
			   {
				   if((jstone==jking-1)&&(istone==iking))
				   {
					   if(jstone==1)
						   continue;
					   else
					   {
						   jking--;
						   jstone--;
					   }
				   }
				   else
				   {
					   if(jking==1)
						   continue;
					   else
						   jking--;
				   }
			   }
			   if(moves[num]=="R")
			   {
				   if((jstone==jking+1)&&(istone==iking))
				   {
					   if(jstone==8)
						   continue;
					   else
					   {
						   jking++;
						   jstone++;
					   }
				   }
				   else
				   {
					   if(jking==8)
						   continue;
					   else
						   jking++;
				   }
			   }
			   if(moves[num]=="T")
			   {
				   if((istone==iking-1)&&(jstone==jking))
				   {
					   if(istone==1)
						   continue;
					   else
					   {
						   iking--;
						   istone--;
					   }
				   }
				   else
				   {
					   if(iking==1)
						   continue;
					   else
						   iking--;
				   }
			   }
			   if(moves[num]=="B")
			   {
				   if((istone==iking+1)&&(jstone==jking))
				   {
					   if(istone==8)
						   continue;
					   else
					   {
						   iking++;
						   istone++;
					   }
				   }
				   else
				   {
					   if(iking==8)
						   continue;
					   else
						   iking++;
				   }
			   }
			   if(moves[num]=="LT")
			   {
				   if((jstone==jking-1)&&(istone==iking-1))
				   {
					   if(jstone==1||istone==1)
						   continue;
					   else
					   {
						   jking--;
						   iking--;
						   jstone--;
						   istone--;
					   }
				   }
				   else
				   {
					   if(jking==1||iking==1)
						   continue;
					   else
					   {
						   jking--;
						   iking--;
					   }

				   }
			   }
			   if(moves[num]=="RT")
			   {
				   if((jstone==jking+1)&&(istone==iking-1))
				   {
					   if(jstone==8||istone==1)
						   continue;
					   else
					   {
						   jking++;
						   iking--;
						   jstone++;
						   istone--;
					   }
				   }
				   else
				   {
					   if(jking==8||iking==1)
						   continue;
					   else
					   {
						   jking++;
						   iking--;
					   }

				   }
			   }
			   if(moves[num]=="RB")
			   {
				   if((jstone==jking+1)&&(istone==iking+1))
				   {
					   if(jstone==8||istone==8)
						   continue;
					   else
					   {
						   jking++;
						   iking++;
						   jstone++;
						   istone++;
					   }
				   }
				   else
				   {
					   if(jking==8||iking==8)
						   continue;
					   else
					   {
						   jking++;
						   iking++;
					   }

				   }
			   }
			   if(moves[num]=="LB")
			   {
				   if((jstone==jking-1)&&(istone==iking+1))
				   {
					   if(jstone==1||istone==8)
						   continue;
					   else
					   {
						   jking--;
						   iking++;
						   jstone--;
						   istone++;
					   }
				   }
				   else
				   {
					   if(jking==1||iking==8)
						   continue;
					   else
					   {
						   jking--;
						   iking++;
					   }

				   }
			   }
		   }
		   string result;
		   result+=(char)(jking+'A'-1);
		   result+=9-iking+'0';
		   result+=',';
		   result+=(char)(jstone+'A'-1);
		   result+=9-istone+'0';
		   return result;
	   }
};
