#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	int T;
	cin>>T;
	for(int t = 1; t<= T; t++)
	{
		double C,F,X;
		cin>>C>>F>>X;

		double ret = X/2.0;
		int up = max( (F*X - 2*C)/(F*C), 0.0);
		//cout<<up<<endl;
		double Nec = 0.0f;
		for(int k = 0; k< up; k++)
		{
			Nec += C/(2+k*F);
			ret = min(ret, Nec + X/(2+(k+1)*F));
		}
		printf("Case #%d: %.7f\n", t, ret);
		//cout<<"Case #"<<t<<": "<<ret<<endl;
	}
}