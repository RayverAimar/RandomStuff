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

int s_tree[ms<<2], nodes[ms];
map<int, int> m, lst;

void build(int cur_node, int s, int e){
    if(s==e) s_tree[cur_node] = nodes[s];
    else{
        int l = cur_node<<1, r = cur_node<<1|1;
        build(l, s, (s+e)>>1);
        build(r, ((s+e)>>1) + 1, e);
        s_tree[cur_node] = max(s_tree[l],s_tree[r]);
    }
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


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while(true){
        int n, q;
        cin>>n;
        if(!n) break;
        cin>>q;
        int t[n+5];
        m.clear();
        lst.clear();
        FORN(i,1,n+1){
            cin>>t[i];
            m[t[i]]++;
            lst[t[i]]=i;
            nodes[i]=m[t[i]];
        }
        build(1,1,n);
        while(q--){
            int l, r, f, s, lst_l_app, ans;
            cin>>l>>r;
            lst_l_app = lst[t[l]];
            f = min(lst_l_app,r)-l+1;
            s = query(1,1,n, lst_l_app+1,r);
            ans = (f > s) ? f : s;
            cout<<ans<<"\n";
        }
    }
}