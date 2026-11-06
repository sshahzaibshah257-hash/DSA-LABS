#include <iostream>
using namespace std;
class customerqueue {
private:
    int* arr;
    int size;
    int frontindex;
    int rear;
public:
    customerqueue(int s) {
        size = s;
        frontindex = -1;
        rear = -1;
        arr = new int[size];
    }
    void enqueue(int ticket_id) {
        if (isfull()) {
            cout << "Ticket queue is full!" << endl;
            return;
        }
        if (frontindex == -1) {
            frontindex = 0;
        }
        rear++;
        arr[rear] = ticket_id;
        cout << "Ticket " << ticket_id << " added successfully." << endl;
    }
    void dequeue() {
        if (isempty()) {
            cout << "No pending tickets!" << endl;
            return;
        }
        cout << "Ticket " << arr[frontindex] << " resolved successfully." << endl;
        if (frontindex == rear) {
            frontindex = -1;
            rear = -1;
        }
        else {
            frontindex++;
        }
    }
    int front() const {
        if (isempty()) {
            cout << "No pending tickets!" << endl;
            return -1;
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
            cout << "No pending tickets!" << endl;
            return;
        }
        cout << "Pending tickets: ";
        for (int i = frontindex; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    ~customerqueue() {
        delete[] arr;
    }
};

int main() {
    customerqueue q(10);
    int choice, ticket_id;
    while (true) {
        cout << endl << "===== CUSTOMER SUPPORT TICKET SYSTEM =====" << endl;
        cout << "1. Add New Ticket" << endl;
        cout << "2. Resolve Ticket" << endl;
        cout << "3. Next Ticket" << endl;
        cout << "4. Display Pending Tickets" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter 4-digit Ticket ID: ";
            cin >> ticket_id;
            if (ticket_id < 1000 || ticket_id > 9999) {
                cout << "Invalid Ticket ID! Enter exactly 4 digits." << endl;
            }
            else {
                q.enqueue(ticket_id);
            }
        }
        else if (choice == 2) {
            q.dequeue();
        }
        else if (choice == 3) {
            if (q.isempty()) {
                cout << "No pending tickets!" << endl;
            }
            else {
                cout << "Next ticket to resolve: " << q.front() << endl;
            }
        }
        else if (choice == 4) {
            q.display();
        }
        else if (choice == 0) {
            cout << "Exiting Customer Support System." << endl;
            break;
        }
        else {
            cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}
