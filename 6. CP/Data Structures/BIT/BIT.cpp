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

size_t n;
vi bit, ar;

int query(int u){
    int ans{0};
    for(int i = u; i >0 ; i ^= (i&-i)) ans+=bit[i];
    return ans;
}

int query(int l, int r){
    if(!l) return query(r);
    return query(r)-query(l-1);
}

void update(int u, int val){
    int diff = val-ar[u];
    for(int i = u; i <= bit.size(); i += (i&-i))
        bit[i]+=diff;
}

void add(int u, int val){
    for(int i = u; i <= bit.size(); i += (i&-i))
        bit[i]+=val;
}

void print_bit(){
    for(int i = 0; i<bit.size(); i++)
        cout<<bit[i]<<" ";
    cout<<endl;
}

void build(){
    for(int i = 1;  i < n+1; i++){
        int pid = i + (i&-i);
        if(pid <= n+1) bit[pid] = bit[pid] + bit[i];
    }
}

int main(){
    cin>>n;
    ar = bit = vi(n+2);
    FORN(i,1,n+1){
        cin>>ar[i];
        bit[i]=ar[i];
    }
    build();
    update(2,4); //Updating the value in ar[2] to 4
    print_bit();
    cout<<endl<<query(5,11)<<endl;
}