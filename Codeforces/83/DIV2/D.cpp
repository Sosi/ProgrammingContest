#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>

using namespace std;

const int MAX=1005;
int N,M,H,s[MAX];

double di(int a, int b){
	double ans=1;
	for(int i=0; i<N-1; i++){
		ans*=(double)(a-i)/(double)(b-i);
	}
	return ans;
}

int main(){
	cin >> N >> M >> H;
	H--;
	int total=0;
	for(int i=0; i<M; i++){
		cin >> s[i];
		total+=s[i];
	}
	if(total<N){
		cout << "-1.0\n";
		return 0;
	}
	total--; s[H]--; 
	double ans=1-di(total-s[H],total);
	printf("%.9f\n", ans);
}