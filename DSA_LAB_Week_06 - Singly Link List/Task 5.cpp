
#include <iostream>
using namespace std;
class node {
public:
    int id;
    string name;
    string priority;
    node* next;
    node(int i, string n, string p) {
        id = i;
        name = n;
        priority = p;
        next = nullptr;
    }
};
class book {
public:
    string title;
    node* head;
    book(string t) {
        title = t;
        head = nullptr;
    }
    void addstudent(int id, string name, string priority) {
        node* newnode = new node(id, name, priority);
        int p = 3;
        if (priority == "research") p = 1;
        else if (priority == "assignment") p = 2;
        if (head == nullptr) {
            head = newnode;
        }
        else {
            int hp = 3;
            if (head->priority == "research") hp = 1;
            else if (head->priority == "assignment") hp = 2;
            if (p < hp) {
                newnode->next = head;
                head = newnode;
            }
            else {
                node* temp = head;
                while (temp->next != nullptr) {
                    int np = 3;
                    if (temp->next->priority == "research") np = 1;
                    else if (temp->next->priority == "assignment") np = 2;
                    if (p < np) break;
                    temp = temp->next;
                }
                newnode->next = temp->next;
                temp->next = newnode;
            }
        }
        cout << "student added successfully!" << endl;
    }
    void removestudent(int id) {
        if (head == nullptr) {
            cout << "reservation list is empty!" << endl;
            return;
        }
        if (head->id == id) {
            node* temp = head;
            head = head->next;
            delete temp;
            cout << "student removed successfully!" << endl;
            return;
        }
        node* temp = head;
        while (temp->next != nullptr && temp->next->id != id) {
            temp = temp->next;
        }
        if (temp->next == nullptr) {
            cout << "student not found!" << endl;
            return;
        }
        node* del = temp->next;
        temp->next = del->next;
        delete del;
        cout << "student removed successfully!" << endl;
    }
    void updatepriority(int id, string priority) {
        if (head == nullptr) {
            cout << "reservation list is empty!" << endl;
            return;
        }
        node* temp = head;
        string name;
        while (temp != nullptr) {
            if (temp->id == id) {
                name = temp->name;
                break;
            }
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "student not found!" << endl;
            return;
        }
        removestudent(id);
        addstudent(id, name, priority);
        cout << "priority updated successfully!" << endl;
    }
    void returnbook() {
        if (head == nullptr) {
            cout << "no students waiting!" << endl;
            return;
        }
        node* temp = head;
        cout << "book issued to: " << temp->name << endl;
        head = head->next;
        delete temp;
    }
    void display() {
        if (head == nullptr) {
            cout << "no reservations for this book!" << endl;
            return;
        }
        node* temp = head;
        cout << "\nreservation list for " << title << ":" << endl;
        while (temp != nullptr) {
            cout << "id: " << temp->id << "  name: " << temp->name << "  priority: " << temp->priority << endl;
            temp = temp->next;
        }
    }
    void countstudents() {
        node* temp = head;
        int count = 0;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        cout << "total students waiting: " << count << endl;
    }
};
int main() {
    book b1("c++ programming");
    book b2("data structures");
    int choice, id, bookchoice;
    string name, priority;
    while (true) {
        cout <<endl << "University library system" << endl;
        cout << "1. add student reservation" << endl;
        cout << "2. cancel reservation" << endl;
        cout << "3. update student priority" << endl;
        cout << "4. display reservation list" << endl;
        cout << "5. count students" << endl;
        cout << "6. return book and issue to next student" << endl;
        cout << "7. exit" << endl;
        cout << "enter your choice: ";
        cin >> choice;
        if (choice >= 1 && choice <= 6) {
            cout << "select book (1. c++ programming, 2. data structures): ";
            cin >> bookchoice;
            if (bookchoice != 1 && bookchoice != 2) {
                cout << "invalid book choice!" << endl;
                continue;
            }
        }
        if (choice == 1) {
            cout << "enter student id: ";
            cin >> id;
            cout << "enter student name: ";
            cin >> name;
            cout << "enter priority (research/assignment/casual): ";
            cin >> priority;
            if (bookchoice == 1) b1.addstudent(id, name, priority);
            else b2.addstudent(id, name, priority);
        }
        else if (choice == 2) {
            cout << "enter student id to cancel: ";
            cin >> id;
            if (bookchoice == 1) b1.removestudent(id);
            else b2.removestudent(id);
        }
        else if (choice == 3) {
            cout << "enter student id: ";
            cin >> id;
            cout << "enter new priority: ";
            cin >> priority;
            if (bookchoice == 1) b1.updatepriority(id, priority);
            else b2.updatepriority(id, priority);
        }
        else if (choice == 4) {
            if (bookchoice == 1) b1.display();
            else b2.display();
        }
        else if (choice == 5) {
            if (bookchoice == 1) b1.countstudents();
            else b2.countstudents();
        }
        else if (choice == 6) {
            if (bookchoice == 1) b1.returnbook();
            else b2.returnbook();
        }
        else if (choice == 7) {
            cout << "program ended!" << endl;
            break;
        }
        else {
            cout << "invalid choice!" << endl;
        }
    }
    return 0;
}
