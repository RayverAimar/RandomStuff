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

const int inf = 1e9+5;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    tt{
        int l,r,k;
        cin>>l>>r>>k;
        if(l == 1 && r == 1) {cout<<"NO\n"; continue;}
        if(l == r) {cout<<"YES\n"; continue;}
        int n = (r-l+1)/2;
        if(l%2 && r%2) n++;
        cout<<(n<=k?"YES":"NO")<<"\n";
    }
}