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

const int n=10;
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

void update(int u, int v){
    for(s_tree[u+=n]=v; u>1; u>>=1)
        s_tree[u>>1] = max(s_tree[u], s_tree[u+1]);
}

int query(int cur_node, int lBound, int rBound, int lQ, int rQ) {
    if (lQ > rBound || rQ < lBound) return -1; // No overlap
    if (lBound >= lQ && rBound <= rQ) return s_tree[cur_node]; // Total Overlap
    int l = query(cur_node<<1, lBound , (lBound + rBound)>>1, lQ, rQ); //Partial Overlap
    int r = query(cur_node<<1|1, ((lBound + rBound)>>1)+1, rBound , lQ, rQ); //Partial Overlap
    if (l == -1) return r; 
    if (r == -1) return l;
    return max(l,r);
}

void print(){
    FORN(i,1,n*4) cout<< s_tree[i] <<" ";
}

int main(){
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int B[n] = {-1,-1,1,1,1,1,3,10,10,10};
    FORN(i,0,n) nodes[i]=B[i];
    build(1, 0, n-1);
    cout<<query(1,0,n-1,2,6)<<endl;
    print();
}