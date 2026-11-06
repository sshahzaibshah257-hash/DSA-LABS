#include <iostream>
using namespace std;
template <typename t>
class mystack {
private:
    t* arr;
    int size;
    int top;
public:
    mystack(int s) {
        size = s;
        top = -1;
        arr = new t[size];
    }
    void push(t value) {
        if (top == size - 1) {
            return;
        }
        top++;
        arr[top] = value;
    }
    t pop() {
        if (isempty()) {
            return t();
        }
        t value = arr[top];
        top--;
        return value;
    }
    bool isempty() const {
        return top == -1;
    }
    ~mystack() {
        delete[] arr;
    }
};

template <typename t>
class myqueue {
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
    void enqueue(t value) {
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
    t dequeue() {
        if (isempty()) {
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
    t front() const {
        if (isempty()) {
            return t();
        }
        return arr[frontindex];
    }
    bool isempty() const {
        return frontindex == -1;
    }
    bool isfull() const {
        return rear == size - 1;
    }
    int getsize() const {
        if (isempty()) {
            return 0;
        }
        return rear - frontindex + 1;
    }
    void display() const {
        if (isempty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue: ";
        for (int i = frontindex; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void reversefirstk(int k) {
        if (k <= 1 || isempty()) {
            return;
        }
        int n = getsize();
        if (k > n) {
            k = n;
        }
        mystack<t> s(n);
        for (int i = 0; i < k; i++) {
            s.push(dequeue());
        }
        while (!s.isempty()) {
            enqueue(s.pop());
        }
        for (int i = 0; i < n - k; i++) {
            enqueue(dequeue());
        }
    }
    ~myqueue() {
        delete[] arr;
    }
};

int main() {
    int n, value, k;
    cout << "Enter number of queue elements: ";
    cin >> n;
    if (n <= 0) {
        cout << "Invalid queue size!" << endl;
        return 0;
    }
    myqueue<int> q(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> value;
        q.enqueue(value);
    }
    cout << endl;
    q.display();
    cout << "Enter value of K: ";
    cin >> k;
    if (k < 0) {
        cout << "K cannot be negative!" << endl;
        return 0;
    }
    q.reversefirstk(k);
    cout << "Output: ";
    q.display();
    return 0;
}
