#include <iostream>
#include <string>
#include <stdlib.h>
#include <utility>
#include <vector>

using namespace std;
#define tt long long testcase; cin>>testcase; while(testcase--)
#define FORN(i,m,n) for(int i=(m); i<int(n); i++)

int y;

string solve(vector<char> actions){
    int count_b{0}, count_m{0};
    FORN(i,0,y) actions[i]=='B' ? count_b++ : count_m++;
    return (2*count_m < count_b) ? "REGALO" : "CARBON"; 
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin>>n;
    FORN(i,0,n){
        string name;
        cin>>name;
        cin>>y;
        vector<char> actions(y);
        FORN(j,0,y) cin>>actions[j];
        cout<<name<<" "<<solve(actions)<<endl;
    }
}