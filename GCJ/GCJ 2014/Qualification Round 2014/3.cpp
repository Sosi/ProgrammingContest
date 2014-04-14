#include <iostream>

using namespace std;

char Map[55][55];
int main()
{
	freopen("C-large-practice.in","r",stdin);
	freopen("C-large-practice.out","w",stdout);
	int T; cin>>T;

	for(int t= 1; t<=T; t++)
	{
		bool possible = false;
		int R,C,M;
		cin>>R>>C>>M;
		for(int i=0; i<R; i++)
		{
			for(int j=0; j<C; j++)
			{
				Map[i][j] = '*';
			}
		}
		if(R == 1 || C == 1 || R*C == M+1)
		{
			possible = true;
			Map[0][0] = 'c';
			int num = R*C - M-1;
			for(int i=0; i<R; i++)
			{
				for(int j=0; j<C; j++)
				{
					if(i==0 && j==0) continue;
					else if(num >0)
					{
						Map[i][j] = '.';
						num--;
					}else Map[i][j] = '*';
				}
			}
		}else
		{
			for(int r = 2; r<=R; r++)
			{
				for(int c = 2; c<=C; c++)
				{
					int mineleft = M - (R*C - r*c);
					if( mineleft <= (r-2)*(c-2) && mineleft >=0)
					{
						possible = true;
						for(int i=0; i<R; i++) for(int j=0; j<C; j++)Map[i][j] = '*';
						Map[0][0]= 'c';
						for(int i=0; i<2; i++) for(int j=0; j<c; j++)
						{
							if(i ==0 && j==0) continue;
							Map[i][j] = '.';
						}
						for(int i=2; i<r; i++) for(int j=0; j<2; j++) Map[i][j] = '.';
						mineleft = (r-2)*(c-2) - mineleft;
						for(int i= 2; i<r; i++) for(int j=2; j<c; j++)
						{
							if(mineleft > 0)
							{
								mineleft --;
								Map[i][j] = '.';
							} else Map[i][j] = '*';

						}
					}

				}
			}

		}
		cout<<"Case #"<<t<<":"<<endl;
		if(possible)
		{
			for(int i=0; i<R; i++)
			{
				for(int j=0; j<C; j++)
				{
					cout<<Map[i][j];
				}
				cout<<endl;
			}
		}
		else
		{
			cout<<"Impossible"<<endl;
		}
	}
}