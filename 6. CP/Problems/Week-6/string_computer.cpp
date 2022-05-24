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
#include <cstring>

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
const int ms = 22;

int dp[ms][ms];

void edit_distance(string a, string b){
    FORN(i,0,a.size()+1){
        FORN(j,0,b.size()+1){
            if(j==0 || i == 0) dp[i][j] = i+j;
            else if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string a;
    while(cin>>a){
        if (a[0] == '#') break;
        string b; cin>>b;
        edit_distance(a,b);
        int i = a.size(),j=b.size();
        while(i>0 || j>0){
            if(a[i-1] == b[j-1]){
                --i, --j;
            }
            else if(i>0 && j>0 && dp[i][j] == dp[i-1][j-1]+1){
                cout<<"C"<<b[--j];
                if(i<9) cout<<"0";
                cout<<i--;
            }
            else if(i>0&& dp[i][j] == dp[i-1][j]+1){
                cout<<"D"<<a[i-1];
                if(i<9) cout<<"0";
                cout << i--;
            }
            else if(j>0 && dp[i][j] == dp[i][j-1]+1){
                cout<<"I"<<b[--j];
                if(i<8) cout<<"0";
                cout<<i+1;
            }
        }
        cout<<"E\n";
    }
}