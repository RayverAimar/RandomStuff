#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <utility>
#include <cmath>
#include <iomanip>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;


//CNode Implementation

template<class T>
struct CNode{
    T m_v;
    //int level;
    CNode<T>* m_children[2];

    //Constructors
    CNode(T _v);
};

template<class T>
CNode<T>::CNode(T _v): m_v(_v){
    m_children[0] = m_children[1] = 0;
}

//CBinTree Implementation

template<class T>
struct CBinTree{

    //Constructors & Destructors
    CBinTree();
    ~CBinTree();

    //primary functions
    bool find(T x, CNode<T>** &p);
    bool insert(T x);
    bool remove(T x);

    //Secondary functions
    void podar(CNode<T>* p, int n);

    //Traversal functions
    void pre_order(CNode<T>* n);
    void in_order(CNode<T>* n);
    void post_order(CNode<T>* n);
    void reverse_order(CNode<T>* n);
    
    //Printing functions
    void print_levels(CNode<T>* n);
    void print_tree(CNode<T>* n);
    void print_node(pair<CNode<T>*, int> n, int lvl, int &spaces, int height);

    //Getters
    CNode<T>* get_root();
    CNode<T>** get_nearest_CNode(CNode<T>** p);
    int getMaxDepth(CNode<T>* n);

private:
   CNode<T>* m_root;
};

template<class T>
CBinTree<T>::CBinTree(): m_root(nullptr) {}

template<class T>
CBinTree<T>::~CBinTree(){}

template<class T>
CNode<T>* CBinTree<T>::get_root(){ return m_root; }

template<class T>
bool CBinTree<T>::find(T x, CNode<T>** &p){
    for(p = &m_root; *p && (*p)->m_v != x; p = &((*p)->m_children[(*p)->m_v < x]));
    return *p;
}

template<class T>
bool CBinTree<T>::insert(T x){
    CNode<T>** p;
    if(find(x, p)) return 0;
    *p = new CNode<T>(x);
    return 1;
}

template<class T>
CNode<T>** CBinTree<T>::get_nearest_CNode(CNode<T>** p){
    srand(unsigned(time(0)));
    int i = rand() % 2;
    for (p = &((*p)->m_children[!i]) ; (*p)->m_children[i]; p = &(*p)->m_children[i]);
    return p;
}

template<class T>
bool CBinTree<T>::remove(T x){
    CNode<T>** p;
    if(!find(x,p)) return 0;
    if((*p)->m_children[0] && (*p)->m_children[1]){
        CNode<T>** q = get_nearest_CNode(&m_root);
        (*p)->m_v = (*q)->m_v;
        p = q;
    }
    CNode<T>* temp = *p;
    *p = (*p)->m_children[ (*p)->m_children[1] != 0 ];
    delete temp;
    return 1;
}

template<class T>
void CBinTree<T>::pre_order(CNode<T>* n){
    if(!n) return;
    cout << n->m_v<<" ";
    pre_order(n->m_children[0]);
    pre_order(n->m_children[1]);
}

template<class T>
void CBinTree<T>::in_order(CNode<T>* n){
    if(!n) return;
    in_order(n->m_children[0]);
    cout << n->m_v<<" ";
    in_order(n->m_children[1]);
}

template<class T>
void CBinTree<T>::post_order(CNode<T>* n){
    if(!n) return;
    post_order(n->m_children[0]);
    post_order(n->m_children[1]);
    cout << n->m_v<<" ";
}

template<class T>
void CBinTree<T>::reverse_order(CNode<T>* n){
    if(!n) return;
    reverse_order(n->m_children[1]);
    cout << n->m_v<<" ";
    reverse_order(n->m_children[0]);
}

template<class T>
void CBinTree<T>::print_levels(CNode<T>* n){
    if(!m_root) return;
    queue<pair<CNode<T>*, int>> q;
    int current_lvl{0};
    q.push({n, current_lvl});
    while(!q.empty()){
        if(q.front().first){
            if(q.front().second != current_lvl){ cout << endl; current_lvl++; }
            cout<< q.front().first->m_v<<" ";
            q.push({q.front().first->m_children[0], q.front().second + 1});
            q.push({q.front().first->m_children[1], q.front().second + 1});            
        }
        q.pop();
    }
}

template<class T>
int CBinTree<T>::getMaxDepth(CNode<T>* n){
    return !n ? 0 : 1 + max(getMaxDepth(n->m_children[0]), getMaxDepth(n->m_children[1]));
}

template<class T>
void CBinTree<T>::print_node(pair<CNode<T>*, int> n, int current_depth, int &spaces, int height){
    if(n.second == current_depth){
        cout<<setw(spaces)<<n.first->m_v;
        spaces = pow(2, height - (current_depth-3));
        return;
    }
    if(n.first->m_children[0]) print_node({n.first->m_children[0], n.second+1}, current_depth, spaces, height);
    else if(n.second <= current_depth - 1) spaces = spaces + pow(2, height - n.second + 2);
    if(n.first->m_children[1]) print_node({n.first->m_children[1], n.second+1}, current_depth, spaces, height);
    else if(n.second <= current_depth - 1) spaces = spaces + pow(2, height - n.second + 2);
}

template<class T>
void CBinTree<T>::print_tree(CNode<T>* n){
    int height = getMaxDepth(n);
    for(int current_depth = 1; current_depth <= height; current_depth++){
        int spaces = pow(2, height - (current_depth-2));
        print_node({n, 1}, current_depth, spaces, height);
        cout<<"\n";
    }
}

int main(){
    CBinTree<int> myTree;
    srand(time(NULL));
    myTree.insert(5000);
    for(size_t i =0; i < 100; i++){
        int t = rand() %9000 + 1000;
        myTree.insert(t);
    }
    if(myTree.getMaxDepth(myTree.get_root())>12)
    {
        cout<<"Nope :(";
        return 0;
    }
    cout<<"Height: "<<myTree.getMaxDepth(myTree.get_root())<<"\n";
    myTree.print_tree(myTree.get_root());
}