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
int A[100], B[100], n1, n2, dp[101][101];;

int lcs(int size_A, int size_B){
    FORN(i,1,size_A+1){
        FORN(j,1,size_B+1){
            if(A[i-1]==B[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[size_A][size_B];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n1, n2, t=1;
    while(cin>>n1>>n2){
        if(!n1 && !n2) break;
        memset(dp, 0, sizeof(dp));
        FORN(i,0,n1) cin>>A[i];
        FORN(i,0,n2) cin>>B[i];
        cout<<"Twin Towers #"<<t++<<"\n";
        cout<<"Number of Tiles : "<<lcs(n1, n2)<<"\n\n";
    }
}