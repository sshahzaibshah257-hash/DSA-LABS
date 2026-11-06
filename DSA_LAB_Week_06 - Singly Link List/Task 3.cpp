#include <iostream>
using namespace std;
class node {
public:
    int data;
    node* next;
    node(int value) {
        data = value;
        next = nullptr;
    }
};
class singlylinkedlist {
private:
    node* head;
public:
    singlylinkedlist() {
        head = nullptr;
    }
    void insertatposition(int value, int position) {
        node* newnode = new node(value);
        if (position == 1) {
            newnode->next = head;
            head = newnode;
            return;
        }
        node* temp = head;
        for (int i = 1; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp == nullptr || position < 1) {
            cout << "invalid position!" << endl;
            delete newnode;
            return;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    void deleteatposition(int position) {
        if (head == nullptr || position < 1) {
            cout << "list is empty or invalid position!" << endl;
            return;
        }
        node* temp = head;
        if (position == 1) {
            head = head->next;
            delete temp;
            return;
        }
        for (int i = 1; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp == nullptr || temp->next == nullptr) {
            cout << "invalid position!" << endl;
            return;
        }
        node* del = temp->next;
        temp->next = del->next;
        delete del;
    }
    void search(int value) {
        node* temp = head;
        int position = 1;
        while (temp != nullptr) {
            if (temp->data == value) {
                cout << "element found at position " << position << endl;
                return;
            }
            temp = temp->next;
            position++;
        }
        cout << "element not found!" << endl;
    }
    void countnodes() {
        node* temp = head;
        int count = 0;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        cout << "total number of nodes: " << count << endl;
    }
    void display() {
        node* temp = head;
        if (head == nullptr) {
            cout << "list is empty!" << endl;
            return;
        }
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "null" << endl;
    }
};
int main() {
    singlylinkedlist list;
    int choice, value, position;
    while (true) {
        cout <<endl << "1. insert node at specific position" << endl;
        cout << "2. delete node at specific position" << endl;
        cout << "3. search an element" << endl;
        cout << "4. count total nodes" << endl;
        cout << "5. display list" << endl;
        cout << "6. exit" << endl;
        cout << "enter your choice: ";
        cin >> choice;
        if (choice == 1) {
            cout << "enter value: ";
            cin >> value;
            cout << "enter position: ";
            cin >> position;
            list.insertatposition(value, position);
        }
        else if (choice == 2) {
            cout << "enter position to delete: ";
            cin >> position;
            list.deleteatposition(position);
        }
        else if (choice == 3) {
            cout << "enter value to search: ";
            cin >> value;
            list.search(value);
        }
        else if (choice == 4) {
            list.countnodes();
        }
        else if (choice == 5) {
            list.display();
        }
        else if (choice == 6) {
            cout << "program ended!" << endl;
            break;
        }
        else {
            cout << "invalid choice!" << endl;
        }
    }
    return 0;
}
