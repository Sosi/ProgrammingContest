#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class SlimeXSlimeRancher2
{
public:int train(vector <int> attributes)
	   {
		   sort(attributes.begin(),attributes.end());
		   int res=0;
		   for(int i=0;i<attributes.size();i++)
		   {
			   res+=attributes[attributes.size()-1]-attributes[i];
		   }
		   return res;
	   }
};