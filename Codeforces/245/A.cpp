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
#include <cstring>
using namespace std;

template<class T> T gcd(T a,T b)
{
    if(a<0) return gcd(-a,b);
    if(b<0)return gcd(a,-b);
    return (b==0)?a:gcd(b,a%b);
}
template <class T> T lcm(T a,T b)
{
    return a*(b/gcd(a,b));
}
template<class T> inline vector<pair<T,int> > factorize(T n)
{
    vector<pair<T,int> > R;
    for (T i=2; n>1;)
    {
        if (n%i==0)
        {
            int C=0;
            for (; n%i==0; C++,n/=i);
            R.push_back(make_pair(i,C));
        }
        i++;
        if (i>n/i) i=n;
    }
    if (n>1) R.push_back(make_pair(n,1));
    return R;
}
template<class T> inline bool isPrimeNumber(T n)
{
    if(n<=1)return false;
    for (T i=2; i*i<=n; i++) if (n%i==0) return false;
    return true;
}
template<class T> inline T eularFunction(T n)
{
    vector<pair<T,int> > R=factorize(n);
    T r=n;
    for (int i=0; i<R.size(); i++)r=r/R[i].first*(R[i].first-1);
    return r;
}
template<class T> string toString(T n)
{
    ostringstream ost;
    ost<<n;
    ost.flush();
    return ost.str();
}
int toInt(string s)
{
    int r=0;
    istringstream sin(s);
    sin>>r;
    return r;
}

int i,j,k;
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
int dirx[]= {1, 1, 0,-1,-1,-1,0,1};
int diry[]= {0,-1,-1,-1, 0, 1,1,1}; //clockwise

/*

The problem asks you to output “-1” if there is no solution.
 A natural question is now: “when there is no solution”? Try to come up with a test like this!

After some analysis, you’ll see anyhow we draw the points and the lines,
there will always be a solution.
By manually solving small cases, you might already have found the pattern.
But for now, let’s assume anyhow we draw points and lines, there will always be a solution.

 Let’s have a fixed set of points. Then, anyhow we draw a line, there should still be a solution.
  So, we need to find a coloring of points, such as for every line,
  |number of red points which belong to it – number of blue points which belong to it| <= 1.

Suppose anytime you color a point with red you assign it +1 value.
 Also, anytime you color it with blue you assign it -1 value.
  Then, for a segment, the drawing is good if S =
  sum of values assigned to points that belong to segment is between -1 and 1 (in other words |S| <= 1).

  Let’s sort points increasing by abscissa.
   It’s useful because now, for a segment, there will be a contiguous range of points that belong to that segment.
   For example, suppose my current segment is [3, 7] and the initial set of points was {4, 1, 5, 2, 8, 7}.
   Initially, points that belong to the segment would be first, third and sixth. Let’s sort the points by abscissa. It looks like {1, 2, 4, 5, 7, 8}. You can see now there is a contiguous range of points that belongs to [3, 7] segment: more exactly third, fourth and fifth.

We reduced problem to: given an array, assign it either +1 or -1 values such as, for each subarray (contiguous range),
 the sum S of subarray’s elements follows the condition |S| <= 1.
 Before reading on, try to come up with an example by yourself.

My solution uses the pattern: +1 -1 +1 -1 +1 -1 ...
Each subarray of it will have sum of its elements either -1, 0 or 1.
 How to proof it? When dealing with sums of subarrays, a good idea is to use partial sums.
  Denote sum[i] = x[1] + x[2] + ... + x[i]. Then, sum of a subarray [x, y] is sum[y] – sum[x – 1]. Partial sums for the pattern looks like: 1 0 1 0 1 0 .... Hence, there are 4 possible cases:

1/ sum[x – 1] = 0 and sum[y] = 0. sum[y] – sum[x – 1] = 0

2/ sum[x – 1] = 1 and sum[y] = 1. sum[y] – sum[x – 1] = 0

3/ sum[x – 1] = 0 and sum[y] = 1. sum[y] – sum[x – 1] = 1

4/ sum[x – 1] = 1 and sum[y] = 0. sum[y] – sum[x – 1] = -1

Hence, each subarray sum is either -1, 0 or 1.
So, general algorithm looks like:
sort points by abscissa, assign them red, blue, red, blue, ...
and then sort them back by original order and print the colors.

Iahub isn't well prepared on geometry problems, but he heard that this year there will be a lot of geometry problems on the IOI selection camp. Scared, Iahub locked himself in the basement and started thinking of new problems of this kind. One of them is the following.

Iahub wants to draw n distinct points and m segments on the OX axis.
 He can draw each point with either red or blue.
 The drawing is good if and only if the following requirement is met: for each segment [li, ri] consider all the red points belong to it (ri points), and all the blue points belong to it (bi points); each segment i should satisfy the inequality |ri - bi| ≤ 1.

Iahub thinks that point x belongs to segment [l, r], if inequality l ≤ x ≤ r holds.

Iahub gives to you all coordinates of points and segments. Please, help him to find any good drawing.

Input
The first line of input contains two integers: n (1 ≤ n ≤ 100) and m (1 ≤ m ≤ 100).
The next line contains n space-separated integers x1, x2, ..., xn (0 ≤ xi ≤ 100) — the coordinates of the points.
 The following m lines contain the descriptions of the m segments.
  Each line contains two integers li and ri (0 ≤ li ≤ ri ≤ 100) — the borders of the i-th segment.

It's guaranteed that all the points are distinct.

Output
If there is no good drawing for a given test, output a single integer -1.
Otherwise output n integers, each integer must be 0 or 1. The i-th number denotes the color of the i-th point (0 is red, and 1 is blue).

If there are multiple good drawings you can output any of them.


*/
int main()
{
    ios_base::sync_with_stdio(0);
//    freopen("1.txt","r",stdin);
    int n,m;
    cin>>n>>m;
    vector<pair<int,int> > p(n);
    vector<int> ret(n);
    for(int i=0; i<n; i++)
    {
        cin>>p[i].first;
        p[i].second = i;
    }
    sort(p.begin(), p.end());
    int a,b;
    for(int i=0; i<m; i++) cin>>a>>b;
    for(int i=0; i<n; i++)
    {
        if(i%2==0)
        {
            ret[p[i].second] = 0;
        }else ret[p[i].second] = 1;
//        else cout<<1<<" ";
    }
    for(int i=0; i<n; i++) cout<<ret[i]<<" ";
    cout<<endl;

    return 0;
}
