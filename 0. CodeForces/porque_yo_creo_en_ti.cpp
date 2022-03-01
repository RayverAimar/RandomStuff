#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
#define tt long long testcase; cin>>testcase; while(testcase--)
#define FORN(i,m,n) for(ll i=(m); i<(n); i++)
typedef long long ll;

const int ms = 1e9+9;
int n, m_n;
vector<int> t[3], m;

void solve(){
    FORN(i,0,3) sort(t[i].begin(), t[i].end());
    FORN(i,0,m_n){
        FORN(j,0,3){
            int count{0};
            FORN(k,0,n){
                if(m[i]<t[j][k]) break;
                else count++;
            }
            cout<<count<<" "; 
        }
        cout<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>n;
    t[0] = t[1] = t[2] = vector<int>(n);
    FORN(i,0,n) cin>>t[0][i];
    FORN(i,0,n) cin>>t[1][i];
    FORN(i,0,n) cin>>t[2][i];
    cin>>m_n; m=vector<int>(m_n);
    FORN(i,0,m_n) cin>>m[i];
    solve();
}
