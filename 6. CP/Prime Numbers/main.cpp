//C++ program to print first n prime numbers using Eratosthenes' Sieve
#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>

typedef long long ll;
#define FORN(i,m,n) for(ll i = (m); i < (ll)n; i++)
#define vi vector<int>
using namespace std;

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

bool isPrime(ll n){
    if(n < sieve_size) return bs.test(n);
    FORN(i,0,primes.size())
        if(n%primes[i]==0) return false;
    return true;
}

int main(){
    sieve(10000);    
    cout<<isPrime(104233);
}