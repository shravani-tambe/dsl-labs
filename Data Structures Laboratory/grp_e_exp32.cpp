/*Pizza parlor accepting maximum M orders. Orders are served in first come first served
basis. Order once placed cannot be cancelled. Write C++ program to simulate the system
using circular queue using array.*/


#include <iostream>
using namespace std;

class PizzaQueue {
private:
    int* orders;  
    int front;     
    int rear;     
    int capacity;  
    int size;      

public:
    PizzaQueue(int cap) {
        capacity = cap;
        orders = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    ~PizzaQueue() {
        delete[] orders;
    }

    bool is_full() {
        return size == capacity; 
    }

    bool is_empty() {
        return size == 0; 
    }

    void place_order(int order_id) {
        if (is_full()) {
            cout << "Queue is full! Cannot place more orders." << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        orders[rear] = order_id;
        size++;
        cout << "Order " << order_id << " placed." << endl;
    }

    void serve_order() {
        if (is_empty()) {
            cout << "No orders to serve." << endl;
            return;
        }
        cout << "Serving order " << orders[front] << endl;
        front = (front + 1) % capacity;
        size--;
    }

    void display_orders() {
        if (is_empty()) {
            cout << "No orders in the queue." << endl;
            return;
        }
        cout << "Current orders in queue: ";
        for (int i = 0; i < size; i++) {
            cout << orders[(front + i) % capacity] << endl;
        }
        cout << endl;
    }
};

int main() {
    int capacity;
    cout << "Enter maximum number of orders: ";
    cin >> capacity;

    PizzaQueue queue(capacity);
    int choice, order_id;

    while (true) {
        cout << "Choose an operation: \n1. Place Order \n2. Serve Order \n3. Display Orders \n4. Exit" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter order ID to place: ";
                cin >> order_id;
                queue.place_order(order_id);
                break;
            case 2:
                queue.serve_order();
                break;
            case 3:
                queue.display_orders();
                break;
            case 4:
                return 0; 
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
