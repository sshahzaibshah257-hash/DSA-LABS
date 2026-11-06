#include <iostream>
using namespace std;
class printqueue {
private:
    string* arr;
    int size;
    int frontindex;
    int rear;
public:
    printqueue(int s) {
        size = s;
        frontindex = -1;
        rear = -1;
        arr = new string[size];
    }
    void enqueue(string document_name) {
        if (isfull()) {
            cout << "Print queue is full!" << endl;
            return;
        }
        if (frontindex == -1) {
            frontindex = 0;
        }
        rear++;
        arr[rear] = document_name;
        cout << document_name << " added to print queue successfully." << endl;
    }
    void dequeue() {
        if (isempty()) {
            cout << "No print jobs available!" << endl;
            return;
        }
        cout << "Printing document: " << arr[frontindex] << endl;
        if (frontindex == rear) {
            frontindex = -1;
            rear = -1;
        }
        else {
            frontindex++;
        }
    }
    string front() const {
        if (isempty()) {
            cout << "Print queue is empty!" << endl;
            return "";
        }
        return arr[frontindex];
    }
    bool isempty() const {
        return frontindex == -1;
    }
    bool isfull() const {
        return rear == size - 1;
    }
    void display() const {
        if (isempty()) {
            cout << "Print queue is empty!" << endl;
            return;
        }
        cout << "Pending print jobs:" << endl;
        for (int i = frontindex; i <= rear; i++) {
            cout << i - frontindex + 1 << ". " << arr[i] << endl;
        }
    }
    ~printqueue() {
        delete[] arr;
    }
};

int main() {
    printqueue q(10);
    int choice;
    string document_name;
    while (true) {
        cout << endl << "===== DOCUMENT PRINTING SYSTEM =====" << endl;
        cout << "1. Add Print Job" << endl;
        cout << "2. Print Document" << endl;
        cout << "3. Check Next Document" << endl;
        cout << "4. Display Pending Print Jobs" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        if (choice == 1) {
            cout << "Enter document name: ";
            getline(cin, document_name);
            q.enqueue(document_name);
        }
        else if (choice == 2) {
            q.dequeue();
        }
        else if (choice == 3) {
            if (q.isempty()) {
                cout << "Print queue is empty!" << endl;
            }
            else {
                cout << "Next document to print: " << q.front() << endl;
            }
        }
        else if (choice == 4) {
            q.display();
        }
        else if (choice == 0) {
            cout << "Exiting Document Printing System." << endl;
            break;
        }
        else {
            cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}
