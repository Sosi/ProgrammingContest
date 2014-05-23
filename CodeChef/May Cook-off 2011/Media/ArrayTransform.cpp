#include <iostream>
#include <map>
using namespace std;
int main(){
    //freopen("ArrayTransform.in","r",stdin);
    //freopen("ArrayTransform.out","w",stdout);
    int T;
    cin>>T;
    for(int t=1;t<=T;t++){
        int n,K;
        cin>>n>>K;
        int temp;
        map<int,int> C;
        for(int i=0;i<n;i++){
        cin>>temp;
        C[temp%(K+1)]++;
        //C.insert(temp%(K+1));
        }
        map<int,int>::iterator it=C.begin();
        if(C.size()==1) cout<<"YES"<<endl;
        else if(C.size()==2 && (it->second==1 || (++it)->second==1)){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
} 
