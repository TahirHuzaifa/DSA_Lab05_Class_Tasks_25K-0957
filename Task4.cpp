#include <iostream>
using namespace std;
class CircularQueue {
private:
    int* arr;
    int capacity;
    int front;
    int rear;

public:
    CircularQueue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = -1;
        rear = -1;
    }

    ~CircularQueue() {
        delete[] arr;
    }

    bool isFull() {
        return (front == 0 && rear == capacity - 1) || (front == rear + 1);
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int id) {
        if (isFull()) {
            return;
        }
        if (front == -1) {
            front = 0;
            rear = 0;
        } else if (rear == capacity - 1 && front != 0) {
            rear = 0;
        } else {
            rear++;
        }
        arr[rear] = id;
    }

    int dequeue() {
        if (isEmpty()) {
            return -1;
        }
        int data = arr[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (front == capacity - 1) {
            front = 0;
        } else {
            front++;
        }
        return data;
    }

    void displayFinal() {
        if (isEmpty()) {
            return;
        }
        cout << "Final front position: " << front << "\n";
        cout << "Final rear position: " << rear << "\n";
        cout << "Final passengers in boarding order: ";
        if (rear >= front) {
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
        } else {
            for (int i = front; i < capacity; i++) {
                cout << arr[i] << " ";
            }
            for (int i = 0; i <= rear; i++) {
                cout << arr[i] << " ";
            }
        }
        cout << "\n";
    }
};

int main() {
    CircularQueue q(6);

    q.enqueue(101);
    q.enqueue(102);
    q.enqueue(103);
    q.enqueue(104);
    q.enqueue(105);
    q.enqueue(106);

    q.dequeue();
    q.dequeue();
    q.dequeue();

    q.enqueue(107);
    q.enqueue(108);
    q.enqueue(109);

    q.dequeue();
    q.dequeue();

    q.enqueue(110);

    q.dequeue();

    q.enqueue(111);
    q.enqueue(112);

    q.displayFinal();

    return 0;
}