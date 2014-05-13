#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int MAXN = 100100;

int N;
int num[MAXN];
bool use[MAXN];
int nxt[MAXN], prv[MAXN];

vector <int> plist, nlist;

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> num[i+1];
        use[i+1] = true;
        nxt[i+1] = i + 2, prv[i+1] = i;
    }
    
    for (int i = 1; i < N; i++)
        if (num[i] > num[i+1])
            plist.push_back (i+1);
    
    int count = 0;
    while (true)
    {
        bool found = false;
        for (int i = 0; i < plist.size(); i++)
        {
            int cval = plist[i];
            
            if (!use[cval]) continue;
            use[cval] = false;
            found = true;
            
            nxt[prv[cval]] = nxt[cval];
            prv[nxt[cval]] = prv[cval];
            
            if (prv[cval] >= 1 && nxt[cval] <= N && num[prv[cval]] > num[nxt[cval]])
                nlist.push_back (nxt[cval]);
        }
        
        if (!found) break;
        
        plist.clear();
        for (int i = 0; i < nlist.size(); i++)
            plist.push_back (nlist[i]);
        nlist.clear();
        count++;
    }
    
    cout << count << "\n";
    return 0;
}
