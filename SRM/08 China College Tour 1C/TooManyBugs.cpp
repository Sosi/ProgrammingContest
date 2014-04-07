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

using namespace std;

class TooManyBugs {
public:
	int bestBugFixing(vector <string>);
};

struct bug {
	int value, fixtime;
};

bool operator < ( const bug &a, const bug &b ) { return a.value > b.value; }

int n, m;
int worktime[50], used[50];
bug bugs[50];

int TooManyBugs::bestBugFixing(vector <string> info) {
	n = m = 0;

	for( int i = 0; i < info.size(); ++i ) {
		istringstream strin( info[i] );
		int u, v;

		strin >> u;
		if( strin >> v ) {
			bugs[m].value = u;
			bugs[m].fixtime = v;
			++m;
		} else {
			worktime[n++] = u;
		}
	}

	sort( worktime, worktime + n );
	sort( bugs, bugs + m );

	memset( used, 0, sizeof used );

	int sum = 0;

	for( int i = 0; i < m; ++i ) {
		int j = 0;
		while( j < n ) {
			if( !used[j] && worktime[j] >= bugs[i].fixtime ) break;
			++j;
		}
		if( j < n ) {
			used[j] = 1;
			sum += bugs[i].value;
		}
	}

	return sum;
}
