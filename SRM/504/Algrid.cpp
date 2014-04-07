#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
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
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
class Algrid
{
public:
	vector <string> makeProgram(vector <string> output)
	{
		vector<string> input=output;
		int W=output[0].size();
		int H=output.size();
		bool flag=false;
		bool s=true;
		for(int i=H-2;i>=0;i--)
		{
			for(int j=W-2;j>=0;j--)
			{
				flag=false;
				cout<<j<<" "<<flag<<endl;
				if(output[i][j]=='W' && output[i][j+1]=='W')
				{
					flag=true;cout<<i<<" "<<j<<" WW__"<<endl;
				}
				if(output[i][j]=='B' && output[i][j+1]=='W' && output[i+1][j]=='B'  )
				{
					input[i+1][j]='A';
					input[i+1][j+1]='A';
					flag=true;
					cout<<i<<" "<<j<<" WWB_"<<endl;
					if(i==H-2&&j==W-2 && output[i+1][j+1]!='B') s=false;
				}
				if(output[i][j]=='W' && output[i][j+1]=='B' && output[i+1][j]=='W')
				{
					input[i+1][j]='A';
					input[i+1][j+1]='A';
					flag=true;
					cout<<i<<" "<<j<<" WBW_"<<endl;
					if(i==H-2 && j==W-2 && output[i+1][j+1]!='W') s=false;
				}
				if(output[i][j]=='B' && output[i][j+1]=='B')
				{
					swap(input[i+1][j],input[i+1][j+1]);
					flag=true;
					cout<<i<<" "<<j<<" BB__"<<endl;
				}
				if(!flag)
				{
					s=false;
					cout<<"ERROR"<<endl;
				}
				cout<<j<<" "<<flag<<endl;
			}
		}
		if(!s)
		{
			input.clear();
			return input;
		}
		for(int i=0;i<input.size();i++)
		{
			for(int j=0;j<input[0].size();j++)
				if(input[i][j]=='A')
					input[i][j]='B';
		}
		return input;
	}
};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor