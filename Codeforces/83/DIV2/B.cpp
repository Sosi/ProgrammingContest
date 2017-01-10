#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int main(){
	int N;
	cin >> N;
	vector<int> num;
	for(int i=0; i<N; i++){
		int a; cin >> a; num.push_back(a);
	}
	sort(num.begin(),num.end());
	bool ans=false;
	for(int i=0; i<N-1; i++){
		if(num[i]*2>num[i+1] && num[i]!=num[i+1]){
			ans=true;
			break;
		}
	}
	if(ans){
		cout << "YES\n";
	}else{
		cout << "NO\n";
	}
}