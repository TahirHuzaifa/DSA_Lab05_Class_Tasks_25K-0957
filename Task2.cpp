#include <iostream>
using namespace std;

class stack{
    string *arr;
    int size;
    int top;
    public:
    stack(int n){
        size = n;
        arr = new string[size];
        top = 0;
    }

    void push(string val){
        if (top>size){
            cout << "Stack is full\n";
            return;
        }
        arr[top++] = val;

    }
    string pop(){
        if (top==0){
            cout << "nothing to undo\n";
            return "";
        }
        top--;
        return arr[top];
        
        
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
    stack mystack(10);
    stack redo(10);


    int choice;

    do{
        cout << "Enter 1 to TYPE, 2 for redo and 3 for undo and 0 for exit: "; cin >> choice;
        if (choice==3){
            string prev = mystack.pop();
            cout << "prev: "<<prev<<'\n';
            if (prev!="") redo.push(prev);
            mystack.show();
        }
        else if (choice==2){
            string add = redo.pop();
            if (add!="")mystack.push(add);
            mystack.show();
        }
        else if (choice==1){
            string val; cout << "enter value to add: "; cin>>val;
            mystack.push(val);
            mystack.show();
        }

    }while(choice!=0);


    return 0;
}