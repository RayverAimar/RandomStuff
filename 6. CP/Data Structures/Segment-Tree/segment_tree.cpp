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

const int ms = 1e5+5;

const int n=9;
int s_tree[ms<<1], nodes[ms];

void build(int cur_node, int s, int e){
    if(s==e) s_tree[cur_node] = nodes[s];
    else{
        int l = cur_node<<1, r = cur_node<<1|1;
        build(l, s, (s+e)>>1);
        build(r, ((s+e)>>1) + 1, e);
        s_tree[cur_node] = max(s_tree[l],s_tree[r]);
    }
}

void print(){
    FORN(i,1,18) cout<< s_tree[i] <<" ";
}

int main(){
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int B[n] = {1,5,6,2,4,16,21,15,67};
    FORN(i,0,n) nodes[i]=B[i];
    build(1, 0, n-1);
    print();
}