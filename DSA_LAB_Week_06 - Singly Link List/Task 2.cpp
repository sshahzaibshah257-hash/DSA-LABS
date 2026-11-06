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
    void insertatbeginning(int value) {
        node* newnode = new node(value);
        newnode->next = head;
        head = newnode;
    }
    void insertatend(int value) {
        node* newnode = new node(value);
        if (head == nullptr) {
            head = newnode;
            return;
        }
        node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    void deletenode(int value) {
        if (head == nullptr) {
            cout << "list is empty!" << endl;
            return;
        }
        if (head->data == value) {
            node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        node* temp = head;
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }
        if (temp->next == nullptr) {
            cout << "value not found!" << endl;
            return;
        }
        node* del = temp->next;
        temp->next = del->next;
        delete del;
    }
    void display() {
        if (head == nullptr) {
            cout << "list is empty!" << endl;
            return;
        }
        node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "null" << endl;
    }
};
int main() {
    singlylinkedlist list;
    list.insertatbeginning(20);
    list.insertatbeginning(10);
    list.insertatend(30);
    list.insertatend(40);
    cout << "linked list: ";
    list.display();
    list.deletenode(30);
    cout << "after deletion: ";
    list.display();
    return 0;
}
