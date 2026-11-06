#include <iostream>
using namespace std;
class node {
public:
    int id;
    string name;
    node* next;
    node(int i, string n) {
        id = i;
        name = n;
        next = nullptr;
    }
};
class hospital {
private:
    node* head;
public:
    hospital() {
        head = nullptr;
    }
    void addpatient(int id, string name) {
        node* newnode = new node(id, name);
        if (head == nullptr) {
            head = newnode;
            return;
        }
        node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newnode;
        cout << "patient added successfully!" << endl;
    }
    void removepatient(int id) {
        if (head == nullptr) {
            cout << "queue is empty!" << endl;
            return;
        }
        if (head->id == id) {
            node* temp = head;
            head = head->next;
            delete temp;
            cout << "patient removed successfully!" << endl;
            return;
        }
        node* temp = head;
        while (temp->next != nullptr && temp->next->id != id) {
            temp = temp->next;
        }
        if (temp->next == nullptr) {
            cout << "patient not found!" << endl;
            return;
        }
        node* del = temp->next;
        temp->next = del->next;
        delete del;
        cout << "patient removed successfully!" << endl;
    }
    void display() {
        if (head == nullptr) {
            cout << "no patients in queue!" << endl;
            return;
        }
        node* temp = head;
        cout << "\npatient queue:" << endl;
        while (temp != nullptr) {
            cout << "id: " << temp->id << "  name: " << temp->name << endl;
            temp = temp->next;
        }
    }
    void countpatients() {
        node* temp = head;
        int count = 0;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        cout << "total patients in queue: " << count << endl;
    }
};
int main() {
    hospital h;
    int choice, id;
    string name;
    while (true) {
        cout <<endl << "===== hospital management system =====" << endl;
        cout << "1. add new patient" << endl;
        cout << "2. remove patient" << endl;
        cout << "3. display patients" << endl;
        cout << "4. count patients" << endl;
        cout << "5. exit" << endl;
        cout << "enter your choice: ";
        cin >> choice;
        if (choice == 1) {
            cout << "enter patient id: ";
            cin >> id;
            cout << "enter patient name: ";
            cin >> name;
            h.addpatient(id, name);
            cout << "patient added successfully!" << endl;
        }
        else if (choice == 2) {
            cout << "enter patient id to remove: ";
            cin >> id;
            h.removepatient(id);
        }
        else if (choice == 3) {
            h.display();
        }
        else if (choice == 4) {
            h.countpatients();
        }
        else if (choice == 5) {
            cout << "program ended!" << endl;
            break;
        }
    }
    return 0;
}
