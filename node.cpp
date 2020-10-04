#include <vector> 
#include <iostream>
int cont =0;

using namespace std;
template<typename T>
struct NodeB{
    int grade=0; 
    T key;
    vector<NodeB<T>*> children;
    NodeB<T>* parent;

    NodeB(T key1):key(key1),parent(nullptr){};

    void print(){
        for(auto it:children){
            it->print();
        }
        cout<<key<<" ";
        
    }
    
    
    void decreaseKey(){
        if(parent==nullptr)return;
        if(parent->key>this->key){
            parent->key=this->key;
            parent->decreaseKey();
        }
    }

    NodeB<T>* find(T number){
        if (this->key==number){ 
            return this;
        }
        NodeB<T>* retorno=nullptr;
        for(auto it:children){
            retorno=it->find(number);
            if(retorno!=nullptr)break;
        }
        return retorno;
        
    }

    void omegaprint(){
        void print(){
            for(auto it:children){
                it->print();
            }
            cout<<key<<" ";
        }
    }
};