#include <iostream>
using namespace std;
template <typename type>
class list {
protected:
    type* arr;
    int maxsize;
    int currentsize;

public:
    list(int s = 10, int cs = 0) {
        maxsize = s;
        currentsize = cs;
        arr = new type[maxsize];
    }

    list(const list<type>& other) {
        maxsize = other.maxsize;
        currentsize = other.currentsize;
        arr = new type[maxsize];

        for (int i = 0; i < currentsize; i++) {
            arr[i] = other.arr[i];
        }
    }

    virtual void addelementatfirstindex(type a) = 0;
    virtual void addelementatlastindex(type b) = 0;
    virtual type removeelementfromend() = 0;
    virtual type removeelementfromstart() = 0;

    virtual ~list() {
        delete[] arr;
    }
};

template <typename type>
class mylist : public list<type> {
public:
    mylist(int s = 10, int cs = 0)
        : list<type>(s, cs) {}

    mylist(const mylist<type>& other)
        : list<type>(other) {}

    bool empty() {
        return this->currentsize == 0;
    }

    bool full() {
        return this->currentsize >= this->maxsize;
    }

    int size() {
        return this->currentsize;
    }

    bool insertAt(int index, type value) {
        if (index < 0 || index > this->currentsize ||
            full()) {
            return false;
        }

        for (int i = this->currentsize; i > index; i--) {
            this->arr[i] = this->arr[i - 1];
        }

        this->arr[index] = value;
        this->currentsize++;
        return true;
    }

    type last() {
        if (empty()) {
            cout << "List is empty!\n";
            return type();
        }

        return this->arr[this->currentsize - 1];
    }

    bool search(type value) {
        for (int i = 0; i < this->currentsize; i++) {
            if (this->arr[i] == value) {
                return true;
            }
        }

        return false;
    }

    void addelementatfirstindex(type value) override {
        if (!insertAt(0, value))
            cout << "List is full!\n";
    }

    void addelementatlastindex(type value) override {
        if (!insertAt(this->currentsize, value))
            cout << "List is full!\n";
    }

    type removeelementfromend() override {
        if (empty()) {
            cout << "List is empty!\n";
            return type();
        }

        type value = this->arr[this->currentsize - 1];
        this->currentsize--;
        return value;
    }

    type removeelementfromstart() override {
        if (empty()) {
            cout << "List is empty!\n";
            return type();
        }

        type value = this->arr[0];

        for (int i = 0; i < this->currentsize - 1; i++) {
            this->arr[i] = this->arr[i + 1];
        }

        this->currentsize--;
        return value;
    }

    ~mylist() override = default;
};

int main() {
    int capacity;

    cout << "Enter maximum list size: ";
    cin >> capacity;

    if (capacity <= 0) {
        cout << "Capacity must be positive.\n";
        return 0;
    }

    mylist<int> obj(capacity);

    int choice, value, index;

    do {
        cout << "\n--- mylist Menu ---\n";
        cout << "1. Add element at beginning\n";
        cout << "2. Add element at end\n";
        cout << "3. Remove element from beginning\n";
        cout << "4. Remove element from end\n";
        cout << "5. Check if empty\n";
        cout << "6. Check if full\n";
        cout << "7. Display size\n";
        cout << "8. Insert at index\n";
        cout << "9. Display last element\n";
        cout << "10. Search for a value\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            obj.addelementatfirstindex(value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            obj.addelementatlastindex(value);
            break;

        case 3:
            if (!obj.empty())
                cout << "Removed: "
                << obj.removeelementfromstart() << '\n';
            else
                cout << "List is empty!\n";
            break;

        case 4:
            if (!obj.empty())
                cout << "Removed: "
                << obj.removeelementfromend() << '\n';
            else
                cout << "List is empty!\n";
            break;

        case 5:
            cout << (obj.empty() ? "List is empty\n"
                : "List is not empty\n");
            break;

        case 6:
            cout << (obj.full() ? "List is full\n"
                : "List is not full\n");
            break;

        case 7:
            cout << "Current size: " << obj.size() << '\n';
            break;

        case 8:
            cout << "Enter index (starting from 0): ";
            cin >> index;
            cout << "Enter value: ";
            cin >> value;

            if (obj.insertAt(index, value))
                cout << "Value inserted successfully.\n";
            else
                cout << "Invalid index or list is full.\n";
            break;

        case 9:
            if (!obj.empty())
                cout << "Last element: " << obj.last() << '\n';
            else
                cout << "List is empty!\n";
            break;

        case 10:
            cout << "Enter value to search: ";
            cin >> value;

            if (obj.search(value))
                cout << "Value found.\n";
            else
                cout << "Value not found.\n";
            break;

        case 0:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}