#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define tt int testcase; cin>>testcase; while(testcase--)
#define FORN(i,m,n) for(int i = (m); i < (int)n; i++)

int x, y, d, x_0, y_0, k, total_s{0}, total_t{0};
int p, m, n, t;

int gcd(int a, int b){ return (b==0 ? a : gcd(b, a%b)); }
bool isInteger(double a){ return (a-int(a))==0 ? true : false;}

void extendedEuclid(int a, int b){
    if(b==0) {x = 1;  y = 0; d = a; return;}
    extendedEuclid(b, a%b);
    int x1=y, y1=x-(a/b)*y;
    x=x1; y=y1;
}

int get_k(double l, double r){
    int k=0;
    FORN(i,l,r+1){
        int xd = ((x_0+((n*i)/d)) + (y_0-((m*i)/d)));
        if( xd == p){ k = i; break; }
    }
    return k;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    tt{
        cin>>p>>m>>n>>t;
        d=gcd(m,n);
        extendedEuclid(m, n);
        x_0 = x*(t/d);
        y_0 = y*(t/d);
        if(!(x > 0 && y > 0) && (x+y!=p)){
            double l = (x*(t/d))/(n/d), r = (y*(t/d))/(m/d);
            l=abs(l); r=abs(r);
            if(r<l) swap(l,r);
            k = get_k(l,r);
            total_s+=x_0+((n*k)/d); total_t+=y_0-((m*k)/d);
        }
        else{ total_s+=x; total_t+=y; }
    }
    cout<<total_s<<" "<<total_t;
}