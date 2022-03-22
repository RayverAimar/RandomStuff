#include <iostream>

using namespace std;

int fast_exp(int base, int exp){
    if(exp==1) return base;
    int t = fast_exp(base, exp>>1);
    return (exp&1)?t*t*base:t*t;
}

int fast_exp_v2(int base, int exp){
    if(exp==1) return base;
    int aux=base;
    base = fast_exp_v2(base, exp>>1);
    return base*base*(exp&1?aux:1);
}

int main(){
    cout<<fast_exp_v2(2,12);
}