
/** Solution template by user Dyatlov **/ 
/** BEGIN PRE-WRITTEN CODE **/ 
#include <stdio.h> 
#include <string.h> 
#include <math.h> 

#include <algorithm> 
#include <set> 
#include <string> 
#include <vector> 

#define FUP(i,l,r) for (int i=(l);i<=(r);i++) 
#define FOR(i,n) for (int i=0;i<(n);i++) 

#define SORT(a) stable_sort((a).begin(), (a).end()) 

using namespace std; 
/** END PRE-WRITTEN CODE **/ 

const double EPS = 1e-9; 

struct Point 
{ 
    double x, y; 
    bool operator<(const Point &a) const 
    { 
        return x + EPS < a.x || (x - EPS < a.x && y + EPS < a.y); 
    } 
    bool operator!=(const Point &a) const 
    { 
        return fabs(x - a.x) + fabs(y - a.y) > EPS; 
    } 
    void norm() 
    { 
        if (x < - EPS || (x < EPS && y < -EPS)) 
        { 
            x = -x; 
            y = -y; 
        } 
    } 
}; 

double sqr(double a) {return a * a;} 

class PizzaDivision 
{ 
    int n, x[50], y[50], res; 
    vector<Point> v1, v2, P; 
    void check(Point p) 
    { 
        v2.clear(); 
        FOR(i,n) 
        { 
            Point q; 
            double t = p.x * x[i] + p.y * y[i]; 
            q.x = x[i] - 2 * t * p.x; 
            q.y = y[i] - 2 * t * p.y; 
            v2.push_back(q); 
        } 
        SORT(v2); 
        FOR(i,n) 
            if (v1[i] != v2[i]) 
                return; 
        printf("%lf %lf\n", p.x, p.y); 
        ++res; 
    } 
    public: 
    int howMany(vector <string> toppings)   
    { 
        n = toppings.size(); 
        FOR(i,n) 
            sscanf(toppings[i].c_str(), "%d%d", &x[i], &y[i]); 
        if (n == 1) 
        { 
            if (!x[0] && !y[0]) 
                return -1; 
            return 1; 
        } 
        res = 0; 
        v1.clear(); 
        FOR(i,n) 
        { 
            Point p; 
            p.x = x[i]; 
            p.y = y[i]; 
            v1.push_back(p); 
        } 
        SORT(v1); 
        int k = (x[0] || y[0]) ? 0 : 1; 

        P.clear(); 
        FOR(i,n) 
            if (i == k) 
            { 
                double l = sqrt(sqr(x[i]) + sqr(y[i])); 
                Point z; 
                z.x = y[i] / l; 
                z.y = - x[i] / l; 
                z.norm(); 
                P.push_back(z); 
            } 
            else 
            { 
                double l = sqrt(sqr(x[i] - x[k]) + sqr(y[i] - y[k])); 
                Point z; 
                z.x = (x[i] - x[k]) / l; 
                z.y = (y[i] - y[k]) / l; 
                z.norm(); 
                P.push_back(z); 
            } 
        SORT(P); 
        FOR(i,P.size()) 
            if (!i || P[i] != P[i - 1]) 
                check(P[i]); 
        return res; 
    } 
}; 
