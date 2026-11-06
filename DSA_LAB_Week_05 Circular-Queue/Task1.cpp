#include <iostream>
using namespace std;
template <typename t>
class abstractqueue {
public:
    virtual void enqueue(t value) = 0;
    virtual t dequeue() = 0;
    virtual t front() const = 0;
    virtual bool isempty() const = 0;
    virtual bool isfull() const = 0;
    virtual ~abstractqueue() {}
};
template <typename t>
class myqueue : public abstractqueue<t> {
private:
    t* arr;
    int size;
    int frontindex;
    int rear;
public:
    myqueue(int s) {
        size = s;
        frontindex = -1;
        rear = -1;
        arr = new t[size];
    }
    void enqueue(t value) override {
        if (isfull()) {
            cout << "Queue is full!" << endl;
            return;
        }
        if (frontindex == -1) {
            frontindex = 0;
        }
        rear++;
        arr[rear] = value;
    }
    t dequeue() override {
        if (isempty()) {
            cout << "Queue is empty!" << endl;
            return t();
        }
        t value = arr[frontindex];
        if (frontindex == rear) {
            frontindex = -1;
            rear = -1;
        }
        else {
            frontindex++;
        }
        return value;
    }
    t front() const override {
        if (isempty()) {
            cout << "Queue is empty!" << endl;
            return t();
        }
        return arr[frontindex];
    }
    bool isempty() const override {
        return frontindex == -1;
    }
    bool isfull() const override {
        return rear == size - 1;
    }
    void display() const {
        if (isempty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = frontindex; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    ~myqueue() {
        delete[] arr;
    }
};
int main() {
    myqueue<int> q(5);
    int choice, value;
    while (true) {
        cout << endl << "===== QUEUE MENU =====" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Front" << endl;
        cout << "4. Display" << endl;
        cout << "5. Check Empty" << endl;
        cout << "6. Check Full" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter value: ";
            cin >> value;
            q.enqueue(value);
        }
        else if (choice == 2) {
            q.dequeue();
        }
        else if (choice == 3) {
            if (q.isempty()) {
                cout << "Queue is empty!" << endl;
            }
            else {
                cout << "Front element: " << q.front() << endl;
            }
        }
        else if (choice == 4) {
            q.display();
        }
        else if (choice == 5) {
            if (q.isempty()) {
                cout << "Queue is empty." << endl;
            }
            else {
                cout << "Queue is not empty." << endl;
            }
        }
        else if (choice == 6) {
            if (q.isfull()) {
                cout << "Queue is full." << endl;
            }
            else {
                cout << "Queue is not full." << endl;
            }
        }
        else if (choice == 0) {
            cout << "Program terminated." << endl;
            break;
        }
        else {
            cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}
