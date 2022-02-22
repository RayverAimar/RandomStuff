#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define INF 1e9

vector<int> change;
int arr[3] = {2,3,5};

int coins(int n){
    if (n < 0) return INF;
    if (!n) return n;
    return 1 + min(coins(n-arr[0]), min(coins(n-arr[1]), coins(n-arr[2])));
}

int main(){
    int n;
    cin>>n;
    cout<<coins(n)<<endl;
}