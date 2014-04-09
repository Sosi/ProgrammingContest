#include <iostream>
#include <vector>
using namespace std;
struct P
{
	char R;
	int num;

};
int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	int T;
	cin>>T;
	for(int Case=1;Case<=T;Case++)
	{

		int N;
		cin>>N;
		vector<P> road(N);
		for(int i=0;i<N;i++)
		{
			cin>>road[i].R;
			cin>>road[i].num;
		}
		int time=0;    //global time
		int Ow=0;     // wait time
		int Bw=0;     // wait time
		int Oc=1;     //current position
		int Bc=1;     //current position
		for(int i=0;i<road.size();i++)
		{
			if(road[i].R=='O')
			{
				time+= (abs(road[i].num-Oc)-(time-Ow)<=0?0:abs(road[i].num-Oc)-(time-Ow)) +1;
				Oc=road[i].num;
				Ow=time;
			}
			if(road[i].R=='B')
			{
				time+=(abs(road[i].num-Bc)-(time-Bw)<=0?0:abs(road[i].num-Bc)-(time-Bw))+1;
				Bc=road[i].num;
				Bw=time;
			}
		}
		cout<<"Case #"<<Case<<": "<<time<<endl;

	}
	return 0;
}