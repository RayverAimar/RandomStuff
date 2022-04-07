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
 
string solve()
{
    string str;
    map<char, bool> m{{'r',0},{'g',0},{'b',0}};
    cin>>str;
    FORN(i,0,6){
        if(str[i]<91){
            str[i]+=32;
            if(!m[str[i]]) return"NO\n";
        }
        else{
            m[str[i]]=true;
        }
    }
    return "YES\n";
}
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    tt{
        cout<<solve();
    }
 
}