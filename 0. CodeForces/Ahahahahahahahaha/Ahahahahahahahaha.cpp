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

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    tt{
        int n;
        cin>>n;
        int*a = new int[n];
        map<int,int> m;
        FORN(i,0,n){
            cin>>a[i];
            m[a[i]]++;
        }
        if(m[0]>=m[1]){
            cout<<n/2<<"\n";
            FORN(i,0,n/2) cout<<0<<" ";
            cout<<"\n";
        }
        else{
            int mid=n/2;
            if(mid%2 !=0) mid++;
            cout<<mid<<"\n";
            FORN(i,0,mid) cout<<1<<" ";
            cout<<"\n";
        }
    }

}