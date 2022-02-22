//C++ program to count strings que no tengan 11 como patrón
#include <iostream>

using namespace std;

size_t n, n_sets{0};

void count_sets(int i, string word){
    if(i == n+1) return;
    count_sets(i+1, word+'0');
    if(word[i-1]=='1') { n_sets++; return;}
    count_sets(i+1, word+'1');
    return;
}

int main(){
    string word = "0";
    cin>>n;
    count_sets(1,word);
    cout<<n_sets<<endl; 
}