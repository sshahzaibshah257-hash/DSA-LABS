#include <iostream>
using namespace std;

class package {
private:
    int package_id;
    string address;
    int starttime;
    int endtime;
public:
    package() {
        package_id = 0;
        address = "";
        starttime = 0;
        endtime = 0;
    }
    void setpackage(int id, string a, int start, int end) {
        package_id = id;
        address = a;
        starttime = start;
        endtime = end;
    }
    int getid() const {
        return package_id;
    }
    string getaddress() const {
        return address;
    }
    int getstarttime() const {
        return starttime;
    }
    int getendtime() const {
        return endtime;
    }
};

class deliveryqueue {
private:
    package* arr;
    int size;
    int frontindex;
    int rear;
public:
    deliveryqueue(int s) {
        size = s;
        frontindex = -1;
        rear = -1;
        arr = new package[size];
    }
    void enqueue(int id, string address, int start, int end) {
        if (isfull()) {
            cout << "Delivery queue is full!" << endl;
            return;
        }
        if (frontindex == -1) {
            frontindex = 0;
        }
        rear++;
        arr[rear].setpackage(id, address, start, end);
        cout << "Package added successfully." << endl;
    }
    void dequeue() {
        if (isempty()) {
            cout << "No packages available!" << endl;
            return;
        }
        cout << "Package " << arr[frontindex].getid()
            << " delivered successfully." << endl;
        if (frontindex == rear) {
            frontindex = -1;
            rear = -1;
        }
        else {
            frontindex++;
        }
    }
    void front() const {
        if (isempty()) {
            cout << "No packages available!" << endl;
            return;
        }
        cout << "\nNext Package Details:" << endl;
        cout << "Package ID: " << arr[frontindex].getid() << endl;
        cout << "Address: " << arr[frontindex].getaddress() << endl;
        cout << "Start Time: " << arr[frontindex].getstarttime() << endl;
        cout << "End Time: " << arr[frontindex].getendtime() << endl;
    }
    bool isempty() const {
        return frontindex == -1;
    }
    bool isfull() const {
        return rear == size - 1;
    }
    void display() const {
        if (isempty()) {
            cout << "No pending packages!" << endl;
            return;
        }
        cout << "\nPending Packages:" << endl;
        for (int i = frontindex; i <= rear; i++) {
            cout << "\nPackage ID: " << arr[i].getid() << endl;
            cout << "Address: " << arr[i].getaddress() << endl;
            cout << "Start Time: " << arr[i].getstarttime() << endl;
            cout << "End Time: " << arr[i].getendtime() << endl;
        }
    }
    void timetodeliver(int currenttime) {
        if (isempty()) {
            cout << "No packages available!" << endl;
            return;
        }
        while (!isempty()) {
            if (currenttime > arr[frontindex].getendtime()) {
                cout << "Package " << arr[frontindex].getid()
                    << " has expired!" << endl;
                if (frontindex == rear) {
                    frontindex = -1;
                    rear = -1;
                }
                else {
                    frontindex++;
                }
            }
            else if (currenttime < arr[frontindex].getstarttime()) {
                cout << "Package " << arr[frontindex].getid()
                    << " is not ready for delivery yet." << endl;
                return;
            }
            else {
                cout << "Package " << arr[frontindex].getid()
                    << " can be delivered now." << endl;
                return;
            }
        }
        cout << "No valid packages remaining!" << endl;
    }
    ~deliveryqueue() {
        delete[] arr;
    }
};

int main() {
    deliveryqueue q(10);
    int choice, id, start, end, currenttime;
    string address;
    while (true) {
        cout << endl << "===== PACKAGE DELIVERY SYSTEM =====" << endl;
        cout << "1. Add New Package" << endl;
        cout << "2. Deliver Package" << endl;
        cout << "3. View Next Package" << endl;
        cout << "4. Display All Packages" << endl;
        cout << "5. Check Delivery Time" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter Package ID: ";
            cin >> id;
            cout << "Enter Recipient Address: ";
            cin.ignore();
            getline(cin, address);
            cout << "Enter Start Time (HHMM): ";
            cin >> start;
            cout << "Enter End Time (HHMM): ";
            cin >> end;
            if (id <= 0 || start < 0 || start > 2359 ||
                end < 0 || end > 2359 ||
                start % 100 >= 60 || end % 100 >= 60 ||
                start > end) {
                cout << "Invalid package details!" << endl;
            }
            else {
                q.enqueue(id, address, start, end);
            }
        }
        else if (choice == 2) {
            q.dequeue();
        }
        else if (choice == 3) {
            q.front();
        }
        else if (choice == 4) {
            q.display();
        }
        else if (choice == 5) {
            cout << "Enter Current Time (HHMM): ";
            cin >> currenttime;
            if (currenttime < 0 || currenttime > 2359 ||
                currenttime % 100 >= 60) {
                cout << "Invalid time!" << endl;
            }
            else {
                q.timetodeliver(currenttime);
            }
        }
        else if (choice == 0) {
            cout << "Exiting Package Delivery System." << endl;
            break;
        }
        else {
            cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}
