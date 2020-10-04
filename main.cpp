#include "BinomialHeap.cpp"

int main(){
    srand(time(NULL));
    BinomialHeap<int> variable;
    int stop=rand()%10;
    int to_change;
    for(int i=0;i<10;i++){
        int temp=rand()%10;
        if(i==stop){
            to_change=temp;
        }
        variable.insert(temp);
        cout<<temp<<" ";
    }
    cout<<endl;
    variable.print();
    cout<<endl;
    cout<<"min es: "<<variable.getMin()<<endl;
    variable.deleteMin();
    variable.print();
    cout<<endl;
    cout<<"decreased key"<<to_change<<endl;
    variable.decreaseKey(to_change,to_change-1);
    variable.print();   
    cout<<endl; 

}
