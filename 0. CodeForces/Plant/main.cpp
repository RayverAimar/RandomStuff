#include <iostream>

using namespace std;

typedef long long ll;

ll mod=1e9+7;

ll fast_exp(ll a, ll n){
    if(!n) return 1;
    if(n%2) return a*fast_exp(a,n-1)%mod;
    return fast_exp(a*a%mod,n/2);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n; cin>>n;
    n=fast_exp(2,n);
    cout<<(n*(n+1)/2)%mod;
}