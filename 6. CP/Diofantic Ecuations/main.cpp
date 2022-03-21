#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <bitset>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;


#define FORN(i,m,n) for(int i = (m); i < (int)n; i++)
#define PRINTVEC(v) FORN(i,0,v.size()) cout<<v[i]<<" "; cout<<"\n";
#define pb(x) push_back(x)
#define mp  make_pair

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;

const int inf = 1e9+5;
const int ms = 1e9 +5;

ll sieve_size;
bitset<ms> bs;
vi primes;
int x, y, d, x_0, y_0, d, p;
int m, n , t, k;

int gcd(int a, int b){ return (b==0 ? a : gcd(b, a%b)); }
bool isInteger(double a){ return (a-int(a))==0 ? true : false;}

void extendedEuclid(int a, int b){
    if(b==0) {x = 1;  y = 0; d = a; return;}
    extendedEuclid(b, a%b);
    int x1=y, y1=x-(a/b)*y;
    x=x1; y=y1;
}

int get_k(double l, double r){
    l=abs(l); r=abs(r);
    if(r<l) swap(l,r);
    if(!isInteger(l)) l+=1;
    int n=0;
    FORN(i,l,r+1){
        int xd = ((x_0+((n*i)/d)) + (y_0-((m*i)/d)));
        if( xd == p){ n = i; break; }
    }
    return n;
}

int main(){
    
    cin>>p>>m>>n>>t;
    d=gcd(m,n);
    extendedEuclid(m, n);
    x_0 = x*(t/d);
    y_0 = y*(t/d);
    if(!(x > 0 && y > 0)){
        double l = (x*(t/d))/(n/d), r = (y*(t/d))/(m/d);
        k = get_k(l, r);
    }
    cout<< x_0+((n*k)/d)<<" "<<y_0-((m*k)/d);
}