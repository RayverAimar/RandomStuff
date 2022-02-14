//C++ program to make all possible subsets of an alphabet
#include <iostream>

using namespace std;

int main(){
    string alphabet = "";
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        char vowel;
        cin >> vowel;
        alphabet+=vowel;
    }
    int total = 1 << n;
    for(int mask = 0; mask < total; mask++){
        for(int i = 0; i < n; i++){
            int f = 1 << i;
            if(mask & f) cout << alphabet[i];
        }
        cout<<endl;
    }
}