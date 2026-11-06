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
    void createnode(int value) {
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
    void display() {
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
    list.createnode(10);
    list.createnode(20);
    list.createnode(30);
    list.createnode(40);
    list.display();
    return 0;
}
