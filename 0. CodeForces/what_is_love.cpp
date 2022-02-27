#include <iostream>
#include <string>
using namespace std;

#define FORN(i,m,n) for(int i=(m); i<int(n); i++)
#define PRINTARR(a,n) FORN(i,0,n) cout<<a[i]<<" "; cout<<endl

int n, ans[505];

void solve(string s, string w){
    int it{0};
    FORN(i,0,n)
        if(w[i]==s[it]){
            ans[it]=i;
            it++;
        }
    if(it == s.size()){
        cout<<"YES"<<"\n";
        PRINTARR(ans,it);
    }
    else cout<<"NO"<<"\n";
}

int main(){
    string s, w;
    cin>>n;
    cin.ignore();
    getline(cin, s);
    getline(cin, w);
    solve(s,w);
}
