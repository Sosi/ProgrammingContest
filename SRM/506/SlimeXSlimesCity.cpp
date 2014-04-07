#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class SlimeXSlimesCity
{
public:
	int merge(vector <int> population)
	{

		sort(population.begin(),population.end());
		int res=0;
		for(int i=0;i<population.size();i++)  // front i
		{
			long long sum=0;
			for(int j=0;j<=i;j++)
				sum+=population[j];
			bool flag=true;
			for(int j=i+1;j<population.size();j++)
			{
				if(sum>=population[j])
					sum+=population[j];
				else
				{
					flag=false;
					break;
				}
			}
			if(flag)
			{ 
				res++;
				cout<<"Correct  "<<i<<endl;
			}
		}
		return res;
	}
};