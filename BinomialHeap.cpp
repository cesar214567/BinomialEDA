#include "node.cpp"
#include <bits/stdc++.h>
#include <unistd.h>

template< typename T>
class BinomialHeap{
    int size=0;
    int grade=0;
    multimap<int,NodeB<T>*> heap;
    NodeB<T>* min;
    
    NodeB<T>* unir(NodeB<T>* a,NodeB<T>* b){
        if(a->grade== grade){
            grade++;
        }
        if(a->key<b->key){
            a->children.push_back(b);
            b->parent=a;
            a->grade++;
            
            return a;
        }else{
            b->children.push_back(a);
            a->parent=b;
            b->grade++;
            return b;
        }
        
    }

    void compactar(){
        for(int i=0; i<=grade; i++){
            if(heap.count(i) > 1){
                auto itr = heap.find(i);
                auto first = itr->second;
                itr++;
                auto second= itr->second;
                NodeB<T>* ptr = unir(first, second);
                heap.erase(i);
                heap.insert({i+1,ptr});
            }
        }
    }

    void insert(NodeB<T>* elem){
        if(size==0 or min->key>elem->key){
            min=elem;
        }
        heap.insert({elem->grade,elem});
        compactar();
        size++;
    }

    NodeB<T>* findMin(){
        NodeB<T>* retorno=new NodeB<T>(INT_MAX);
        for(int i=0; i<=grade; i++){
            auto itr = heap.find(i);
            if(retorno->key > (*itr)->key){
                retorno = *itr;
            }
        } 
        return retorno;
    }
    
    void decreaseKey(NodeB<T>* from, T to){
        from->key=to;
        from->decreaseKey();
    }

public:

    BinomialHeap(){};

    void insert(T elem){
        insert(new NodeB<T>(elem));
    }
    
    T getMin(){
        return min->key;
    }

    void deleteMin(){
        print();
        for(auto it:min->children){
            this->insert(it);
            print();
        }
        heap.erase(min->grade);
        
    }

    void decreaseKey(T from, T to){
        for(int i=0; i<=grade; i++){
            if(heap.count(i) == 1){
                auto temp= heap.find(i);
                auto temp2 = (*temp).second->find(from);
                if(temp2!=nullptr){
                    decreaseKey(temp2,to);
                    break;
                }
            }
        }
    }
    

    void print(){
        for(auto it:heap){
            //cout<<"grado: "<<it.second->grade<<endl;
            it.second->print();
            cout<<endl;
        }
    }

    void omegaprint(){
        cont=0;
        fstream output("graphviz2.dot", ios::out | ios::trunc);
        output << "graph \"\"" << endl;
        output << "{" << endl;
        output << "label=\"besto trabajo ever\"" << endl;
        int cnt=0;
        for(int i=0; i<=grade; i++){
            auto ptr = heap.find(i);
            if(ptr == heap.end()) continue;
            output << "subgraph cluster" << cnt << endl;
            output << "{" << endl;
            output << "label=\"Grado: " << i << "\"" << endl;
            output << "n" << cnt << " ;"<< endl;
            ptr->second->omegaprint(output,cnt);
            cnt++;
            output << "}" << endl;
        }
        output << "}" << endl;
    }

};