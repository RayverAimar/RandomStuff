#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
#define tt long long testcase; cin>>testcase; while(testcase--)
#define FORN(i,m,n) for(int i=(m); i<int(n); i++)

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long double a, b, h, ans, aux;
    cin>>a>>b>>h;
    ans=((a+b)/2)*h;
    auto decimal = modf(ans,&aux);
    if(!decimal) cout<<setprecision(0)<<fixed<<ans;
    else cout<<setprecision(1)<<fixed<<ans;
}