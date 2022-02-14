//C++ program to make words by giving it its max length
#include <iostream>

using namespace std;

void make_words(string word, int n){
    if(word.size() == n){
        cout << word << endl;
        return;
    }
    make_words(word + '0', n);
    make_words(word + '1', n );
}

int main(){
    string word = "";
    make_words(word, 3);
}
