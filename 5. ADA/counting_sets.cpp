//C++ program to count strings which does not have 11 as pattern
#include <iostream>

using namespace std;

int count_sets(int n){
    int ans{0};
    for(int i = 1; i < 1<<n; i++){
        int count{0};
        for(int bm = 0; bm < n; bm++){
            if(1<<bm & i) count++;
            else count=0;
            if(count == 2) {ans++; break;}
        }
    }
    return (1<<n) - ans;
}

int main(){
    for(int i = 0; i < 10; i++)
        cout<<count_sets(i)<<endl;
}