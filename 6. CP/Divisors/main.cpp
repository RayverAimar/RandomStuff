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

#define tt int testcase; cin>>testcase; while(testcase--)
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

const int ms = 1e9 +5;

ll sieve_size;
bitset<ms> bs;
vi primes;
int l, u;

void sieve(ll upperbound){
    sieve_size = upperbound+1;
    ll square_root =  sqrt(sieve_size);
    bs.set(); bs.set(0, false); bs.set(1, false);
    FORN(i,2,sieve_size)
        if(bs.test((size_t)i)){
            if(i <= square_root){
                for(ll j = i * i; j < sieve_size; j+=i)
                    bs.set((size_t)j, false);
            }
            primes.emplace_back(i);
        }
}

int n_factors(int N){
    int idx = 0, pf = primes[idx], ans=1;
    while(N!=1 && (pf*pf <= N)){
        int d=0;
        while(N%pf == 0){
            N/=pf;
            d++;
        }
        pf = primes[++idx];
        ans*=(++d);
    }
    if(N!=1) ans*=2; //N is a prime
    return ans;
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    sieve(35000);
    tt{
        cin>>l>>u;
        int p=0, d = 0;
        FORN(i,l,u+1){
            int temp=n_factors(i);
            if(temp>d){
                d = temp;
                p = i;
            }
        }
        cout<<"Between " <<l<< " and " <<u<<", "<<p<<" has a maximum of "<<d<<" divisors."<<endl;
    }
}