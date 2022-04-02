#include <iostream>
#include <cmath>
#include <random>
#include <map>
#include <string>
#include <fstream>

using namespace std;

const int n_elements = 20000;
const int n_dims = 100; // 1 2 3 4 5 6 7 8 9 10 20 30 40 50 60 70 80 90 100

struct Point_ND{
    int *dim;
    Point_ND();
    void print();
};

Point_ND::Point_ND() {
    dim = new int[n_dims];
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<>distrib(1,100);
    for(int i = 0; i < n_dims; i++)
        dim[i]=distrib(gen);
}

void Point_ND::print(){
    for(int i = 0; i < n_dims; i++)
        cout<<i<<"th dimension: "<<dim[i]<<"\n";
}

int dist(Point_ND p, Point_ND q){
    int ans = 0;
    for(int i = 0; i < n_dims; i++){
        ans+= pow(p.dim[i]-q.dim[i], 2);
    }
    return sqrt(ans);
}

int main(){
    string name = to_string(n_dims) + "_dimensions.csv";
    Point_ND* ptr;
    ptr = new Point_ND[n_elements];
    map<int ,int> mp;
    for(int i = 1; i<n_elements; i++)
        mp[dist(ptr[0], ptr[i])]++;
    ofstream file(name);
    for (auto it = mp.begin(); it != mp.end(); ++it)
        file <<it->first<<","<<it->second <<"\n";
    file.close();
}