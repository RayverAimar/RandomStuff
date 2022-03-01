#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

#define FORN(i,m,n) for(int i=(m); i<int(n); i++)

const int ms = 1e5+5;
int p[ms], m[ms], n[ms], t[ms], x[ms], y[ms], a{0}, b{0};

void solve(int i){
    int c=abs(m[i]), d=abs(n[i]);
    int c1=1, d1=0, c2=0, d2=1;
    while(d){
        int q=c/d, r =c-(q*d),
        r1=c1-q*d1, r2=c2-q*d2;
        c=d; c1=d1; c2=d2;
        d=r; d1=r1; d2=r2;
    }
    a+=c1; b+=c2;
}

int main(){
    int d;
    cin>>d;
    FORN(i,0,d) cin>>p[i]>>m[i]>>n[i]>>t[i];
    FORN(i,0,d) solve(i);
    cout<<a<<" "<<b<<endl;
}
