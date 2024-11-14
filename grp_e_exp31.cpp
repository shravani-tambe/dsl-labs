#include <iostream>
using namespace std;

class Deque {
private:
    int* arr;      
    int front;      
    int rear;       
    int capacity;  
    int size;    

public:
    Deque(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = -1;
        rear = 0;
        size = 0;
    }

    ~Deque() {
        delete[] arr; 
    }

    bool is_full() {
        return size == capacity; 
    }

    bool is_empty() {
        return size == 0; 
    }

    void add_front(int item) {
        if (is_full()) return;
        front = (front + 1) % capacity;
        arr[front] = item;
        if (size == 0) rear = front;
        size++;
    }

    void add_rear(int item) {
        if (is_full()) return;
        rear = (rear - 1 + capacity) % capacity;
        arr[rear] = item;
        if (size == 0) front = rear;
        size++;
    }

    void delete_front() {
        if (is_empty()) return;
        front = (front - 1 + capacity) % capacity;
        size--;
        if (size == 0) {
            front = -1;
            rear = 0;
        }
    }

    void delete_rear() {
        if (is_empty()) return;
        rear = (rear + 1) % capacity;
        size--;
        if (size == 0) {
            front = -1;
            rear = 0;
        }
    }

    void display() {
        if (is_empty()) return;
        cout << "Elements in deque: ";
        for (int i = 0; i < size; i++) {
            cout << arr[(rear + i) % capacity] << " ";
        }
        cout << endl;
    }
};

int main() {
    int capacity;
    cout << "Enter the capacity of the deque: ";
    cin >> capacity;
    Deque deque(capacity);

    int choice, item;
    while (true) {
        cout << "Choose an operation: \n1. Add to Front \n2. Add to Rear \n3. Delete from Front \n4. Delete from Rear \n5. Display \n6. Exit" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter item to add to front: ";
                cin >> item;
                deque.add_front(item);
                break;
            case 2:
                cout << "Enter item to add to rear: ";
                cin >> item;
                deque.add_rear(item);
                break;
            case 3:
                deque.delete_front();
                break;
            case 4:
                deque.delete_rear();
                break;
            case 5:
                deque.display();
                break;
            case 6:
                return 0; 
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
