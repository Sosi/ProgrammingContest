// BEGIN CUT HERE

// END CUT HERE
#line 5 "DistinguishableSetDiv2.cpp"
#include <bits/stdc++.h>
using namespace std;
class DistinguishableSetDiv2
{
public:
int count(vector <string> answer)
{
    int num = answer[0].size();
    int ret = 0;
    for(int i= 0; i< (1<<num); i++)
    {
        set<string> C;
        for(int j = 0; j< answer.size(); j++)
        {
            string ans = "";
            for(int k = 0; k< num; k++)
            {
                if(i& (1<<k)) ans += answer[j][k];
            }
            C.insert(ans);
        }
//        cout<<i<<" "<<endl;
        if(C.size() == answer.size()) ret++;
    }
    return ret;
//$CARETPOSITION$
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"AA","AB","CC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { string Arr0[] = {"XYZ","XYZ","XYZ"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { string Arr0[] = {"AAAA","BACA","CDCE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 11; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { string Arr0[] = {"HGHHGUHUHI","BQHJWOSZMM","NDKSKCNXND","QOEOEIWIDS","IIQIWUNNZM"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1017; verify_case(3, Arg1, count(Arg0)); }
	void test_case_4() { string Arr0[] = {"XYZ","XAB","YAC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(4, Arg1, count(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
DistinguishableSetDiv2 ___test;
___test.run_test(-1);
system("pause");
}
// END CUT HERE
