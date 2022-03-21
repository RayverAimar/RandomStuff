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

void sieve(ll upperbound){
    sieve_size = upperbound+1;
    ll square_root =  sqrt(sieve_size);
    bs.reset(); bs.flip();
    bs.set(0, false); bs.set(1, false);
    FORN(i,0,sieve_size)
        if(bs.test((size_t)i)){
            if(i <= square_root){
                for(ll j = i * i; j < sieve_size; j+=i)
                    bs.set((size_t)j, false);
            }
            primes.emplace_back(i);
        }
}

vi primeFactors(int N){
    vi factors;
    int i = 0; int pf = primes[i];
    while(N!=1 && (pf*pf <= N)){
        while(N%pf == 0){
            N/=pf;
            factors.push_back(pf);
        }
        pf = primes[++i];
    }
    if(N!=1) factors.push_back(N);
    return factors;
}

int euler_phi(int n){
    vi factors = primeFactors(n);
    vi::iterator new_end = unique(factors.begin(), factors.end());
    int ans = n;
    for(auto it = factors.begin(); it != new_end; ++it)
        ans = ans - ans/(*it);
    return ans;
}

int main(){
    sieve(100);
    cout<<euler_phi(36);
}