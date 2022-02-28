#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;
#define FORN(i,m,n) for(int i=(m); i<int(n); i++)

int a{0}, b{0};

void solve(int p, int m, int n, int t){
    int x, y;
    FORN(i,0,p){
        x=i; y = p-x;
        if(m*x+n*y==t) break;
    }
    a+=x;b+=y;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int d,p,m,n,t;
    cin>>d;
    FORN(i,0,d){
        cin>>p>>m>>n>>t;
        solve(p,m,n,t);
    }
    cout<<a<<" "<<b<<endl;
}
