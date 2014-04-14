#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	freopen("D-large.in","r",stdin);
	freopen("D-large.out","w",stdout);
	int T; cin>>T;
	for(int t=1; t<= T; t++)
	{
		int N;
		cin>>N;
		vector<double> A(N);
		vector<double> B(N);
		for(int i=0; i<N; i++) cin>>A[i];
		for(int i=0; i<N; i++) cin>>B[i];
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());
		int War = 0;
		for(int i = A.size()-1, j= B.size()-1; i>=0 && j>= 0;)
		{
			if(B[j]>A[i])
			{
				War++;
				i--;
				j--;
			} else if(B[j] <A[i])
			{
				i--;
			}
		}
		//cout<<N - War<<endl;
		int NOWar = 0;
		for(int i = B.size()-1, j= A.size()-1; i>=0 && j>= 0;)
		{
			if(A[j]>B[i])
			{
				NOWar++;
				i--;
				j--;
			} else if(A[j] <B[i])
			{
				i--;
			}
		}
		//cout<<NOWar<<endl;
		cout<<"Case #"<<t<<": "<<NOWar<<" "<<N-War<<endl;
	}
	return 0;
}