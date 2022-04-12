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
#define ff first
#define ss second

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;

const int ms = 1e5+5;
const int max_nodes = 8;
int santa[5][5]= {  {0,1,1,0,1},
                    {1,0,1,0,1},
                    {1,1,0,1,1},
                    {0,0,1,0,1},
                    {1,1,1,1,0}};

void dfs(int cur_node, int n_nodes, string str){
    str+= ((cur_node+1) + '0');
    if(n_nodes == max_nodes) cout<<str<<"\n";
    for(int i = 0; i<5; i++){
        if(santa[cur_node][i]){
            santa[cur_node][i]=santa[i][cur_node]=0;
            dfs(i,n_nodes+1,str);
            santa[cur_node][i]=santa[i][cur_node]=1;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string str = "";
    dfs(0,0,str);
}