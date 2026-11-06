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
        if (isfull()) {
            cout << "Stack is full!" << endl;
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
    t peek() const {
        if (isempty()) {
            return t();
        }
        return arr[top];
    }
    bool isempty() const {
        return top == -1;
    }
    bool isfull() const {
        return top == size - 1;
    }
    int gettop() const {
        return top;
    }
    ~mystack() {
        delete[] arr;
    }
};
template <typename t>
class myqueue {
private:
    mystack<t> s1;
    mystack<t> s2;
    int size;
    void transfertostack2() {
        while (!s1.isempty()) {
            s2.push(s1.pop());
        }
    }
public:
    myqueue(int s) : s1(s), s2(s) {
        size = s;
    }
    void enqueue(t value) {
        if (s1.gettop() + s2.gettop() + 2 >= size) {
            cout << "Queue is full!" << endl;
            return;
        }
        s1.push(value);
        cout << value << " inserted successfully." << endl;
    }
    t dequeue() {
        if (isempty()) {
            cout << "Queue is empty!" << endl;
            return t();
        }
        if (s2.isempty()) {
            transfertostack2();
        }
        t value = s2.pop();
        cout << value << " removed successfully." << endl;
        return value;
    }
    t front() {
        if (isempty()) {
            cout << "Queue is empty!" << endl;
            return t();
        }
        if (s2.isempty()) {
            transfertostack2();
        }
        return s2.peek();
    }
    bool isempty() const {
        return s1.isempty() && s2.isempty();
    }
    void display() {
        if (isempty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = s2.gettop(); i >= 0; i--) {
            mystack<t> temp(size);
            while (!s2.isempty()) {
                temp.push(s2.pop());
            }
            while (!temp.isempty()) {
                t value = temp.pop();
                cout << value << " ";
                s2.push(value);
            }
            break;
        }
        mystack<t> temp(size);
        while (!s1.isempty()) {
            temp.push(s1.pop());
        }
        while (!temp.isempty()) {
            t value = temp.pop();
            cout << value << " ";
            s1.push(value);
        }
        cout << endl;
    }
};
int main() {
    myqueue<int> q(5);
    int choice, value;
    while (true) {
        cout << endl << "===== QUEUE USING STACKS =====" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Front" << endl;
        cout << "4. Display" << endl;
        cout << "5. Check Empty" << endl;
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
