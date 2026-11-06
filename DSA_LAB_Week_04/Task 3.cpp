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

template <typename type>
class customlist : public mylist<type> {
public:
    customlist(int s = 10, int cs = 0)
        : mylist<type>(s, cs) {}

    customlist(const customlist<type>& other)
        : mylist<type>(other) {}

    bool isPrime(int n) {
        if (n < 2)
            return false;

        for (int i = 2; i <= n / i; i++) {
            if (n % i == 0)
                return false;
        }

        return true;
    }

    type sum_ofPrime() {
        type sum = type();

        for (int i = 0; i < this->currentsize; i++) {
            if (isPrime(static_cast<int>(this->arr[i])))
                sum += this->arr[i];
        }

        return sum;
    }

    type secondMaxEven() {
        type largest = type(), second = type();
        bool foundLargest = false, foundSecond = false;

        for (int i = 0; i < this->currentsize; i++) {
            type value = this->arr[i];

            if (value % 2 != 0)
                continue;

            if (!foundLargest || value > largest) {
                if (foundLargest) {
                    second = largest;
                    foundSecond = true;
                }
                largest = value;
                foundLargest = true;
            }
            else if (value != largest &&
                (!foundSecond || value > second)) {
                second = value;
                foundSecond = true;
            }
        }

        if (!foundSecond) {
            cout << "Second maximum even number does not exist.\n";
            return type();
        }

        return second;
    }

    type secondMinOdd() {
        type smallest = type(), second = type();
        bool foundSmallest = false, foundSecond = false;

        for (int i = 0; i < this->currentsize; i++) {
            type value = this->arr[i];

            if (value % 2 == 0)
                continue;

            if (!foundSmallest || value < smallest) {
                if (foundSmallest) {
                    second = smallest;
                    foundSecond = true;
                }
                smallest = value;
                foundSmallest = true;
            }
            else if (value != smallest &&
                (!foundSecond || value < second)) {
                second = value;
                foundSecond = true;
            }
        }

        if (!foundSecond) {
            cout << "Second minimum odd number does not exist.\n";
            return type();
        }

        return second;
    }

    void printDuplicates() {
        bool found = false;

        for (int i = 0; i < this->currentsize; i++) {
            bool appearedBefore = false;

            for (int j = 0; j < i; j++) {
                if (this->arr[i] == this->arr[j]) {
                    appearedBefore = true;
                    break;
                }
            }

            if (appearedBefore)
                continue;

            int count = 0;

            for (int j = 0; j < this->currentsize; j++) {
                if (this->arr[i] == this->arr[j])
                    count++;
            }

            if (count > 1) {
                cout << this->arr[i] << " ";
                found = true;
            }
        }

        if (!found)
            cout << "No duplicates found.";

        cout << '\n';
    }

private:
    void rotateRight(int start, int length, int r) {
        if (length <= 1)
            return;

        r %= length;

        for (int k = 0; k < r; k++) {
            type temp = this->arr[start + length - 1];

            for (int i = start + length - 1; i > start; i--)
                this->arr[i] = this->arr[i - 1];

            this->arr[start] = temp;
        }
    }

    void rotateLeft(int start, int length, int r) {
        if (length <= 1)
            return;

        r %= length;

        for (int k = 0; k < r; k++) {
            type temp = this->arr[start];

            for (int i = start; i < start + length - 1; i++)
                this->arr[i] = this->arr[i + 1];

            this->arr[start + length - 1] = temp;
        }
    }

public:
    void rotateClockwaise(int r) {
        if (r < 0 || this->currentsize == 0)
            return;

        int firstHalf = (this->currentsize + 1) / 2;
        int secondHalf = this->currentsize - firstHalf;

        rotateRight(0, firstHalf, r);
        rotateRight(firstHalf, secondHalf, r);
    }

    void rotateanitclockwaise(int rt) {
        if (rt < 0 || this->currentsize == 0)
            return;

        int firstHalf = (this->currentsize + 1) / 2;
        int secondHalf = this->currentsize - firstHalf;

        rotateLeft(0, firstHalf, rt);
        rotateLeft(firstHalf, secondHalf, rt);
    }

    void display() {
        for (int i = 0; i < this->currentsize; i++)
            cout << this->arr[i] << " ";

        cout << '\n';
    }

    ~customlist() override = default;
};

int main() {
    int capacity;

    cout << "Enter maximum list size: ";
    cin >> capacity;

    if (capacity <= 0) {
        cout << "Capacity must be positive.\n";
        return 0;
    }

    customlist<int> obj(capacity);

    int choice, value, r;

    do {
        cout << "\n--- customlist Menu ---\n";
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
        cout << "11. Display list\n";
        cout << "12. Sum of prime numbers\n";
        cout << "13. Second maximum even number\n";
        cout << "14. Second minimum odd number\n";
        cout << "15. Print duplicates\n";
        cout << "16. Rotate clockwise\n";
        cout << "17. Rotate anti-clockwise\n";
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

        case 8: {
            int index;
            cout << "Enter index: ";
            cin >> index;
            cout << "Enter value: ";
            cin >> value;

            if (obj.insertAt(index, value))
                cout << "Value inserted successfully.\n";
            else
                cout << "Invalid index or list is full.\n";
            break;
        }

        case 9:
            if (!obj.empty())
                cout << "Last element: " << obj.last() << '\n';
            else
                cout << "List is empty!\n";
            break;

        case 10:
            cout << "Enter value to search: ";
            cin >> value;

            cout << (obj.search(value) ? "Value found\n"
                : "Value not found\n");
            break;

        case 11:
            cout << "List: ";
            obj.display();
            break;

        case 12:
            cout << "Sum of prime numbers: "
                << obj.sum_ofPrime() << '\n';
            break;

        case 13:
            cout << "Second maximum even number: "
                << obj.secondMaxEven() << '\n';
            break;

        case 14:
            cout << "Second minimum odd number: "
                << obj.secondMinOdd() << '\n';
            break;

        case 15:
            cout << "Duplicate values: ";
            obj.printDuplicates();
            break;

        case 16:
            cout << "Enter rotation count: ";
            cin >> r;
            obj.rotateClockwaise(r);
            cout << "List after clockwise rotation: ";
            obj.display();
            break;

        case 17:
            cout << "Enter rotation count: ";
            cin >> r;
            obj.rotateanitclockwaise(r);
            cout << "List after anti-clockwise rotation: ";
            obj.display();
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