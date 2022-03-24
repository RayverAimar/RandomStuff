#include <iostream>
#include <string>

using namespace std;

#define FORN(i,m,n) for(int i = (m); i < (int)n; i++)
const int mod = 131071;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string n;
    int temp=0;
    while(cin>>n){
        FORN(i,0,n.length()){
            if(n[i]=='#'){
                cout<<(temp==0?"YES":"NO")<<"\n";
                temp=0;
            }
            else if(n[i]=='1'|| n[i]=='0'){
                temp=((temp<<1)+n[i]-'0')%mod;
            }
        }
    }
}