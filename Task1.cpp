#include <iostream>
using namespace std;

class stack{
    int *arr;
    int size;
    int top;
    public:
    stack(int n){
        size = n;
        arr = new int[size];
        top = 0;
    }

    void push(int val){
        if (top>size){
            cout << "Stack is full\n";
            return;
        }
        arr[top++] = val;

    }
    void pop(){
        if (top==0){
            cout << "stack is empty\n";
            return;
        }
        top--;
    }
    void show(){
        if (top==0){
            cout << "empty\n";
            return;
        }
        for(int i=0; i<top; i++) cout << arr[i] << " ";
        cout << '\n';
    }
};
int main(){
    stack mystack(6);
    mystack.push(12);
    mystack.push(25);
    mystack.push(17);
    mystack.push(31);
    mystack.push(44);
    mystack.push(19);
    mystack.show();
    int choice; 
    do
    {
        cout << "enter 0 to add and 1 to undo and 2 to exit "; cin>>choice;
        if (choice==1){
            mystack.pop();
            mystack.show();
        }
        if (choice==0){
            int val; cout<< "enter value to add: "; cin>>val;
            mystack.push(val);
            mystack.show();
        }
    } while (choice!=2);
    
    





    return 0;
}