//C++ program to make all possible words given its max length
#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int total = 1 << n;
    for(int mask = 0; mask < total; mask++){
        for(int i = n - 1; i >= 0; i--){
            int f = 1 << i;
            if(f & mask) cout<< 1;
            else cout << 0;
        }
        cout<<endl;
    }
}