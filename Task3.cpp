#include <iostream>
#include <string>

using namespace std;

struct Node {
    string data;
    Node* next;
    Node(string d) : data(d), next(nullptr) {}
};

class Queue {
private:
    Node* head;
    Node* tail;
    int count;

public:
    Queue() : head(nullptr), tail(nullptr), count(0) {}

    void push(string val) {
        Node* temp = new Node(val);
        if (tail == nullptr) {
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
        count++;
    }

    void pop() {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        if (head == nullptr) tail = nullptr;
        delete temp;
        count--;
    }

    string front() {
        if (head != nullptr) return head->data;
        return "";
    }

    bool empty() {
        return head == nullptr;
    }

    int size() {
        return count;
    }

    ~Queue() {
        while (!empty()) pop();
    }
};

class Stack {
private:
    Node* topNode;

public:
    Stack() : topNode(nullptr) {}

    void push(string val) {
        Node* temp = new Node(val);
        temp->next = topNode;
        topNode = temp;
    }

    void pop() {
        if (topNode == nullptr) return;
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    string top() {
        if (topNode != nullptr) return topNode->data;
        return "";
    }

    bool empty() {
        return topNode == nullptr;
    }

    ~Stack() {
        while (!empty()) pop();
    }
};

void reverseFirstK(Queue& q, int k) {
    if (q.empty() || k <= 0 || k > q.size()) {
        return;
    }

    Stack s;

    for (int i = 0; i < k; ++i) {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    int remaining = q.size() - k;
    for (int i = 0; i < remaining; ++i) {
        q.push(q.front());
        q.pop();
    }
}

int main() {
    Queue q;
    string jobs[] = {"J1", "J2", "J3", "J4", "J5", "J6", "J7"};

    for (const string& job : jobs) {
        q.push(job);
    }

    int k = 3;
    reverseFirstK(q, k);

    bool first = true;
    while (!q.empty()) {
        if (!first) cout << ", ";
        cout << q.front();
        q.pop();
        first = false;
    }
    cout << endl;

    return 0;
}