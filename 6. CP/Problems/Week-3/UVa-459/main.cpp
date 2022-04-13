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

#define tt int testcase; cin>>testcase; getchar();while(testcase--)
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

vector<vector<size_t>> graph;
size_t n_nodes;
vector<bool> visited;


void dfs(int u){
    visited[u]= true;
    for(int neighbor : graph[u]){
        if(!visited[neighbor])
            dfs(neighbor);
    }
}

int connected_components(){
    int ans{0};
    visited = vector<bool>(n_nodes, 0);
    for(int i = 0; i < n_nodes; i++){    
        if(!visited[i]){
            dfs(i);
            ans++;
        }    
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    tt{
        char max_bound;
        cin>>max_bound;
        int it=0;
        map<char, int> node_names;
        FORN(i,65, max_bound+1) node_names[i]=it++;
        n_nodes = int(max_bound) - 64;
        graph = vector<vector<size_t>>(n_nodes, vector<size_t>());
        string str;
        cin.ignore();
        while(getline(cin, str) && str != ""){
            graph[node_names[str[0]]].push_back(node_names[str[1]]);
            graph[node_names[str[1]]].push_back(node_names[str[0]]);
        }
        cout << connected_components()<<"\n";
        if(testcase) cout<<"\n";
    }
    
}