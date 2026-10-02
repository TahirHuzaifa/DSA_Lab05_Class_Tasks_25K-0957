#include <iostream>
#include <string>

using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

class MyStack {
private:
    Node* topNode;

public:
    MyStack() : topNode(nullptr) {}

    ~MyStack() {
        while (!empty()) {
            pop();
        }
    }

    void push(int item) {
        Node* newNode = new Node(item);
        newNode->next = topNode;
        topNode = newNode;
    }

    void pop() {
        if (topNode != nullptr) {
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
    }

    int top() {
        if (topNode != nullptr) {
            return topNode->data;
        }
        throw runtime_error("Stack empty");
    }

    bool empty() {
        return topNode == nullptr;
    }
};

class MyQueue {
private:
    MyStack incoming;
    MyStack outgoing;

public:
    void enqueue(int item) {
        incoming.push(item);
    }

    int dequeue() {
        if (outgoing.empty()) {
            while (!incoming.empty()) {
                outgoing.push(incoming.top());
                incoming.pop();
            }
        }
        if (outgoing.empty()) {
            throw runtime_error("Queue empty");
        }
        int frontItem = outgoing.top();
        outgoing.pop();
        return frontItem;
    }
};

int main() {
    MyQueue q;
    
    q.enqueue('A');
    q.enqueue('B');
    cout << (char)q.dequeue() << "\n";
    
    q.enqueue('C');
    cout << (char)q.dequeue() << "\n";
    cout << (char)q.dequeue() << "\n";
    
    return 0;
}