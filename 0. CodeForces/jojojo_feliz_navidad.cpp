#include <iostream>
#include <string>
#include <vector>

using namespace std;
#define tt long long testcase; cin>>testcase; while(testcase--)
#define FORN(i,m,n) for(int i=(m); i<int(n); i++)

int y;
const int ms = 1e3+5;
vector<char> actions(ms);

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin>>n;
    FORN(i,0,n){
        string name;
        int count_b{0};
        cin>>name;
        cin>>y;
        FORN(j,0,y){
            cin>>actions[j];
            if(actions[j]=='B') count_b++;
        }
        cout<<name<<(count_b > 2*(y-count_b) ? " REGALO" : " CARBON")<<"\n";
    }
}