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
#include <tuple>
#include <cmath>
#include <iomanip>
using namespace std;

#define tt int testcase; cin>>testcase; while(testcase--)
#define FORN(i,m,n) for(int i = (m); i < (int)n; i++)
#define PRINTVEC(v) FORN(i,0,v.size()) cout<<v[i]<<" "; cout<<"\n";
#define eb(x) emplace_back(x)
#define ebp(x,y) emplace_back(x,y)
#define ebt(x,y,z) emplace_back(x,y,z)
#define mp  make_pair

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;

const int inf = 1e9+5;
const int ms = 1e5+5;
vector<pii> nodes;
vector<tuple<double, int , int>> edges;
vector<double> opt;

#define MAX_S 100
#define MAX_P 500

int parent[MAX_P], rnk[MAX_P];
int s, p;

int Find(int i){ return i==parent[i]?i:parent[i]=Find(parent[i]);}

void Union(int x, int y){
    if(rnk[x]<rnk[y]) swap(x,y);
    parent[y]=x;
    if(rnk[x]=rnk[y]) rnk[x]++;
}

double dist(pii a, pii b){
    double _x = a.first - b.first, _y = a.second - b.second;
    return sqrt((_x*_x)+(_y*_y));
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    tt{
        nodes.clear(); edges.clear(); opt.clear();
        int edges_size = 0, opt_size = 0;
        cin>>s>>p;
        FORN(i,0,p){
            int x, y;
            cin>>x>>y;
            nodes.ebp(x,y);
            parent[i]=i;
            rnk[i]=1;
        }
        FORN(i,0,p-1){
            FORN(j,i+1,p){
                edges.ebt(dist(nodes[i], nodes[j]), i,j);
                edges_size++;
            }
        }
        sort(edges.begin(), edges.end());
        FORN(i,0,edges_size){
            int start, end; double weight;
            tie(weight,start,end) = edges[i];
            start = Find(start); end=Find(end);
            if(start != end){
                Union(start,end);
                opt.eb(weight);
                opt_size++;
            }
        }
        cout<<fixed<<setprecision(2)<<opt[opt_size-s]<<"\n";
    }
}