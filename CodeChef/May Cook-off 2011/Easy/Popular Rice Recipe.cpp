#include <iostream>
#include <map>
#include <string>
using namespace std;
int main(){
   // freopen("PopularRiceRecipe.in","r",stdin);
  //  freopen("PopularRiceRecipe.out","w",stdout);
    int T;
    cin>>T;
    for(int t=1;t<=T;t++){
        int n;
        cin>>n;
        map<string,int> M;
        string name;
        char c;
        for(int i=0;i<n;i++){
            cin>>name>>c;
            if(c=='+')M[name]=1;
            else M[name]=-1;
        }
        int res=0;
        map<string,int>::iterator it;
        for(it=M.begin();it!=M.end();it++)
        res+=it->second;
        cout<<res<<endl;
    }
    return 0;
} 
